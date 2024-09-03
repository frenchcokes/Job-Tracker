#ifndef JOB_H
#define JOB_H

#include <QMainWindow>
#include <QDate>

class Job
{
public:
    QString jobTitle;
    QString companyName;

    QDate dateApplied;

    QString wasCoverLetter;
    QString wasLogin;
    QString wasTranscript;

    QDate datePosted;

    Job(QString jobTitle, QString companyName, QDate dateApplied, QString wasCoverLetter, QString wasLogin, QString wasTranscript, QDate datePosted) {
        this->jobTitle = jobTitle;
        this->companyName = companyName;

        this->dateApplied = dateApplied;

        this->wasCoverLetter = wasCoverLetter;
        this->wasLogin = wasLogin;
        this->wasTranscript = wasTranscript;

        this->datePosted = datePosted;
    }

    operator QString() const
    {
        return "Title: " + jobTitle + ", Company Name: " + companyName
                        + ", dateApplied: " + dateApplied.toString() + ", isCoverLetter: " + wasCoverLetter
                        + ", isLogin: " + wasLogin + ", isTranscript: " + wasTranscript
                        + ", datePosted: " + datePosted.toString();
    }

    QString getJobTitle();
    QString getCompanyName();

    QDate getDateApplied();

    QString getWasCoverLetter();
    QString getWasLogin();
    QString getWasTranscript();

    QDate getDatePosted();
};

#endif // JOB_H
