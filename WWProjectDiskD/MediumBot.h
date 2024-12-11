
void fillArray(char polePlayer[11][11]);
void PrintPole(char pole[11][11]);
void PlaceDestroyers(int& letterKey, int& numKey, int destroyer, char polePlayer[11][11]);
void Cruiser(int letterKey, int numKey, int wayKey, int cruiser, char pole[11][11], int& countOfMatch, int& countOfWins);
void PlaceCruiserBot(int cruiser, char field[11][11] , int oneTry);
void Submarine(int letterKey, int numKey, int wayKey, int submarine, char pole[11][11], int& countOfMatch, int& countOfWins);
void PlaceSubmarineBot(int submarine , char field[11][11] ,int oneTry);
void BattleShip(int letterKey, int numKey, int wayKey, int battleShip, char pole[11][11], int& countOfMatch, int& countOfWins);
void PlaceBattleshipBot(int battleShip, char field[11][11] , int oneTry);
void MarkSurroundings(int letterKey, int numKey, char pole[11][11]);
void WriteRow(int& letterKey);
void WriteColumn(int& numKey);
void PlayerMove(char field[11][11], char field2[11][11], char viewField[11][11], int& countOfMoves, int& switchSides, int& countOfShips, int letterKey, int numKey);
void BotPlacing(char poleBot[11][11]);
bool GameBot(char mainField[11][11], char rivalField[11][11], char viewRivalField[11][11],char viewMainField[11][11], int& swichSides, int& countOfMoves, int& countOfShipsPL1, int& countOfShipsPL2, int letterKey, int numKey, int& countOfWins);
void MediumBot(int& countOfGames, int& countOfWins);
void BotMove(char field[11][11], char viewField[11][11], int& countOfMoves, int& swichSides, int& countOfShipsPL1);




void PlaceDestroyersBot(int destroyer, char field[11][11]) {
	while (destroyer > 0) {
		int x = rand() % 10 + 1;
		int y = rand() % 10 + 1;

		if (field[x][y] == '.') {
			field[x][y] = 'D';
			MarkSurroundings(x, y, field);
			destroyer--;
		}
	}
}

void Cruiser(int letterKey, int numKey, int wayKey, int cruiser, char pole[11][11], int& countOfMatch, int& countOfWins) {
    cout << "\nSecondly place your cruiser's ships: \n" << endl;

    while (cruiser > 0) {
        WriteRow(letterKey);
        WriteColumn(numKey);

        while (pole[letterKey][numKey] != '.') {
            cout << "\nThis position is already occupied, please choose another.\n";
            WriteRow(letterKey);
            WriteColumn(numKey);
        }

        bool validPlacement = false;
        while (!validPlacement) {
            cout << "\nWrite direction (W, w - up; A, a - left; S, s - down; D, d - right OR E , e - for replace): \n";
            wayKey = _getch();
            wayKey = toupper(wayKey);
            switch (wayKey) {
            case 'A':
                if (numKey - 1 >= 1 && pole[letterKey][numKey] == '.' && pole[letterKey][numKey - 1] == '.') {
                    pole[letterKey][numKey] = 'C';
                    pole[letterKey][numKey - 1] = 'C';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey, numKey - 1, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'S':
                if (letterKey + 1 <= 10 && pole[letterKey][numKey] == '.' && pole[letterKey + 1][numKey] == '.') {
                    pole[letterKey][numKey] = 'C';
                    pole[letterKey + 1][numKey] = 'C';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey + 1, numKey, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'D':
                if (numKey + 1 <= 10 && pole[letterKey][numKey] == '.' && pole[letterKey][numKey + 1] == '.') {
                    pole[letterKey][numKey] = 'C';
                    pole[letterKey][numKey + 1] = 'C';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey, numKey + 1, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'W':
                if (letterKey - 1 >= 1 && pole[letterKey][numKey] == '.' && pole[letterKey - 1][numKey] == '.') {
                    pole[letterKey][numKey] = 'C';
                    pole[letterKey - 1][numKey] = 'C';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey - 1, numKey, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'E':
                cout << "Sorry but u dont listen my advise.\n";
                MediumBot(countOfMatch, countOfWins);

            default:
                cout << "Invalid direction. Please use W, A, S, or D. Or E for replace the position.\n";
                break;
            }
        }
        cruiser--;
        PrintPole(pole);

    }
}


void PlaceCruiserBot(int cruiser, char field[11][11] , int oneTry) {
    while (cruiser > 0) {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;

        // Попытка найти подходящее место
        while (field[x][y] != '.') {
            x = rand() % 10 + 1;
            y = rand() % 10 + 1;
        }

        bool validPlacement = false;
        while (!validPlacement) {
            if (oneTry == 10) {
                BotPlacing(field);
            }
            int direction = rand() % 4; // Генерация направления: 0 - вверх, 1 - вниз, 2 - влево, 3 - вправо

            switch (direction) {
            case 0: // Вверх
                if (x - 1 >= 1 && field[x][y] == '.' && field[x - 1][y] == '.') {
                    field[x][y] = 'C';
                    field[x - 1][y] = 'C';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x - 1, y, field);
                    validPlacement = true;
                }
                break;
            case 1: // Вниз
                if (x + 1 <= 10 && field[x][y] == '.' && field[x + 1][y] == '.') {
                    field[x][y] = 'C';
                    field[x + 1][y] = 'C';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x + 1, y, field);
                    validPlacement = true;
                }
                break;
            case 2: // Влево
                if (y - 1 >= 1 && field[x][y] == '.' && field[x][y - 1] == '.') {
                    field[x][y] = 'C';
                    field[x][y - 1] = 'C';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x, y - 1, field);
                    validPlacement = true;
                }
                break;
            case 3: // Вправо
                if (y + 1 <= 10 && field[x][y] == '.' && field[x][y + 1] == '.') {
                    field[x][y] = 'C';
                    field[x][y + 1] = 'C';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x, y + 1, field);
                    validPlacement = true;
                }
                break;
            default:
                oneTry++;
            }
            
        }
        cruiser--; // Уменьшение числа оставшихся кораблей
    }
}

