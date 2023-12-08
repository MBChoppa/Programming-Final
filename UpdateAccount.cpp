//
// Created by Evan Crabtree on 11/29/23.
//
//Pre statement : Each account has pre-set account numbers, social security numbers, names, phone numbers, and addresses
//
//Purpose statement : The teller can update an accounts social security number, name, address, and phone number

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void update_account() {

    char selection; // declare variables
    string replace;
    string current;
    string accounts = "data/accounts.dat";
    string ssReplace(11, ' ');
    bool changeNext = false;
    bool changeNext2 = false;
    bool changeNext3 = false;
    bool changeNext4 = false;

    fstream fin(accounts); // Open accounts.dat to be read
    if (!fin.is_open()) {
        cout << "Accounts.dat does not exist" << endl; // Informs the user if accounts.dat doesn't exist
    } else {
        ofstream temp("data/temp.dat"); // If accounts.dat exists creates a new file "temp.dat" that can be written to
        string accountNumber;
        cout << "Enter the 5-digit account number you would like to search for: "
             << endl; // Asks the user what account will be updated
        cin >> accountNumber;
        cout << "What account information would you like to update?" << endl; // Asks what account information will be updated
        cout << "1. Social Security Number" << endl;
        cout << "2. Name" << endl;
        cout << "3. Address" << endl;
        cout << "4. Phone number" << endl;
        cin >> selection; // User inputs their selection of what information to update

        switch (selection) { // Determines what to update based on users input
            case '1': {
                cout << "Enter new social security number" << endl; // Asks the user for new SS Number input
                cin >> replace;
                if (replace.length() !=
                    9) { // this ensures that the social security number is 9 digits long and user didn't cancel
                    cout << "That is not a valid social security number" << endl;
                    update_account(); // Restarts the function if input SS number is not valid
                    return; // Ends function after user completes rerun of function
                } else { // if the user inputs a valid social security number, this formats it as xxx-xx-xxxx
                    int ssValue = 0;
                    for (int total = 0; total < 11; total++) { // Counts how many digits in the SS number have been declared
                        char ssCurrent = replace[ssValue];
                        if (total == 3 || total == 6) { // If current place in the SS number is 4 or 7, inputs '-'
                            ssReplace[total] = '-';
                        } else { // All digits in the SS number that are not the 4th or 7th become the necessary numbers
                            ssReplace[total] = ssCurrent;
                            ssValue = ssValue + 1;
                        }
                    }
                            while (std::getline(fin, current)) {
                                if (changeNext) {
                                    temp << ssReplace << endl;
                                    changeNext = false;
                                } else if (current !=
                                           accountNumber) { // Outputs the current line from accounts.dat to temp.dat if
                                    temp << current << endl; // the input account number does not equal the current line
                                } else if (current ==
                                           accountNumber) { // If the input account number is found, outputs current line
                                    temp << current << endl; // to temp.dat and marks changeNext as true
                                    changeNext = true;
                                }
                            }
                    break;
                }
                        case '2': {
                            cout << "Enter new account holder name: " << endl;
                            cin.ignore();
                            getline(cin, replace);
                            while (std::getline(fin, current)) {
                                if (changeNext2) {
                                    temp << replace << endl;
                                    changeNext = false;
                                    changeNext2 = false;
                                } else if (changeNext) {
                                    temp << current << endl;
                                    changeNext2 = true;
                                } else if (current != accountNumber) {
                                    temp << current << endl;
                                } else if (current == accountNumber) {
                                    temp << current << endl;
                                    changeNext = true;
                                }
                            }
                            break;
                        }
                    }
                case '3': {
                    cout << "Enter new address: " << endl;
                    cin.ignore();
                    getline(cin, replace);
                    while (std::getline(fin, current)) {
                        if (changeNext3) {
                            temp << replace << endl;
                            changeNext3 = false;
                        } else if (changeNext2) {
                            temp << current << endl;
                            changeNext3 = true;
                            changeNext2 = false;
                        } else if (changeNext) {
                            temp << current << endl;
                            changeNext2 = true;
                            changeNext = false;
                        } else if (current != accountNumber) {
                            temp << current << endl;
                        } else if (current == accountNumber) {
                            temp << current << endl;
                            changeNext = true;
                        }
                    }
                    break;
                }
                case '4': {
                    cout << "Enter new phone number: " << endl;
                    cin.ignore();
                    getline(cin, replace);
                    while (std::getline(fin, current)) {
                        if (changeNext4) {
                            temp << replace << endl;
                            changeNext4 = false;
                        } else if (changeNext3) {
                            temp << current << endl;
                            changeNext4 = true;
                            changeNext3 = false;
                        } else if (changeNext2) {
                            temp << current << endl;
                            changeNext3 = true;
                            changeNext2 = false;
                        } else if (changeNext) {
                            temp << current << endl;
                            changeNext2 = true;
                            changeNext = false;
                        } else if (current != accountNumber) {
                            temp << current << endl;
                        } else if (current == accountNumber) {
                            temp << current << endl;
                            changeNext = true;
                        }
                    }
                    break;
                }
                default: {
                    cout << "That is not a valid input." << endl;
                    fin.close();
                    temp.close();
                    std::remove("temp.dat");
                    return;
                }
            }
                std::remove("data/accounts.dat");
                std::rename("data/temp.dat", "data/accounts.dat");
                fin.close();
                temp.close();
        }
    }
// Post statement : Updates a piece of information related to a pre-existing account
