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
#include <string>
#include "clock.h"
#include <iomanip>
#include <regex>

using namespace std;

// CONSTRUCTOR
Clock::Clock()
{
  meridian = "am";
  min = 0;
  hour = 12;
  failState = true;
}

// MODIFICATION MEMBER FUNCTIONS
void Clock::setMeridian(const string value)
{
  meridian = value;

  // Ensure meridian is in lower case
  for (int i = 0; i < meridian.length(); i++)
    meridian[i] = tolower(meridian[i]); 
}

void Clock::incrementHour()
{
  // Increment the Hour
  hour++;

  // Check if the value is above 12, and roll it over to 1
  if (hour > 12)
    hour -= 12;
  
  // If the hour increments to 12, swap the meridian (ie, am -> pm)
  if (hour == 12)
    swapMeridian();  
}


void Clock::incrementMin()
{
  // Increment the minute
  min++;

  // Check if the minute is greather than 59, if it is roll over to 0 and increment the hour
  if (min > 59)
  {
    min -= 60;
    incrementHour();
  }
}

void Clock::set(string input){
  // Find the relevant substring positions
  int colonPosition = input.find(":");
  int spacePosition = input.find(" ");

  // Get the input hour
  string inputHour = "";
  for(int i=0; i < colonPosition; i++)
    inputHour += input[i];
  hour = stoi(inputHour);

  // Get the input minute
  string inputMinute = "";
  for(int i=colonPosition+1; i < spacePosition; i++)
    inputMinute += input[i];
  min = stoi(inputMinute);

  // Get the input Meridian
  string inputMeridian = "";
  for(int i=spacePosition+1; i < input.length(); i++)
    inputMeridian += input[i];
  setMeridian(inputMeridian);
}


// CONSTANT MEMBER FUNCTIONS
string Clock::getMeridian(void) const
{
  return meridian;
}


int Clock::getHour(void) const
{
  return hour;
}


int Clock::getMin(void) const
{
  return min;
}

/**
 * display()
 * 
 * This should be a tostring and return it instead of handling its direct display to cout
 */
void Clock::display(void) const
{
  cout << setfill('0');
  cout << setw(2) << hour << ":" << setw(2) << min << " " << meridian;
}

/**
 * swapMeridian()
 * 
 * Changes the meridian from 'am' to 'pm' or from 'pm' to 'am'  
 */
void Clock::swapMeridian()
{
  if (meridian.compare("am") == 0)
    setMeridian("pm");
  else
    setMeridian("am");
}


bool Clock::operator<(const Clock& c2)
{
  if ( this->meridian[0] < c2.getMeridian()[0] )
    return true;

  else if ( this->meridian[0] > c2.getMeridian()[0] )
    return false;

  else {

    if (this->hour < c2.getHour())
      return true;

    else if (this->hour > c2.getHour())
      return false;

    else {

      return this->min < c2.getMin();

    }

  }
}

bool Clock::operator==(const Clock& c2)
{
    return (this->meridian[0] == c2.getMeridian()[0] && this->hour == c2.getHour() && this->min == c2.getMin());
}

bool Clock::operator<=(const Clock& c2)
{
    return *this < c2 || *this == c2;
}

bool Clock::operator!=(const Clock& c2)
{
    return !(*this == c2);
}

bool Clock::operator>=(const Clock& c2)
{
    return !(*this < c2);
}

bool Clock::operator>(const Clock& c2)
{
    return !(*this <= c2);
}

Clock operator+(const Clock& clock, const int minutes)
{
    Clock newClock;

    newClock.hour = clock.getHour();
    newClock.meridian = clock.getMeridian();
    newClock.min = clock.getMin() + minutes;

    while(newClock.min > 60)
    {
        newClock.hour++;
        if(newClock.hour==12)
            newClock.swapMeridian();
        newClock.hour -= (newClock.hour > 12)*12;
        newClock.min -= 60;
    }

    return newClock;
}

ostream& operator<<(ostream& out, const Clock& clock)
{
    cout << setfill('0');
    cout << setw(2) << clock.getHour() << ":" << setw(2) << clock.getMin() << " " << clock.getMeridian();
    return out;
} 

istream& operator>>(istream& in, Clock& clock)
{
    string temp;
    getline(in, temp);

    if (!clock.validateInputTime(temp))
    {
        clock.setFailState(true);
        return in;
    }

    clock.set(temp);
    clock.setFailState(false);

    return in;
}

void Clock::setFailState(bool val)
{
    this->failState = val;
}

bool Clock::getFailState()
{
    return this->failState;
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
bool Clock::validateInputTime(string  input){

    // A regex string that matches to 12:00 time with mandatory meridians 
    // - from https://stackoverflow.com/questions/7536755/regular-expression-for-matching-hhmm-time-format/7536768
    string TIME_REGEX = "((1[0-2]|0?[1-9]):([0-5][0-9]) ?([AaPp][Mm]))";

    return regex_match(input, regex(TIME_REGEX));
}
