#include <iostream>
#ifndef CarType_H
#define CarType_H

using namespace std;

class CarType{

    private:

    string carName;
    string carColor;
    int horsePower;
    int carTopSpeed;

    public:

    CarType();
    CarType(string carName_input, string carColor_input);

    string getCarName();
    string getCarColor();
    int getHorsePower();
    int getCarTopSpeed();
    
    void setCarName(string carName_input);
    void setCarColor(string carColor_input);
    void setCarStat(string carName_input); 

};

#endif

