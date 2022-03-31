#include <iostream> 
#include "StopLightStat.h"

using namespace std;

StopLightStat::StopLightStat(){

    gameWons = 0;
    lightsPassed = 0;
    gameLost = 0;
    speedingTickets = 0;
    carAccidents = 0;

}

StopLightStat::StopLightStat(int gameWons1, int lightsPassed1, int gameLost1, int speedingTickets1, int carAccidents1){

    gameWons = gameWons1;
    lightsPassed = lightsPassed1;
    gameLost = gameLost1;
    speedingTickets = speedingTickets1;
    carAccidents = carAccidents1;

}

int StopLightStat::getGameWons(){

    return gameWons;

}

int StopLightStat::getLightsPassed(){

    return lightsPassed;

}

int StopLightStat::getGameLost(){

    return gameLost;

}

int StopLightStat::getSpeedingTickets(){

    return speedingTickets;

}

int StopLightStat::getCarAccidents(){

      return carAccidents;

}

void StopLightStat::setGameWons(int gameWons1){

    gameWons = gameWons1;

}

void StopLightStat::setLightsPassed(int lightsPassed1){

    lightsPassed = lightsPassed1;

}

void StopLightStat::setGameLost(int gameLost1){

     gameLost = gameLost1;

}

void StopLightStat::setSpeedingTickets( int speedingTickets1){

    speedingTickets = speedingTickets1;

}

void StopLightStat::setCarAccidents(int carAccidents1){

    carAccidents = carAccidents1;

}



