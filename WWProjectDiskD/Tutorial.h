#pragma once

void fillPlayerArr(char field[5][5]);
void WritePlayerField(const char field[5][5]);
void PlaceDestroyers(int destroyer, char field[5][5]);
void PlaceDestroyersBot(int destroyer, char field[5][5]);
void PlayerMove(char field[5][5], char field2[5][5], int& countOfMoves, int& botDestroyers);
void BotMove(char field[5][5], int& countOfMoves, int& playerDestroyers);
bool GameMode(char field[5][5], char field2[5][5], int& countOfMoves, int& playerDestroyers, int& botDestroyers);
void Tutorial();

void fillPlayerArr(char field[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            field[i][j] = '.';
        }
    }
}

void WritePlayerField(const char field[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void PlaceDestroyers(int destroyer, char field[5][5]) {
    int x, y;
    cout << "Place your destroyers:" << endl;

    while (destroyer > 0) {
        cout << "Enter row (0-4): ";
        cin >> x;
        cout << "Enter column (0-4): ";
        cin >> y;

        if (x >= 0 && x < 5 && y >= 0 && y < 5 && field[x][y] == '.') {
            field[x][y] = 'D';
            destroyer--;
            WritePlayerField(field);
        }
        else {
            cout << "Invalid position. Try again." << endl;
        }
    }
}

void PlaceDestroyersBot(int destroyer, char field[5][5]) {
    while (destroyer > 0) {
        int x = rand() % 5;
        int y = rand() % 5;

        if (field[x][y] == '.') {
            field[x][y] = 'D';
            destroyer--;
        }
    }
}

void PlayerMove(char field[5][5], char field2[5][5], int& countOfMoves, int& botDestroyers, char viewField[5][5]) {
    int x, y;
    cout << "Enter row (0-4): ";
    cin >> x;
    cout << "Enter column (0-4): ";
    cin >> y;

    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        if (field2[x][y] == 'D') {
            field2[x][y] = 'X';
            viewField[x][y] = 'X';
            cout << "Hit!" << endl;
            botDestroyers--;
        }
        else if (field2[x][y] == '.') {
            field2[x][y] = '0';
            viewField[x][y] = '0';
            cout << "Miss!" << endl;
            countOfMoves++;
        }
        else {
            cout << "You already attacked this position. Try again." << endl;
        }
    }
    else {
        cout << "Invalid coordinates. Try again." << endl;
    }

    cout << "Your field:" << endl;
    WritePlayerField(field);
    cout << "Bot's field : " << endl;
    WritePlayerField(viewField);
}

void BotMove(char field[5][5], int& countOfMoves, int& playerDestroyers) {
    int x, y;

    do {
        x = rand() % 5;
        y = rand() % 5;
    } while (field[x][y] == 'X' || field[x][y] == '0');

    if (field[x][y] == 'D') {
        field[x][y] = 'X';
        cout << "Bot hit your ship at (" << x << ", " << y << ")!" << endl;
        playerDestroyers--;
    }
    else {
        field[x][y] = '0';
        cout << "Bot missed!" << endl;
        countOfMoves++;
    }

    cout << "Your field after bot's move:" << endl;
    WritePlayerField(field);
}

bool GameMode(char field[5][5], char field2[5][5], int& countOfMoves, int& playerDestroyers, int& botDestroyers, char viewField[5][5]) {
    if (playerDestroyers == 0) {
        cout << "Bot wins the game!!!" << endl;
        return false;
    }
    if (botDestroyers == 0) {
        cout << "You win the game!!!" << endl;
        return false;
    }
    if (countOfMoves % 2 == 0) {
        cout << "Your move:" << endl;
        PlayerMove(field, field2, countOfMoves, botDestroyers, viewField);
    }
    else {
        cout << "Bot's move:" << endl;
        BotMove(field, countOfMoves, playerDestroyers);
    }
    return true;
}

void Tutorial() {
    srand(time(NULL));
    char playerField[5][5], botField[5][5], viewField[5][5];
    fillPlayerArr(playerField);
    fillPlayerArr(botField);
    fillPlayerArr(viewField);

    cout << "Welcome to Battleship Tutorial! First of all place your ships:" << endl;
    PlaceDestroyers(5, playerField);

    cout << "Bot is placing ships..." << endl;
    PlaceDestroyersBot(5, botField);

    int countOfMoves = 0, playerDestroyers = 5, botDestroyers = 5;

    while (GameMode(playerField, botField, countOfMoves, playerDestroyers, botDestroyers, viewField));

    cout << "U end with tutorial , GG" << endl;

    lobby();
}
