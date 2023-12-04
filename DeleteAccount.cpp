//
// Created by Evan Crabtree on 11/29/23.
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void delete_account() {
    string accounts = "accounts.dat";
    string accountNumber;
    char answer;
    string current;
    fstream fin(accounts);
    bool deleteNext = false;

    if (!fin.is_open()) {
        cout << "Accounts.dat does not exist";
        return;
    }
    ofstream fout("temp.dat");

    cout << "Enter account number to be deleted" << endl;
    cin >> accountNumber;
    cout << "Are you sure you want to delete the account " << accountNumber << "?" << endl;
    cout << "1: Yes" << endl;
    cout << "2: No" << endl;
    cin >> answer;

    switch (answer) {
        case '1': {
            int counter = 0;
            while (std::getline(fin, current)){
                int deleteLine = 0;
                if (current == accountNumber) {
                    deleteNext = true;
                }
            if (!deleteNext) {
                fout << current << endl;
            } else {
                deleteLine++;
            }
        }

            cout << "Account deleted." << endl;
            break;
    }

            case '2': {
                cout << "Canceling." << endl;
                break;
            }
            default:
            {
                cout << "That is not a valid input." << endl;
                break;
            }
        }
        fin.close();
        fout.close();
        std::remove("accounts.dat");
        std::rename("temp.dat", "accounts.dat");
    }

