/**
 * 
 * Author: Robert Krency
 * Author: Austin Pringle
 * Author: Anthony Stepich
 * 
 * Assignment 4 for CSC 265.
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

#include "clock.h"

using namespace std;

Clock getNewClock()
{
    Clock newClock;
    do 
    {
        cout << "Input a valid time (eg, 12:20 pm): ";
        cin >> newClock;    
    } 
    while (newClock.getFailState());
 
    return newClock;
}

int main()
{
    // Initialize values
    bool continueMenu = true;
    int menuInput = 0, minutes = 0;

    // Instantiate the Clock
    Clock clock, clock2; // Initial values: 12:00 am

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
        cout << "5. Clock + minutes?" << endl;
        cout << "6. Clock < Time" << endl;
        cout << "7. Clock <= Time" << endl;
        cout << "8. Clock > Time" << endl;
        cout << "9. Clock >= Time" << endl;
        cout << "10. Clock == Time" << endl;
        cout << "11. Clock != Time" << endl;
        cout << "12. Quit" << endl;

        // Get the Input
        cout << "Please make a selection from the menu: ";
        while(!(cin >> menuInput) || cin.peek() != '\n' && menuInput > 0 && menuInput < 13)
        {
            cout << "Please make a selection from the menu: ";
            cin.clear();
            cin.ignore(30000, '\n');            
        }
        
        cin.clear();
        cin.ignore(30000, '\n'); 

        // Process Input
        switch(menuInput) 
        {
            case 1: // Set the time
                clock = getNewClock();
                break;

            case 2: // Display the time
                cout << clock << endl;
                break;

            case 3: // Increment the hour
                clock.incrementHour();
                break;
            
            case 4: // Increment the minute
                clock.incrementMin();
                break;
            
            case 5: // Add minutes
                // Get the Input Minutes
                cout << "Input number of minutes as integer greater than 0: ";
                while(!(cin >> minutes) || cin.peek() != '\n' && minutes > 0)
                {
                    cout << "Please make a selection from the menu: ";
                    cin.clear();
                    cin.ignore(30000, '\n');            
                }
                clock = clock + minutes;
                break;
            
            case 6: // Clock < Time
                clock2 = getNewClock();
                cout << clock << " < " << clock2 << "? " << ((clock < clock2) ? "True" : "False") << endl;
                break;
            
            case 7: // Clock <= Time
                clock2 = getNewClock();
                cout << clock << " <= " << clock2 << "? " << ((clock <= clock2) ? "True" : "False") << endl;
                break;
            
            case 8: // Clock > Time
                clock2 = getNewClock();
                cout << clock << " > " << clock2 << "? " << ((clock > clock2) ? "True" : "False") << endl;
                break;
            
            case 9: // Clock >= Time
                clock2 = getNewClock();
                cout << clock << " >= " << clock2 << "? " << ((clock >= clock2) ? "True" : "False") << endl;
                break;
            
            case 10: // Clock == Time
                clock2 = getNewClock();
                cout << clock << " == " << clock2 << "? " << ((clock == clock2) ? "True" : "False") << endl;
                break;
            
            case 11: // Clock != Time
                clock2 = getNewClock();
                cout << clock << " != " << clock2 << "? " << ((clock != clock2) ? "True" : "False") << endl;
                break;

            case 12: // Quit
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

