#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// Structure to represent a user
struct User {
    std::string name;
    std::string username;
    std::string password;
    std:: string note;
    std::string month;
    double monthlyBudget;
    double savings;
    double expenses;
};

// Structure to represent a daily transaction
struct Transaction {
    std::string date;
    std::string description;
    std::string note;
    std::string month;
    double amount;
};

// Class to manage the budget tracker
class BudgetTracker {
private:
    User currentUser;
    std::vector<Transaction> transactions;

public:
    void login() {
        std::cout<<"This program will ask you to enter your username and password.\nAfter You have successfully logged in, you will be asked to choose from 5 functions given: \n1.Set MOnthly Budget \n2.Log Daily Expense \n3.Display Summary \n4.Transaction History \n5.Logout\nYou have to enter your choice and the respective function will execute.\n";
        std::cout << "Enter your username: ";
        std::cin >> currentUser.username;
        std::cout << "Enter your password: ";
        std::cin >> currentUser.password;
  
        // Check username and password (dummy check)
        if (currentUser.username == "user" && currentUser.password == "pass") {
            std::cout << "Login successful!\n";
            currentUser.name = "John Doe"; // You can replace this with a database lookup
            // Set initial values
            currentUser.monthlyBudget = 0.0;
            currentUser.savings = 0.0;
            currentUser.expenses = 0.0;
        } else {
            std::cout << "Login failed. Invalid username or password.\n";
            exit(0);
        }
        
    }

    void setBudget() {
        std::cout << "Enter your monthly budget: ";
        std::cin >> currentUser.monthlyBudget;
    }

    void logExpense() {
        Transaction transaction;
        std::cout<<"Enter the month: ";
        std::cin>>transaction.month;
        std::cout << "Enter the date (YYYY-MM-DD): ";
        std::cin >> transaction.date;
        std::cout << "Enter expense category: ";
        std::cin.ignore();
        std::getline(std::cin, transaction.description);
        std::cout<<"Any additional notes:";
        std::cin>>transaction.note;
        std::cout << "Enter expense amount: ";
        std::cin >> transaction.amount;

        transactions.push_back(transaction);
        currentUser.expenses += transaction.amount;
        currentUser.savings = currentUser.monthlyBudget - currentUser.expenses;
        currentUser.note=transaction.note;
        currentUser.month=transaction.month;
        std::cout<<"LOGGED!\n";
        std::cout<< "GENTLE REMINDER: you have " << currentUser.savings << " left to spend.\n";
    }

    void displaySummary() {
        std::cout << "\nBudget and Expense Summary for " << currentUser.name << "\n";
        std::cout << "Month: " << currentUser.month<< "\n";
        std::cout << "Monthly Budget: $" << currentUser.monthlyBudget << "\n";
        std::cout << "Total Expenses: $" << currentUser.expenses << "\n";
        std::cout << "Remaining Savings: $" << currentUser.expenses-currentUser.monthlyBudget<< "\n";
        if(currentUser.expenses>currentUser.monthlyBudget){
            std::cout<<"You are over budget\n";
            std::cout<<"Savings left:" << currentUser.expenses-currentUser.monthlyBudget<<"\n";
        }
        else if(currentUser.expenses<currentUser.monthlyBudget){
            std::cout<<"You are under budget\n";
            std::cout<<"Refrain from spending any further\n";
            std::cout<<"Excess amount spent:"<<currentUser.expenses-currentUser.monthlyBudget<<"\n";
            
        }
        else if(currentUser.expenses==currentUser.monthlyBudget){
            std::cout<<"You have reached your monthly budget limit. Refrain from spending further\n";
            std::cout<<"Savings left: $0";
        }

        displayTransactionHistory();
    }

    void displayTransactionHistory() {
        std::cout << "\nTransaction History:\n";
        for (const auto& transaction : transactions) {
            std::cout << "Date:"<<transaction.date<<"\t" << "Category:"<< transaction.description <<"\t"<<"Amount:"<< ": $" << transaction.amount << "\t"<< "Note:"<<transaction.note<<"\n";
        }
    }


};

int main() {
    BudgetTracker budgetTracker;
    int choice;

    // Login
    budgetTracker.login();

    do {
        std::cout << "\nPersonalized Budget and Expense Tracker\n";
        std::cout << "1. Set Monthly Budget\n";
        std::cout << "2. Log Daily Expense\n";
        std::cout << "3. Display Summary\n";
        std::cout << "4. Transaction History\n";
        std::cout << "5. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                budgetTracker.setBudget();
                break;
            case 2:
                budgetTracker.logExpense();
                break;
            case 3:
                budgetTracker.displaySummary();
                break;
            case 4:
                budgetTracker.displayTransactionHistory();
                break;
            case 5:
                std::cout << "Logging out. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
