
void fillArray(char polePlayer[11][11]);
void PrintPole(char pole[11][11]);
void PlaceDestroyers(int& letterKey, int& numKey, int destroyer, char polePlayer[11][11]);
void cruiser(int letterKey, int numKey, int wayKey, int cruiser, char pole[11][11], int& countOfMatch, int& countOfWins);
void submarine(int letterKey, int numKey, int wayKey, int submarine, char pole[11][11], int& countOfMatch, int& countOfWins);
void Battleship(int letterKey, int numKey, int wayKey, int battleShip, char pole[11][11], int& countOfMatch, int& countOfWins);
void MarkSurroundings(int letterKey, int numKey, char pole[11][11]);
void WriteRow(int& letterKey);
void WriteColumn(int& numKey);
void PlayerMove(char field[11][11], char field2[11][11], char viewField[11][11], int& countOfMoves, int& switchSides, int& countOfShips, int letterKey, int numKey);
void BotPlacing(char poleBot[11][11]);
bool GameBot(char mainField[11][11], char rivalField[11][11], char viewRivalField[11][11], char viewMainField[11][11], int& swichSides, int& countOfMoves, int& countOfShipsPL1, int& countOfShipsPL2, int letterKey, int numKey, int& countOfWins);
void EasyBot(int& countOfGames, int& countOfWins);
void BotMove(char field[11][11], char viewField[11][11], int& countOfMoves, int& swichSides, int& countOfShipsPL1);




void cruiser(int letterKey, int numKey, int wayKey, int cruiser, char pole[11][11], int& countOfMatch, int& countOfWins) {
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
                EasyBot(countOfMatch, countOfWins);

            default:
                cout << "Invalid direction. Please use W, A, S, or D. Or E for replace the position.\n";
                break;
            }
        }
        cruiser--;
        PrintPole(pole);

    }
}

void submarine(int letterKey, int numKey, int wayKey, int submarine, char pole[11][11], int& countOfMatch, int& countOfWins) {
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
                EasyBot(countOfMatch, countOfWins);
            default:
                cout << "Invalid direction. Please use W, A, S, or D.\n";
            }
        }
        submarine--;
        PrintPole(pole);
    }
}


void Battleship(int letterKey, int numKey, int wayKey, int battleShip, char pole[11][11], int& countOfMatch, int& countOfWins) {
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
                EasyBot(countOfMatch, countOfWins);
            default:
                cout << "Invalid direction. Please use W, A, S, or D .\n";
            }
        }

        PrintPole(pole);
        battleShip--;
    }
}

void BotPlacing(char poleBot[11][11] , char poleUser[11][11]) {
    int place = rand() % 2;
    switch (place) {
    case 0:  // copy default massive
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                poleBot[i][j] = poleUser[i][j];
            }
        }
    case 1: // copy inverted by x massive 
        for (int i = 0; i  < 11; i--) {
            for (int j = 0; j  < 11; j--) {
                poleBot[i][j] = poleUser[10 - i][10 - j];
                if (i == 0 || j == 0) {
                    poleBot[i][j] = poleUser[i][j];
                }
            }
        }
    }
}



void EasyBot(int& countOfGames, int& countOfWins) {
    fillArray(polePlayer);
    fillArray(player1Shots);
    fillArray(botShots);
    cout << "Player num1 please place ur ship's : " << endl;
    PlaceDestroyers(letterKey, numKey, countOfDestroyShip, polePlayer);
    cout << "Please dont try to place ships there u cant choose way because u need to replace all ships" << endl;
    cruiser(letterKey, numKey, wayKey, countOfCruiseShip, polePlayer, countOfGames, countOfWins);
    submarine(letterKey, numKey, wayKey, countOfSubmarines, polePlayer, countOfGames, countOfWins);
    Battleship(letterKey, numKey, wayKey, countOfBattleShips, polePlayer, countOfGames, countOfWins);
    cout << "Bot is placing ships..." << endl;
    BotPlacing(poleBot , polePlayer);
    while (GameBot(polePlayer, poleBot, player1Shots, botShots, swichSides, countOfMoves, countOfShips1, countOfBotsShip, letterKey, numKey, countOfWins));
    countOfGames++;
    lobby();
}