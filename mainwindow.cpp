#include "mainwindow.h"
#include "ui_mainwindow.h"

/******************************************************************************
 *
 * @file       mainwindow.cpp
 * @brief      主窗口
 *
 * @author     liuming
 * @date       2024/10/17
 * @history
 *****************************************************************************/



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //登录
    _login_dlg = new LoginDialog(this);
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    connect(_login_dlg,&LoginDialog::sig_loginSwitchRegister,this,&MainWindow::slot_loginSwitchReg);
    connect(_login_dlg,&LoginDialog::sig_loginSwitchReset,this,&MainWindow::slot_loginSwitchReset);

    setCentralWidget(_login_dlg);

    //注册
    _register_dlg = new RegisterDialog(this);
    _register_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    connect(_register_dlg,&RegisterDialog::sig_registerSwitchLogin,this,&MainWindow::slot_registerSwitchLogin);

    //重置密码
    _reset_dlg = new ResetDialog(this);
    _reset_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    connect(_reset_dlg,&ResetDialog::sig_resetSwitchLogin,this,&MainWindow::slot_resetSwitchLogin);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_loginSwitchReg()
{
    takeCentralWidget();
    setCentralWidget(_register_dlg);
    _login_dlg->hide();
    _register_dlg->show();
}

void MainWindow::slot_registerSwitchLogin()
{
    takeCentralWidget();
    setCentralWidget(_login_dlg);
    _register_dlg->hide();
    _login_dlg->show();
}

void MainWindow::slot_loginSwitchReset()
{
    takeCentralWidget();
    setCentralWidget(_reset_dlg);
    _login_dlg->hide();
    _reset_dlg->show();
}

void MainWindow::slot_resetSwitchLogin()
{
    takeCentralWidget();
    setCentralWidget(_login_dlg);
    _reset_dlg->hide();
    _login_dlg->show();
}

