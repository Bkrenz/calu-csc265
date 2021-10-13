/**
 * 
 * Author: Robert Krency
 * Author: Austin Pringle
 * Author: Anthony Stepich
 * 
 * Assignment 2 for CSC 265.
 * 
 */

#ifndef __LIST_H__
#define __LIST_H__

/**
 *  Class List
 *      Defines a list with appropriate functions for removing and inserting elements, and printing the list
 *  
 *  void insert(const int data)
 *      description: Inserts a value at the end of the list
 *      precondition: none
 *      postcondition: The data input is added to the end of the list
 * 
 *  void remove(const int data)
 *      description: Removes the first occurrence of the input data, if it exists, and shifts all data in the list to the left
 *      precondition: none
 *      postcondition: Data removed if exists
 * 
 *  void printList() const 
 *      description: Prints the list, with each element on a new line
 *      precondition: none
 *      postcondition: List printed to output
 * 
 */

class List {

    public:
        List();
        ~List();

        void printList() const;
        
        /* Modification Methods */
        void insert(const int data);
        void remove(const int data);
        
        /* Constant Accessor Methods */
        int getLength() const;

    private:
        int arrayLength;    // Tracks how many items are in the array
        int arraySize;      // Tracks the total size of the array

    protected:
        int* array;         // Dynamic array as the list

};

#endif
