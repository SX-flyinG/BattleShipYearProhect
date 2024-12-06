
void rules();
void accInfo(); 
void lobby(int& countOfGames , int& countOfWins);
void Tutorial();
void Play(int& countOfGames , int& countOfWins);

void rules() {
	cout << "Battleship Game Rules : " << endl;
	cout << "The objective of the game is to locate and sink all of your opponent's ships before they sink yours. " << endl;

	cout << "Setup : " << endl;
	cout << "Players : Battleship is a game for two players. " << endl;
	cout << "Grid : Each player has two grids : one for placing their own ships, and another for tracking hits and misses on the opponent’s grid.Each grid is typically 10x10 squares, labeled with letters(A - J) for columns and numbers(1 - 10) for rows." << endl;
	cout << "Ships : Each player has a fleet of ships to place on their grid.The typical fleet consists of : " << endl;
	cout << "\t1)Battleship(4 squares)" << endl;
	cout << "\t2)Submarine(3 squares)" << endl;
	cout << "\t3)Cruiser(2 squares)" << endl;
	cout << "\t4)Destroyer(1 squares)" << endl;
	cout << "Placing Ships : " << endl;
	cout << "Ships are placed horizontally or vertically on the grid, not diagonally.Ships cannot overlap and must remain within the boundaries of the grid." << endl;
	cout << "Gameplay : " << endl;
	cout << "Turns : " << endl;
	cout << "Players take turns calling out coordinates(for example, B5) to attack their opponent's grid. " << endl;
	cout << "Hit or Miss :  " << endl;
	cout << "If a player’s shot hits an opponent's ship, the opponent must announce a hit and mark the hit spot on their grid. " << endl;
	cout << "If the shot misses, the opponent announces a miss, and the player marks that spot as missed on their tracking grid. " << endl;
	cout << "Sinking Ships : " << endl;
	cout << "When all squares of a ship are hit, that ship is considered sunk. The player who owns the ship must announce, You sunk my [type of ship]!" << endl;
	cout << "Tracking : " << endl;
	cout << "Each player should track their shots and the opponent's hits to avoid targeting the same spot twice.  " << endl;
	cout << "Winning the Game : " << endl;
	cout << "The first player to sink all of their opponent’s ships wins the game." << endl;
	int choice;
	cout << "Return to lobby : ";
	cin >> choice;
	cin.ignore();
	while (choice != 0) {
		cout << "Return to lobby : ";
		cin >> choice;
		cin.ignore();
	}
	lobby();
}

void accInfo(int& countOfGames , int& countOfWins) {
	char* titul = new char [5];
	cout << "Write titul : ";
	cin.getline(titul, 50);
	string username;
	ifstream outFileName("username.txt");
	getline(outFileName, username);
	outFileName.close();
	cout << "Username :  " << username << endl;
	cout << "Titul : " << titul << endl;
	if (countOfGames != 0){
		cout << "Winrate : " << (countOfWins / countOfGames) * 100 << endl;
	}
	else {
		cout << "Winrate : 0%"  << endl;
	}
	
	
	delete[]titul;
	titul = nullptr;
	lobby();
}

void lobby() {
	int countOfGames = 0 , countOfWins = 0;
	cout << "Hello this a project which realized Ship War with C++" << endl;
	int choice;
	cout << "0  - rules \n1 - acc Info\n2 - Tutorial\n3 - Play 1v1 with friend :";
	cin >> choice;
	cin.ignore();
	if (choice == 0) {
		rules();
	}
	else if (choice == 1) {
		accInfo(countOfGames , countOfWins);
	}
	else if (choice == 2) {
		Tutorial();
	}
	else if (choice == 3) {
		Play(countOfGames , countOfWins);
	}
}
