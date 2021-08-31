/**
 * author: Robert Krency
 * 
 * Notes for class August 31, 2021 
 * 
 */

#include <iostream>

using namespace std;

// Declaring a constant
//      in C:
//          #define SIZE 50
//      in C++:
const int SIZE = 50;

void swapNumbers(int& ref1, int& ref2)
{
    int temp = 0;
    temp = ref1;
    ref1 = ref2;
    ref2 = temp;
};

/* Main Function
 * Program entry point
 */
int main()
{
    // Booleans
    bool flag = true;  // Can only be true or false

    // Type casting
    int num1 = 3, num2 = 4;
    float avg = 0;
    
    avg = num1 / num2; // avg = 0; integer division, need to type cast
    avg = (float) num1 / num2; // the c way
    avg = static_cast<float>(num1) / static_cast<float>(num2); // The c++ way

    // Passing by Reference
    int num3 = 5, num4 = 12;
    cout << num3 << ", " << num4 << endl;
    swapNumbers(num3, num4);
    cout << num3 << ", " << num4 << endl;


    // Error Handling for cin
    int num = 0;
    cout << "Please enter an integer: ";

    // Notes:
    //      1. cin >> num   returns a true/false value
    //      2. peek is used to make sure they didn't type 'extra stuff'
    //      3. clear is used to take the stream out of 'fail state'
    //      4. ignore is used to remove chars from stream
    while( !(cin >> num) || cin.peek() != '\n')
    {
        cout << "Please enter an integer: ";
        cin.clear();
        cin.ignore(30000, '\n');
    }

    cout << "You've finally listened! You entered: " << num << endl;


    // Exit
    return 0;
}





