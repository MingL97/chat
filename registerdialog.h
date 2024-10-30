#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "global.h"

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();


private slots:
    void slot_http_finish(ReqId id,QString res,ErrorCodes err);

    void on_btn_get_code_clicked();

    void on_btn_confirm_clicked();

    void on_return_btn_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::RegisterDialog *ui;
    QMap<ReqId,std::function<void(const QJsonObject&)>> _handers;
    QMap<TipErr,QString> _tipErrs;

    void showErrTip(QString str,bool b_ok);
    void initHttpHandlers();
    bool checkUserVaild();
    bool checkEmailVaild();
    bool checkPasswdVaild();
    bool checkConfirmVaild();
    bool checkVerifyVaild();



    void addTipErr(TipErr,QString);
    void delTipErr(TipErr);

    void changeTipPage();




    QTimer* _countTimer;
    int _count;

signals:
    void sig_registerSwitchLogin();

};

#endif // REGISTERDIALOG_H
