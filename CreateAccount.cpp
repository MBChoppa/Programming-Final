//
// Created by Evan Crabtree on 11/29/23.
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void create_account() //create_account function made by evan
{
    string ssNumber;
    string ssDashes(11, ' ');
    string accounts = "accounts.dat";
    string name;
    string address;
    string phoneNumber;
    string phoneDashes;
    int accountNumber;

    fstream fout(accounts, std::ios::app); // this opens the file accounts.dat in append mode

    if (!fout.is_open()) { // if the file accounts.dat can't be found, it informs the user and ends the function
        cout << "Accounts.dat does not exist";
    }
    else { // if the file does exist it begins asking the user for the new account's details
        cout << "Enter account holder social security number (9-digits with no dashes): " << endl;
        cin >> ssNumber;
        if (ssNumber.length() != 9) { // this ensures that the social security number is 9 digits long
            cout << "That is not a valid social security number" << endl;
        }
        else { // if the user inputs a valid social security number, this formats it as xxx-xx-xxxx
            int ssValue = 0;
            for (int total = 0; total < 11; total++) {
                char ssCurrent = ssNumber[ssValue];
                if (total == 3 || total == 6) {
                    ssDashes[total] = '-';
                }
                else {
                        ssDashes[total] = ssCurrent;
                        ssValue = ssValue + 1;
                    }
                }
            }
        }

        cout << "Enter account holder name:" << endl;
        cin >> name;
        cout << "Enter account holder address: " << endl;
        cin >> address;
        cout << "Enter account holder phone number: " << endl;
        cin >> phoneNumber;
        if (ssNumber.length() != 9) { // this ensures that the social security number is 9 digits long
            cout << "That is not a valid social security number";
        }
        else { // if the user inputs a valid phone number, this formats it as xxx-xxx-xxxx
             int phoneValue = 0;
        for (int total = 0; total < 12; total++) {
            char phoneCurrent = phoneNumber[phoneValue];
            if (total == 4 || total == 8) {
                phoneDashes[total] = '-';
            }
            else {
                phoneDashes[total] = phoneCurrent;
                phoneValue = phoneValue + 1;
            }
        }
    }
        cout << phoneDashes << "Enter a new account number: " << endl;
        cin >> accountNumber;
        cout << "Creating new account" << endl;
        fout << accountNumber << endl;
        fout << ssDashes << endl;
        fout << name << endl;
        fout << address << endl;
        fout << phoneNumber;
        fout.close();
    }
