#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "User.h"
#include "MAPP.h"
#include "Events.h"
#include <ctime>
#include <cmath>
#include <vector>


using namespace std;

// global varriables needed for the game
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char tracker;
int player;

// makes the board for the tik tak toe game
void boardMap()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// helps with tracking the game and helps placement
bool boardData(int slot)
{

    int row = slot / 3;
    int column;

    if (slot % 3 == 0)
    {
        row = row - 1;
        column = 2;
    }

    else
    {
        column = (slot % 3) - 1;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O')
    {

        board[row][column] = tracker;

        return true;
    }
    else
    {
        return false;
    }

}

// helps with determining the winner
int winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return player;

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return player;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return player;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return player;
    }

    return 0;
}

//helps change the player and the marker
void change_player_and_marker()
{
    if (tracker == 'X')
    {

        tracker = 'O';
    }

    else
    {
        tracker = 'X';
    }

    if (player == 1)
    {

        player = 2;
    }

    else
    {
        player = 1;
    }
}

// this is the Tik Tak Toe game
void TikTakToe()
{

    cout << "Player one, Please choose your marker! : " << endl;
    char marker_p1;
    cin >> marker_p1;

    while (marker_p1 != 'X' && marker_p1 != 'O')
    {

        cout << "Please enter an appropriate marker!" << endl;
        cin >> marker_p1;
    }

    player = 1;
    tracker = marker_p1;

    boardMap();

    int win;
    // while loop if they continue to enter wrong markers
    // while loop asks for input

    for (int i = 0; i < 9; i++)
    {
        cout << "Now it is player " << player << "'s turn. Please enter your slot! : " << endl;

        int slot;
        // char slot1;

        cin >> slot;
        // slot = slot1;

        if (!(slot >= 1 && slot <= 9))
        {

            cout << "Slot numbers have to be between 1 and 9!" << endl;

            i--;

            continue;
        }

        if (!boardData(slot))
        {
            cout << "This spot is already in play! Please try a different one" << endl;

            i--;

            continue;
        }

        boardMap();

        win = winner();

        if (win == 1)
        {
            cout << "Congratulations Player 1! You have won the game!" << endl;
            break;
        }

        if (win == 2)
        {
            cout << "Congratulations Player 2! You have won the game!" << endl;
            break;
        }

        change_player_and_marker();
    }

    if (win == 0)
    {
        cout << " Neither of you have won! This game ends in a tie! " << endl;
    }
}

// helps split files
int split(string phrases, char characters, string splitString[], int number)
{

    // defines the varriables
    int length = phrases.length();
    int point = 0;
    int count = 0;

    // pairs the strings
    string s1 = "";

    // makes sure that the length and number isnt 0
    while (count != length && (point != number))
    {
        // checks conditions
        if (phrases[count] == characters)
        {

            if (s1 != "")
            {
                splitString[point] = s1;
                point++;
                s1 = "";
            }
        }

        // else it just prints out first solution
        else
        {
            s1 += phrases[count];
        }

        // checks conditions
        if (count == length - 1)
        {
            if (s1 != "")
            {
                splitString[point] = s1;
                point++;
                s1 = "";
            }
        }
        count++;
    }
    // checks conditions and returns either a negative one or the point value
    if (count != length && point == number)
    {
        return -1;
    }
    else
    {
        return point;
    }
}

// this makes the map
void makeMap(string gameMap[7][8])
{

    string line;

    // defines my arrays
    string mapArray[8];

    // defines file
    ifstream myFile;

    // defines the position of the map
    int vertical = 0;
    int horizontal1;

    // opens file
    myFile.open("2dMap.txt");

    // reads each line in the file
    while (getline(myFile, line))
    {
        // splits the function
        split(line, ',', mapArray, 8);

        // defines in the horrizontal position of the 2d array of the map
        for (horizontal1 = 0; horizontal1 < 8; horizontal1++)
        {

            gameMap[vertical][horizontal1] = mapArray[horizontal1];
        }

        // defines veritcal
        vertical++;
    }

    myFile.close();
}

