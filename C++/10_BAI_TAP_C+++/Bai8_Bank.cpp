#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

using namespace std;

class BankAccount
{
private:
    string NameAccount;
    uint64_t NumberBankAccount;
    uint64_t BankAccountBalance;
public:
    BankAccount(string NameAccount, uint64_t NumberBankAccount, uint64_t BankAccountBalance);
    string getNameAccount();
    uint64_t getNumberBankAccount();
    uint64_t getBankAccountBalance();
    void CheckAccountBalance();
    void WithdrawMoney();
    void Deposit();
};

BankAccount::BankAccount(string NameAccount, uint64_t NumberBankAccount, uint64_t BankAccountBalance){
    this->NameAccount = NameAccount;
    this->NumberBankAccount = NumberBankAccount;
    this->BankAccountBalance = BankAccountBalance;
}

string BankAccount::getNameAccount(){
    return this->NameAccount;
}

uint64_t BankAccount::getNumberBankAccount(){
    return this->NumberBankAccount = NumberBankAccount;
}

uint64_t BankAccount::getBankAccountBalance(){
    return this->BankAccountBalance;
}

void BankAccount::CheckAccountBalance(){
    cout << " " << this->getNameAccount() << endl;
    cout << " " << this->getNumberBankAccount() << endl;
    if(this->getBankAccountBalance() > 0){
        cout << "Current account balance is " << this->getBankAccountBalance() << endl;
    }
    else {
        cout << "Current account balance is not money" << endl;
    }
}

void BankAccount::WithdrawMoney(){
    uint64_t money;
    cout << " " << this->getNameAccount() << endl;
    cout << " " << this->getNumberBankAccount() << endl;
    if(this->getBankAccountBalance() > 0){
        cout << "Current account balance is " << this->getBankAccountBalance() << endl;
        cout << "You want to withdraw how much money " << endl;
        cin >> money;
        this->BankAccountBalance = this->BankAccountBalance - money;
        cout << "You withdraw money finish " << endl;
        
    }
    else {
        cout << "Current account balance is not money" << endl;
    }
}

void BankAccount::Deposit(){
    
    uint64_t money;
    if(this->getBankAccountBalance() > 0){
        cout << " " << this->getNameAccount() << endl;
        cout << " " << this->getNumberBankAccount() << endl;
        cout << "Current account balance is " << this->getBankAccountBalance() << endl;
        cout << "You want to Deposit how much money in to the account " << endl;
        cin >> money;
        this->BankAccountBalance = this->BankAccountBalance + money;
        cout << "You successfully Deposit money into the account " << endl;
        
    }
    else {
        cout << "Current account balance is not money" << endl;
    }
}

int main(int argc, char const *argv[])
{
    BankAccount Account("Ma Thanh van", 10002001, 2000);
    Account.WithdrawMoney();
    Account.CheckAccountBalance();

    Account.Deposit();
    Account.CheckAccountBalance();
    return 0;
}
