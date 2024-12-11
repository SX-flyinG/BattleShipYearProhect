//off any warnings to string library
#define _CRT_SECURE_NO_WARNINGS

//Download all librarys i need for a project
#include <iostream>
#include <string>
#include <ctime>
//Work with files
#include <fstream>
//Work with keyboard
#include <conio.h>


//using namespace
using namespace std;
int reg(char* username, char* password);
void registration(char* username, char* password);

//Include my header files for project
#include "LObby.h"
#include "registration.h"
#include "Tutorial.h"
#include "PlayWithFriend.h"
#include "EasyBot.h"
#include "MediumBot.h"

// global values 
int letterKey = 0;
int numKey = 0;
int wayKey = 0;
int countOfDestroyShip = 4;
int countOfCruiseShip = 3;
int countOfSubmarines = 2;
int countOfBattleShips = 1;
char polePlayer[11][11];
char poleBot[11][11];
char player1Shots[11][11];
char botShots[11][11];
int countOfMoves = 0;
int swichSides = 0;
int countOfShips1 = 20;
int countOfBotsShip = 20;
char polePlayer2[11][11];
char player2Shots[11][11];
int countOfShips2 = 20;


//the main of my project
int main()
{
	// off random by time
	srand(time(NULL));
	//create two dynamic value username and password
	char* username = new char[16];
	char* password = new char[64];
	//start the program by the registration menu
	reg(username, password);
	//delete bag with more then on eopen console
	return 0;
}