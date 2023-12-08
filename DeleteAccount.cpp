//
// Created by Evan Crabtree on 11/29/23.
//
// Pre statement : There are a number of accounts in accounts.dat
//
// Purpose statement : The teller chooses an account to be deleted from accounts.dat

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void delete_account() {
    const string data = "data/"; // Variable declaration
    const string dat = ".dat";
    string accounts = "data/accounts.dat";
    string accountNumber;
    char answer;
    string current;
    bool deleteNext = false;
    bool deleted = false;

    fstream fin(accounts); // Open the file accounts.dat to be read

    if (!fin.is_open()) { // If accounts.dat is not found, tell the user and end the function
        cout << "Accounts.dat does not exist" << endl;
        return;
    }
    ofstream fout("data/temp.dat"); // Create the file temp.dat to write information to

    cout << "Enter account number to be deleted" << endl; // Ask user what account to delete
    cin >> accountNumber;
    const string accountData = data + accountNumber + dat; // create string for .dat file to delete


    cout << "Are you sure you want to delete the account " << accountNumber << "?" << endl; // Ask user to confirm deletion
    cout << "1: Yes" << endl;
    cout << "2: No" << endl;
    cin >> answer;

    switch (answer) {
        case '1': // If user is sure, begins account deletion
        {
            while (std::getline(fin, current)) { // Reads current line from accounts.dat
                if (current == accountNumber) { // If the current line is the account number, marks next lines for deletion
                    deleteNext = true;
                }
                if (!deleteNext) { // If the line isn't marked for deletion, copies current line to temp.dat
                    fout << current << endl;
                }
                else {
                    for(int i=0;i<4;i++) { // Does not copy next 4 lines if marked for deletion
                        std::getline(fin, current);
                        deleteNext = false; // Stops future lines from being deleted once current deletion finishes
                    }
                }
            }

            cout << "Account deleted." << endl; // Inform user that the account was successfully deleted
            deleted = true; // Remembers that an account is deleted for later
            break;
    }

            case '2': { // End deletion if user inputs '2' when prompted, ends the function
                cout << "Canceling." << endl;
                return;
            }
            default: // Informs the user that their input is invalid if neither '1' nor '2' is entered
            {
                cout << "That is not a valid input." << endl;
                break;
            }
        }
        fin.close(); // Close accounts.dat
        fout.close(); // Close temp.dat
        if (deleted) { // Makes sure an account has been deleted before deleting the original accounts.dat
            std::remove("data/accounts.dat"); // Delete accounts.dat
            std::remove(accountData.c_str());
            std::rename("data/temp.dat", "data/accounts.dat"); // Rename temp.dat to accounts.dat with account removed
        }
        else{ // If no account was deleted, only deletes temp.dat
            std::remove("data/temp.dat");
        }
    }

    // Post statement : An existing account has been deleted and no longer exists
