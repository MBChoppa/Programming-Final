/*
Written By Hale Walls
Pre: All the information is on the file. 
Post: All the information is stored in Arrays. 
Purpose: To read all of the information from the files. 
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void filemanip(string tellerinfo[][2], int numTellers, string accountinfo[][5], int numAccounts)
{
    int count = 0;
    ifstream fin;
    fin.open(TELLERS); //opens tellers.dat
    while (fin >> tellerinfo[count][0]) //reads teller information from file.
    {
        fin >> tellerinfo[count][1];
        count++;
    }
    fin.close();
    count = 0;

    string suffix = ".dat";
    fin.open(ACCOUNTS); //opens accounts.dat
    while (fin >> accountinfo[count][0]) //reads account information from file.
    {
        string junk;
        fin >> accountinfo[count][1];
        getline(fin, junk);
        getline(fin, accountinfo[count][2]);
        getline(fin, accountinfo[count][3]);
        getline(fin, accountinfo[count][4]);

        accountfiles[count] = accountinfo[count][0] + suffix;
        ofstream fout;
        fout.open(accountfiles[count]);
        fout << "0.00";
        fout.close();

        count++;
    }
}
