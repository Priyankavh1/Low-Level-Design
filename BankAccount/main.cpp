#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(const string& accountNumber, const string& ownerName)
        : accountNumber(accountNumber), ownerName(ownerName), balance(0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account("123456", "John Doe");
    account.deposit(1000);
    cout << fixed << setprecision(1) << account.getBalance() << endl;

    bool success = account.withdraw(500);
    cout << boolalpha << success << endl;
    cout << fixed << setprecision(1) << account.getBalance() << endl;

    success = account.withdraw(1000);
    cout << boolalpha << success << endl;

    return 0;
}