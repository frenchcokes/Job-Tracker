#include "event.h"

int Event::getEventType()
{
    return eventType;
}

QString Event::getEventTypeName()
{
    switch(eventType)
    {
        case 0:
            return "Application Declined";
            break;
        case 1:
            return "Offer Received";
            break;
        case 2:
            return "Offer Accepted";
            break;
        case 3:
            return "Offer Rejected";
            break;
        case 4:
            return "Ask Interview";
            break;
        case 5:
            return "Did Interview";
            break;
        case 6:
            return "Ask Assessment";
            break;
        case 7:
            return "Did Assessment";
            break;
        case 8:
            return "Other";
            break;
    }
    return "INVALID EVENT";
}

QDate Event::getEventDate()
{
    return eventDate;
}

QString Event::getOtherText()
{
    return otherText;
}

QString Event::getEventString()
{
    if(eventType != 8)
    {
        return Event::getEventTypeName() + "-" + getEventDate().toString();
    }
    else
    {
        return Event::getEventTypeName() + "-" + getEventDate().toString() + "-" + getOtherText();
    }
}
