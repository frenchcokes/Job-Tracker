#include "mainwindow.h"
#include "job.h"

#include "./ui_mainwindow.h"
#include "QDebug"
#include "QList"
#include "QSettings"
#include "QJsonArray"

bool isDatePostedEnabled = false;
QList<Job> jobs;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //JOB ADD SETUP

    QSettings registry("HKEY_LOCAL_MACHINE");
    if(registry.contains("jobData") == true)
    {
        QJsonArray jobData = registry.value("jobData").toJsonArray();
        for (int i = 0; i < jobData.size(); i++)
        {
            Job newJob = Job();
            newJob.loadSaveData(jobData[i].toObject());
            jobs.append(newJob);

            QString jobDisplayText = "";
            for (int i = 0; i < jobs.count(); i++)
            {
                jobDisplayText = jobDisplayText + "[" + QString::number(i) + "] " + jobs[i].getJobTitle() + ", " + jobs[i].getCompanyName() + ", (" + jobs[i].getDateApplied().toString() + ")\n";
            }
            ui->jobDisplayPlainTextEdit->setPlainText(jobDisplayText);
        }

    }

    ui->dateAppliedDateEdit->setDate(QDateTime::currentDateTime().date());
    ui->datePostedDateEdit->setDate(QDateTime::currentDateTime().date());
    on_datePosedCheckBox_toggled(false);
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

    QString notes = ui->notesEdit->text();

    if(jobTitle != "" && companyName != "")
    {
        if(isDatePostedEnabled == false)
        {
            datePosted = QDate();
        }

        Job newJob = Job(jobTitle, companyName, dateApplied, wasCoverLetter, wasLogin, wasTranscript, datePosted, notes);
        jobs.append(newJob);

        //SAVE
        QJsonArray jobData;
        for (int i = 0; i < jobs.count(); i++)
        {
            jobData.append(jobs[i].getSaveData());
        }
        QSettings registry("HKEY_LOCAL_MACHINE");
        registry.setValue("jobData", QVariant(jobData));

        //UPDATE JOBS DISPLAY
        QString jobDisplayText = "";
        for (int i = 0; i < jobs.count(); i++)
        {
            jobDisplayText = jobDisplayText + "[" + QString::number(i) + "] " + jobs[i].getJobTitle() + ", " + jobs[i].getCompanyName() + ", (" + jobs[i].getDateApplied().toString() + ")\n";
        }
        ui->jobDisplayPlainTextEdit->setPlainText(jobDisplayText);

        //QJsonArray loadedData = registry.value("jobData").toJsonArray();
        //qDebug() << loadedData;
    }
}

void MainWindow::on_datePosedCheckBox_toggled(bool checked)
{
    isDatePostedEnabled = checked;
    ui->datePostedDateEdit->setVisible(isDatePostedEnabled);
    ui->datePostedLabel->setVisible(isDatePostedEnabled);
}

