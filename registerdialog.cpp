#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "httpmgr.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog),_count(4)
{
    ui->setupUi(this);

    initHttpHandlers();

    ui->stackedWidget->setCurrentWidget(ui->page);


    ui->passwd_lineEdit->setEchoMode(QLineEdit::Password);
    ui->confirm_lineEdit->setEchoMode(QLineEdit::Password);


    ui->label_error->setProperty("state","normal");
    repolish(ui->label_error);
    connect(HttpMgr::GetInstance().get(),&HttpMgr::sig_reg_mod_finished,
            this,&RegisterDialog::slot_http_finish);

    ui->label_error->clear();

    connect(ui->user_lineEdit,&QLineEdit::editingFinished,[this](){
        checkUserVaild();
    });
    connect(ui->email_lineEdit,&QLineEdit::editingFinished,[this](){
        checkEmailVaild();
    });
    connect(ui->passwd_lineEdit,&QLineEdit::editingFinished,[this](){
        checkPasswdVaild();
    });
    connect(ui->confirm_lineEdit,&QLineEdit::editingFinished,[this](){
        checkConfirmVaild();
    });
    connect(ui->verify_lineEdit,&QLineEdit::editingFinished,[this](){
        checkVerifyVaild();
    });


//    ui->passwd_visible->setCursor(Qt::PointingHandCursor);
//    ui->confirm_visible->setCursor(Qt::PointingHandCursor);


    ui->passwd_visible->setState("unvisible","unvisible_hover","","visible",
                                 "visible_hover","");
    ui->confirm_visible->setState("unvisible","unvisible_hover","","visible",
                                  "visible_hover","");

    connect(ui->passwd_visible,&ClickedLabel::clicked,[this](){

        auto state = ui->passwd_visible->getState();
        if(state == ClickLbState::Normal)
        {
            ui->passwd_lineEdit->setEchoMode(QLineEdit::Password);

        }
        else
        {
            ui->passwd_lineEdit->setEchoMode(QLineEdit::Normal);
        }

    });

    connect(ui->confirm_visible,&ClickedLabel::clicked,[this](){

        auto state = ui->confirm_visible->getState();
        if(state == ClickLbState::Normal)
        {
            ui->confirm_lineEdit->setEchoMode(QLineEdit::Password);

        }
        else
        {
            ui->confirm_lineEdit->setEchoMode(QLineEdit::Normal);
        }

    });


    _countTimer = new QTimer(this);

    connect(_countTimer,&QTimer::timeout,[this](){
        if(_count == 0)
        {

            _countTimer->stop();
            emit sig_registerSwitchLogin();
            return;
        }

        auto str = QString("注册成功，%1s后返回登录界面").arg(_count);
        _count -- ;
        ui->tip_label->setText(str);

    });



}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_btn_get_code_clicked()
{
    auto email = ui->email_lineEdit->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@?(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();
    if(match)
    {
        QJsonObject  json_object;
        json_object["email"] = email;
        HttpMgr::GetInstance()->postHttpReq(QUrl(gate_url_prefix + "/get_verifycode"),
                                            json_object,
                                            ReqId::ID_GET_VERIFY_CODE,
                                            Modules::REGISTER_MOD);

    }
    else
    {
        showErrTip(tr("邮箱地址不正确"),false);
    }
}

void RegisterDialog::slot_http_finish(ReqId id, QString res, ErrorCodes err)
{

    if(err != ErrorCodes::SUCCESS)
    {
        showErrTip(tr("网络请求错误"),false);
        return;
    }

    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull())
    {
        showErrTip(tr("json解析失败"),false);
        return;
    }

    if(!jsonDoc.isObject())
    {
        showErrTip(tr("json解析失败"),false);
        return;
    }

    //调用对应函数
    _handers[id](jsonDoc.object());

    return;

}

void RegisterDialog::showErrTip(QString str, bool b_ok)
{
    if(b_ok)
    {
        ui->label_error->setProperty("state","normal");
    }
    else
    {
        ui->label_error->setProperty("state","err");

    }
    ui->label_error->setText(str);
    repolish(ui->label_error);
}

