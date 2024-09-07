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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *jobDisplayPlainTextEdit;
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *add_Job;
    QHBoxLayout *row_1;
    QLabel *jobTitleLabel;
    QLineEdit *jobTitleLineEdit;
    QHBoxLayout *row_2;
    QLabel *companyNameLabel;
    QLineEdit *companyNameLineEdit;
    QHBoxLayout *row_3;
    QLabel *dateAppliedLabel;
    QDateEdit *dateAppliedDateEdit;
    QHBoxLayout *row_4;
    QLabel *coverLetterLabel;
    QComboBox *coverLetterComboBox;
    QHBoxLayout *row_5;
    QLabel *transcriptLabel;
    QComboBox *transcriptComboBox;
    QHBoxLayout *row_6;
    QLabel *loginLabel;
    QComboBox *loginComboBox;
    QHBoxLayout *row_7;
    QSpacerItem *horizontalSpacer;
    QCheckBox *datePosedCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *row_8;
    QLabel *datePostedLabel;
    QDateEdit *datePostedDateEdit;
    QHBoxLayout *row_9;
    QLabel *notesLabel;
    QLineEdit *notesEdit;
    QLabel *addJobLabel;
    QPushButton *submitButton;
    QWidget *page_1;
    QLabel *JobTitleViewLabel;
    QLabel *companyNameViewLabel;
    QLabel *dateOfApplicationViewLabel;
    QLabel *otherViewLabel;
    QLabel *notesViewLabel;
    QPlainTextEdit *JobEventsViewPlainTextEdit;
    QPushButton *addEventViewPushButton;
    QPushButton *editJobDetailsPushButton;
    QPushButton *deleteJobPushButton;
    QSpinBox *jobLoadSpinBox;
    QPushButton *jobLoadPushButton;
    QPushButton *addJobPushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(720, 540);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        jobDisplayPlainTextEdit = new QPlainTextEdit(centralwidget);
        jobDisplayPlainTextEdit->setObjectName("jobDisplayPlainTextEdit");
        jobDisplayPlainTextEdit->setGeometry(QRect(10, 40, 251, 441));
        jobDisplayPlainTextEdit->setReadOnly(true);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(270, 10, 441, 511));
        page_0 = new QWidget();
        page_0->setObjectName("page_0");
        verticalLayoutWidget = new QWidget(page_0);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 40, 441, 431));
        add_Job = new QVBoxLayout(verticalLayoutWidget);
        add_Job->setObjectName("add_Job");
        add_Job->setContentsMargins(0, 0, 0, 0);
        row_1 = new QHBoxLayout();
        row_1->setObjectName("row_1");
        jobTitleLabel = new QLabel(verticalLayoutWidget);
        jobTitleLabel->setObjectName("jobTitleLabel");

        row_1->addWidget(jobTitleLabel);

        jobTitleLineEdit = new QLineEdit(verticalLayoutWidget);
        jobTitleLineEdit->setObjectName("jobTitleLineEdit");

        row_1->addWidget(jobTitleLineEdit);


        add_Job->addLayout(row_1);

        row_2 = new QHBoxLayout();
        row_2->setObjectName("row_2");
        companyNameLabel = new QLabel(verticalLayoutWidget);
        companyNameLabel->setObjectName("companyNameLabel");

        row_2->addWidget(companyNameLabel);

        companyNameLineEdit = new QLineEdit(verticalLayoutWidget);
        companyNameLineEdit->setObjectName("companyNameLineEdit");

        row_2->addWidget(companyNameLineEdit);


        add_Job->addLayout(row_2);

        row_3 = new QHBoxLayout();
        row_3->setObjectName("row_3");
        dateAppliedLabel = new QLabel(verticalLayoutWidget);
        dateAppliedLabel->setObjectName("dateAppliedLabel");

        row_3->addWidget(dateAppliedLabel);

        dateAppliedDateEdit = new QDateEdit(verticalLayoutWidget);
        dateAppliedDateEdit->setObjectName("dateAppliedDateEdit");

        row_3->addWidget(dateAppliedDateEdit);


        add_Job->addLayout(row_3);

        row_4 = new QHBoxLayout();
        row_4->setObjectName("row_4");
        coverLetterLabel = new QLabel(verticalLayoutWidget);
        coverLetterLabel->setObjectName("coverLetterLabel");

        row_4->addWidget(coverLetterLabel);

        coverLetterComboBox = new QComboBox(verticalLayoutWidget);
        coverLetterComboBox->addItem(QString());
        coverLetterComboBox->addItem(QString());
        coverLetterComboBox->addItem(QString());
        coverLetterComboBox->setObjectName("coverLetterComboBox");

        row_4->addWidget(coverLetterComboBox);


        add_Job->addLayout(row_4);

        row_5 = new QHBoxLayout();
        row_5->setObjectName("row_5");
        transcriptLabel = new QLabel(verticalLayoutWidget);
        transcriptLabel->setObjectName("transcriptLabel");

        row_5->addWidget(transcriptLabel);

        transcriptComboBox = new QComboBox(verticalLayoutWidget);
        transcriptComboBox->addItem(QString());
        transcriptComboBox->addItem(QString());
        transcriptComboBox->addItem(QString());
        transcriptComboBox->setObjectName("transcriptComboBox");

        row_5->addWidget(transcriptComboBox);


        add_Job->addLayout(row_5);

        row_6 = new QHBoxLayout();
        row_6->setObjectName("row_6");
        loginLabel = new QLabel(verticalLayoutWidget);
        loginLabel->setObjectName("loginLabel");

        row_6->addWidget(loginLabel);

        loginComboBox = new QComboBox(verticalLayoutWidget);
        loginComboBox->addItem(QString());
        loginComboBox->addItem(QString());
        loginComboBox->addItem(QString());
        loginComboBox->setObjectName("loginComboBox");

        row_6->addWidget(loginComboBox);


        add_Job->addLayout(row_6);

        row_7 = new QHBoxLayout();
        row_7->setObjectName("row_7");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        row_7->addItem(horizontalSpacer);

        datePosedCheckBox = new QCheckBox(verticalLayoutWidget);
        datePosedCheckBox->setObjectName("datePosedCheckBox");
        datePosedCheckBox->setTristate(false);

        row_7->addWidget(datePosedCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        row_7->addItem(horizontalSpacer_2);

        row_7->setStretch(0, 4);
        row_7->setStretch(1, 1);
        row_7->setStretch(2, 4);

        add_Job->addLayout(row_7);

        row_8 = new QHBoxLayout();
        row_8->setObjectName("row_8");
        datePostedLabel = new QLabel(verticalLayoutWidget);
        datePostedLabel->setObjectName("datePostedLabel");
        datePostedLabel->setEnabled(true);

        row_8->addWidget(datePostedLabel);

        datePostedDateEdit = new QDateEdit(verticalLayoutWidget);
        datePostedDateEdit->setObjectName("datePostedDateEdit");
        datePostedDateEdit->setEnabled(true);

        row_8->addWidget(datePostedDateEdit);


        add_Job->addLayout(row_8);

        row_9 = new QHBoxLayout();
        row_9->setObjectName("row_9");
        notesLabel = new QLabel(verticalLayoutWidget);
        notesLabel->setObjectName("notesLabel");

        row_9->addWidget(notesLabel);

        notesEdit = new QLineEdit(verticalLayoutWidget);
        notesEdit->setObjectName("notesEdit");

        row_9->addWidget(notesEdit);


        add_Job->addLayout(row_9);

        addJobLabel = new QLabel(page_0);
        addJobLabel->setObjectName("addJobLabel");
        addJobLabel->setGeometry(QRect(0, 1, 439, 41));
        QFont font;
        font.setPointSize(20);
        addJobLabel->setFont(font);
        addJobLabel->setTextFormat(Qt::TextFormat::MarkdownText);
        addJobLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        submitButton = new QPushButton(page_0);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(0, 480, 439, 24));
        stackedWidget->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        JobTitleViewLabel = new QLabel(page_1);
        JobTitleViewLabel->setObjectName("JobTitleViewLabel");
        JobTitleViewLabel->setGeometry(QRect(0, 0, 441, 41));
        QFont font1;
        font1.setPointSize(18);
        JobTitleViewLabel->setFont(font1);
        JobTitleViewLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        companyNameViewLabel = new QLabel(page_1);
        companyNameViewLabel->setObjectName("companyNameViewLabel");
        companyNameViewLabel->setGeometry(QRect(0, 40, 441, 31));
        QFont font2;
        font2.setPointSize(17);
        companyNameViewLabel->setFont(font2);
        companyNameViewLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dateOfApplicationViewLabel = new QLabel(page_1);
        dateOfApplicationViewLabel->setObjectName("dateOfApplicationViewLabel");
        dateOfApplicationViewLabel->setGeometry(QRect(0, 70, 441, 31));
        QFont font3;
        font3.setPointSize(16);
        dateOfApplicationViewLabel->setFont(font3);
        dateOfApplicationViewLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        otherViewLabel = new QLabel(page_1);
        otherViewLabel->setObjectName("otherViewLabel");
        otherViewLabel->setGeometry(QRect(0, 100, 441, 31));
        QFont font4;
        font4.setPointSize(12);
        otherViewLabel->setFont(font4);
        otherViewLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        notesViewLabel = new QLabel(page_1);
        notesViewLabel->setObjectName("notesViewLabel");
        notesViewLabel->setGeometry(QRect(0, 130, 441, 31));
        notesViewLabel->setFont(font4);
        notesViewLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        JobEventsViewPlainTextEdit = new QPlainTextEdit(page_1);
        JobEventsViewPlainTextEdit->setObjectName("JobEventsViewPlainTextEdit");
        JobEventsViewPlainTextEdit->setGeometry(QRect(10, 160, 421, 311));
        JobEventsViewPlainTextEdit->setReadOnly(true);
        addEventViewPushButton = new QPushButton(page_1);
        addEventViewPushButton->setObjectName("addEventViewPushButton");
        addEventViewPushButton->setGeometry(QRect(280, 480, 151, 24));
        editJobDetailsPushButton = new QPushButton(page_1);
        editJobDetailsPushButton->setObjectName("editJobDetailsPushButton");
        editJobDetailsPushButton->setGeometry(QRect(120, 480, 151, 24));
        deleteJobPushButton = new QPushButton(page_1);
        deleteJobPushButton->setObjectName("deleteJobPushButton");
        deleteJobPushButton->setGeometry(QRect(10, 480, 101, 24));
        stackedWidget->addWidget(page_1);
        jobLoadSpinBox = new QSpinBox(centralwidget);
        jobLoadSpinBox->setObjectName("jobLoadSpinBox");
        jobLoadSpinBox->setGeometry(QRect(10, 490, 91, 22));
        jobLoadPushButton = new QPushButton(centralwidget);
        jobLoadPushButton->setObjectName("jobLoadPushButton");
        jobLoadPushButton->setGeometry(QRect(110, 490, 151, 24));
        addJobPushButton = new QPushButton(centralwidget);
        addJobPushButton->setObjectName("addJobPushButton");
        addJobPushButton->setGeometry(QRect(10, 10, 251, 24));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        coverLetterComboBox->setCurrentIndex(2);
        transcriptComboBox->setCurrentIndex(2);
        loginComboBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        jobDisplayPlainTextEdit->setPlainText(QString());
        jobTitleLabel->setText(QCoreApplication::translate("MainWindow", "Job Title", nullptr));
        companyNameLabel->setText(QCoreApplication::translate("MainWindow", "Company", nullptr));
        dateAppliedLabel->setText(QCoreApplication::translate("MainWindow", "Date Applied", nullptr));
        coverLetterLabel->setText(QCoreApplication::translate("MainWindow", "Cover Letter?", nullptr));
        coverLetterComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Yes", nullptr));
        coverLetterComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "No", nullptr));
        coverLetterComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "N/A", nullptr));

        transcriptLabel->setText(QCoreApplication::translate("MainWindow", "Transcript?", nullptr));
        transcriptComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Yes", nullptr));
        transcriptComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "No", nullptr));
        transcriptComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "N/A", nullptr));

        loginLabel->setText(QCoreApplication::translate("MainWindow", "Login?", nullptr));
        loginComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Yes", nullptr));
        loginComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "No", nullptr));
        loginComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "N/A", nullptr));

        datePosedCheckBox->setText(QCoreApplication::translate("MainWindow", "Include Date Posted?", nullptr));
        datePostedLabel->setText(QCoreApplication::translate("MainWindow", "Date Posted", nullptr));
        notesLabel->setText(QCoreApplication::translate("MainWindow", "Notes", nullptr));
        addJobLabel->setText(QCoreApplication::translate("MainWindow", "Add Job", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "Add Job", nullptr));
        JobTitleViewLabel->setText(QCoreApplication::translate("MainWindow", "Software Engineer Coop Summer", nullptr));
        companyNameViewLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        dateOfApplicationViewLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        otherViewLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        notesViewLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        addEventViewPushButton->setText(QCoreApplication::translate("MainWindow", "Add Event", nullptr));
        editJobDetailsPushButton->setText(QCoreApplication::translate("MainWindow", "Edit Job Details", nullptr));
        deleteJobPushButton->setText(QCoreApplication::translate("MainWindow", "Delete Job", nullptr));
        jobLoadPushButton->setText(QCoreApplication::translate("MainWindow", "Load Job", nullptr));
        addJobPushButton->setText(QCoreApplication::translate("MainWindow", "Add Job", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
