#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    string pinCode;
    double balance;

public:
    // Constructor to initialize ATM with a default pin and balance
    ATM(string pin, double initialBalance) {
        pinCode = pin;
        balance = initialBalance;
    }

    // Function to check if the entered pin is correct
    bool validatePin(string enteredPin) {
        if (enteredPin == pinCode) {
            return true;
        }
        else {
            cout << "Incorrect PIN. Please try again." << endl;
            return false;
        }
    }

    // Function to check account balance
    void checkBalance() {
        cout << "Your current balance is: Rs" << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "You have deposited Rs" << amount << ". Your new balance is: Rs" << balance << endl;
        }
        else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "You have withdrawn Rs" << amount << ". Your new balance is: Rs" << balance << endl;
        }
        else {
            cout << "Insufficient funds or invalid withdrawal amount!" << endl;
        }
    }

    // Function to change the pin code
    void changePin(string newPin) {
        pinCode = newPin;
        cout << "Your PIN has been successfully changed." << endl;
    }
};

int main() {
    string enteredPin;
    string newPin;
    int choice;
    double amount;
    
    // Initialize ATM with a default PIN and balance of Rs 1000
    ATM atm("1234", 1000.00);

    cout << "Welcome to the ATM Machine!" << endl;

    // Ask user to enter pin
    cout << "Please enter your PIN: ";
    cin >> enteredPin;

    // Validate entered PIN
    if (!atm.validatePin(enteredPin)) {
        return 0; // Exit if PIN is incorrect
    }

    // Display menu
    do {
        cout << "\nATM Menu: " << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Change PIN" << endl;
        cout << "5. Exit" << endl;
        cout << "Please choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: // Check Balance
                atm.checkBalance();
                break;
            case 2: // Deposit Money
                cout << "Enter the amount to deposit: RS";
                cin >> amount;
                atm.deposit(amount);
                break;
            case 3: // Withdraw Money
                cout << "Enter the amount to withdraw: Rs";
                cin >> amount;
                atm.withdraw(amount);
                break;
            case 4: // Change PIN
                cout << "Enter new PIN: ";
                cin >> newPin;
                atm.changePin(newPin);
                break;
            case 5: // Exit
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}