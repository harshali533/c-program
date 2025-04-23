#include <iostream>
#include <string>
using namespace std;

class Bank 
{
public:
    void deposit(int amount) 
    {
        cout << "Depositing :" << amount << " in cash." << endl;
    }
    void deposit(double amount) 
    {
        cout << "Depositing :" << amount << " via digital payment." << endl;
    }
    void deposit(const string& upiID, double amount) 
    {
        cout << "Depositing :" << amount << " using UPI (" << upiID << ")." << endl;
    }
};

class Account 
{
private:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}
    void display() const 
    {
        cout << "Account " << accountNumber << " Balance: " << balance << endl;
    }
    void operator+(Account& otherAccount) 
    {
        double transferAmount;
        cout << "Enter amount to transfer from Account " << accountNumber << " to Account " << otherAccount.accountNumber << ": ";
        cin >> transferAmount;
        
        if (balance >= transferAmount) 
        {
            balance -= transferAmount;
            otherAccount.balance += transferAmount;
            cout << "Transferring " << transferAmount << " from Account " << accountNumber << " to Account " << otherAccount.accountNumber << "..." << endl;
            cout << "New Account " << accountNumber << " Balance: " << balance << endl;
            cout << "New Account " << otherAccount.accountNumber << " Balance: " << otherAccount.balance << endl;
        } else {
            cout << "Insufficient funds for transfer!" << endl;
        }
    }

    void operator-(double amount) 
    {
        if (balance >= amount) 
        {
            balance -= amount;
            cout << "Withdrawing " << amount << " from Account " << accountNumber << "..." << endl;
            cout << "Remaining Balance: " << balance << endl;
        } else 
        {
            cout << "Insufficient funds for withdrawal!" << endl;
        }
    }
};

int main() 
{
    Bank bank;
    bank.deposit(5000);                 
    bank.deposit(1500.75);               
    bank.deposit("gpay@upi", 2500);    
    cout << endl;
    Account account1(1, 10000);  
    Account account2(2, 5000);   
    account1.display();
    account2.display();
    cout << endl;
    account1 + account2;   
    cout << endl;
    account1 - 2000;  
    return 0;
}
