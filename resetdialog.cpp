#include "resetdialog.h"
#include "ui_resetdialog.h"
#include "httpmgr.h"

ResetDialog::ResetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResetDialog)
{
    ui->setupUi(this);


    connect(ui->user_lineEdit,&QLineEdit::editingFinished,[this](){
        checkUserVaild();
    });
    connect(ui->email_lineEdit,&QLineEdit::editingFinished,[this](){
        checkEmailVaild();
    });
    connect(ui->passwd_lineEdit,&QLineEdit::editingFinished,[this](){
        checkPasswdVaild();
    });

    connect(ui->verify_lineEdit,&QLineEdit::editingFinished,[this](){
        checkVerifyVaild();
    });

    initHandles();
    connect(HttpMgr::GetInstance().get(),&HttpMgr::sig_reset_mod_finished,
            this,&ResetDialog::slot_httpFinished);


}

ResetDialog::~ResetDialog()
{
    delete ui;
}

void ResetDialog::on_verify_btn_clicked()
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
                                            Modules::RESET_MOD);

    }
    else
    {
        showErrTip(tr("邮箱地址不正确"),false);
    }
}


void ResetDialog::on_confirm_btn_clicked()
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

    if(!checkVerifyVaild())
    {
        return;
    }


    QJsonObject json_obj;
    json_obj["user"] = ui->user_lineEdit->text();
    json_obj["email"] = ui->email_lineEdit->text();
    json_obj["passwd"] = xorString(ui->passwd_lineEdit->text());
    json_obj["verifyCode"] = ui->verify_lineEdit->text();
    HttpMgr::GetInstance()->postHttpReq(QUrl(gate_url_prefix+"/reset_pwd"),
                                        json_obj, ReqId::ID_RESET_PWD,Modules::RESET_MOD);

}


void ResetDialog::on_return_btn_clicked()
{
    emit sig_resetSwitchLogin();
}

void ResetDialog::initHandles()
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


    //重置密码
    _handers.insert(ReqId::ID_RESET_PWD,[this](const QJsonObject& jsonObj){

        int error = jsonObj["error"].toInt();

        if(error != ErrorCodes::SUCCESS)
        {
            showErrTip(tr("参数错误"),false);
            return;
        }

        auto email = jsonObj["email"].toString();
        showErrTip(tr("重置成功，点击返回登录页面"),true);
        qDebug()<<"email is " << email ;
        return;

    });


}

void ResetDialog::showErrTip(QString str, bool b_ok)
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

bool ResetDialog::checkUserVaild()
{
    if(ui->user_lineEdit->text() == "")
    {
        addTipErr(TipErr::TIP_USER_ERR,tr("用户名不能为空"));
        return false;
    }
    delTipErr(TipErr::TIP_USER_ERR);
    return true;
}

bool ResetDialog::checkEmailVaild()
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

bool ResetDialog::checkPasswdVaild()
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

bool ResetDialog::checkVerifyVaild()
{
    if(ui->user_lineEdit->text() == "")
    {
        addTipErr(TipErr::TIP_VERIFY_ERR,tr("验证码不能为空"));
        return false;
    }
    delTipErr(TipErr::TIP_VERIFY_ERR);
    return true;
}

void ResetDialog::addTipErr(TipErr tipErr, QString tip)
{
    _tipErrs[tipErr] = tip;
    showErrTip(tip,false);
}

void ResetDialog::delTipErr(TipErr tipErr)
{
    _tipErrs.remove(tipErr);
    if(_tipErrs.empty())
    {
        ui->label_error->clear();
        return;
    }
    showErrTip(_tipErrs.first(),false);
}

void ResetDialog::slot_httpFinished(ReqId id, QString res, ErrorCodes err)
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

