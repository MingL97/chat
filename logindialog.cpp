#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPainter>
#include <QPainterPath>
#include <QJsonObject>
#include "httpmgr.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    connect(ui->btn_register,&QPushButton::clicked,this,&LoginDialog::sig_loginSwitchRegister);

    ui->forgetPw_label->setState("normal","hover","","selected","selected_hover","");
    connect(ui->forgetPw_label,&ClickedLabel::clicked,this,&LoginDialog::sig_loginSwitchReset);
    initHeadUI();
    initHttpHandlers();

    connect(ui->email_lineEdit,&QLineEdit::editingFinished,[this](){
        checkEmailVaild();
    });
    connect(ui->passwd_lineEdit,&QLineEdit::editingFinished,[this](){
        checkPasswdVaild();
    });

    connect(HttpMgr::GetInstance().get(),&HttpMgr::sig_login_mod_finished,
            this,&LoginDialog::slot_http_finish);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::initHeadUI()
{
    QPixmap originPixmap(":/res/head_1.jpg");

    originPixmap = originPixmap.scaled(ui->head_label->size(),
                                       Qt::KeepAspectRatio,
                                       Qt::SmoothTransformation);

    // 创建一个和原始图片相同大小的QPixmap，用于绘制圆角图片
    QPixmap roundedPixmap(originPixmap.size());
    roundedPixmap.fill(Qt::transparent); // 用透明色填充

    QPainter painter(&roundedPixmap);
    painter.setRenderHint(QPainter::Antialiasing); // 设置抗锯齿，使圆角更平滑
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    // 使用QPainterPath设置圆角
    QPainterPath path;
    path.addRoundedRect(0, 0, originPixmap.width(), originPixmap.height(), 10, 10); // 最后两个参数分别是x和y方向的圆角半径
    painter.setClipPath(path);

    // 将原始图片绘制到roundedPixmap上
    painter.drawPixmap(0, 0, originPixmap);

    // 设置绘制好的圆角图片到QLabel上
    ui->head_label->setPixmap(roundedPixmap);
}

void LoginDialog::showErrTip(QString str, bool b_ok)
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

void LoginDialog::initHttpHandlers()
{
    //登录
    _handers.insert(ReqId::ID_LOGIN_USER,[this](const QJsonObject& jsonObj){

        int error = jsonObj["error"].toInt();

        if(error != ErrorCodes::SUCCESS)
        {
            showErrTip(tr("邮箱或密码错误"),false);
            return;
        }

        ServerInfo serverinfo;

        serverinfo.host = jsonObj["host"].toString();
        serverinfo.port = jsonObj["port"].toString();
        serverinfo.token = jsonObj["token"].toString();
        serverinfo.uid = jsonObj["uid"].toInt();

        showErrTip(tr("登录成功"),true);
        return;

    });
}

bool LoginDialog::checkEmailVaild()
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

bool LoginDialog::checkPasswdVaild()
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

void LoginDialog::addTipErr(TipErr tipErr, QString tip)
{
    _tipErrs[tipErr] = tip;
    showErrTip(tip,false);
}

void LoginDialog::delTipErr(TipErr tipErr)
{
    _tipErrs.remove(tipErr);
    if(_tipErrs.empty())
    {
        ui->label_error->clear();
        return;
    }
    showErrTip(_tipErrs.first(),false);
}

void LoginDialog::slot_http_finish(ReqId id, QString res, ErrorCodes err)
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

void LoginDialog::on_btn_login_clicked()
{

    if(!checkEmailVaild())
    {
        return;
    }

    if(!checkPasswdVaild())
    {
        return;
    }


    QJsonObject json_obj;
    json_obj["email"] = ui->email_lineEdit->text();
    json_obj["passwd"] = xorString(ui->passwd_lineEdit->text());
    HttpMgr::GetInstance()->postHttpReq(QUrl(gate_url_prefix+"/user_login"),
                                        json_obj, ReqId::ID_LOGIN_USER,Modules::LOGIN_MOD);
}

