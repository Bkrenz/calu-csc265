/**
 * 
 * Author: Robert Krency
 * 
 * Assignment 1 for CSC 265.
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>


using namespace std;

int main()
{
    bool continueMenu = true;
    int menuInput = 0;

    // Instantiate the Clock
    // Clock clock = Clock(); // Initial value: 00:00 am

    while(continueMenu)
    {
        // Display the Menu
        cout << "1. Set the Time" << endl;
        cout << "2. Display the Time" << endl;
        cout << "3. Advance one hour" << endl;
        cout << "4. Advance one minute" << endl;
        cout << "5. Quit" << endl;

        // Get the Input
        while(!(cin >> menuInput) || cin.peek() != '\n' && menuInput > 0 && menuInput < 13)
        {
            cout << "Please enter an INTEGER: ";
            cin.clear();
            cin.ignore(30000, '\n');            
        }

        // Process Input
        switch(menuInput) 
        {
            case 1:
                // clock.setTime(getValidInput());
                break;

            case 2:
                // clock.displayTime();
                break;

            case 3:
                // clock.incrementHour();
                break;
            
            case 4: 
                // clock.incrementMinute();
                break;

            case 5: // Quit
                continueMenu = false;
                break;

            default: // Error in input
                cout << "Error; try again.";
        }
    }

}

/**
 * getValidInput()
 * Precondition: None
 * Returns:
 *      (string) input - an input time in the format "hh:mm am/pm" 
 */
string getValidInput(){
    string input;

    // A regex string that matches to 12:00 time with mandatory meridians 
    // - from https://stackoverflow.com/questions/7536755/regular-expression-for-matching-hhmm-time-format/7536768
    string TIME_REGEX = "/((1[0-2]|0?[1-9]):([0-5][0-9]) ?([AaPp][Mm]))/";
    
    while(true)
    {
        getline(cin, input);
        if (regex_match(input, regex(TIME_REGEX)))
            return input;
        else
            cout << "Invalid input, try again." << endl;
    }
}