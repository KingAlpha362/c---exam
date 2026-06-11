#include <iostream>
#include <string>
#include <cstdlib> // for abs()
using namespace std;

// ----- function prototypes (declared for you) -----
bool login();
double calculateFine(int daysLate);
void printReceipt(string name, double fine);

const double RATE = 2.50; // R2.50 per day late

int main() {
    bool loggedIn = login();

    if (loggedIn == false) {
        cout << "Access denied." << endl;
        return 0;
    }

// Task 1 (3 Marks) -- check the login
//_______________________________________
// Step 1: call login(); if it returns false, print "Access denied."
// and return 0;

int choice;
do {
    cout << "\n--- Library Fine System ---\n";
    cout << "1. Calculate a fine\n";
    cout << "2. Quit\n";
    cout << "Choice: ";

    cin >> choice;

// Task 2 (5 Marks) -- handle the menu choice
//_______________________________________
    if (choice == 1) {

        string name;
        int daysLate;

        cout << "Enter member name: ";
        cin >> name;

        cout << "Enter days late: ";
        cin >> daysLate;

        double fine = calculateFine(daysLate);

            // Step 3: call printReceipt(name, fine)
            printReceipt(name, fine);
        } else if (choice != 2) {
            // Step 4: print "Invalid choice, try again."
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 2); // do-while repeats until the user quits

    return 0;
}

// Task 3 (4 Marks) -- the login and calculateFine functions
//_______________________________________
bool login() {
    string user, pass;

    cout << "Username: ";
    cin >> user;

    cout << "Password: ";
    cin >> pass;

    // return true only if user == "admin" and pass == "1234"
    if (user == "admin" && pass == "1234") {
        return true;
    } else {
        cout << "Try again." << endl;
        return false;
    }
}
// return true only if user == "admin" and pass == "1234"

double calculateFine(int daysLate) {

    daysLate = abs(daysLate);


    return daysLate * RATE;
// Step 1: use abs(daysLate) so a negative value can't give a negative fine
// Step 2: return that number of days * RATE
}

// Task 4 (3 Marks) -- the printReceipt void function
//_______________________________________
void printReceipt(string name, double fine) {
cout << fixed;
cout.precision(2);

cout << "The member name is: " << name << endl;
cout << "and the fine is:R " << fine << endl;
// print a receipt showing the member name and the fine as R<fine>
}