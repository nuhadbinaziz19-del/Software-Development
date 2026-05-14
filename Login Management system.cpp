#include <iostream>
#include <fstream>
using namespace std;
class temp {
    string UserName, Email, Password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void Login();
    void SingUp();
    void Forgot();
} obj;
int main() {
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case '1':
        obj.Login();
        break;
    case '2':
        obj.SingUp();
        break;
    case '3':
        obj.Forgot();
        break;
    case '4':
        return 0;
    default:
        cout << "Invalid Selection....!!";
    }
}
void temp::SingUp() {
    cout << "\nEnter Your User Name: ";
    getline(cin, UserName);
    cout << "\nEnter Your Email Address: ";
    getline(cin, Email);
    cout << "\nEnter Your Password: ";
    getline(cin, Password);
    file.open("LoginData.txt", ios::out | ios::app);
    file << UserName << "*" << Email << "*" << Password << endl;
    file.close();
    cout << "\nAccount Created Successfully!\n";
}
void temp::Login() {
    cout << "\n-------LOGIN--------\n";
    cout << "Enter Your User Name: ";
    getline(cin, searchName);
    cout << "Enter Your Password: ";
    getline(cin, searchPass);
    file.open("LoginData.txt", ios::in);
    getline(file, UserName, '*');
    getline(file, Email, '*');
    getline(file, Password, '\n');
    while (!file.eof()) {
        if (UserName == searchName) {
            if (Password == searchPass) {
                cout << "\nLogin Successful!\n";
                cout << "Username: " << UserName << endl;
                cout << "Email: " << Email << endl;
                return;
            }
            else {
                cout << "Incorrect Password!\n";
                return;
            }
        }
        getline(file, UserName, '*');
        getline(file, Email, '*');
        getline(file, Password, '\n');
    }
    cout << "User Not Found!\n";
    file.close();
}

void temp::Forgot() {
    cout << "\nEnter Your UserName: ";
    getline(cin, searchName);
    cout << "Enter Your Email Address: ";
    getline(cin, searchEmail);
    file.open("LoginData.txt", ios::in);
    getline(file, UserName, '*');
    getline(file, Email, '*');
    getline(file, Password, '\n');
    while (!file.eof()) {
        if (UserName == searchName && Email == searchEmail) {
            cout << "\nAccount Found!\n";
            cout << "Your Password: " << Password << endl;
            return;
        }
        getline(file, UserName, '*');
        getline(file, Email, '*');
        getline(file, Password, '\n');
    }
    cout << "Account Not Found!\n";
    file.close();
}
