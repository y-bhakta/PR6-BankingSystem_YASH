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
    int accountType = 0;

    cout << "==============================================================" << endl;
    cout << "\t\tWelcome to Banking System" << endl;
    cout << "==============================================================" << endl;
    do{
        cout << "Select Account Type:" << endl;
        cout << "1. Savings Account" << endl;
        cout << "2. Current Account" << endl;
        cout << "3. Fixed Deposit Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> accountType;
        switch(accountType) {
            case 1: {
                SavingsAccount sa;
                int choice;
                sa.setacc();
                cout<<"----- What do you want to do? -----"<<endl;
                cout<<"1. Deposit"<<endl;
                cout<<"2. Withdraw"<<endl;
                cout<<"3. Calculate Interest"<<endl;
                cout<<"4. Get Balance"<<endl;
                cout<<"5. Display Account Info"<<endl;
                cout<<"6. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin >> choice;
                if(choice == 1) {
                    sa.deposit();
                } else if(choice == 2) {
                    sa.withdraw();
                } else if(choice == 3) {
                    sa.calculateInterest();
                } else if(choice == 4) {
                    cout << "Current Balance: " << sa.getBalance() << endl;
                } else if(choice == 5) {
                    sa.displayAccountInfo(1);
                } else if(choice == 6) {
                    cout << "Exiting the program." << endl;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                cout<<"----- End of Savings Account -----"<<endl;
                break;
            }
            case 2: {
                CurrentAccount ca;
                ca.setacc();
                int choice1;
                cout<<"----- What do you want to do? -----"<<endl;
                cout<<"1. Deposit"<<endl;
                cout<<"2. Withdraw"<<endl;
                cout<<"3. Set Overdraft Limit"<<endl;
                cout<<"4. Get Balance"<<endl;
                cout<<"5. Display Account Info"<<endl;
                cout<<"6. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin >> choice1;
                if(choice1 == 1) {
                    ca.deposit();
                } else if(choice1 == 2) {
                    ca.withdraw();
                } else if(choice1 == 3) {
                    double limit;
                    cout << "Enter overdraft limit: ";
                    cin >> limit;
                    ca.setOverdraftLimit(limit);
                } else if(choice1 == 4) {
                    cout << "Current Balance: " << ca.getBalance() << endl;
                } else if(choice1 == 5) {
                    ca.displayAccountInfo(2);
                } else if(choice1 == 6) {
                    cout << "Exiting the program." << endl;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                cout<<"----- End of Current Account -----"<<endl;
                break;
            }
            case 3: {
                FixedDipositAccount fda;
                fda.setacc();
                int choice2;
                cout<<"----- What do you want to do? -----"<<endl;
                cout<<"1. Deposit"<<endl;
                cout<<"2. Withdraw"<<endl;
                cout<<"3. Calculate Interest"<<endl;
                cout<<"4. Get Balance"<<endl;
                cout<<"5. Display Account Info"<<endl;
                cout<<"6. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin >> choice2;
                if(choice2 == 1) {
                    fda.deposit();
                } else if(choice2 == 2) {
                    fda.withdraw();
                } else if(choice2 == 3) {
                    fda.CalInterest();
                } else if(choice2 == 4) {
                    cout << "Current Balance: " << fda.getBalance() << endl;
                } else if(choice2 == 5) {
                    fda.displayAccountInfo(3);
                } else if(choice2 == 6) {
                    cout << "Exiting the program." << endl;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }while(accountType!=4);
    

    cout << "==============================================================" << endl;
    cout << "\tThank you for using our Banking System!" << endl;
    cout << "\t\tHave a great day!" << endl;
    cout << "==============================================================" << endl;
    return 0;
}