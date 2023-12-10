/*
Written by Hale Walls on 12/5/23
Pre: there is an amount of money in the account.
Post: there is a larger amount of money in the account based on the previous balance + the balance the teller is depositing. 
Purpose: Allows the teller to put a certain amount of money into the account.
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void DepositAccount(string accountinfo[][5], string accountfiles[], int numAccounts)
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
    float deposit = 0.00, balance; //using float because of decimal places.
    cout << "How much money would you like to deposit into the account?" << endl;
    cin >> deposit; //gets amount.

    if(deposit >= 0) //checks to see if the amount is valid.
    {
        ifstream fin;
        fin.open("data/"+num+".dat");
        fin >> balance; //gets balance from file.
        fin.close();
        balance += deposit; //adds new amount to the balance in the file.

        ofstream fout;
        fout.open("data/"+num+".dat"); //opens the file for the account.
        fout << fixed << setprecision(2) << balance; //deposits the amount into the file.
        fout.close();
        cout << "Depositing $" << fixed << setprecision(2) <<deposit << " into that account." << endl;
        cout << "The current balance in the account is " << balance << endl;
        // ifstream fin;
        fin.open("data/"+num+".dat"); //opens the file for the account.
        fin >> balance;
        fin.close();
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
    }
    else
    {
        cout << "That is not a valid amount." << endl;
        return;
    }
}
