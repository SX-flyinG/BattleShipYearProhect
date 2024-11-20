
void registration(char* username, char* password);
int reg(char* username, char* password);


int reg(char* username, char* password) {
    int choice;

    cout << "Write a num of move :\n0 - Exit;\n1 - Registration;\n";
    cin >> choice;
    cin.ignore();

    while (choice < 0 || choice > 2) {
        cout << "Write a valid num of move: ";
        cin >> choice;
        cin.ignore();
    }

    if (choice == 0) {
        delete[] username;
        delete[] password;
        cout << "Goodbye!" << endl;
        return 0;
    }
    else if (choice == 1) {
        registration(username, password);
    }

    delete[] username;
    delete[] password;

    return 0;
}

void registration(char* username, char* password) {
    cout << "Write your nickname (max 16 letters and no space): ";
    cin.getline(username, 16);
    ofstream inFileName("username.txt");
    inFileName << username;
    inFileName.close();

    cout << "Write your password (max 64 letters and no space): ";
    cin.getline(password, 64);
    ofstream inFilePass("password.txt");
    inFilePass << password;
    inFilePass.close();

    lobby();
}

