#ifndef EVENT_H
#define EVENT_H

#include "QDate"

class Event
{
public:
    int eventType;

    QDate eventDate;

    QString otherText = "NULL";

    Event(int eventType, QDate eventDate)
    {
        this->eventType = eventType;
        this->eventDate = eventDate;
        this->otherText = "NULL";
    }

    Event(QString otherText, QDate eventDate)
    {
        this->eventType = 8;
        this->eventDate = eventDate;
        this->otherText = otherText;
    }

    int getEventType();

    QString getEventTypeName();

    QDate getEventDate();

    QString getOtherText();

    QString getEventString();
};

#endif // EVENT_H
