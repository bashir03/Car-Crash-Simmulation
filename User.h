#include <iostream>
#include "StopLightStat.h"
#include "CarType.h"
#include "Character.h"
// #ifndef User_H
// #define User_H

using namespace std;

class User
{

private:
    string userName;
    int totalMoney;
    int score;
    double timeElapsed;
    int driverReadyScore;

    StopLightStat stopLightUserStat;
    CarType userCarStat;
    Character userCharacter;

public:
    User(); // default contructor
    User(string newUser, int totalMoney_input, int newScore, double newTime);

    string getUserName();
    int getTotalMoney();
    int getScore();
    double getTime();
    int getReadyScore();
    void getUserstat();
    void getCarInfo();
    void getCharacterInfo();

    void setUserName(string newUser);
    void setTotalMoney(int totalMoney_input);
    void setScore(int newScore);
    void setTime(double newTime);
    void setUserStat(StopLightStat StopLightInfo);
    void setCarInfo(CarType carInfo);
    void setCharacterInfo(Character characterInfo);
    void setReadyScore(int newScore, int totalMoney_input, double newTime);
};

// #endif