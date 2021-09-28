/**
 * 
 * Author: Robert Krency
 * Author: Austin Pringle
 * Author: Anthony Stepich
 * 
 * Assignment 2 for CSC 265.
 * 
 */

#include <iostream>
#include "list.h"
#include "set.h"

using namespace std;

int getInputValue();

int main(){

    // Init
    bool continueMenu = true;
    int menuInput = 0;

    // Display the Menu
    cout << endl << "Would you like to use a List or Set?" << endl;
    cout << "1. List" << endl;
    cout << "2. Set" << endl;

    // Get the Input
    cout << "Please make a selection from the menu: ";
    while(!(cin >> menuInput) || cin.peek() != '\n' && menuInput > 0 && menuInput < 3)
    {
        cout << "Please make a selection from the menu: ";
        cin.clear();
        cin.ignore(30000, '\n');            
    }

    // Init the Set or List
    List l; // technically I'm using polymorphism here...
    if (menuInput == 1)
        l = List();
    else if (menuInput == 2)
        l = Set();

    // While the system should continue running
    menuInput = 0;
    while(continueMenu)
    {
        // Display the Menu
        cout << endl << endl;
        cout << "1. Insert a Value" << endl;
        cout << "2. Remove a Value" << endl;
        cout << "3. Print the List" << endl;
        cout << "4. Quit" << endl;

        // Get the Input
        cout << "Please make a selection from the menu: ";
        while(!(cin >> menuInput) || cin.peek() != '\n' && menuInput > 0 && menuInput < 5)
        {
            cout << "Please make a selection from the menu: ";
            cin.clear();
            cin.ignore(30000, '\n');            
        }

        // Process Input
        switch(menuInput) 
        {
            case 1: // Insert a Value
                l.insert(getInputValue());
                break;

            case 2: // Remove a Value
                l.remove(getInputValue());
                break;

            case 3: // Print the List
                l.printList();
                break;

            case 4: // Quit
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


int getInputValue(){
    int value = 0;


    return value;
}