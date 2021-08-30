/**
 * Robert Krency
 * 
 * 
 * Notes for class on August 26th 
 * 
 * Mostly covering initial differences between C and C++
 */

#include <stdio.h>
#include <iostream>
#include <ctime>

/**
 * Fraction Struct
 * 
 * numerator - the numerator of a fraction
 * denominator - the denominator of a fraction
 */
struct Fraction
{
    int numerator;
    int denominator;
};


/* Main Function */
int main(){

    // To instantiate a Fraction struct
    Fraction f1, f2, f3;                      // in C, would have to define as 'struct Fraction f1, f2, f3'


    // To output text to the console
    int num = 0;
    printf("The number is %d", num);                           // in C, use printf
    std::cout << "The number is " << num << std::endl;         // in C++, use the cout object. '<<' is called the stream insertion operator
    // Recommend avoiding endl's for performance reasons in large programs
    // Can use 'flush' in place of 'endl', which flushes the output stream buffer, but does not insert a newline


    // To input text from the console
    int age;
    std::cout << "Input your age: ";
    std::cin >> num;                                           // '>>' is the stream output operator
    std::cout << std::endl;

    // What if bad data is input? eg, 'sl;kdf' instead of a number?
    // Bad data puts 'cin', the input stream, into a fail state permanently
    //      What this means is the input stream will skip the 'cin' statements
    //      Permanently means until the program ends, or until we do something about it

    // What if 2 numbers are input when expecting one?
    //      eg, '34 56'
    //      'cin' will grab the first number, 34, and the 56 will hang out in the buffer
    //      The very next 'cin' call will immediately return the 56
    

    // Allocating pointers and arrays
    Fraction* ptr = 0;    // When initializing pointers, the value '0' means NULL
    Fraction array[1];    // Allocating a static array requires the size to be a CONSTANT value
    ptr = new Fraction[num];  // A dynamic array can be allocated using a variable input size
    delete [] ptr;            // Freeing the memory after usage


    // Working with random numbers
    std::srand(time(0));   // Seeding the RNG
    num = rand() % 10 + 1; // Random number 1-10



    return 0;
}