/*
Writeen by Hale Walls on 12/5/23
Pre: There is an ammount in the account number file. 
Post: The amount in the account is changed based on (previous amount - amount teller is taking out). 
Purpose: Allows tellers to take money out of their account.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void WithdrawAccount(string accountinfo[][5], string accountfiles[], int numAccounts)
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
    float balance, withdraw; //defining variables.
    ifstream fin;
    fin.open(accountfiles[place]); //opens the account file.
    fin >> balance; //gets the balance from the account file.
    fin.close();
    cout << "That account has $" << balance << " in it.  How much would you like to withdraw?" << endl; //prompts the user for how much they want to withdraw.
    cin >> withdraw; //get withdraw amount.
    if (withdraw > balance || withdraw < 0) //checks to see if the amount is valid.
    {
        cout << "That is not a valid amount." << endl;
        return;
    }
    else
    {
        balance -= withdraw; //subtracts the withdraw amount from the existing balance.
        ofstream fout;
        fout.open(accountfiles[place]); //reopens the account file.
        fout << balance; //writes the new balance.
        fout.close();
        cout << "$" << withdraw << " has been withdrawn.  The current balance for this account is $" << balance << "." << endl; //tells user new balance.
    }
}
