#include <iostream>
using namespace std;

void bank()
{
    cout << "Checking Account " << endl;
    cout << "1. Check balance " << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
}

void save()
{
    cout << "Saving Account" << endl;
    cout << "1. Check balance " << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
}

void credit()
{
    cout << "Credit Account " << endl;
    cout << "1. Credit limit" << endl;
    cout << "2. Monthly payment" << endl;
    cout << "3. Your credit score " << endl;
    cout << "4. Exit" << endl;
}

void choice()
{
    int choose;
    cout << "Choose an account: ";
    cin >> choose;

    switch (choose) {
        case 1:
            cout << "Checking Account" << endl;
            break;
        case 2:
            cout << "Saving Account" << endl;
            break;
        case 3:
            cout << "Credit Account" << endl;
            break;
        default:
            cout << "Invalid!" << endl;
            break;
    }
}

int main()
{
    int option;
    double balance;

    cout << "Enter your balance" << endl;
    cin >> balance;
    double credit_limit = 2000;
    int credit_score = 600;
    do {
        choice(); // Display account options

        cout << "option: ";
        cin >> option;

        if (option == 1 || option == 2) {
            switch (option) {
                case 1:
                    bank(); // Display Checking Account options
                    cout << "Balance amount: " << balance << endl;
                    break;
                case 2:
                    save(); // Display Saving Account options
                    cout << "Deposit amount: ";
                    double depositAmount;
                    cin >> depositAmount;
                    balance += depositAmount;
                    break;
                case 3:
                    credit(); // Display Credit Account options
                    cout << "Withdraw amount: ";
                    double withdrawAmount;
                    cin >> withdrawAmount;
                    if (withdrawAmount <= balance) {
                        balance -= withdrawAmount;
                    } else {
                        cout << "Not enough money" << endl;
                    }
                    break;
            }
        } else if (option == 3) {
            credit(); // Display Credit Account options

            int card;
            cout << "Credit card: ";
            cin >> card;

            switch (card) {
                case 1:
                    cout << "Credit line: " << credit_limit << endl;
                    break;
                case 2:
                    cout << "Enter how much you spent this month: ";
                    double owe;
                    cin >> owe;
                    credit_limit -= owe;
                    cout << "Your credit limit is: " << credit_limit << endl;
                    cout << "You will pay " << (owe / 12) << " per month" << endl;
                    if (owe > (credit_limit / 2)) 
                        {
                        
                       credit_score -= 100; // Decrease credit score
                       cout << "Your credit limit is " << credit_score<< endl;
                    }
                      else
                    {
                        credit_score += 50; // Increase credit score
                        cout << "Your credit limit is " << credit_score<< endl;
                    }
                    break;
                    
                    
                    
                    
                case 3:
                    cout << "Enter your credit score: ";
                    int score;
                    cin >> score;
                    if (score >= 300 && score <= 580) {
                        cout << "Bad credit score" << endl;
                    } else if (score >= 581 && score <= 670) {
                        cout << "Average credit score" << endl;
                    } else if (score >= 671 && score <= 740) {
                        cout << "Good credit score" << endl;
                    } else if (score >= 750 && score <= 850) {
                        cout << "Great credit score" << endl;
                    } else {
                        cout << "Invalid credit score" << endl;
                    }
                    break;
            }
        } else {
            cout << "Sorry, invalid option" << endl;
        }
    } while (option != 4);

    return 0;
}