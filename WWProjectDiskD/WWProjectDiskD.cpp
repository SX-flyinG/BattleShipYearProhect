#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <conio.h>

using namespace std;
int reg(char* username, char* password);
void registration(char* username, char* password);

#include "LObby.h"
#include "registration.h"
#include "Tutorial.h"
#include "PlayWithFriend.h"

int main()
{
	srand(time(NULL));
	char* username = new char[16];
	char* password = new char[64];
	reg(username, password);
}