/**
 * 
 * Author: Robert Krency
 * Author: Austin Pringle
 * Author: Anthony Stepich
 * 
 * Assignment 2 for CSC 265.
 * 
 */

#include "list.h"


List::List() {
    // Initialize the array to size 2
    array = new int[2];
    arrayLength = 2;
}


List::~List(){
    // Delete the array
    delete [] array;
}


void List::insert(int data){

    // Check if the array is full and needs to be expanded
    if ( this->arrayLength == this->arraySize )
    {
        // Incraese the size by 2
        this->arraySize += 2;

        // Create a new array and copy values
        int* newArray = new int[this->arraySize];
        for (int i = 0; i < this->arrayLength; i++)
            newArray[i] = this->array[i];

        // Delete the old array
        delete [] this->array;

        // Set to new array
        this->array = newArray;
    }

    // Add the data to the List
    this->array[ this->arrayLength ] = data;
    this->arrayLength++;

}


void List::remove(int data){

    // Check if the data is in the list
        // If it is, remove the first instance and shift all data to the left
        // Careful with nulls and shifting data

}


void List::printList() const{

    // For each element in the array
        // Print the element
        // Print an endl;

}


