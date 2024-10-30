/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedlabel.h>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_error;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *head_label;
    QHBoxLayout *horizontalLayout;
    QLabel *email_label;
    QLineEdit *email_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwd_label;
    QLineEdit *passwd_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    ClickedLabel *forgetPw_label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_login;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_register;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(300, 500);
        LoginDialog->setMinimumSize(QSize(300, 500));
        LoginDialog->setMaximumSize(QSize(300, 500));
        verticalLayout_2 = new QVBoxLayout(LoginDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        label_error = new QLabel(LoginDialog);
        label_error->setObjectName(QString::fromUtf8("label_error"));
        label_error->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_error);

        widget = new QWidget(LoginDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        head_label = new QLabel(widget);
        head_label->setObjectName(QString::fromUtf8("head_label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(head_label->sizePolicy().hasHeightForWidth());
        head_label->setSizePolicy(sizePolicy);
        head_label->setMinimumSize(QSize(200, 200));
        head_label->setMaximumSize(QSize(200, 200));
        head_label->setLayoutDirection(Qt::LeftToRight);
        head_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(head_label, 1, 0, 1, 1);


        verticalLayout->addWidget(widget, 0, Qt::AlignVCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        email_label = new QLabel(LoginDialog);
        email_label->setObjectName(QString::fromUtf8("email_label"));
        email_label->setMinimumSize(QSize(0, 25));
        email_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(email_label);

        email_lineEdit = new QLineEdit(LoginDialog);
        email_lineEdit->setObjectName(QString::fromUtf8("email_lineEdit"));
        email_lineEdit->setMinimumSize(QSize(0, 25));
        email_lineEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(email_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        passwd_label = new QLabel(LoginDialog);
        passwd_label->setObjectName(QString::fromUtf8("passwd_label"));
        passwd_label->setMinimumSize(QSize(0, 25));
        passwd_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(passwd_label);

        passwd_lineEdit = new QLineEdit(LoginDialog);
        passwd_lineEdit->setObjectName(QString::fromUtf8("passwd_lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(passwd_lineEdit->sizePolicy().hasHeightForWidth());
        passwd_lineEdit->setSizePolicy(sizePolicy1);
        passwd_lineEdit->setMinimumSize(QSize(0, 25));
        passwd_lineEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(passwd_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        forgetPw_label = new ClickedLabel(LoginDialog);
        forgetPw_label->setObjectName(QString::fromUtf8("forgetPw_label"));
        forgetPw_label->setMinimumSize(QSize(0, 25));
        forgetPw_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(forgetPw_label);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        btn_login = new QPushButton(LoginDialog);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setMinimumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(btn_login);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        btn_register = new QPushButton(LoginDialog);
        btn_register->setObjectName(QString::fromUtf8("btn_register"));
        btn_register->setEnabled(true);
        btn_register->setMinimumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(btn_register);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        label_error->setText(QString());
        head_label->setText(QString());
        email_label->setText(QCoreApplication::translate("LoginDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        passwd_label->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        forgetPw_label->setText(QCoreApplication::translate("LoginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        btn_login->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        btn_register->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