void Submarine(int letterKey, int numKey, int wayKey, int submarine, char pole[11][11], int& countOfMatch, int& countOfWins) {
    cout << "\nSecondly place your submarine's ships: \n" << endl;

    while (submarine > 0) {  // Fixed loop condition
        WriteRow(letterKey);
        WriteColumn(numKey);

        while (pole[letterKey][numKey] != '.') {
            cout << "\nThis position is already occupied, please choose another.\n";
            WriteRow(letterKey);
            WriteColumn(numKey);
        }

        bool validPlacement = false;
        while (!validPlacement) {
            cout << "Write direction (W, w - up; A, a - left; S, s - down; D, d - right): \n";
            wayKey = _getch();
            wayKey = toupper(wayKey);

            switch (wayKey) {
            case 'A':
                if (numKey - 2 >= 1 && pole[letterKey][numKey] == '.'
                    && pole[letterKey][numKey - 1] == '.'
                    && pole[letterKey][numKey - 2] == '.') {
                    pole[letterKey][numKey] = 'S';
                    pole[letterKey][numKey - 1] = 'S';
                    pole[letterKey][numKey - 2] = 'S';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey, numKey - 1, pole);
                    MarkSurroundings(letterKey, numKey - 2, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'S':
                if (letterKey + 2 <= 10 && pole[letterKey][numKey] == '.'
                    && pole[letterKey + 1][numKey] == '.'
                    && pole[letterKey + 2][numKey] == '.') {
                    pole[letterKey][numKey] = 'S';
                    pole[letterKey + 1][numKey] = 'S';
                    pole[letterKey + 2][numKey] = 'S';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey + 1, numKey, pole);
                    MarkSurroundings(letterKey + 2, numKey, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'D':
                if (numKey + 2 <= 10 && pole[letterKey][numKey] == '.'
                    && pole[letterKey][numKey + 1] == '.'
                    && pole[letterKey][numKey + 2] == '.') {
                    pole[letterKey][numKey] = 'S';
                    pole[letterKey][numKey + 1] = 'S';
                    pole[letterKey][numKey + 2] = 'S';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey, numKey + 1, pole);
                    MarkSurroundings(letterKey, numKey + 2, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'W':
                if (letterKey - 2 >= 1 && pole[letterKey][numKey] == '.'
                    && pole[letterKey - 1][numKey] == '.'
                    && pole[letterKey - 2][numKey] == '.') {
                    pole[letterKey][numKey] = 'S';
                    pole[letterKey - 1][numKey] = 'S';
                    pole[letterKey - 2][numKey] = 'S';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey - 1, numKey, pole);
                    MarkSurroundings(letterKey - 2, numKey, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'E':
                cout << "Sorry but u dont listen my advise.\n";
                MediumBot(countOfMatch, countOfWins);
            default:
                cout << "Invalid direction. Please use W, A, S, or D.\n";
            }
        }
        submarine--;
        PrintPole(pole);
    }
}

void PlaceSubmarineBot(int submarine, char field[11][11] , int oneTry) {
    while (submarine > 0) {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;

        // Попытка найти подходящее место
        while (field[x][y] != '.') {
            x = rand() % 10 + 1;
            y = rand() % 10 + 1;
        }

        bool validPlacement = false;
        while (!validPlacement) {
            if (oneTry == 10) {
                BotPlacing(field);
            }
            int direction = rand() % 4; // Генерация направления: 0 - вверх, 1 - вниз, 2 - влево, 3 - вправо

            switch (direction) {
            case 0: // Вверх
                if (x - 2 >= 1 && field[x][y] == '.' 
                    && field[x - 1][y] == '.'
                    && field[x - 2][y] == '.') {
                    field[x][y] = 'S';
                    field[x - 1][y] = 'S';
                    field[x - 2][y] = 'S';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x - 1, y, field);
                    MarkSurroundings(x - 2, y, field);
                    validPlacement = true;
                }
                break;
            case 1: // Вниз
                if (x + 2 <= 10 && field[x][y] == '.' 
                    && field[x + 1][y] == '.'
                    && field[x +2][y] == '.') {
                    field[x][y] = 'S';
                    field[x + 1][y] = 'S';
                    field[x + 2][y] = 'S';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x + 1, y, field);
                    MarkSurroundings(x + 2, y, field);
                    validPlacement = true;
                }
                break;
            case 2: // Влево
                if (y - 1 >= 1 && field[x][y] == '.' 
                    && field[x][y - 1] == '.'
                    && field[x][y  -2] == '.') {
                    field[x][y] = 'S';
                    field[x][y - 1] = 'S';
                    field[x][y - 2] = 'S';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x, y - 1, field);
                    MarkSurroundings(x, y - 2, field);
                    validPlacement = true;
                }
                break;
            case 3: // Вправо
                if (y + 1 <= 10 && field[x][y] == '.' 
                    && field[x][y + 1] == '.'
                    && field[x][y + 2] == '.') {
                    field[x][y] = 'S';
                    field[x][y + 1] = 'S';
                    field[x][y + 2] = 'S';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x, y + 1, field);
                    MarkSurroundings(x, y + 2, field);
                    validPlacement = true;
                }
                break;
            default:
                oneTry++;
            }
        }
        submarine--; // Уменьшение числа оставшихся кораблей
    }
}

