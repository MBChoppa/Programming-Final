//
// Created by Hale Walls on 12/5/23
//

#include <iostream>
#include <string>
#include <fstream>

#ifndef FILEMANIP_H
#define FILEMANIP_H

const std::string TELLERS = "tellers.dat", ACCOUNTS = "accounts.dat"; //defining file names.

void filemanip(std::string tellerinfo[][2], int numTellers, std::string accountinfo[][5], int numAccounts);

#endif //FILEMANIP_H