// helps show the map
void showMap(string gameMap[7][8], MAPP &MappMane)
{

    cout << "---- The game map ----" << endl;
    for (int vertical = 0; vertical < 7; vertical++)
    {

        for (int horizontal = 0; horizontal < 8; horizontal++)
        {

            // sets player location
            if (vertical == MappMane.getVerticalPosition() && horizontal == MappMane.getHorizontalPosition())
            {

                cout << "P"
                     << " ";
            }

            else
            {

                cout << gameMap[vertical][horizontal] << " ";
            }
        }

        cout << endl;
    }
}

// helps randomize the events
void randomizeEvents(EVENTS events[22], EVENTS initilizatorEvents[22], string gameMap[7][8])
{

    // defines string
    string line;

    // initilizes file
    ifstream myFile;

    // opens file
    myFile.open("events.txt");

    // intilizes all my variables
    int i = 0;
    int horizontalPosition = 0;
    int verticalPosition = 0;
    int condition;
    string arr[4];

    while (getline(myFile, line))
    {

        // splits the file
        split(line, ',', arr, 4);

        // helps set all the information
        initilizatorEvents[i].setEvent(arr[0]);
        initilizatorEvents[i].setCarName(arr[1]);

        initilizatorEvents[i].setCarSpeed(stoi(arr[2]));
        initilizatorEvents[i].setHorsePower(stoi(arr[3]));

        // moves to next possition
        i++;
    }
    myFile.close();

    srand(time(NULL));
    for (int j = 0; j < 22; j++)
    {

        // this checks conditions
        condition = 0;

        // randomizes the variables
        int randomLocation = rand() % 22;
        horizontalPosition = rand() % 8;
        verticalPosition = rand() % 7;
        

        for (int z = 0; z < j; z++)
        {
            if (horizontalPosition == events[z].getHorizontalLocation() && verticalPosition == events[z].getVerticalLocation())
            {
                condition = -1;
                // break;
            }
        }

        

        if (gameMap[verticalPosition][horizontalPosition] == "S" || condition == -1)
        {
            j--;
            continue;
        }

        // defines the event and its location
        events[j] = initilizatorEvents[randomLocation];
        events[j].setHorizontalLocation(horizontalPosition);
        events[j].setVerticalLocation(verticalPosition);
    }    
}
// checks for event

bool checkEvent(MAPP &MappMane, EVENTS events[22], int &slotNumber)
{

    for (slotNumber = 0; slotNumber < 22; slotNumber++)
    {
        if (MappMane.getHorizontalPosition() == events[slotNumber].getHorizontalLocation() && MappMane.getVerticalPosition() == events[slotNumber].getVerticalLocation())
        {

            return true;
        }
    }

    return false;
}

