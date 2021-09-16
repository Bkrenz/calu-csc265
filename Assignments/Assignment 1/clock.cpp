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
#include <string>
#include "clock.h"
#include <iomanip>

using namespace std;

// CONSTRUCTOR
Clock::Clock()
{
  meridian = "am";
  min = 0;
  hour = 12;
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