void BattleShip(int letterKey, int numKey, int wayKey, int battleShip, char pole[11][11], int& countOfMatch, int& countOfWins) {
    cout << "\nSecondly place your battleship's ships: \n" << endl;

    while (battleShip > 0) {
         // Fixed loop condition
        WriteRow(letterKey);
        WriteColumn(numKey);

        while (pole[letterKey][numKey] != '.') {
            cout << "\nThis position is already occupied, please choose another.\n";
            WriteRow(letterKey);
            WriteColumn(numKey);
        }

        bool validPlacement = false;
        while (!validPlacement) {
            cout << "Write direction (W, w - up; A, a - left; S, s - down; D, d - right): \n";
            wayKey = _getch();
            wayKey = toupper(wayKey);

            switch (wayKey) {
            case 'A':
                if (numKey - 3 >= 1 && pole[letterKey][numKey] == '.'
                    && pole[letterKey][numKey - 1] == '.'
                    && pole[letterKey][numKey - 2] == '.'
                    && pole[letterKey][numKey - 3] == '.') {
                    pole[letterKey][numKey] = 'B';
                    pole[letterKey][numKey - 1] = 'B';
                    pole[letterKey][numKey - 2] = 'B';
                    pole[letterKey][numKey - 3] = 'B';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey, numKey - 1, pole);
                    MarkSurroundings(letterKey, numKey - 2, pole);
                    MarkSurroundings(letterKey, numKey - 3, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'S':
                if (letterKey + 3 <= 10 && pole[letterKey][numKey] == '.'
                    && pole[letterKey + 1][numKey] == '.'
                    && pole[letterKey + 2][numKey] == '.'
                    && pole[letterKey + 3][numKey] == '.') {
                    pole[letterKey][numKey] = 'B';
                    pole[letterKey + 1][numKey] = 'B';
                    pole[letterKey + 2][numKey] = 'B';
                    pole[letterKey + 3][numKey] = 'B';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey + 1, numKey, pole);
                    MarkSurroundings(letterKey + 2, numKey, pole);
                    MarkSurroundings(letterKey + 3, numKey, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'D':
                if (numKey + 3 <= 10 && pole[letterKey][numKey] == '.'
                    && pole[letterKey][numKey + 1] == '.'
                    && pole[letterKey][numKey + 2] == '.'
                    && pole[letterKey][numKey + 3] == '.') {
                    pole[letterKey][numKey] = 'B';
                    pole[letterKey][numKey + 1] = 'B';
                    pole[letterKey][numKey + 2] = 'B';
                    pole[letterKey][numKey + 3] = 'B';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey, numKey + 1, pole);
                    MarkSurroundings(letterKey, numKey + 2, pole);
                    MarkSurroundings(letterKey, numKey + 3, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'W':
                if (letterKey - 3 >= 1 && pole[letterKey][numKey] == '.'
                    && pole[letterKey - 1][numKey] == '.'
                    && pole[letterKey - 2][numKey] == '.'
                    && pole[letterKey - 3][numKey] == '.') {
                    pole[letterKey][numKey] = 'B';
                    pole[letterKey - 1][numKey] = 'B';
                    pole[letterKey - 2][numKey] = 'B';
                    pole[letterKey - 3][numKey] = 'B';
                    MarkSurroundings(letterKey, numKey, pole);
                    MarkSurroundings(letterKey - 1, numKey, pole);
                    MarkSurroundings(letterKey - 2, numKey, pole);
                    MarkSurroundings(letterKey - 3, numKey, pole);
                    validPlacement = true;
                }
                else {
                    cout << "Invalid placement! Try again.\n";
                }
                break;
            case 'E':
                cout << "Sorry but u dont listen my advise.\n";
                MediumBot(countOfMatch, countOfWins);
            default:
                cout << "Invalid direction. Please use W, A, S, or D .\n";
            }
        }

        PrintPole(pole);
        battleShip--;
    }
}

void PlaceBattleshipBot(int battleShip, char field[11][11] , int oneTry) {
    while (battleShip > 0) {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;

        // Попытка найти подходящее место
        while (field[x][y] != '.') {
            x = rand() % 10 + 1;
            y = rand() % 10 + 1;
        }

        bool validPlacement = false;
        while (!validPlacement) {
            if (oneTry == 10) {
                BotPlacing(field);
            }
            int direction = rand() % 4; // Генерация направления: 0 - вверх, 1 - вниз, 2 - влево, 3 - вправо

            switch (direction) {
            case 0: // Вверх
                if (x - 2 >= 1 && field[x][y] == '.'
                    && field[x - 1][y] == '.'
                    && field[x - 2][y] == '.'
                    && field[x - 3][y] == '.') {
                    field[x][y] = 'B';
                    field[x - 1][y] = 'B';
                    field[x - 2][y] = 'B';
                    field[x - 3][y] = 'B';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x - 1, y, field);
                    MarkSurroundings(x - 2, y, field);
                    MarkSurroundings(x - 3, y, field);
                    validPlacement = true;
                }
                break;
            case 1: // Вниз
                if (x + 2 <= 10 && field[x][y] == '.'
                    && field[x + 1][y] == '.'
                    && field[x + 2][y] == '.'
                    && field[x + 3][y] == '.') {
                    field[x][y] = 'B';
                    field[x + 1][y] = 'B';
                    field[x + 2][y] = 'B';
                    field[x + 3][y] = 'B';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x + 1, y, field);
                    MarkSurroundings(x + 2, y, field);
                    MarkSurroundings(x + 3, y, field);
                    validPlacement = true;
                }
                break;
            case 2: // Влево
                if (y - 1 >= 1 && field[x][y] == '.'
                    && field[x][y - 1] == '.'
                    && field[x][y - 2] == '.'
                    && field[x][y - 3] == '.') {
                    field[x][y] = 'B';
                    field[x][y - 1] = 'B';
                    field[x][y - 2] = 'B';
                    field[x][y - 3] = 'B';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x, y - 1, field);
                    MarkSurroundings(x, y - 2, field);
                    MarkSurroundings(x, y - 3, field);
                    validPlacement = true;
                }
                break;
            case 3: // Вправо
                if (y + 1 <= 10 && field[x][y] == '.'
                    && field[x][y + 1] == '.'
                    && field[x][y + 2] == '.'
                    && field[x][y + 3] == '.') {
                    field[x][y] = 'B';
                    field[x][y + 1] = 'B';
                    field[x][y + 2] = 'B';
                    field[x][y + 3] = 'B';
                    MarkSurroundings(x, y, field);
                    MarkSurroundings(x, y + 1, field);
                    MarkSurroundings(x, y + 2, field);
                    MarkSurroundings(x, y + 3, field);
                    validPlacement = true;
                }
                break;
            }
        }
        battleShip--; // Уменьшение числа оставшихся кораблей
    }
}