// this shows the stats of the events and helps with some of the game
void showEvents(EVENTS events[22], int &slotNumber, int &money, int &newScore, StopLightStat &StopLightMane, User &UserMane)
{

    int gameLost1 = 0;
    int gameWon1 = 0;
    int lightsPassed1 = 0;

    if (events[slotNumber].getEvent() == "speedingTickets")
    {

        cout << "You are now speeding and now the cops are chasing you" << endl;
        cout << "Since you chose this option you must race yourself out of this mess" << endl;
        cout << "The cop cars speed is: " << events[slotNumber].getCarSpeed() << endl;
        cout << "The cop cars horse power is: " << events[slotNumber].getHorsePower() << endl;
    }

    else if (events[slotNumber].getEvent() == "lightPassed")
    {

        string decision;

        cout << "You have now passed a light" << endl;
        cout << "You have two options here" << endl;
        cout << "Option 1: You can play a mini game and only lose 50 dollars" << endl;
        cout << "Option 2: You can take the fine for a 150 dollars" << endl;
        cin >> decision;  

        if (decision == "1")
        {

            TikTakToe();
            int wins = winner();

            if (wins == 1)
            {

                cout << "Turns out you won!!" << endl;
                cout << "Congrats as a suprise I will add money to your account" << endl;
                money = money + 50;
                newScore = newScore + 50;
                gameWon1 = gameWon1 + 1;
                lightsPassed1 = lightsPassed1 + 1;
                StopLightMane.setGameWons(gameWon1);
                StopLightMane.setLightsPassed(lightsPassed1);
                UserMane.setScore(newScore);
                UserMane.setTotalMoney(money);
            }

            else if (decision == "2")
            {

                cout << "Wow it turns out your lost. " << endl;
                cout << "We are so sorry about that" << endl;
                cout << "We must fine you now" << endl;
                newScore = newScore - 50;
                gameLost1 = gameLost1 + 1;
                lightsPassed1 = lightsPassed1 + 1;
                StopLightMane.setGameLost(gameLost1);
                StopLightMane.setLightsPassed(lightsPassed1);
                UserMane.setScore(newScore);
            }

            else
            {
            cout << "The only options you can choose from is option 1 or 2" << endl;
            cin >> decision;

            }      
        }

        else if (decision == "2")
        {

            cout << "We are so sorry about that" << endl;
            cout << "We must fine you now" << endl;
            newScore = newScore - 50;
            UserMane.setScore(newScore);
        }
    }

    else if (events[slotNumber].getEvent() == "carAccident")
    {

        cout << "You have crashed into a car" << endl;
        cout << "Since you ended up in this mess, I must tell you about this car" << endl;
        cout << "The cars name is: " << events[slotNumber].getCarName() << endl;
        cout << "The cars speed is: " << events[slotNumber].getCarSpeed() << endl;
        cout << "The cars horse power is: " << events[slotNumber].getHorsePower() << endl;
    }

    else {

        cout << "Failure happening from data transfer" << endl;
        cout <<" OH Boy!!! Did we commit an error?" << endl;
        cout << "Sorry about that, but now you can keep playing" << endl;
        cout << endl;

    }

}

// causes you to loose or make money
void theFinaleOfEvents(User &UserMane, CarType &CarTypeMane, int &money, StopLightStat &StopLightMane, int &newScore, string gameMap[7][8], bool &StopLightBool, MAPP &MappMane, EVENTS events[22], int &slotNumber)
{

    int speedingTickets1 = 0;
    int carAccidents1 = 0;

    showEvents(events, slotNumber, money, newScore, StopLightMane, UserMane);

    if (events[slotNumber].getEvent() == "speedingTickets" && events[slotNumber].chanceOfWinning(events[slotNumber].getEvent(), CarTypeMane, events[slotNumber].getCarSpeed(), events[slotNumber].getHorsePower()) == true)
    {

        cout << endl;
        cout << "You have succesfully gotten away" << endl;
        cout << "You will be charged nothing" << endl;
    }

    else if (events[slotNumber].getEvent() == "speedingTickets" && events[slotNumber].chanceOfWinning(events[slotNumber].getEvent(), CarTypeMane, events[slotNumber].getCarSpeed(), events[slotNumber].getHorsePower()) == false)
    {

        cout << endl;
        cout << "Sorry but it looks like your car was not fast enough to beat the cop" << endl;
        cout << "You will be charged 100 dollars" << endl;
        newScore = newScore - 100;
        speedingTickets1 = speedingTickets1 + 1;
        StopLightMane.setSpeedingTickets(speedingTickets1);
        UserMane.setScore(newScore);
    }

    else if (events[slotNumber].getEvent() == "carAccident" && events[slotNumber].chanceOfWinning(events[slotNumber].getEvent(), CarTypeMane, events[slotNumber].getCarSpeed(), events[slotNumber].getHorsePower()) == true)
    {

        cout << endl;
        cout << "It looks like you just commited a hit and run!!" << endl;
        cout << "With how heavy your car is, it turns out you survived! " << endl;
        cout << "You will not be charged" << endl;
        carAccidents1 = carAccidents1 + 1;
        StopLightMane.setCarAccidents(carAccidents1);
    }

    else if (events[slotNumber].getEvent() == "carAccident" && events[slotNumber].chanceOfWinning(events[slotNumber].getEvent(), CarTypeMane, events[slotNumber].getCarSpeed(), events[slotNumber].getHorsePower()) == false)
    {

        cout << endl;
        cout << "Sorry but it looks like your car was wrecked in the car accident" << endl;
        cout << "You will be charged 200 dollars" << endl;
        cout << "One hundred is just for fixing your car" << endl;
        newScore = newScore - 200;
        carAccidents1 = carAccidents1 + 1;
        StopLightMane.setCarAccidents(carAccidents1);
        UserMane.setScore(newScore);
    }

    else if (events[slotNumber].getEvent() == "lightPassed" && events[slotNumber].chanceOfWinning(events[slotNumber].getEvent(), CarTypeMane, events[slotNumber].getCarSpeed(), events[slotNumber].getHorsePower()) == false)
    {

        cout << endl;
        cout << "We must still fine you the other 100 dollars though" << endl;
        newScore = newScore - 100;
        UserMane.setScore(newScore);
    }

    else {

        cout << "Failure happening from data transfer" << endl;
        cout <<" OH Boy!!! Did we commit an error?" << endl;
        cout << "Sorry about that, but now you can keep playing" << endl;
        cout << endl;

    }

}

