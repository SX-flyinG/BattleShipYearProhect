#pragma once

void fillPlayerArr(char field[6][6]);
void WritePlayerField(const char field[6][6]);
void PlaceDestroyers(int destroyer, int letterKey, int numKey , char field[6][6]);
void PlaceDestroyersBot(int destroyer, char field[6][6]);
void PlayerMove(char field[6][6], char field2[6][6], int& countOfMoves, int& botDestroyers, char viewField[6][6], int& letterKey, int& numKey);
void BotMove(char field[6][6], int& countOfMoves, int& playerDestroyers);
bool GameMode(char field[6][6], char field2[6][6], int& countOfMoves, int& playerDestroyers, int& botDestroyers, char viewField[6][6], int letterKey, int numKey);
void WriteRow(int& letterKey);
void WriteColumn(int& numKey);
void Tutorial();

void fillPlayerArr(char field[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			field[i][j] = '.';
			if (i == 0 && j != 0) {
				field[i][j] = char(47 + j);
			}
			if (j == 0 && i != 0) {
				field[i][j] = char(65 + i - 1);
			}
			if (i == 0 && j == 0) {
				field[i][j] = 'X';
			}
		}
	}
}

void WritePlayerField(const char field[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

void PlaceDestroyers(int destroyer, int letterKey, int numKey, char field[6][6]) {
	cout << "Place ur destroyer's ships : " << endl;
	for (destroyer; destroyer > 0; destroyer--) {
		WriteRow(letterKey);
		WriteColumn(numKey);

		while (field[letterKey][numKey] != '.') {
			cout << "\nThis position is already occupied, please choose another.\n";
			WriteRow(letterKey);
			WriteColumn(numKey);
		}

		field[letterKey][numKey] = 'D';

		WritePlayerField(field);
	}
}

void PlaceDestroyersBot(int destroyer, char field[6][6]) {
	while (destroyer > 0) {
		int x = rand() % 5 + 1;
		int y = rand() % 5 + 1;

		if (field[x][y] == '.') {
			field[x][y] = 'D';
			destroyer--;
		}
	}
}

void PlayerMove(char field[6][6], char field2[6][6], int& countOfMoves, int& botDestroyers, char viewField[6][6], int& letterKey, int& numKey) {
	WriteRow(letterKey);
	WriteColumn(numKey);

	if (field2[letterKey][numKey] == 'D') {
		field2[letterKey][numKey] = 'X';
		viewField[letterKey][numKey] = 'X';
		cout << "Hit!" << endl;
		botDestroyers--;
	}
	else if (field2[letterKey][numKey] == '.') {
		field2[letterKey][numKey] = '0';
		viewField[letterKey][numKey] = '0';
		cout << "Miss!" << endl;
		countOfMoves++;
	}
	else {
		cout << "You already attacked this position. Try again." << endl;
	}


	cout << "Your field:" << endl;
	WritePlayerField(field);
	cout << "Bot's field : " << endl;
	WritePlayerField(viewField);
}

void BotMove(char field[6][6], int& countOfMoves, int& playerDestroyers) {
	int x, y;

	do {
		x = rand() % 5 + 1;
		y = rand() % 5 + 1;
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

bool GameMode(char field[6][6], char field2[6][6], int& countOfMoves, int& playerDestroyers, int& botDestroyers, char viewField[6][6], int letterKey, int numKey) {
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
		PlayerMove(field, field2, countOfMoves, botDestroyers, viewField, letterKey, numKey);
	}
	else {
		cout << "Bot's move:" << endl;
		BotMove(field, countOfMoves, playerDestroyers);
	}
	return true;
}

void WriteRow(int& letterKey) {
	do {
		cout << "\nWrite a row (A - E or a - e): \n";
		letterKey = _getch();
		cout << (char)letterKey << "\n";
	} while ((letterKey < 65 || letterKey > 74) && (letterKey < 97 || letterKey > 106));

	switch (letterKey) {
	case 65:
	case 97:
		letterKey = 1;
		break;
	case 66:
	case 98:
		letterKey = 2;
		break;
	case 67:
	case 99:
		letterKey = 3;
		break;
	case 68:
	case 100:
		letterKey = 4;
		break;
	case 69:
	case 101:
		letterKey = 5;
		break;
	default:
		break;
	}
}

void WriteColumn(int& numKey) {
	do {
		cout << "\nWrite a column (0 - 4): ";
		numKey = _getch();
		cout << (char)numKey << "\n";
	} while (numKey < 48 || numKey > 57);

	switch (numKey) {
	case 48:
		numKey = 1;
		break;
	case 49:
		numKey = 2;
		break;
	case 50:
		numKey = 3;
		break;
	case 51:
		numKey = 4;
		break;
	case 52:
		numKey = 5;
		break;
	default:
		break;
	}
}

void Tutorial() {
	srand(time(NULL));
	char playerField[6][6], botField[6][6], viewField[6][6];
	int letterKey = 0;
	int numKey = 0;
	fillPlayerArr(playerField);
	fillPlayerArr(botField);
	fillPlayerArr(viewField);

	cout << "Welcome to Battleship Tutorial! First of all place your ships:" << endl;
	PlaceDestroyers(5, letterKey, numKey, playerField);

	cout << "Bot is placing ships..." << endl;
	PlaceDestroyersBot(5, botField);

	int countOfMoves = 0, playerDestroyers = 5, botDestroyers = 5;

	while (GameMode(playerField, botField, countOfMoves, playerDestroyers, botDestroyers, viewField, letterKey, numKey));

	cout << "U end with tutorial , GG" << endl;

	lobby();
}
