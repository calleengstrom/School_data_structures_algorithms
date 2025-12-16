#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>

class BankAccount
{
    std::string accountNumber;
    float balance;

public:
    BankAccount()
    {
    }

    BankAccount(std::string accountNumber, float balance = 0)
        : accountNumber(accountNumber), balance(balance)
    {
    }

    std::string getAccountNumber()
    {
        return this->accountNumber;
    }
};

// INTERFACE - gränssnitt "standard"
class IAccountStorage
{
public:
    virtual void addAccount(BankAccount account) = 0;
    virtual BankAccount *findAccount(std::string accountNumber) = 0;
};

class VectorAccountStorage : public IAccountStorage
{

    std::vector<BankAccount> accounts1;
    std::vector<BankAccount> accounts2;
    std::vector<BankAccount> accounts3;
    std::vector<BankAccount> accounts4;
    std::vector<BankAccount> accounts5;
    std::vector<BankAccount> accounts6;
    std::vector<BankAccount> accounts7;
    std::vector<BankAccount> accounts8;
    std::vector<BankAccount> accounts9;

public:
    void addAccount(BankAccount account) override
    {
        std::string firstIdx = account.getAccountNumber();

        switch (firstIdx[0])
        {
        case '0':

            break;
        case '1':
            accounts1.push_back(account);

            break;
        case '2':
            accounts2.push_back(account);

            break;
        case '3':
            accounts3.push_back(account);

            break;
        case '4':

            accounts4.push_back(account);
            break;
        case '5':

            accounts5.push_back(account);
            break;
        case '6':

            accounts6.push_back(account);
            break;
        case '7':

            accounts7.push_back(account);
            break;
        case '8':

            accounts8.push_back(account);
            break;
        case '9':
            accounts9.push_back(account);

            break;

        default:
            break;
        }
    }

    BankAccount *findAccount(std::string accountNumber)
    {
        BankAccount *ret = nullptr;
        switch (accountNumber[0])
        {
        case '1':
            ret = findVectorCollum(accounts1,accountNumber);
            break;
        case '2':
            ret = findVectorCollum(accounts2,accountNumber);
            break;
        case '3':
            ret = findVectorCollum(accounts3,accountNumber);
            break;
        case '4':
            ret = findVectorCollum(accounts4,accountNumber);
            break;
        case '5':
            ret = findVectorCollum(accounts5,accountNumber);
            break;
        case '6':
            ret = findVectorCollum(accounts6,accountNumber);
            break;
        case '7':
            ret = findVectorCollum(accounts7,accountNumber);
            break;
        case '8':
            ret = findVectorCollum(accounts8,accountNumber);
            break;
        case '9':
            ret = findVectorCollum(accounts9,accountNumber);
            break;

        default:
            break;
        }
        return ret;
    }

    BankAccount* findVectorCollum(std::vector<BankAccount> &collum,std::string accountNumber)
    {
       // std::cout << "Finding " << accountNumber << std::endl;
        BankAccount *ret = nullptr;
        for (BankAccount &account : collum)
        {
            if (account.getAccountNumber() == accountNumber)
            {
                ret = &account;
                break;
            }
        }
        return ret;
    }
};

class Bank
{
private:
    IAccountStorage *accountStorage;

public:
    Bank(IAccountStorage *storage) : accountStorage(storage)
    {
    }
    bool addAccount(std::string accountNumber)
    {
        // validate
        // if something (accountNumber) return false
        accountStorage->addAccount(accountNumber);
        return true;
    }
    BankAccount *getAccount(std::string accountNumber)
    {
        return accountStorage->findAccount(accountNumber);
    }
};

int main(int, char **)
{
    // VectorAccountStorage storage;
    VectorAccountStorage storage;
    // MapAccountStorage storage;
    Bank bank(&storage);

    const int AntalAccounts = 10000000;

    std::string sFirst = "";
    std::string sLast = "";
    std::string sNotFound = "notfound";

    std::cout << "INITIALIZE: " << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < AntalAccounts; i++)
    {
        std::string accountNumber = std::to_string(i);
        if (i == 1)
        {
            sFirst = accountNumber;
        }
        if (i == AntalAccounts - 1)
        {
            sLast = accountNumber;
        }
        bank.addAccount(accountNumber);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::cout << "INIT Took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " milliseconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    BankAccount *p = bank.getAccount(sFirst);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << p->getAccountNumber() << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " milliseconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    p = bank.getAccount(sLast);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << p->getAccountNumber() << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " milliseconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    p = bank.getAccount(sNotFound);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "NOT FOUND" << " took: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " milliseconds" << std::endl;
}