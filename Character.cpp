#include <iostream>
#include "Character.h"

using namespace std;

Character::Character(){

    hairColor = "";
    height = "";
    gender = "";

}

Character::Character(string hairColor1, string height1, string gender1){

    hairColor = hairColor1;
    height = height1;
    gender = gender1;

}

string Character::getHairColor(){

    return hairColor;

}

string Character::getHeight(){

    return height;

}

string Character::getGender(){

    return gender;

}

void Character::setHairColor(string hairColor1){

     hairColor = hairColor1;

}

void Character::setHeight( string height1){

    height = height1;

}

void Character::setGender(string gender1){

    gender = gender1;

}