void BotPlacing(char poleBot[11][11] ) {
    int countOfDestroyers = 4; 
    int countOfCruisers = 3; 
    int countOfSubmarine = 2; 
    int countOfBattleship = 1;
    int oneTry = 0;
    fillArray(poleBot);
    PlaceDestroyersBot(countOfDestroyers, poleBot);
    PlaceCruiserBot(countOfCruisers, poleBot, oneTry);
    PlaceSubmarineBot(countOfSubmarine, poleBot, oneTry);
    PlaceBattleshipBot(countOfBattleship, poleBot, oneTry);
}

void BotMove(char field[11][11] , char viewField[11][11], int& countOfMoves, int& swichSides, int& countOfShipsPL1) {
    int x, y;

    do {
        x = rand() % 11 + 1;
        y = rand() % 11 + 1;
    } while (field[x][y] == 'X' || field[x][y] == '0' || x == 0 || y == 0);

    if (field[x][y] == 'D' || field[x][y] == 'C' || field[x][y] == 'S' || field[x][y] == 'B') {
        viewField[x][y] = 'X';
        cout << "Bot hit your ship at (" << x << ", " << y << ")!" << endl;
        countOfShipsPL1--;
        
    }
    else {
        viewField[x][y] = '0';
        cout << "Bot missed!" << endl;
        swichSides++;
    }
    countOfMoves++;
    cout << "Your field after bot's move:" << endl;
    PrintPole(viewField);
}



