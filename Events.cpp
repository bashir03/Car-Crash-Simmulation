#include <iostream>
#include "Events.h"

EVENTS::EVENTS()
{

    typeOfEvent = "";
    carName = "";
    carSpeed = 0;
    horsePower = 0;
    horizontalLocation = 0;
    verticalLocation = 0;
}

void EVENTS::setEvent(string event1)
{

    typeOfEvent = event1;
}

void EVENTS::setCarName(string carName1)
{

    carName = carName1;
}

void EVENTS::setCarSpeed(int speed1)
{

    carSpeed = speed1;
}

void EVENTS::setHorsePower(int horsePower1)
{

    horsePower = horsePower1;
}

void EVENTS::setHorizontalLocation(int horizontal1)
{

    horizontalLocation = horizontal1;
}

void EVENTS::setVerticalLocation(int vertical1)
{

    verticalLocation = vertical1;
}

string EVENTS::getEvent()
{

    return typeOfEvent;
}

string EVENTS::getCarName()
{

    return carName;
}

int EVENTS::getCarSpeed()
{

    return carSpeed;
}

int EVENTS::getHorsePower()
{

    return horsePower;
}

int EVENTS::getHorizontalLocation()
{

    return horizontalLocation;
}

int EVENTS::getVerticalLocation()
{

    return verticalLocation;
}

bool EVENTS::chanceOfWinning(string event1, CarType CarTypeMane, int speed1, int horsePower1)
{

    if (event1 == "speedingTickets")
    {

        if (CarTypeMane.getCarTopSpeed() > speed1)
        {

            return true;
        }

        else
        {

            return false;
        }
    }

    else if (event1 == "carAccident")
    {

        if (CarTypeMane.getHorsePower() > horsePower1)
        {
            return true;
        }

        else
        {

            return false;
        }
    }

    else if (event1 == "lightPassed")
    {

        return false;
        
    }

    else
    {

        return false;

    }
}