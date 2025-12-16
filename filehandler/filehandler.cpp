#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>
#include <fstream>
#include <string.h>
#include <string>
#include "../include/main.h"

void writeTofile(const std::string &file, const std::string &accountNo)
{
    std::ofstream outFile;

    outFile.open(file, std::ios::app);

    outFile << accountNo << std::endl;

    outFile.close();
}

std::vector<BankAccount> readFile(std::string file, std::string &accountNo,std::vector<BankAccount> &account)
{
    std::ifstream inFile;
    inFile.open(file, std::ios::in);
    std::string line;
    std::vector<BankAccount> temp;
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            temp.push_back(BankAccount(line));

        }
    }
}

void findAndWriteToFile(std::string &accountNo)
{

    switch (accountNo[0])
    {
    case '1':
        writeTofile("doc1.txt", accountNo);
        break;

    case '2':
        writeTofile("doc2.txt", accountNo);
        break;

    case '3':
        writeTofile("doc3.txt", accountNo);
        break;

    case '4':
        writeTofile("doc4.txt", accountNo);
        break;

    case '5':
        writeTofile("doc5.txt", accountNo);
        break;

    case '6':
        writeTofile("doc6.txt", accountNo);
        break;

    case '7':
        writeTofile("doc7.txt", accountNo);
        break;

    case '8':
        writeTofile("doc8.txt", accountNo);
        break;

    case '9':
        writeTofile("doc9.txt", accountNo);
        break;

    default:
        break;
    }
}

std::string returnAccountNumber(std::string &accountNo,std::vector<BankAccount> &account)
{
    std::vector<BankAccount>;
    
    
    switch (accountNo[0])
    {
    case '1':
        readFile("doc1.txt", accountNo,account);
        break;

    case '2':
        readFile("doc2.txt", accountNo,account);
        break;

    case '3':
        readFile("doc3.txt", accountNo,account);
        break;

    case '4':
       readFile("doc4.txt", accountNo,account);
        break;

    case '5':
        readFile("doc5.txt", accountNo,account);
        break;

    case '6':
        readFile("doc6.txt", accountNo,account);
        break;

    case '7':
        readFile("doc7.txt", accountNo,account);
        break;

    case '8':
        readFile("doc8.txt", accountNo,account);
        break;

    case '9':
        readFile("doc9.txt", accountNo,account);
        break;

    default:
        break;
        
    }
    return ret;
}

