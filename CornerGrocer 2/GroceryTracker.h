#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>
using namespace std;

// Class that keeps track of how many times each item was bought
class GroceryTracker {
public:
    void loadItems(string fileName);       // read input file and count items
    void writeBackup(string fileName);     // save counts to frequency.dat
    int getFrequency(string item);         // count for one item
    void printFrequencies();               // print every item with its number
    void printHistogram();                 // print every item with stars

private:
    map<string, int> itemCounts;           // item name -> times purchased
};

#endif
