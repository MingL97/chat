/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedlabel.h>
#include <timerbtn.h>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_error;
    QHBoxLayout *horizontalLayout;
    QLabel *user_label;
    QLineEdit *user_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *email_label;
    QLineEdit *email_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *passwd_label;
    QLineEdit *passwd_lineEdit;
    ClickedLabel *passwd_visible;
    QHBoxLayout *horizontalLayout_4;
    QLabel *confirm_label;
    QLineEdit *confirm_lineEdit;
    ClickedLabel *confirm_visible;
    QHBoxLayout *horizontalLayout_5;
    QLabel *verify_label;
    QLineEdit *verify_lineEdit;
    TimerBtn *btn_get_code;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_confirm;
    QPushButton *btn_cancel;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *tip_label;
    QLabel *tip2_label;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *return_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QString::fromUtf8("RegisterDialog"));
        RegisterDialog->resize(300, 500);
        RegisterDialog->setMinimumSize(QSize(300, 500));
        RegisterDialog->setMaximumSize(QSize(300, 500));
        verticalLayout_2 = new QVBoxLayout(RegisterDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        stackedWidget = new QStackedWidget(RegisterDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_error = new QLabel(widget);
        label_error->setObjectName(QString::fromUtf8("label_error"));
        label_error->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_error);


        verticalLayout_3->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        user_label = new QLabel(page);
        user_label->setObjectName(QString::fromUtf8("user_label"));
        user_label->setMinimumSize(QSize(0, 25));
        user_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(user_label);

        user_lineEdit = new QLineEdit(page);
        user_lineEdit->setObjectName(QString::fromUtf8("user_lineEdit"));
        user_lineEdit->setMinimumSize(QSize(0, 25));
        user_lineEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(user_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        email_label = new QLabel(page);
        email_label->setObjectName(QString::fromUtf8("email_label"));
        email_label->setMinimumSize(QSize(0, 25));
        email_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(email_label);

        email_lineEdit = new QLineEdit(page);
        email_lineEdit->setObjectName(QString::fromUtf8("email_lineEdit"));
        email_lineEdit->setMinimumSize(QSize(0, 25));
        email_lineEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(email_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        passwd_label = new QLabel(page);
        passwd_label->setObjectName(QString::fromUtf8("passwd_label"));
        passwd_label->setMinimumSize(QSize(0, 25));
        passwd_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(passwd_label);

        passwd_lineEdit = new QLineEdit(page);
        passwd_lineEdit->setObjectName(QString::fromUtf8("passwd_lineEdit"));

        horizontalLayout_3->addWidget(passwd_lineEdit);

        passwd_visible = new ClickedLabel(page);
        passwd_visible->setObjectName(QString::fromUtf8("passwd_visible"));
        passwd_visible->setMinimumSize(QSize(20, 20));
        passwd_visible->setMaximumSize(QSize(20, 20));

        horizontalLayout_3->addWidget(passwd_visible);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        confirm_label = new QLabel(page);
        confirm_label->setObjectName(QString::fromUtf8("confirm_label"));

        horizontalLayout_4->addWidget(confirm_label);

        confirm_lineEdit = new QLineEdit(page);
        confirm_lineEdit->setObjectName(QString::fromUtf8("confirm_lineEdit"));

        horizontalLayout_4->addWidget(confirm_lineEdit);

        confirm_visible = new ClickedLabel(page);
        confirm_visible->setObjectName(QString::fromUtf8("confirm_visible"));
        confirm_visible->setMinimumSize(QSize(20, 20));
        confirm_visible->setMaximumSize(QSize(20, 20));

        horizontalLayout_4->addWidget(confirm_visible);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, 5, 5, 5);
        verify_label = new QLabel(page);
        verify_label->setObjectName(QString::fromUtf8("verify_label"));

        horizontalLayout_5->addWidget(verify_label);

        verify_lineEdit = new QLineEdit(page);
        verify_lineEdit->setObjectName(QString::fromUtf8("verify_lineEdit"));

        horizontalLayout_5->addWidget(verify_lineEdit);

        btn_get_code = new TimerBtn(page);
        btn_get_code->setObjectName(QString::fromUtf8("btn_get_code"));

        horizontalLayout_5->addWidget(btn_get_code);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(5, 5, 5, 5);
        btn_confirm = new QPushButton(page);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setMinimumSize(QSize(0, 25));
        btn_confirm->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(btn_confirm);

        btn_cancel = new QPushButton(page);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setMinimumSize(QSize(0, 25));
        btn_cancel->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(btn_cancel);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tip_label = new QLabel(page_2);
        tip_label->setObjectName(QString::fromUtf8("tip_label"));
        tip_label->setLayoutDirection(Qt::LeftToRight);
        tip_label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(tip_label);

        tip2_label = new QLabel(page_2);
        tip2_label->setObjectName(QString::fromUtf8("tip2_label"));
        tip2_label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(tip2_label);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        widget_2 = new QWidget(page_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_7 = new QHBoxLayout(widget_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(73, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        return_btn = new QPushButton(widget_2);
        return_btn->setObjectName(QString::fromUtf8("return_btn"));

        horizontalLayout_7->addWidget(return_btn);

        horizontalSpacer_2 = new QSpacerItem(73, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_5->addWidget(widget_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RegisterDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        label_error->setText(QCoreApplication::translate("RegisterDialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        user_label->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        email_label->setText(QCoreApplication::translate("RegisterDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        passwd_label->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        passwd_visible->setText(QString());
        confirm_label->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\357\274\232", nullptr));
        confirm_visible->setText(QString());
        verify_label->setText(QCoreApplication::translate("RegisterDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        btn_get_code->setText(QCoreApplication::translate("RegisterDialog", "\350\216\267\345\217\226", nullptr));
        btn_confirm->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\345\256\232", nullptr));
        btn_cancel->setText(QCoreApplication::translate("RegisterDialog", "\345\217\226\346\266\210", nullptr));
        tip_label->setText(QCoreApplication::translate("RegisterDialog", "\346\263\250\345\206\214\346\210\220\345\212\237\357\274\2145s\345\220\216\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        tip2_label->setText(QCoreApplication::translate("RegisterDialog", "\347\202\271\345\207\273\350\277\224\345\233\236\346\214\211\351\222\256\357\274\214\347\253\213\345\215\263\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        return_btn->setText(QCoreApplication::translate("RegisterDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
