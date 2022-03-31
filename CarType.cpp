#include <iostream>
#include "CarType.h"

using namespace std;

CarType::CarType(){

    carName = "";
    carColor = "";
    horsePower = 0;
    carTopSpeed = 0;

}

CarType::CarType(string carName_input, string carColor_input){

    carName = carName_input;
    carColor = carColor_input;

}

string CarType::getCarName(){

    return carName;

}

string CarType::getCarColor(){

    return carColor;

}

int CarType::getHorsePower(){

    return horsePower;

}

int CarType::getCarTopSpeed(){

    return carTopSpeed;

}

void CarType::setCarName(string carName_input){

    carName = carName_input;

}

void CarType::setCarColor(string carColor_input){

    carColor = carColor_input;

}

void CarType::setCarStat(string carName_input){

    if (carName_input == "Family-Car"){

        horsePower = 220;
        carTopSpeed = 160;

    }

    else if (carName_input == "Semi-Truck"){

        horsePower = 400;
        carTopSpeed = 80;

    }

    else if (carName_input == "Sports-Car"){

        horsePower = 610;
        carTopSpeed = 220;

    }

}



