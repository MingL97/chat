#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

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
    void on_btn_get_code_clicked();

private:
    Ui::RegisterDialog *ui;

    void showErrTip(QString str,bool b_ok);

};

#endif // REGISTERDIALOG_H