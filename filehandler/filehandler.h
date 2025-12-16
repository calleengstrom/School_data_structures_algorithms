#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include "../include/main.h"


void findAndWriteToFile(std::string &accountNo);
void writeTofile(const std::string& file, const std::string& accountNo);
std::string readFile(std::string file, std::string &accountNo);
std::string returnAccountNumber(std::string &accountNo);
#endif