// helps travel the map
void travelingMap(string gameMap[7][8], User &UserMane, MAPP &MappMane, EVENTS events[22], CarType &CarTypeMane, int &money, StopLightStat &StopLightMane, int &newScore, bool &StopLightBool, int &slotNumber)
{

    while (true)
    {

        string line;

        //&& MappMane.getHorizontalPosition() != 5 && MappMane.getVerticalPosition() != 4

        if (checkEvent(MappMane, events, slotNumber) == true)
        {
 
            theFinaleOfEvents(UserMane, CarTypeMane, money, StopLightMane, newScore, gameMap, StopLightBool, MappMane, events, slotNumber);
        }

        if (UserMane.getScore() <= 0)
        {

            break;

        }

        showMap(gameMap, MappMane);

        cout << endl;
        cout << "Press 1 for Up" << endl;
        cout << "Press 2 for Down" << endl;
        cout << "Press 3 for Left" << endl;
        cout << "Press 4 for Right" << endl;
        cout << "5.Back to Game Menu" << endl;

        cin >> line;
        // getline(cin, line);

        if (line == "1")
        {

            if (MappMane.getVerticalPosition() - 1 < 0)
            {
                cout << "That move doesn't work. Move somewhere else" << endl;
                continue;
            }
            MappMane.verticalPosition(MappMane.getVerticalPosition() - 1);
        }
        else if (line == "2")
        {

            if (MappMane.getVerticalPosition() + 1 >= 7)
            {

                cout << "That move doesn't work. Move somewhere else" << endl;
                continue;
            }

            MappMane.verticalPosition(MappMane.getVerticalPosition() + 1);
        }
        else if (line == "3")
        {

            if (MappMane.getHorizontalPosition() - 1 < 0)
            {

                cout << "That move doesn't work. Move somewhere else" << endl;
                continue;
            }

            MappMane.horizontalPosition(MappMane.getHorizontalPosition() - 1);
        }
        else if (line == "4")
        {

            if (MappMane.getHorizontalPosition() + 1 >= 8)
            {

                cout << "That move doesn't work. Move somewhere else" << endl;
                continue;
            }

            MappMane.horizontalPosition(MappMane.getHorizontalPosition() + 1);
        }

        else if (line == "5")
        {

            break;
        }

        else
        {

            cout << "We are sorry, but that input was invalid try again" << endl;
            continue;

        }
    }
}

// helps set up the game
void option1(User &UserMane, CarType &CarTypeMane, int &money, StopLightStat &StopLightMane, int &newScore, string gameMap[7][8], bool &StopLightBool, MAPP &MappMane, EVENTS events[22], int &slotNumber)
{
    // cout << "This is the famous map for the game!" << endl;
    // showMap(gameMap, MappMane);
    cout << endl;
    travelingMap(gameMap, UserMane, MappMane, events, CarTypeMane, money, StopLightMane, newScore, StopLightBool, slotNumber);
}

