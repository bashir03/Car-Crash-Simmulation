#include <iostream>
#include "User.h"

using namespace std;

User::User(){
    userName = "";
    totalMoney = 1000;
    score = 1000;
    timeElapsed = 0.00;
    driverReadyScore = 0;
}

User::User(string newUser,int totalMoney_input, int newScore, double newTime){

    userName = newUser;
    totalMoney = totalMoney_input;
    score = newScore;
    timeElapsed = newTime;

}

string User::getUserName(){

    return userName;

}

int User::getTotalMoney(){

    return totalMoney;

}

int User::getScore(){

    return score;

}

double User::getTime(){

    return timeElapsed;

}

int User::getReadyScore(){

    return driverReadyScore;

}

void User::getUserstat(){

    cout << "Mini Games Won: " << stopLightUserStat.getGameWons() << endl;
    cout << "Lights passed: " << stopLightUserStat.getLightsPassed() << endl;
    cout << "Mini Games Lost: " << stopLightUserStat.getGameLost() << endl;
    cout << "Speeding Tickets: " << stopLightUserStat.getSpeedingTickets() << endl;
    cout << "Car Accidents: " << stopLightUserStat.getCarAccidents() << endl;

}

void User::getCarInfo(){

    cout << "Car Name: " << userCarStat.getCarName() << endl;
    cout << "Car Color: " << userCarStat.getCarColor() << endl;
    cout << "Horse Power: " << userCarStat.getHorsePower() << endl;
    cout << "Car's Top Speed: " << userCarStat.getCarTopSpeed() << endl;

}

void User::getCharacterInfo(){

    cout << "User's Hair Color: " << userCharacter.getHairColor() << endl;
    cout << "User's Height: " << userCharacter.getHeight() << endl;
    cout << "User's Gender: " << userCharacter.getGender() << endl;

}

void User::setUserName(string newUser){

    userName = newUser;

}

void User::setTotalMoney(int totalMoney_input){

    totalMoney = totalMoney_input;

}

void User::setScore(int newScore){

    score = newScore;

}

void User::setTime(double newTime){

    timeElapsed = newTime;

}

void User::setUserStat(StopLightStat StopLightInfo){

    stopLightUserStat.setGameWons(StopLightInfo.getGameWons());
    stopLightUserStat.setLightsPassed(StopLightInfo.getLightsPassed());
    stopLightUserStat.setGameLost(StopLightInfo.getGameLost());
    stopLightUserStat.setSpeedingTickets(StopLightInfo.getSpeedingTickets());
    stopLightUserStat.setCarAccidents(StopLightInfo.getCarAccidents());

}

void User::setCarInfo(CarType carInfo){

    userCarStat.setCarName(carInfo.getCarName());
    userCarStat.setCarColor(carInfo.getCarColor());
    userCarStat.setCarStat(carInfo.getCarName());

}

void User::setCharacterInfo(Character characterInfo){

    userCharacter.setHairColor(characterInfo.getHairColor());
    userCharacter.setHeight(characterInfo.getHeight());
    userCharacter.setGender(characterInfo.getGender());

}

void User::setReadyScore(int newScore, int totalMoney_input, double newTime){

    int newTotalMoney = 0;

    if(newScore > 0 && newTime < 60.00){

        cout << "A driver ready score cannot be determined because you quit the game to early or you paused the game" << endl;
        driverReadyScore = 0;

    }

    else if (newScore <= 0 && newTime >= 0.00 && newTime <= 180.00){

        cout <<"You are good at driving and you are set to drive" << endl;
        newTotalMoney = totalMoney_input - 1000;

        if (newTotalMoney == 0){
            driverReadyScore = 70;
        }
        else if (newTotalMoney > 0 && newTotalMoney <= 20){
            driverReadyScore = 75;
        }
        else if (newTotalMoney > 20 && newTotalMoney <= 40){
            driverReadyScore = 85;
        }
        else if (newTotalMoney > 40 && newTotalMoney <= 60){
            driverReadyScore = 90;
        }
         else if (newTotalMoney > 60 && newTotalMoney <= 80){
            driverReadyScore = 95;
        }
        else if (newTotalMoney >= 80){
            driverReadyScore = 100;
        }

    }

    else if (newTime > 180.00)
    {
        cout <<"You are extreamly good at driving" << endl;
        driverReadyScore = 100;
    }
    
}





