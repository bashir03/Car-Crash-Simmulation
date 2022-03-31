#include <iostream>
#ifndef Character_H
#define Character_H

using namespace std;

class Character{

    private:

    string hairColor;
    string height;
    string gender;

    public:

    Character();
    Character(string hairColor1, string height1, string gender1);

    string getHairColor();
    string getHeight();
    string getGender();

    void setHairColor(string hairColor1);
    void setHeight( string height1);
    void setGender(string gender1);

};

#endif