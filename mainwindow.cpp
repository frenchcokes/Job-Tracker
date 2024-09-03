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

    QString wasCoverLetter = ui->coverLetterComboBox->currentText();

    QString wasLogin = ui->loginComboBox->currentText();

    QString wasTranscript = ui->transcriptComboBox->currentText();

    QDate datePosted = ui->datePostedDateEdit->date();

    if(jobTitle != "" && companyName != "") {
        QString dataOutput = "Title: " + jobTitle + ", Company Name: " + companyName
             + ", dateApplied: " + dateApplied.toString() + ", isCoverLetter: " + wasCoverLetter
                 + ", isLogin: " + wasLogin + ", isTranscript: " + wasTranscript
                     + ", datePosted: " + datePosted.toString();

        qDebug() << dataOutput;
    }
}
