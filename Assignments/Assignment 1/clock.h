/**
 * 
 * Author: Robert Krency
 * Author: Austin Pringle
 * Author: Anthony Stepich
 * 
 * Assignment 1 for CSC 265.
 * 
 */

// CLASS PROVIDED:  Clock (an ADT for a fraction)
//
// CONSTRUCTOR for the Clock class:
//   Clock()
//     Description:		constructor will initialize Clock objects
//     Preconditions:	none
//     Postcondition:	Clock has been set to 00:00 am
//
// MODIFICATION MEMBER FUNCTIONS for the Clock  class
//   void setmeridian (const char value)
//     Description:		set the meridian of the Clock 
//     Precondition:	value is either 'am' or 'pm'
//     Postcondition:	meridian of the clock has been set to value
//
//   void sethour(const int value)
//     Description:		set the hour of the clock
//     Precondition:	value is a non-negative value
//     Postcondition:	hour of the clock has been set to value
//
//   void setmin (const int value)
//     Description:		set the min of the clock
//     Precondition:	value is a non-negative value
//     Postcondition:	min of the clock has been set to value

//
// CONSTANT MEMBER FUNCTIONS for the Fraction class
//   char getmeridian (void) const
//     Description:		obtain sign of the clock
//     Preconditions:	none
//     Postcondition:	meridian of the  is returned
//
//   int  gethour(void) const
//     Description:		obtain hour of the Clock 
//     Preconditions:	none
//     Postcondition:	hour of the Clock  is returned
//
//   int  getmin  (void) const
//     Description:		obtain min of the Clock 
//     Preconditions:	none
//     Postcondition:	min of the Clock  is returned

//
//   void display (void) const
//     Description:		display Clock  to the screen
//     Preconditions:	none
//     Postcondition:	value of the Clock  is displayed on the screen

#include <string>
using namespace std;

#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
  public:
    // CONSTRUCTOR
    Clock();

    // MODIFICATION MEMBER FUNCTIONS
    void setMeridian(const string);
    void incrementHour();
    void incrementMin();
    void set(string);
    

    // CONSTANT MEMBER FUNCTIONS
    string getMeridian (void) const;
    int  getHour(void) const;
    int  getMin(void) const;
    void display(void) const;

  private:
    string meridian;
    int hour;
    int min;

    void swapMeridian();
    
};

#endif
