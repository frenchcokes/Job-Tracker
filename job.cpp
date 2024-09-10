#include "job.h"
#include "QJsonObject"
#include "QJsonArray"

void Job::addEvent(int eventType, QDate eventDate)
{
    Event newEvent = Event(eventType, eventDate);
    events.append(newEvent);
}

void Job::addEvent(QString otherText, QDate eventDate)
{
    Event newEvent = Event(otherText, eventDate);
    events.append(newEvent);
}

void Job::replaceEventAtIndex(int index, Event newEvent)
{
    events[index] = newEvent;
}

QString Job::getEventsString()
{
    QString output = "";
    for (int i = 0; i < events.size(); i++)
    {
        output = output + "[" + QString::number(i) +  "] " + events[i].getEventString() + "\n";
    }
    return output;
}

QList<Event> Job::getEvents()
{
    return events;
}

void Job::setEvents(QList<Event> events)
{
    this->events = events;
}

void Job::debugPrintEvents()
{
    qDebug() << getCompanyName();
    for(int i = 0; i < events.size(); i++)
    {
        qDebug() << events[i].getEventString();
    }
}

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

QString Job::getDateAppliedString()
{
    QString op = dateApplied.toString();
    if(op == "")
    {
        return "N/A";
    }
    else
    {
        return op;
    }
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

QString Job::getDatePostedString()
{
    QString op = datePosted.toString();
    if(op == "")
    {
        return "N/A";
    }
    else
    {
        return op;
    }
}

bool Job::isEmptyDate()
{
    if(Job::getDatePostedString() == "N/A")
    {
        return true;
    }
    else
    {
        return false;
    }
}

QString Job::getNotes()
{
    return notes;
}

QJsonObject Job::getSaveData()
{
    QJsonObject json;
    json["jobTitle"] = jobTitle;
    json["companyName"] = companyName;
    json["dateApplied"] = dateApplied.toString();
    json["wasCoverLetter"] = wasCoverLetter;
    json["wasLogin"] = wasLogin;
    json["wasTranscript"] = wasTranscript;
    json["datePosted"] = datePosted.toString();
    json["notes"] = notes;

    QJsonArray eventsSave;
    for (int i = 0; i < events.size(); i++)
    {
        eventsSave.append(events[i].getSaveData());
    }
    json["events"] = eventsSave;

    return json;
}

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

    QJsonArray eventsData = data.value("events").toArray();
    for (int i = 0; i < eventsData.size(); i ++)
    {
        Event newEvent = Event();
        newEvent.loadSaveData(eventsData[i].toObject());
        events.append(newEvent);
    }
}
