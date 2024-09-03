#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submitButton_clicked()
{
    QString jobTitle = ui->jobTitleLineEdit->text();

    QString companyName = ui->companyNameLineEdit->text();

    QDate dateApplied = ui->dateAppliedDateEdit->date();

    bool isCoverLetter = ui->isCoverLetterCheckBox->isChecked();

    bool isLogin = ui->isLoginCheckBox->isChecked();

    bool isTranscript = ui->isTranscriptCheckBox->isChecked();

    QDate datePosted = ui->datePostedDateEdit->date();

    if(jobTitle != "" && companyName != "") {
        QString dataOutput = "Title: " + jobTitle + ", Company Name: " + companyName
             + ", dateApplied: " + dateApplied.toString() + ", isCoverLetter: " + QString::number(isCoverLetter)
                 + ", isLogin: " + QString::number(isLogin) + ", isTranscript: " + QString::number(isTranscript)
                     + ", datePosted: " + datePosted.toString();

        qDebug() << dataOutput;
    }
}
