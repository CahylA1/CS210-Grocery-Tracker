# CS210-Grocery-Tracker

A C++ console program that reads a day's grocery purchases from a text file and reports how often each item was bought.

## Files

| File | Purpose |
|------|---------|
| `main.cpp` | Menu loop and user input handling |
| `GroceryTracker.h` | Class declaration |
| `GroceryTracker.cpp` | Class implementation (loading, counting, printing, backup) |
| `CS210_Project_Three_Input_File.txt` | Sample purchase data, one item per line |
| `frequency.dat` | Backup file generated automatically when the program starts |

## Reflection

### Summarize the project and what problem it was solving.

This project is a purchase-tracking tool for a grocery store. The store has a list of every item sold during the day, and the program turns that raw list into something useful. It counts how many times each item appears, then lets the user look up a single item, print every item with its count, or print a text histogram where each purchase is shown as an asterisk. When the program starts, it also writes all of the counts to a backup file called `frequency.dat`, so the data is saved even if the program is closed.

### What did you do particularly well?

I think the strongest part of this project is the separation of responsibilities. All of the data handling lives in the `GroceryTracker` class, and `main.cpp` only deals with the menu and user input. The counts are stored in a private `std::map<string, int>`, so nothing outside the class can change them directly. I chose a map because it handles counting naturally and keeps the items in alphabetical order, which makes the printed output easy to read. I also made sure the menu handles bad input. If someone types a letter instead of a number, the program clears the error and shows an "Invalid choice" message instead of getting stuck in an endless loop. Looking up an item that doesn't exist returns 0 rather than accidentally creating a new entry in the map.

### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

There are a few places I would improve:

- **Case-insensitive search.** Right now searching for "spinach" will not find "Spinach." Converting input to a consistent case before counting and searching would make the program friendlier and more accurate.
- **Better error handling.** If the input file can't be opened, `loadItems` prints a message but the program keeps running with no data. `writeBackup` also never checks that its file opened. Returning a success/failure value and having `main` react to it would make the program more reliable.
- **Pass by `const` reference and use `const` methods.** Functions like `getFrequency(string item)` copy the string every time, and the methods that only read data are not marked `const`. Using `const string&` and `const` methods would be slightly more efficient and would make the code's intent clearer and safer.
- **Input validation for the item search.** `cin >> item` only reads one word, so a multi-word item name would not work correctly. Using `getline` and trimming whitespace would fix that.
- **Magic numbers.** The menu choices (1-4) and the `1000` used in `cin.ignore` could be named constants or an `enum` so the code is easier to change later.

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The trickiest parts were the input handling in the menu loop and working with map iterators. When `cin` fails on a non-number, it stays in a failed state, so I had to learn that `cin.clear()` and `cin.ignore()` are both needed to recover. I overcame this by testing with bad input on purpose (letters, symbols, very long strings) until the loop behaved correctly. For iterators, I wrote small test loops to print `it->first` and `it->second` until I was comfortable with how they work. Resources I am adding to my support network include cppreference.com for the standard library, the course materials and instructor feedback, and debugging with breakpoints and print statements to see exactly what the program is doing at each step.

### What skills from this project will be particularly transferable to other projects or course work?

The biggest transferable skills are object-oriented design (encapsulation and separating a class from the code that uses it), working with file input and output, and choosing the right data structure for a problem. Counting items with a map is a pattern that shows up constantly, from word counts to log analysis. I also practiced defensive programming by checking whether a file opened and handling invalid user input, which applies to nearly every program that takes input from a person or a file. Finally, breaking a program into a header file, an implementation file, and a main file is a structure I will use in future C++ work.

### How did you make this program maintainable, readable, and adaptable?

I kept each function small and focused on one job, such as loading, backing up, looking up a single item, printing counts, and printing the histogram. I gave functions and variables descriptive names like `itemCounts`, `loadItems`, and `printHistogram`, and I added a short comment above each function explaining what it does. The data is private inside the class, so the internal storage could be changed (for example, to an `unordered_map`) without having to rewrite `main.cpp`. The file names are passed in as parameters instead of being hard-coded inside the class, so the same class can be reused with a different input file. Adding a new menu option would only require a new class method and one more `else if` branch in `main`.

## How to Build and Run

```bash
g++ main.cpp GroceryTracker.cpp -o grocerytracker
./grocerytracker
```

Make sure `CS210_Project_Three_Input_File.txt` is in the same folder as the executable.
