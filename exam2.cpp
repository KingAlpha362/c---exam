#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    try {
        ofstream outfile("members.txt");

        // Step 1: if (!outFile) throw runtime_error("Could not open members.txt");

        if (!outfile)
        throw runtime_error("Could not open members.txt");

        int n;

        cout << "How many members? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            string name;
            int booksOut;

            // Step 2: read the name and booksOut from the user
            // Step 3: write name booksOut to the file on one line

            cout << "Name: ";
            cin >> name;

            cout << "Books out: ";
            cin >> booksOut;

            outfile << name << " " << booksOut << endl;
        }

        // Step 4: close the file and print "Members saved."

        outfile.close();
        cout << "Members saved." << endl;

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        ifstream infile("members.txt");

        // Step 1: if (!inFile) throw runtime_error("Could not open members.txt");


        if (!infile)
        throw runtime_error("Could not open members.txt");

        string name;
        int booksOut, total = 0;

        cout << "\n--- Members on file ---" << endl;

        // Step 1: loop while (inFile >> name >> booksOut)
        // Step 2: display each member and add booksOut to total
        // Step 3: close the file and display the total

        while (infile >> name >> booksOut) {
            cout << name << ": " << booksOut << total << endl;
            total += booksOut;
        }
        infile.close();
        cout << "Total books out: " << total << endl;

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}