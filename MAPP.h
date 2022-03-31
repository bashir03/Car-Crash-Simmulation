#include <iostream>
#ifndef MAPP_H
#define MAPP_H

class MAPP{

    private:

    // defines the positions on the 2dMap
    int horizontalMap;
    int verticalMap;

    public:

    MAPP();

    // sets Users position
    void setPosition(int horizontal, int vertical);

    // sets the horizontal position
    void horizontalPosition(int horizontal);

    // sets the vertical position
    void verticalPosition(int vertical);

    // gets the current position
    int getHorizontalPosition();
    int getVerticalPosition();


};

#endif