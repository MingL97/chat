#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "global.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    Ui::LoginDialog *ui;


    void initHeadUI();

    QMap<ReqId,std::function<void(const QJsonObject&)>> _handers;
    QMap<TipErr,QString> _tipErrs;

    void showErrTip(QString str,bool b_ok);
    void initHttpHandlers();
    bool checkEmailVaild();
    bool checkPasswdVaild();




    void addTipErr(TipErr, QString);
    void delTipErr(TipErr);



signals:
   void sig_loginSwitchRegister();
   void sig_loginSwitchReset();
private slots:
   void slot_http_finish(ReqId id,QString res,ErrorCodes err);

   void on_btn_login_clicked();
};

#endif // LOGINDIALOG_H
