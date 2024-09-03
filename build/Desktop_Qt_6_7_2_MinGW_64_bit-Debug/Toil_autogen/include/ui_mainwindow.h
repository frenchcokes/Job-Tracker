/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *addJobLabel;
    QHBoxLayout *row1;
    QLabel *jobTitleLabel;
    QLineEdit *jobTitleLineEdit;
    QHBoxLayout *row2;
    QLabel *companyNameLabel;
    QLineEdit *companyNameLineEdit;
    QHBoxLayout *row3;
    QLabel *dateAppliedLabel;
    QDateEdit *dateAppliedDateEdit;
    QCheckBox *isCoverLetterCheckBox;
    QCheckBox *isTranscriptCheckBox;
    QCheckBox *isLoginCheckBox;
    QHBoxLayout *row4;
    QLabel *datePostedLabel;
    QDateEdit *datePostedDateEdit;
    QPushButton *submitButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(720, 540);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(200, 80, 311, 342));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addJobLabel = new QLabel(verticalLayoutWidget);
        addJobLabel->setObjectName("addJobLabel");
        addJobLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(addJobLabel);

        row1 = new QHBoxLayout();
        row1->setObjectName("row1");
        jobTitleLabel = new QLabel(verticalLayoutWidget);
        jobTitleLabel->setObjectName("jobTitleLabel");

        row1->addWidget(jobTitleLabel);

        jobTitleLineEdit = new QLineEdit(verticalLayoutWidget);
        jobTitleLineEdit->setObjectName("jobTitleLineEdit");

        row1->addWidget(jobTitleLineEdit);


        verticalLayout->addLayout(row1);

        row2 = new QHBoxLayout();
        row2->setObjectName("row2");
        companyNameLabel = new QLabel(verticalLayoutWidget);
        companyNameLabel->setObjectName("companyNameLabel");

        row2->addWidget(companyNameLabel);

        companyNameLineEdit = new QLineEdit(verticalLayoutWidget);
        companyNameLineEdit->setObjectName("companyNameLineEdit");

        row2->addWidget(companyNameLineEdit);


        verticalLayout->addLayout(row2);

        row3 = new QHBoxLayout();
        row3->setObjectName("row3");
        dateAppliedLabel = new QLabel(verticalLayoutWidget);
        dateAppliedLabel->setObjectName("dateAppliedLabel");

        row3->addWidget(dateAppliedLabel);

        dateAppliedDateEdit = new QDateEdit(verticalLayoutWidget);
        dateAppliedDateEdit->setObjectName("dateAppliedDateEdit");

        row3->addWidget(dateAppliedDateEdit);


        verticalLayout->addLayout(row3);

        isCoverLetterCheckBox = new QCheckBox(verticalLayoutWidget);
        isCoverLetterCheckBox->setObjectName("isCoverLetterCheckBox");

        verticalLayout->addWidget(isCoverLetterCheckBox);

        isTranscriptCheckBox = new QCheckBox(verticalLayoutWidget);
        isTranscriptCheckBox->setObjectName("isTranscriptCheckBox");

        verticalLayout->addWidget(isTranscriptCheckBox);

        isLoginCheckBox = new QCheckBox(verticalLayoutWidget);
        isLoginCheckBox->setObjectName("isLoginCheckBox");
        isLoginCheckBox->setChecked(false);
        isLoginCheckBox->setTristate(false);

        verticalLayout->addWidget(isLoginCheckBox);

        row4 = new QHBoxLayout();
        row4->setObjectName("row4");
        datePostedLabel = new QLabel(verticalLayoutWidget);
        datePostedLabel->setObjectName("datePostedLabel");

        row4->addWidget(datePostedLabel);

        datePostedDateEdit = new QDateEdit(verticalLayoutWidget);
        datePostedDateEdit->setObjectName("datePostedDateEdit");

        row4->addWidget(datePostedDateEdit);


        verticalLayout->addLayout(row4);

        submitButton = new QPushButton(verticalLayoutWidget);
        submitButton->setObjectName("submitButton");

        verticalLayout->addWidget(submitButton);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addJobLabel->setText(QCoreApplication::translate("MainWindow", "Add Job", nullptr));
        jobTitleLabel->setText(QCoreApplication::translate("MainWindow", "Job Title", nullptr));
        companyNameLabel->setText(QCoreApplication::translate("MainWindow", "Company", nullptr));
        dateAppliedLabel->setText(QCoreApplication::translate("MainWindow", "Date Applied", nullptr));
        isCoverLetterCheckBox->setText(QCoreApplication::translate("MainWindow", "Cover Letter?", nullptr));
        isTranscriptCheckBox->setText(QCoreApplication::translate("MainWindow", "Transcript?", nullptr));
        isLoginCheckBox->setText(QCoreApplication::translate("MainWindow", "Login?", nullptr));
        datePostedLabel->setText(QCoreApplication::translate("MainWindow", "Date Posted", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
