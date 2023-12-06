//
// Created by Hale Walls on 12/5/23
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void SearchAccount(string accountinfo[][5], int numAccounts)
{
    cout << "Please enter the account number." << endl; //account number is the name of the file it will be drawn from.
    string num;
    int place = -1; //set up for checking validitiy. 
    cin >> num;

    for (int i = 0; i < 19; i++) //checks to see if the inputed number is valid.
    {
        if (accountinfo[i][0] == num)
        {
            place = i;
        }
    }
    if (place == -1)
    {
        cout << "That is not an account that exists." << endl;
        break;
    }
    cout << "Here is the information for account number " << accountinfo[place][0] << endl; //prints the account information.
    cout << "Social Security Number: " << accountinfo[place][1] << endl;
    cout << "Name: " << accountinfo[place][2] << endl;
    cout << "Address: " << accountinfo[place][3] << endl;
    cout << "Phone Number: " << accountinfo[place][4] << endl;
}
