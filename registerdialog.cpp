#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "httpmgr.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);

    ui->passwd_lineEdit->setEchoMode(QLineEdit::Password);
    ui->confirm_lineEdit->setEchoMode(QLineEdit::Password);
    ui->label_error->setProperty("state","normal");
    repolish(ui->label_error);
    connect(HttpMgr::GetInstance().get(),&HttpMgr::sig_reg_mod_finished,
            this,&RegisterDialog::slot_http_finish);

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
    _handers.insert(ReqId::ID_GET_VARIFY_CODE,[this](const QJsonObject& jsonObj){

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
}

