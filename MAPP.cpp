#include <iostream>
#include "MAPP.h"

MAPP::MAPP(){

    horizontalMap = 5;
    verticalMap = 4;

}

int MAPP::getHorizontalPosition(){

    return horizontalMap;

}

int MAPP::getVerticalPosition(){

    return verticalMap;

}

void MAPP::setPosition(int horizontal, int vertical){

    horizontalMap = horizontal;
    verticalMap = vertical;

}

void MAPP::horizontalPosition(int horizontal){

    horizontalMap = horizontal;

}

void MAPP::verticalPosition(int vertical){

    verticalMap = vertical;

}