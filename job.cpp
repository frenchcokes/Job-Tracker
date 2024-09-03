#include "job.h"
#include "QJsonObject"

QString Job::getJobTitle()
{
    return jobTitle;
}

QString Job::getCompanyName()
{
    return companyName;
}

QDate Job::getDateApplied()
{
    return dateApplied;
}

QString Job::getWasCoverLetter()
{
    return wasCoverLetter;
}

QString Job::getWasLogin()
{
    return wasLogin;
}

QString Job::getWasTranscript()
{
    return wasTranscript;
}

QDate Job::getDatePosted()
{
    return datePosted;
}

QString Job::getNotes()
{
    return notes;
}

QJsonObject Job::getSaveData()
{
    QJsonObject saveData
    {
        {"jobTitle", jobTitle},
        {"companyName", companyName},
        {"dateApplied", dateApplied.toString()},
        {"wasCoverLetter", wasCoverLetter},
        {"wasLogin", wasLogin},
        {"wasTranscript", wasTranscript},
        {"datePosted", datePosted.toString()},
        {"notes", notes}
    };
    return saveData;
};

void Job::loadSaveData(QJsonObject data)
{
    jobTitle = data.value("jobTitle").toString();
    companyName = data.value("companyName").toString();
    dateApplied = QDate::fromString(data.value("dateApplied").toString());
    wasCoverLetter = data.value("wasCoverLetter").toString();
    wasLogin = data.value("wasLogin").toString();
    wasTranscript = data.value("wasTranscript").toString();
    datePosted = QDate::fromString(data.value("datePosted").toString());
    notes = data.value("notes").toString();
}
