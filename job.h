#ifndef JOB_H
#define JOB_H

#include <QMainWindow>
#include <QDate>
#include <QJsonObject>

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

    QString notes;

    Job(QString jobTitle, QString companyName, QDate dateApplied, QString wasCoverLetter, QString wasLogin, QString wasTranscript, QDate datePosted, QString notes) {
        this->jobTitle = jobTitle;
        this->companyName = companyName;

        this->dateApplied = dateApplied;

        this->wasCoverLetter = wasCoverLetter;
        this->wasLogin = wasLogin;
        this->wasTranscript = wasTranscript;

        this->datePosted = datePosted;
        this->notes = notes;
    }

    ~Job() {}

    Job() {}

    operator QString() const
    {
        return "Title: " + jobTitle + ", Company Name: " + companyName
                        + ", dateApplied: " + dateApplied.toString() + ", isCoverLetter: " + wasCoverLetter
                        + ", isLogin: " + wasLogin + ", isTranscript: " + wasTranscript
                        + ", datePosted: " + datePosted.toString()
                        + ", notes: " + notes;
    }

    QString getJobTitle();
    QString getCompanyName();

    QDate getDateApplied();
    QString getDateAppliedString();

    QString getWasCoverLetter();
    QString getWasLogin();
    QString getWasTranscript();

    QDate getDatePosted();
    QString getDatePostedString();

    QString getNotes();

    QJsonObject getSaveData();
    void loadSaveData(QJsonObject);
};

#endif // JOB_H
