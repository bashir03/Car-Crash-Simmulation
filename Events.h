#include <iostream>
#include "CarType.h"
#ifndef Events_H
#define Events_H

class EVENTS
{

    // private info of all the data
private:
    string typeOfEvent;
    string carName;
    int carSpeed;
    int horsePower;
    int horizontalLocation;
    int verticalLocation;

public:
    // defualt constructor
    EVENTS();

    // sets all the information
    void setEvent(string event1);
    void setCarName(string carName1);
    void setCarSpeed(int speed1);
    void setHorsePower(int horsePower1);
    void setHorizontalLocation(int horizontal1);
    void setVerticalLocation(int vertical1);

    // gets all the information
    string getEvent();
    string getCarName();
    int getCarSpeed();
    int getHorsePower();
    int getHorizontalLocation();
    int getVerticalLocation();

    // determines winning possibility against event
    bool chanceOfWinning(string event1, CarType CarTypeMane, int speed1, int horsePower1);
};

#endif