// turns the boolean to true and makes sure the classes are defined
void setStopLightBool(User &UserMane, bool &StopLightBool, StopLightStat &StopLightMane)
{

    UserMane.setUserStat(StopLightMane);
    StopLightBool = true;

}

// this shows the stats of the games User
void showStats(User &UserMane, bool &StopLightBool)
{

    cout << "Good job, " << UserMane.getUserName() << endl;
    cout << endl;
    cout << "Here is your stats! " << endl;
    cout << endl;
    cout << "Total Money made: " << UserMane.getTotalMoney() << endl;
    cout << endl;
    cout << "Money you have left: " << UserMane.getScore() << endl;
    cout << endl;

    if (UserMane.getTime() == -1.00)
    {

        cout << "Your total time is undetermined yet." << endl;
        cout << endl;
    }

    else
    {

        cout << "Your total time is: " << UserMane.getTime() << endl;
        cout << endl;

    }

    UserMane.getCarInfo();
    UserMane.getCharacterInfo();

    if (StopLightBool == true)
    {

        UserMane.getUserstat();
        cout << endl;
    }

    else
    {

        cout << "Not enough information to show the stop light stats" << endl;
        cout << endl;

    }

    UserMane.setReadyScore(UserMane.getScore(), UserMane.getTotalMoney(), UserMane.getTime());
    cout << "Your driver score is: " << UserMane.getReadyScore() << ". For now!" << endl;
    cout << endl;
}

// this is the menu of the game
void theMenu(User &UserMane, CarType &CarTypeMane, int &money, StopLightStat &StopLightMane, int &newScore, string gameMap[7][8], bool &StopLightBool, MAPP &MappMane, EVENTS events[22], int &slotNumber)
{

    while (newScore > 0)
    {

        // defines the string
        string option;

        // Prints the Menu
        cout << "----- Menu -----" << endl;
        cout << "1. Play the best game ever created!!" << endl;
        cout << "2. View the map of the game" << endl;
        cout << "3. View the game stats" << endl;
        cout << "4. Quit the game" << endl;

        // puts the option in option string
       cin >> option;

        if (option == "1")
        {
            option1(UserMane, CarTypeMane, money, StopLightMane, newScore, gameMap, StopLightBool, MappMane, events, slotNumber);
        }

        else if (option == "2")
        {

            showMap(gameMap, MappMane);
        }

        else if (option == "3")
        {

            showStats(UserMane, StopLightBool);
        }

        else if (option == "4")
        {

            break;
        }

        else if (UserMane.getScore() <= 0)
        {

            break;
        }

        else
        {

            cout << "Your input was invalid. The input must be between 1-4" << endl;
            continue;
        }
    }
}

