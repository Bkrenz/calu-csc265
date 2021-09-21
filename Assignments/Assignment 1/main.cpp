/**
 * 
 * Author: Robert Krency
 * Author: Austin Pringle
 * Author: Anthony Stepich
 * 
 * Assignment 1 for CSC 265.
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

#include "clock.h"

using namespace std;

string getValidInputTime();

int main()
{
    // Initialize values
    bool continueMenu = true;
    int menuInput = 0;

    // Instantiate the Clock
    Clock clock = Clock(); // Initial value: 12:00 am

    // Display welcome message
    cout << "Welcome to the Clock interface.";

    // While the system should continue running
    while(continueMenu)
    {
        // Display the Menu
        cout << endl << endl;
        cout << "1. Set the Time" << endl;
        cout << "2. Display the Time" << endl;
        cout << "3. Advance one hour" << endl;
        cout << "4. Advance one minute" << endl;
        cout << "5. Quit" << endl;

        // Get the Input
        cout << "Please make a selection from the menu: ";
        while(!(cin >> menuInput) || cin.peek() != '\n' && menuInput > 0 && menuInput < 13)
        {
            cout << "Please make a selection from the menu: ";
            cin.clear();
            cin.ignore(30000, '\n');            
        }

        // Process Input
        switch(menuInput) 
        {
            case 1: // Set the time
                clock.set(getValidInputTime());
                break;

            case 2: // Display the time
                cout << endl << "The current time is: ";
                clock.display();
                cout << endl;
                break;

            case 3: // Increment the hour
                clock.incrementHour();
                break;
            
            case 4: // Increment the minute
                clock.incrementMin();
                break;

            case 5: // Quit
                continueMenu = false;
                break;

            default: // Error in input
                cout << "Error; try again." << endl;
        }
    }

    // Quit the program
    cout << endl <<"Thank you, come again!" << endl;
    return 0;

}


/**
 * validateInputTime()
 * 
 * Checks if the input string matches a valid representation of a clock's time, in the format:
 *      hh:mm aa
 * 
 * Precondition:
 *      (string) input - a string representing an input value from cin
 * Returns:
 *      A boolean value of whether the string is a valid input for a clock 
 * 
 */
bool validateInputTime(string  input){

    // A regex string that matches to 12:00 time with mandatory meridians 
    // - from https://stackoverflow.com/questions/7536755/regular-expression-for-matching-hhmm-time-format/7536768
    string TIME_REGEX = "((1[0-2]|0?[1-9]):([0-5][0-9]) ?([AaPp][Mm]))";

    return regex_match(input, regex(TIME_REGEX));
}


/**
 * getValidInput()
 * 
 * Gets an input string from the user for the time for the clock
 * 
 * Precondition: None
 * Returns:
 *      (string) input - an input time in the format "hh:mm am/pm" 
 */
string getValidInputTime(){
    string input;

    // Clean up cin
    cin.clear();
    cin.ignore(30000, '\n');

    // Get the first input
    cout << "Input a valid time in format hh:mm aa: " << endl;
    getline(cin, input);
    
    // Loop until there is a valid input.
    while(!validateInputTime(input))
    {
        cout << "Invalid input, try again." << endl;
        getline(cin, input);    
    }

    // Return the valid input
    return input;
}