bool GameBot(char mainField[11][11], char rivalField[11][11], char viewRivalField[11][11],char viewMainField[11][11], int& swichSides, int& countOfMoves, int& countOfShipsPL1, int& countOfBotsShip, int letterKey, int numKey, int& countOfWins) {


    if (countOfShipsPL1 == 0) {
        cout << "Player2 wins the game!!!" << endl;
        ofstream inHistoryOfMatches("history.txt", ios::app);
        inHistoryOfMatches << "Game mod: Math with bot ; Level of bot : Medium ; Winner : Bot ; Count of moves : " << countOfMoves << "; " << endl;
        inHistoryOfMatches.close();
        return false;
    }
    if (countOfBotsShip == 0) {
        countOfWins++;
        cout << "Player win the game!!!" << endl;
        string username;
        ifstream outFileName("username.txt");
        getline(outFileName, username);
        outFileName.close();
        ofstream inHistoryOfMatches("history.txt", ios::app);
        inHistoryOfMatches << "Game mod: Math with bot; Level of bot : Medium ;Winner : " << username << "; Count of moves : " << countOfMoves << "; " << endl;
        inHistoryOfMatches.close();
        return false;
    }
    if (swichSides % 2 == 0) {
        cout << "Pole of rival before move : " << endl;
        PrintPole(viewRivalField);
        cout << "Player 1's move:" << endl;
        PlayerMove(mainField, rivalField, viewRivalField, countOfMoves, swichSides, countOfBotsShip, letterKey, numKey);
    }
    else {
        cout << "Bot's move:" << endl;
        BotMove(mainField, viewMainField ,countOfMoves  ,swichSides , countOfShipsPL1 );
    }

    return true;
}

void MediumBot(int& countOfGames, int& countOfWins) {
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
    fillArray(polePlayer);
    fillArray(player1Shots);
    fillArray(botShots);
    cout << "Player num1 please place ur ship's : " << endl;
    PlaceDestroyers(letterKey, numKey, countOfDestroyShip, polePlayer);
    cout << "Please dont try to place ships there u cant choose way because u need to replace all ships" << endl;
    Cruiser(letterKey, numKey, wayKey, countOfCruiseShip, polePlayer, countOfGames, countOfWins);
    Submarine(letterKey, numKey, wayKey, countOfSubmarines, polePlayer, countOfGames, countOfWins);
    BattleShip(letterKey, numKey, wayKey, countOfBattleShips, polePlayer, countOfGames, countOfWins);
    cout << "Bot is placing ships..." << endl;
    BotPlacing(poleBot);
    while (GameBot(polePlayer, poleBot, player1Shots,  botShots,swichSides, countOfMoves, countOfShips1, countOfBotsShip, letterKey, numKey, countOfWins));
    countOfGames++;
    lobby();
}