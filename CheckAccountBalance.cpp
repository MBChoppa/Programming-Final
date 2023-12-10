/*
Written by Hale Walls on 12/5/23
Pre: the account balance is not being displayed.
Post: the account balance has been displayed. 
Purpose: To display the information of account balance to the teller.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void CheckAccountBalance(string accountinfo[][5], string accountfiles[], int numAccounts)
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
    float balance;
    ifstream fin;
    fin.open(accountfiles[place]); //opens the account file.
    fin >> balance; //gets the balance number.
    fin.close();
    cout << "The balance for that account is $" << balance << "." << endl; //prints the balance currently in the account.

}
