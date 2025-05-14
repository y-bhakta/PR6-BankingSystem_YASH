//Banking System
#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
protected:
    string accountType;
public:
    int balance;
    void setacc() {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter account holder name: ";
        cin >> accountHolderName;
        cout << "Enter initial balance: ";
        cin >> balance;
    }
    void displayAccountInfo(int accountType) {
        this->accountType = accountType;
        if(accountType == 1) {
            cout << "Account Type: Savings Account" << endl;
        } else if(accountType == 2) {
            cout << "Account Type: Current Account" << endl;
        } else if(accountType == 3) {
            cout << "Account Type: Fixed Deposit Account" << endl;
        }
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Account Holder Name: " << this->accountHolderName << endl;
        cout << "Balance: " << this->balance << endl;
    }
    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }
    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
    int getBalance() {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    int interestRate;
public:
    void calculateInterest() {
        cout << "Enter interest(in percentage): ";
        cin >> interestRate;
        int interest;
        interest = (getBalance() * interestRate) / 100;
        cout << "Interest earned: " << interest << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;
public:
    
    void setOverdraftLimit(double limit) {
        overdraftLimit = limit;
        cout << "Overdraft limit set to: " << overdraftLimit << endl;
    }
    void withdraw() {
        double amount;
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;
        if (amount > 0 && amount <= (getBalance() + overdraftLimit)) {
            cout << "Withdrawal successful. New balance: " << getBalance() - amount << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
};

class FixedDipositAccount : public BankAccount {
private:
    int term;
    int balance = getBalance();
public:
    void CalInterest() {
        cout << "Enter Term(In Year): ";
        cin >> term;
        cout << "You will get 10 percent interest Each Year...!!" << endl;
        BankAccount::balance = BankAccount::balance + (BankAccount::balance / 10);
        cout << "Your Total Balance After " << term << " Year: " << BankAccount::balance * term << endl;
    }
};

int main() {
    BankAccount account;
    SavingsAccount savingsAccount;
    CurrentAccount currentAccount;
    FixedDipositAccount fixedDepositAccount;
    int accountType = 0;

    cout << "==============================================================" << endl;
    cout << "\t\tWelcome to Banking System" << endl;
    cout << "==============================================================" << endl;
    cout << "Select Account Type to Create:" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Current Account" << endl;
    cout << "3. Fixed Deposit Account" << endl;
    cout << "Enter your choice: ";
    cin >> accountType;

    account.setacc();

    int choice;
    do {
        cout << "----- Menu -----" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Account Info" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                account.deposit();
                if(accountType == 1) {
                    savingsAccount.calculateInterest();
                } 
                else if(accountType == 3) {
                    fixedDepositAccount.CalInterest();
                }
                cout << "----- Done! -----" << endl;
                break;
            case 2:
                if(accountType==2){
                    int limit;
                    cout << "Enter Overdraft Limit: ";
                    cin >> limit;
                    currentAccount.setOverdraftLimit(limit);
                }
                account.withdraw();
                cout << "----- Done! -----" << endl;
                break;
            case 3:
                account.displayAccountInfo(accountType);
                cout << "----- Done! -----" << endl;
                break;
            case 4:
                int bal=account.getBalance();
                cout << "Your Balance is: " << bal << endl;
                cout << "----- Done! -----" << endl;
                break;
        }
    } while (choice != 5);

    cout << "==============================================================" << endl;
    cout << "\tThank you for using our Banking System!" << endl;
    cout << "\t\tHave a great day!" << endl;
    cout << "==============================================================" << endl;
    return 0;
}