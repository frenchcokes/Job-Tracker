#include "job.h"

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
