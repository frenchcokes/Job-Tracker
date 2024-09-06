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

    startup();
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

        MainWindow::saveJobs(jobs);

        MainWindow::displayJobs(jobs);
    }
}

void MainWindow::on_datePostedCheckBox_toggled(bool checked)
{
    isDatePostedEnabled = checked;
    ui->datePostedDateEdit->setVisible(isDatePostedEnabled);
    ui->datePostedLabel->setVisible(isDatePostedEnabled);
}



void MainWindow::on_jobLoadPushButton_clicked()
{
    int index = ui->jobLoadSpinBox->value();
    if(index <= (jobs.count() - 1))
    {
        ui->stackedWidget->setCurrentIndex(1);
        Job loadJob = jobs[index];

        ui->JobTitleViewLabel->setText(loadJob.getJobTitle());
        ui->companyNameViewLabel->setText(loadJob.getCompanyName());
        ui->dateOfApplicationViewLabel->setText(loadJob.getDateApplied().toString());
        ui->otherViewLabel->setText("Cover Letter: " + loadJob.getWasCoverLetter() + " Transcript: " + loadJob.getWasTranscript() + " Date Posted: " + loadJob.getDatePosted().toString() + " Login: " + loadJob.getWasLogin());
        ui->notesViewLabel->setText(loadJob.getNotes());
    }
}


void MainWindow::on_addJobPushButton_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}

//HELPERS
void MainWindow::saveJobs(QList<Job> jobList)
{
    QJsonArray jobData;
    for (int i = 0; i < jobList.count(); i++)
    {
        jobData.append(jobList[i].getSaveData());
    }
    QSettings registry("HKEY_LOCAL_MACHINE");
    registry.setValue("jobData", QVariant(jobData));
}

QList<Job> MainWindow::loadJobs()
{
    QSettings registry("HKEY_LOCAL_MACHINE");
    QList<Job> outputData;
    if(registry.contains("jobData") == true)
    {
        QJsonArray jobData = registry.value("jobData").toJsonArray();
        for (int i = 0; i < jobData.size(); i++)
        {
            Job newJob = Job();
            newJob.loadSaveData(jobData[i].toObject());
            outputData.append(newJob);
        }
    }
    return outputData;
}

void MainWindow::startup()
{
    jobs = MainWindow::loadJobs();
    MainWindow::displayJobs(jobs);

    ui->dateAppliedDateEdit->setDate(QDateTime::currentDateTime().date());
    ui->datePostedDateEdit->setDate(QDateTime::currentDateTime().date());
    on_datePostedCheckBox_toggled(false);
}

void MainWindow::displayJobs(QList<Job> jobList)
{
    QString jobDisplayText = "";
    for (int i = 0; i < jobList.count(); i++)
    {
        jobDisplayText = jobDisplayText + "[" + QString::number(i) + "] " + jobList[i].getJobTitle() + ", " + jobList[i].getCompanyName() + ", (" + jobList[i].getDateApplied().toString() + ")\n";
    }
    ui->jobDisplayPlainTextEdit->setPlainText(jobDisplayText);
}