void RegisterDialog::initHttpHandlers()
{
    //获取验证码
    _handers.insert(ReqId::ID_GET_VERIFY_CODE,[this](const QJsonObject& jsonObj){

        int error = jsonObj["error"].toInt();

        if(error != ErrorCodes::SUCCESS)
        {
            showErrTip(tr("参数错误"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        showErrTip(tr("验证码已发送到邮箱，请注意查收"),true);
        qDebug()<<"email is " << email ;
        return;

    });

    //注册用户
    _handers.insert(ReqId::ID_REGISTER_USER,[this](const QJsonObject& jsonObj){

        int error = jsonObj["error"].toInt();

        if(error != ErrorCodes::SUCCESS)
        {
            showErrTip(tr("参数错误"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        auto uuid = jsonObj["uid"].toInt();

        showErrTip(tr("用户注册成功"),true);

        changeTipPage();
        qDebug()<<"email is " << email << " uid is " << uuid ;
        return;

    });
}

bool RegisterDialog::checkUserVaild()
{
    if(ui->user_lineEdit->text() == "")
    {
        addTipErr(TipErr::TIP_USER_ERR,tr("用户名不能为空"));
        return false;
    }
    delTipErr(TipErr::TIP_USER_ERR);
    return true;

}

bool RegisterDialog::checkEmailVaild()
{
    //验证邮箱的地址正则表达式
    auto email = ui->email_lineEdit->text();
    // 邮箱地址的正则表达式
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch(); // 执行正则表达式匹配
    if(!match){
        //提示邮箱不正确
        addTipErr(TipErr::TIP_EMAIL_ERR, tr("邮箱地址不正确"));
        return false;
    }
    delTipErr(TipErr::TIP_EMAIL_ERR);
    return true;
}

bool RegisterDialog::checkPasswdVaild()
{
    auto pass = ui->passwd_lineEdit->text();

    if(pass.length() < 6 || pass.length() > 15)
    {
        addTipErr(TipErr::TIP_PWD_ERR,tr("密码长度应为6~15"));
        return false;
    }


    QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
    bool match = regExp.match(pass).hasMatch();
    if(!match)
    {
        addTipErr(TipErr::TIP_PWD_ERR,tr("密码包含非法字符"));
        return false;
    }

    delTipErr(TipErr::TIP_PWD_ERR);
    return true;
}

bool RegisterDialog::checkConfirmVaild()
{

    if(ui->confirm_lineEdit->text() != ui->passwd_lineEdit->text())
    {
        addTipErr(TipErr::TIP_PWD_CONFIRM,tr("密码不匹配"));
        return false;
    }
    delTipErr(TipErr::TIP_PWD_CONFIRM);
    return true;
}

bool RegisterDialog::checkVerifyVaild()
{
    if(ui->user_lineEdit->text() == "")
    {
        addTipErr(TipErr::TIP_VERIFY_ERR,tr("验证码不能为空"));
        return false;
    }
    delTipErr(TipErr::TIP_VERIFY_ERR);
    return true;
}

void RegisterDialog::addTipErr(TipErr tipErr, QString tip)
{
    _tipErrs[tipErr] = tip;
    showErrTip(tip,false);
}

void RegisterDialog::delTipErr(TipErr tipErr)
{
    _tipErrs.remove(tipErr);
    if(_tipErrs.empty())
    {
        ui->label_error->clear();
        return;
    }
    showErrTip(_tipErrs.first(),false);

}

void RegisterDialog::changeTipPage()
{
    _countTimer->stop();
    ui->stackedWidget->setCurrentWidget(ui->page_2);

    _countTimer->start(1000);
    _count = 4;

}


void RegisterDialog::on_btn_confirm_clicked()
{
    if(!checkUserVaild())
    {
        return;
    }

    if(!checkEmailVaild())
    {
        return;
    }

    if(!checkPasswdVaild())
    {
        return;
    }

    if(!checkConfirmVaild())
    {
        return;
    }

    if(!checkVerifyVaild())
    {
        return;
    }


    QJsonObject json_obj;
    json_obj["user"] = ui->user_lineEdit->text();
    json_obj["email"] = ui->email_lineEdit->text();
    json_obj["passwd"] = xorString(ui->passwd_lineEdit->text());
    json_obj["confirm"] = xorString(ui->confirm_lineEdit->text());
    json_obj["verifyCode"] = ui->verify_lineEdit->text();
    HttpMgr::GetInstance()->postHttpReq(QUrl(gate_url_prefix+"/user_register"),
                                        json_obj, ReqId::ID_REGISTER_USER,Modules::REGISTER_MOD);
}


void RegisterDialog::on_return_btn_clicked()
{
    _countTimer->stop();
    emit sig_registerSwitchLogin();
}


void RegisterDialog::on_btn_cancel_clicked()
{
    emit sig_registerSwitchLogin();
}

