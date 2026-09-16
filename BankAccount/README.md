# BankAccount (C++)

A simple C++ class demonstrating basic object-oriented programming concepts through a bank account simulation. Supports deposits, withdrawals, and balance checks with basic validation.

## Features

- Create an account with an account number and owner name (starting balance is always 0)
- Deposit funds (rejects non-positive amounts)
- Withdraw funds (only succeeds if funds are sufficient and the amount is positive)
- Check the current balance

## Class Overview

### `BankAccount`

**Private fields**
- `accountNumber` (string)
- `ownerName` (string)
- `balance` (double)

**Public methods**
| Method | Description |
|---|---|
| `BankAccount(const string& accountNumber, const string& ownerName)` | Constructs an account with balance initialized to 0 |
| `void deposit(double amount)` | Adds `amount` to the balance if it is positive |
| `bool withdraw(double amount)` | Subtracts `amount` from the balance if positive and sufficient funds exist. Returns `true` on success, `false` otherwise |
| `double getBalance() const` | Returns the current balance |

## Example Usage

```cpp
BankAccount account("123456", "John Doe");
account.deposit(1000);
cout << account.getBalance() << endl;   // 1000.0

bool success = account.withdraw(500);
cout << success << endl;                // true
cout << account.getBalance() << endl;   // 500.0

success = account.withdraw(1000);
cout << success << endl;                // false
```

## Building and Running

Compile with any standard C++ compiler (C++11 or later):

```bash
g++ -std=c++11 -o bank_account main.cpp
./bank_account
```

### Expected Output

```
1000.0
true
500.0
false
```

## Requirements

- A C++11-compatible compiler (e.g., `g++`, `clang++`)
- Standard library headers: `<iostream>`, `<iomanip>`, `<string>`

## License

Feel free to use and modify this code for learning purposes.
