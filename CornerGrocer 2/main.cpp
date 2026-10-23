#include <iostream>
#include "GroceryTracker.h"
using namespace std;

int main() {
    GroceryTracker tracker;
    int choice = 0;
    string item;

    tracker.loadItems("CS210_Project_Three_Input_File.txt");
    tracker.writeBackup("frequency.dat");  // backup file made at start

    while (choice != 4) {
        cout << endl;
        cout << "1. Find an item" << endl;
        cout << "2. Print all items" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // If the user typed something that isn't a number
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }

        if (choice == 1) {
            cout << "Enter item: ";
            cin >> item;
            cout << item << " was bought " << tracker.getFrequency(item) << " times." << endl;
        }
        else if (choice == 2) {
            tracker.printFrequencies();
        }
        else if (choice == 3) {
            tracker.printHistogram();
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice, enter 1-4." << endl;
        }
    }

    return 0;
}
