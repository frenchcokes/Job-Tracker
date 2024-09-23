#include "mainwindow.h"
#include "Job.h"

#include "./ui_mainwindow.h"
#include "QDebug"
#include "QList"
#include "QSettings"
#include "QJsonArray"

bool isDatePostedEnabled = false;
QList<Job> jobs;
int currentlyDisplayedJobIndex = -1;
int eventIndex = -1;

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

//JOB ADD
void MainWindow::on_datePostedCheckBox_toggled(bool checked)
{
    isDatePostedEnabled = checked;
    ui->datePostedDateEdit->setVisible(isDatePostedEnabled);
    ui->datePostedLabel->setVisible(isDatePostedEnabled);
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
        if(currentlyDisplayedJobIndex == -1)
        {
            jobs.append(newJob);
        }
        else
        {
            newJob.setEvents(jobs[currentlyDisplayedJobIndex].getEvents());
            jobs[currentlyDisplayedJobIndex] = newJob;
            viewJobAtIndex(currentlyDisplayedJobIndex);
        }
        MainWindow::saveJobs(jobs);

        ui->jobTitleLineEdit->setText("");
        ui->companyNameLineEdit->setText("");
        ui->dateAppliedDateEdit->setDate(QDateTime::currentDateTime().date());
        ui->coverLetterComboBox->setCurrentIndex(2);
        ui->loginComboBox->setCurrentIndex(2);
        ui->transcriptComboBox->setCurrentIndex(2);
        ui->datePostedDateEdit->setDate(QDateTime::currentDateTime().date());
        ui->notesEdit->setText("");
    }
}

//JOB VIEW
void MainWindow::on_jobLoadPushButton_clicked()
{
    int index = ui->jobLoadSpinBox->value();
    MainWindow::viewJobAtIndex(index);
}

void MainWindow::on_editJobDetailsPushButton_clicked()
{
    MainWindow::changeWindow(3);
}

void MainWindow::on_addEventViewPushButton_clicked()
{
    MainWindow::changeWindow(2);
}

void MainWindow::on_editEventPushButton_clicked()
{
    MainWindow::changeWindow(5);
}

//EVENT ADD
void MainWindow::on_addEventPushButton_clicked()
{
    int selectedIndex = -1;
    for(int i = 0; i < 9; i++)
    {
        QString widgetName = "event" + QString::number(i) + "RadioButton";
        QRadioButton* widget = MainWindow::findChild<QRadioButton *>(widgetName);
        if(widget->isChecked() == true)
        {
            selectedIndex = i;
            break;
        }
    }
    if(selectedIndex != -1)
    {
        if(eventIndex == -1)
        {
            if(selectedIndex != 8)
            {
                jobs[currentlyDisplayedJobIndex].addEvent(selectedIndex, ui->eventDateEdit->date());
            }
            else
            {
                jobs[currentlyDisplayedJobIndex].addEvent(ui->eventOtherTextEdit->toPlainText(), ui->eventDateEdit->date());
            }
        }
        else
        {
            Event newEvent;
            if(selectedIndex != 8)
            {
                newEvent = Event(selectedIndex, ui->eventDateEdit->date());
            }
            else
            {
                newEvent = Event(ui->eventOtherTextEdit->toPlainText(), ui->eventDateEdit->date());
            }
            jobs[currentlyDisplayedJobIndex].replaceEventAtIndex(eventIndex, newEvent);
        }

        MainWindow::saveJobs(jobs);
        ui->stackedWidget->setCurrentIndex(1);
        viewJobAtIndex(currentlyDisplayedJobIndex);
    }
}

void MainWindow::on_addEventBackPushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//ALWAYS VISIBLE BUTTONS
void MainWindow::on_addJobPushButton_clicked()
{
    MainWindow::changeWindow(0);
}

void MainWindow::on_deleteJobPushButton_clicked()
{
    MainWindow::deleteJob(currentlyDisplayedJobIndex);
}

void MainWindow::on_searchLineEdit_textChanged(const QString &arg1)
{
    QList<Job> jobsToDisplay;
    QString check = arg1.toLower();
    for(int i = 0; i < jobs.size(); i++)
    {
        if(jobs[i].getCompanyName().toLower().contains(check) == 1)
        {
            jobsToDisplay.append(jobs[i]);
        }
        else if(jobs[i].getJobTitle().toLower().contains(check) == 1)
        {
            jobsToDisplay.append(jobs[i]);
        }
        else if(jobs[i].getDateAppliedString().toLower().contains(check) == 1)
        {
            jobsToDisplay.append(jobs[i]);
        }
    }

    displayJobs(jobsToDisplay);
}

