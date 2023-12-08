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

void filemanip(string tellerinfo[][2], int numTellers, string accountinfo[][5], string accountfiles[], int numAccounts)
{
    int count = 0;
    ifstream fin;
    fin.open("data/tellers.dat"); //opens tellers.dat
    while (fin >> tellerinfo[count][0]) //reads teller information from file.
    {
        fin >> tellerinfo[count][1];
        count++;
    }
    fin.close();
    count = 0;

    string suffix = ".dat", prefix = "data/";
    fin.open("data/accounts.dat"); //opens accounts.dat
    while (fin >> accountinfo[count][0]) //reads account information from file.
    {
        string junk;
        fin >> accountinfo[count][1];
        getline(fin, junk);
        getline(fin, accountinfo[count][2]);
        getline(fin, accountinfo[count][3]);
        getline(fin, accountinfo[count][4]);

        accountfiles[count] = prefix + accountinfo[count][0];
        accountfiles[count] = accountinfo[count][0] + suffix;

        count++;
    }
    fin.close();
    string value = "";
    for(int i = 0; i < numAccounts; i++)
    {
        ifstream fin;
        fin.open(accountfiles[i]);
        if(!fin.is_open()) 
        {

        }
        else
        {
            fin >> value;
            if (value == "") {
                ofstream fout;
                fout.open(accountfiles[i]);
                fout << "0.00";
                fout.close();
                value = "";
                fin.close();
            }
        }
    }
}
