/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETDIALOG_H
#define UI_RESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_error;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *user_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *email_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *verify_lineEdit;
    QPushButton *verify_btn;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *passwd_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *confirm_btn;
    QPushButton *return_btn;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName(QString::fromUtf8("ResetDialog"));
        ResetDialog->resize(300, 500);
        ResetDialog->setMinimumSize(QSize(300, 500));
        ResetDialog->setMaximumSize(QSize(300, 500));
        verticalLayoutWidget = new QWidget(ResetDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 291, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_error = new QLabel(verticalLayoutWidget);
        label_error->setObjectName(QString::fromUtf8("label_error"));
        label_error->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_error);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label_2);

        user_lineEdit = new QLineEdit(verticalLayoutWidget);
        user_lineEdit->setObjectName(QString::fromUtf8("user_lineEdit"));

        horizontalLayout->addWidget(user_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, 6, 6, 6);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(label_3);

        email_lineEdit = new QLineEdit(verticalLayoutWidget);
        email_lineEdit->setObjectName(QString::fromUtf8("email_lineEdit"));

        horizontalLayout_2->addWidget(email_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, 6, 6, 6);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(50, 0));
        label_4->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_4);

        verify_lineEdit = new QLineEdit(verticalLayoutWidget);
        verify_lineEdit->setObjectName(QString::fromUtf8("verify_lineEdit"));

        horizontalLayout_3->addWidget(verify_lineEdit);

        verify_btn = new QPushButton(verticalLayoutWidget);
        verify_btn->setObjectName(QString::fromUtf8("verify_btn"));

        horizontalLayout_3->addWidget(verify_btn);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(6, 6, 6, 6);
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(50, 0));
        label_5->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(label_5);

        passwd_lineEdit = new QLineEdit(verticalLayoutWidget);
        passwd_lineEdit->setObjectName(QString::fromUtf8("passwd_lineEdit"));

        horizontalLayout_4->addWidget(passwd_lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(6, 6, 6, 6);
        confirm_btn = new QPushButton(verticalLayoutWidget);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));

        horizontalLayout_5->addWidget(confirm_btn);

        return_btn = new QPushButton(verticalLayoutWidget);
        return_btn->setObjectName(QString::fromUtf8("return_btn"));

        horizontalLayout_5->addWidget(return_btn);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(ResetDialog);

        QMetaObject::connectSlotsByName(ResetDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetDialog)
    {
        ResetDialog->setWindowTitle(QCoreApplication::translate("ResetDialog", "Dialog", nullptr));
        label_error->setText(QCoreApplication::translate("ResetDialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("ResetDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("ResetDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ResetDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        verify_btn->setText(QCoreApplication::translate("ResetDialog", "\350\216\267\345\217\226", nullptr));
        label_5->setText(QCoreApplication::translate("ResetDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        confirm_btn->setText(QCoreApplication::translate("ResetDialog", "\347\241\256\350\256\244", nullptr));
        return_btn->setText(QCoreApplication::translate("ResetDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
