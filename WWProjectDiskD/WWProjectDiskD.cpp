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