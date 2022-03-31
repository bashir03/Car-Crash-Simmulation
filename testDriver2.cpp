#include <iostream>
#include "User.h"
#include "StopLightStat.h"
#include "Character.h"
#include "CarType.h"

using namespace std;

int main(){

    User testUser;

    testUser.setUserName("bob");
    testUser.getUserName();

    testUser.setTotalMoney(1100);
    testUser.getTotalMoney();

    testUser.setScore(0);
    testUser.getScore();

    testUser.setTime(180.00);
    testUser.getTime();

    testUser.getReadyScore();

    StopLightStat testStat;

    testStat.setGameWons(100);
    testStat.getGameWons();

    testStat.setLightsPassed(100);
    testStat.getLightsPassed();

    testStat.setGameLost(100);
    testStat.getGameLost();

    testStat.setSpeedingTickets(100);
    testStat.getSpeedingTickets();

    testStat.setCarAccidents(100);
    testStat.getCarAccidents();

    Character testCharacter;

    testCharacter.setHairColor("black");
    testCharacter.getHairColor();

    testCharacter.setHeight("100");
    testCharacter.getHeight();

    testCharacter.setGender("Women");
    testCharacter.getGender();

    CarType testCartype;

    testCartype.setCarName("truck");
    testCartype.getCarName();

    testCartype.setCarColor("black");
    testCartype.getCarColor();

    testCartype.getHorsePower();
    testCartype.getCarTopSpeed();


}