/**
 * Author: Robert Krency
 * 
 * Notes for class September 2, 2021
 *  
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

    // To get a full line of text from the input of cin
    string name = "";

    cout << "Please enter your name: ";
    getline(cin, name);

    cout << "Your name is " << name << "." << endl; 

    /**
     * cout Manipulators - used to format output 
     * Manipulators that have arguments require #include <iomanip>
     * 1. endl                  // newLine AND flushes the output stream
     * 2. flush                 // flushes the output stream only
     * 3. setw(int)             // sets field width for the next item output - sets the width temporarily for the immediate use
     * 4. left                  // sets left justification
     * 5. right                 // sets right justification
     * 6. scientific            // use scientific notation for numbers    1000000 -> 1E+06
     * 7. fixed                 // 'not' scientific notation
     * 8. showpoint             // if you want to see digits after a decimal, even if they are just zeroes
     * 9. setprecision(num)     // sets the precision of floating point numbers, how many decimal places show
     * 10. noshowpoint          // turn off showpoint
     * 11. setfill('*')         // when using setw, would pad the spaces with any characters, can be any character
     */

    /**
     * File I/O
     */

    string line;
    
    ifstream inp;
    inp.open("input.txt");      // Note - use input.txt for all assignments for grading reasons

    ofstream out;
    out.open("output.txt"       // Note - use output.txt for all assignments for grading reasons
    , ios::out);                // Can use out or app - controls overwrite or append behavior for the file

    while(!inp.eof())
    {
        getline(inp, line);
        // perform checks for data validation
        out << line << endl;
    }

    inp.close();                // Always close a file when done using it
    out.close();


    return 0;
}