// runs the game
int main()
{

    /*
    Defines all the variables needed in the beginning 
    */
    // user definition
    User UserMane;
    StopLightStat StopLightMane;
    Character CharacterMane;
    CarType CarTypeMane;
    MAPP MappMane;
    EVENTS events[22];
    EVENTS initilizatorEvents[22];

    // varibales
    string newUser, hairColor1, gender1, carName_input, carColor_input, startGame;
    string height1;
    int money = 1000;
    int newScore = 1000;

    // sets variables for events
    int slotNumber;

    // defines some variables for hidden test cases for the User
    UserMane.setTotalMoney(money);
    UserMane.setScore(newScore);
    UserMane.setTime(-1.00);
    // checks to see if stoplight stat is defined yet
    bool StopLightBool = false;
    // defines for the map
    string gameMap[7][8];
    
    // makes map for game
    makeMap(gameMap);

    // randomizes the events
    randomizeEvents(events, initilizatorEvents, gameMap);

    // defines the game
    cout << "Traffic and The Law" << endl;
    cout << endl;
    cout << "Before begining the game, the game is CAP Sensitive" << endl;
    cout << "Make sure to use the same capitalization of the game" << endl;
    cout << endl;
    cout << "This game is about following traffic laws under extreme conditions." << endl;
    cout << "The game starts with letting you pick the type of car you want." << endl;
    cout << endl;
    cout << "Depending on what car you get then you get tested to see if you can survive the game" << endl;
    cout << endl;
    cout << "Are you ready to start the game? " << endl;
    cin >> startGame;
    cout << endl;

    // Make sure they want to play
    while (startGame != "yes")
    {   
        cout << "Thats not the right input!! Must say yes to continue" << endl;
        cin >> startGame;
    }

    // must add a while loop for a space bar

    // defines the name for the User
    cout << "What is your name?" << endl;
    cin >> newUser;
    cout << endl;
    UserMane.setUserName(newUser);

    // defines the hairColor for the User
    cout << "What do you want your Characters hair color to be, " << newUser << "?" << endl;
    cin >> hairColor1;
    cout << endl;
    CharacterMane.setHairColor(hairColor1);

    // defines the Users Height
    cout << "What is your Height in inches?" << endl;
    cin >> height1;
    cout << endl;
    CharacterMane.setHeight(height1);

    // defines the Users Gender
    cout << "What is your Character's Gender?" << endl;
    cin >> gender1;
    cout << endl;
    CharacterMane.setGender(gender1);

    // redfines the user Character
    UserMane.setCharacterInfo(CharacterMane);

    // defines the Users Car
    cout << "What car do you want? You have three Options:" << endl;
    cout << "Option 1: Sports-Car" << endl;
    cout << "Option 2: Family-Car" << endl;
    cout << "Option 3: Semi-Truck" << endl;
    cin >> carName_input;
    cout << endl;

    // makes sure they pick the right car
    while (carName_input != "Sports-Car" && carName_input != "Semi-Truck" && carName_input != "Family-Car")
    {

        cout << "Must be one of the three options!" << endl;
        cout << "Possibly you picked one of these three options" << endl;
        cout << "but you didnt put in the right input, for option one" << endl;
        cout << "it must be [Sports-Car]" << endl;
        cout << "for option two, it must be [Semi-Truck]" << endl;
        cout << "for option three, it must be [Family-Car]. " << endl;
        cout << "Okay now try again!!" << endl;
        cout << "What car do you want? You have three Options:" << endl;
        cout << endl;
        cin >> carName_input;
        break;
    }

    // defines the User Car name to the car class
    CarTypeMane.setCarName(carName_input);
    CarTypeMane.setCarStat(carName_input);

    // defines the Users Car Color
    cout << "what color do you want your car to be? " << endl;
    cin >> carColor_input;
    cout << endl;
    CarTypeMane.setCarColor(carColor_input);

    // sets the Users Car to the User
    UserMane.setCarInfo(CarTypeMane);

    // starts the timer for the game
    clock_t timeElapsed1;
    timeElapsed1 = clock();

    // gives the user more directions
    cout << endl;
    cout << "Now we have set all the values." << endl;
    cout << "Pick an option from the Menu to continue the game." << endl;
    cout << endl;

    theMenu(UserMane, CarTypeMane, money, StopLightMane, newScore, gameMap, StopLightBool, MappMane, events, slotNumber);
    cout << endl;

    // times the whole game
    timeElapsed1 = clock() - timeElapsed1;
    double newTime = ((double)timeElapsed1) / CLOCKS_PER_SEC;

    // defines more things that were undifened
    UserMane.setTime(newTime);

    // shows the game stats
    cout << endl;
    setStopLightBool(UserMane, StopLightBool, StopLightMane);
    showStats(UserMane, StopLightBool);

    // thanks the user for the game
    cout << endl;
    cout << "Thank you for playing this game! Hope you enjoyed it" << endl;

    return 0;
}

// this class was honestly extremely fun!! Glad I took it 
// Sincerely, Albashir Ali and Justice Asamonye