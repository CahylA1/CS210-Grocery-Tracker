#include <iostream>
#include <fstream>
#include "GroceryTracker.h"
using namespace std;

// Reads the input file and counts each word
void GroceryTracker::loadItems(string fileName) {
    ifstream inFile(fileName);
    string item;

    if (!inFile.is_open()) {
        cout << "Could not open " << fileName << endl;
        return;
    }

    while (inFile >> item) {
        itemCounts[item] = itemCounts[item] + 1;  // add one to the count
    }

    inFile.close();
}

// Saves every item and its count to a file
void GroceryTracker::writeBackup(string fileName) {
    ofstream outFile(fileName);
    map<string, int>::iterator it;

    for (it = itemCounts.begin(); it != itemCounts.end(); it++) {
        outFile << it->first << " " << it->second << endl;
    }

    outFile.close();
}

// Returns how many times one item was bought (0 if not found)
int GroceryTracker::getFrequency(string item) {
    if (itemCounts.find(item) == itemCounts.end()) {
        return 0;
    }
    return itemCounts[item];
}

// Prints each item with its number
void GroceryTracker::printFrequencies() {
    map<string, int>::iterator it;

    for (it = itemCounts.begin(); it != itemCounts.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

// Prints each item with one * for every purchase
void GroceryTracker::printHistogram() {
    map<string, int>::iterator it;

    for (it = itemCounts.begin(); it != itemCounts.end(); it++) {
        cout << it->first << " ";
        for (int i = 0; i < it->second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}
