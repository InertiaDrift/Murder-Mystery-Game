#include <iostream>
#include <limits>
#include <string>

int getNumber(const string prompt, int minNum, int maxNum) {
    int number;
    bool validInput = false;

    while (!validInput) {
        cout << prompt;
        cin >> number;

        // Check if the input is valid
        if (cin.fail()) {
            cout << "Invalid input! Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (number < minNum || number > maxNum) {
            cout << "Invalid input! Please enter a number between " << minNum << " and " << maxNum << ".\n";
        } else {
            validInput = true;
        }
    }

    return number;
}


