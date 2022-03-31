#include <iostream>
#ifndef StopLightStat_H
#define StopLightStat_H

using namespace std;

class StopLightStat{

    private:

    int gameWons;
    int lightsPassed;
    int gameLost;
    int speedingTickets;
    int carAccidents;

    public:

    StopLightStat();
    StopLightStat(int gameWons1, int lightsPassed1, int gameLost1, 
    int speedingTickets1, int carAccidents1);

    int getGameWons();
    int getLightsPassed();
    int getGameLost();
    int getSpeedingTickets();
    int getCarAccidents();

    void setGameWons(int gameWons1);
    void setLightsPassed(int lightsPassed1);
    void setGameLost(int gameLost1);
    void setSpeedingTickets( int speedingTickets1);
    void setCarAccidents(int carAccidents1);

};

#endif