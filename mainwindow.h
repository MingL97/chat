#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"
#include "registerdialog.h"
#include "resetdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LoginDialog *_login_dlg;
    RegisterDialog *_register_dlg;
    ResetDialog *_reset_dlg;
public  slots:
    void slot_loginSwitchReg();
    void slot_loginSwitchReset();
    void slot_registerSwitchLogin();
    void slot_resetSwitchLogin();

};
#endif // MAINWINDOW_H
