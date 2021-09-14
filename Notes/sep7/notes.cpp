/**
 * Author: Robert Krency
 * 
 * Notes for class September 7, 2021
 * 
 * Discussing object oriented concepts, function overloading, and function templating
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**
 * Find the minimum of two numbers.
 */
template <class T>
T smaller(T num1, T num2);

int main(){

    /**
     * Function overloading and templating allows one to pass different sets of arguments to a function of the same name.
     * There are more examples in the samples files.
     */
    cout << "The minimum of 7.1 and 3.6 is: " << smaller(7.1, 3.6) << endl;
    cout << "The minimum of 1 and 6 is: " << smaller(6, 1) << endl;

    /**
     * Classes
     * 
     * A class is a reusable software component that models a real world item.
     * 
     * A class has attributes and behaviors.
     *  Attribute - describe an object
     *  Behavior - things an object can do
     */
    return 0;
};

template  <class T>
T smaller(T num1, T num2){
    T answer = num2;

    if (num1 < num2)
        answer = num1;

    return answer;
};