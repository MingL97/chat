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
    _login_dlg = new LoginDialog(this);
    setCentralWidget(_login_dlg);

    connect(_login_dlg,&LoginDialog::sig_switchRegister,this,&MainWindow::SlotSwitchReg);

    _register_dlg = new RegisterDialog(this);
    _register_dlg->hide();

    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    _register_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotSwitchReg()
{
    setCentralWidget(_register_dlg);
    _login_dlg->hide();
    _register_dlg->show();
}

