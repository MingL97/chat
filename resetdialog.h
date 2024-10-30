#ifndef RESETDIALOG_H
#define RESETDIALOG_H

#include <QDialog>
#include "global.h"

namespace Ui {
class ResetDialog;
}

class ResetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResetDialog(QWidget *parent = nullptr);
    ~ResetDialog();

private slots:
    void on_verify_btn_clicked();

    void on_confirm_btn_clicked();

    void on_return_btn_clicked();

private:
    Ui::ResetDialog *ui;
    QMap<TipErr,QString> _tipErrs;
    QMap<ReqId,std::function<void(const QJsonObject&)>> _handers;



    void initHandles();

    void showErrTip(QString str,bool b_ok);
    bool checkUserVaild();
    bool checkEmailVaild();
    bool checkPasswdVaild();
    bool checkVerifyVaild();



    void addTipErr(TipErr,QString);
    void delTipErr(TipErr);
signals:
    void sig_resetSwitchLogin();
private slots:
    void slot_httpFinished(ReqId id,QString res,ErrorCodes err);

};

#endif // RESETDIALOG_H