//HELPERS
bool MainWindow::viewJobAtIndex(int index)
{
    if(index <= (jobs.count() - 1))
    {
        ui->stackedWidget->setCurrentIndex(1);
        Job loadJob = jobs[index];
        currentlyDisplayedJobIndex = index;

        ui->JobTitleViewLabel->setText(loadJob.getJobTitle());
        ui->companyNameViewLabel->setText(loadJob.getCompanyName());
        ui->dateOfApplicationViewLabel->setText(loadJob.getDateApplied().toString());
        ui->otherViewLabel->setText("Cover Letter: " + loadJob.getWasCoverLetter() + " Transcript: " + loadJob.getWasTranscript() + " Date Posted: " + loadJob.getDatePostedString() + " Login: " + loadJob.getWasLogin());
        ui->notesViewLabel->setPlainText(loadJob.getNotes());

        ui->JobEventsViewPlainTextEdit->setPlainText(jobs[index].getEventsString());

        if(loadJob.getEvents().size() != 0)
        {
            ui->editEventSpinBox->setMaximum(loadJob.getEvents().size() - 1);
        }
        else
        {
            ui->editEventSpinBox->setMaximum(0);
        }

        return true;
    }
    return false;
}

void MainWindow::deleteJob(int index)
{
    jobs.removeAt(index);
    MainWindow::saveJobs(jobs);
    MainWindow::changeWindow(0);
}

void MainWindow::saveJobs(QList<Job> jobList)
{
    QJsonArray jobData;
    for (int i = 0; i < jobList.count(); i++)
    {
        jobData.append(jobList[i].getSaveData());
    }
    QSettings registry("HKEY_LOCAL_MACHINE");
    registry.setValue("jobData", QVariant(jobData));

    MainWindow::displayJobs(jobList);
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

    MainWindow::changeWindow(0);
}

void MainWindow::displayJobs(QList<Job> jobList)
{
    QString jobDisplayText = "";
    for (int i = 0; i < jobList.count(); i++)
    {
        jobDisplayText = jobDisplayText + "[" + QString::number(i) + "] " + jobList[i].getJobTitle() + ", " + jobList[i].getCompanyName() + ", [" + jobList[i].getDateAppliedString() + "] [" + jobList[i].getStatusString() + "]\n";
    }
    ui->jobDisplayPlainTextEdit->setPlainText(jobDisplayText);
    ui->jobLoadSpinBox->setMaximum(jobList.count() - 1);
}

void MainWindow::changeWindow(int type)
{
    switch(type)
    {
        case 0: //Add Job
            ui->stackedWidget->setCurrentIndex(0);

            ui->addJobLabel->setText("Add Job");

            ui->jobTitleLineEdit->setText("");
            ui->companyNameLineEdit->setText("");
            ui->dateAppliedDateEdit->setDate(QDateTime::currentDateTime().date());
            ui->coverLetterComboBox->setCurrentText("N/A");
            ui->transcriptComboBox->setCurrentText("N/A");
            ui->loginComboBox->setCurrentText("N/A");

            on_datePostedCheckBox_toggled(false);
            ui->datePostedDateEdit->setDate(QDateTime::currentDateTime().date());

            ui->notesEdit->setText("");
            currentlyDisplayedJobIndex = -1;
            break;
        case 2: //Add Event
            ui->addEventLabel->setText("Add Event");
            ui->stackedWidget->setCurrentIndex(2);
            ui->eventDateEdit->setDate(QDate::currentDate());

            for(int i = 0; i < 9; i++)
            {
                QString widgetName = "event" + QString::number(i) + "RadioButton";
                QRadioButton* widget = MainWindow::findChild<QRadioButton *>(widgetName);
                widget->setChecked(false);
            }
            ui->eventOtherTextEdit->setPlainText("");
            eventIndex = -1;
            break;
        case 5: //Edit Event
            if(ui->editEventSpinBox->value() <= (jobs[currentlyDisplayedJobIndex].getEvents().count() - 1))
            {
                eventIndex = ui->editEventSpinBox->value();
                ui->addEventLabel->setText("Edit Event");
                Event theEvent = jobs[currentlyDisplayedJobIndex].getEvents()[eventIndex];

                ui->stackedWidget->setCurrentIndex(2);
                ui->eventDateEdit->setDate(theEvent.getEventDate());

                QString widgetName = "event" + QString::number(theEvent.getEventType()) + "RadioButton";
                QRadioButton* widget = MainWindow::findChild<QRadioButton *>(widgetName);
                widget->setChecked(true);

                ui->notesEdit->setText(theEvent.getOtherText());
            }


            break;
        case 3: //Edit Job
            ui->stackedWidget->setCurrentIndex(0);
            Job editJob = jobs[currentlyDisplayedJobIndex];

            ui->addJobLabel->setText("Edit Job");

            ui->jobTitleLineEdit->setText(editJob.getJobTitle());
            ui->companyNameLineEdit->setText(editJob.getCompanyName());
            ui->dateAppliedDateEdit->setDate(editJob.getDateApplied());
            ui->coverLetterComboBox->setCurrentText(editJob.getWasCoverLetter());
            ui->transcriptComboBox->setCurrentText(editJob.getWasTranscript());
            ui->loginComboBox->setCurrentText(editJob.getWasLogin());

            if(editJob.isEmptyDate() == true)
            {
                on_datePostedCheckBox_toggled(false);
            }
            else
            {
                on_datePostedCheckBox_toggled(true);
            }
            ui->datePostedDateEdit->setDate(editJob.getDatePosted());

            ui->notesEdit->setText(editJob.getNotes());
            break;
    }
}

