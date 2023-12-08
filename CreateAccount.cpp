//
// Created by Evan Crabtree on 11/29/23
//
// Pre statement : There are a number of accounts in accounts.dat
//
// Purpose statement : Create a new account based on the information input by the teller

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void create_account() //create_account function made by evan
{
    string ssNumber; // Variable declaration
    string ssDashes(11, ' ');
    string accounts = "data/accounts.dat";
    string name;
    string address;
    string phoneNumber;
    string accountNumber;
    float newBalance = 0.00;

    ofstream fout(accounts, std::ios::app); // this opens the file accounts.dat in append mode

    if (!fout.is_open()) { // if the file accounts.dat can't be found, it informs the user and ends the function
        cout << "Accounts.dat does not exist" << endl;
        return;
    }
    else { // if the file does exist it begins asking the user for the new account's details
        cout << "Enter account holder social security number (9-digits with no dashes) - enter '2' to cancel " << endl;
        cin >> ssNumber; // Receive SS number input
        if (ssNumber.length() != 9 && ssNumber != "2") { // this ensures that the social security number is 9 digits long and user didn't cancel
            cout << "That is not a valid social security number" << endl;
            create_account(); // Restarts the function if input SS number is not valid
            return; // Ends function after user completes rerun of function
        }
        else if (ssNumber == "2"){ // Cancels account creation if user inputs 2
            cout << "canceling" << endl;
            return; // Quit account creation script and return to main.cpp
        }
        else { // if the user inputs a valid social security number, this formats it as xxx-xx-xxxx
            int ssValue = 0;
            for (int total = 0; total < 11; total++) { // Counts how many digits in the SS number have been declared
                char ssCurrent = ssNumber[ssValue];
                if (total == 3 || total == 6) { // If current place in the SS number is 4 or 7, inputs '-'
                    ssDashes[total] = '-';
                }
                else { // All digits in the SS number that are not the 4th or 7th become the necessary numbers
                    ssDashes[total] = ssCurrent;
                    ssValue = ssValue + 1;
                }
            }
        }
    }

    cout << "Enter account holder name: " << endl; // Ask user to input account holder name
    std::getline(cin >> ws, name); // Receive account holder name input

    cout << "Enter account holder address: " << endl; // Ask user to input account holder address
    std::getline(cin >> ws, address); // Receive account holder address input

    cout << "Enter account holder phone number: "<< endl;// Ask user to input account holder phone number
    std::getline(cin >> ws, phoneNumber); // Receive account holder phone number input

    cout << "Enter a new account number: " << endl; // Ask user to input account number
    cin >> accountNumber; // Receive account number input

    cout << "Creating new account" << endl; // Tell user account is being created

    fout << accountNumber << endl; // Write new account information to accounts.dat
    fout << ssDashes << endl;
    fout << name << endl;
    fout << address << endl;
    fout << phoneNumber << endl;

    fout.close(); // Close accounts.dat

    std::ofstream out("data/"+accountNumber+".dat"); // Creates a .dat file using the new account number
    out << fixed << setprecision(2) << newBalance; // Writes a balance of 0.00 to the new accounts balance file
    out.close(); // Close the new accounts balance file


}

// Post statement : A new account has been added to accounts.dat
