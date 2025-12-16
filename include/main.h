#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>

// Forward declaration
class BankAccount;

class IAccountStorage
{
public:
    virtual ~IAccountStorage() = default;
    virtual void addAccount(BankAccount account) = 0;
    virtual BankAccount* findAccount(const std::string& accountNumber) = 0;
};

class VectorAccountStorage : public IAccountStorage
{
private:
    std::vector<BankAccount> accounts;

public:
    void addAccount(BankAccount account) override;
    BankAccount* findAccount(const std::string& accountNumber) override;
};

class Bank
{
private:
    IAccountStorage* accountStorage;

public:
    Bank(IAccountStorage* storage);
    bool addAccount(const std::string& accountNumber);
    BankAccount* getAccount(const std::string& accountNumber);
};

#endif // BANK_H
