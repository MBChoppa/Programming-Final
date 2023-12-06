//
// Created by Hale Walls on 12/5/23
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void DepositAccount(string accountinfo[][5], int numAccounts)
{
    cout << "Please enter the account number: ";
    string num;
    int place = -1; //set up for checking validitiy. 
    cin >> num;

    for (int i = 0; i < numAccounts; i++) //checks to see if the inputed number is valid.
    {
        if (accountinfo[i][0] == num)
        {
            place = i;
        }
    }
    if (place == -1)
    {
        cout << "That is not an account that exists." << endl;
        return;
    }
    float deposit = 0.00; //using float because of decimal places.
    cout << "How much money would you like to deposit into the account?" << endl; 
    cin >> deposit; //gets amount.

    if(deposit >= 0) //checks to see if the amount is valid. 
    {
        ofstream fout; 
        fout.open(accountfiles[place]); //opens the file for the account.
        fout << deposit; //deposits the amount into the file.
        fout.close();
        cout << "Depositing $" << deposit << " into that account." << endl; 
    }
    else
    {
        cout << "That is not a valid amount." << endl;
        return;
    }
}
