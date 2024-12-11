// Off the problem with placement of functions
void registration(char* username, char* password);
int reg(char* username, char* password);
void LogIn(char* username, char* password);


/*function of start program where user can leave , register or log in his accaunt  */
int reg(char* username, char* password) {
    int choice;

    cout << "Write a num of move :\n0 - Exit;\n1 - Registration;\n2 - Log in;\n ";
    cout << "LOG IN DON'T WORK !!!!!" << endl;
    cin >> choice;
    cin.ignore();

    while (choice < 0 || choice > 2) {
        cout << "Write a valid num of move: ";
        cin >> choice;
        cin.ignore();
    }

    if (choice == 0) {
        // delete dynamic's values and close programm
        delete[] username;
        delete[] password;
        cout << "Goodbye!" << endl;
        return 0;
    }
    else if (choice == 1) {
        registration(username, password);
    }
    else if (choice == 2) {
        LogIn(username, password);
    }

    // delete dynamic values
    delete[] username;
    delete[] password;

    return 0;
}

/*Function in which user registrate
He need to write username and password
After that user goes to main lobby of program*/
void registration(char* username, char* password) {
    cout << "Write your nickname (max 16 letters and no space): ";
    cin.getline(username, 16);
    //Write in txt file an username of the user
    ofstream inFileName("username.txt");
    inFileName << username;
    inFileName.close();

    cout << "Write your password (max 64 letters and no space): ";
    cin.getline(password, 64);
    //Write in txt file a password which user wrote
    ofstream inFilePass("password.txt");
    inFilePass << password;
    inFilePass.close();
    
    // delete all history of matches because its registration and we have a new user
    ofstream inHistoryOfMatches("history.txt");
    inHistoryOfMatches << " ";
    inHistoryOfMatches.close();

    //Go to main lobby
    lobby();
}

/*Function to log in acc by username and password
If u write wrong username or password program dont go to next*/
void LogIn(char* username, char* password) {
    int choose;
    cout << "Write your nickname (max 16 letters and no space): ";
    cin.getline(username, 16);
    string user ;
    ifstream outFileName("username.txt");
    getline(outFileName, user);
    outFileName.close();
    cout << "Write your password (max 64 letters and no space): ";
    cin.getline(password, 64);
    string pass;
    ifstream outFilePass("username.txt");
    getline(outFilePass, pass);
    outFilePass.close();
    if (username == user) {
        cout << "Good";
    }
    if (password == pass) {
        cout << "Good pass";
    }
    else {
        cout << "U write incorect username or password , do u want to try again? [0 - no ; 1 - yes]";
        cin >> choose;
        cin.ignore();
        if (choose == 0) {
            cout << "Goodbye!";
        }
        else {
            LogIn(username, password);
        }
    }
}

