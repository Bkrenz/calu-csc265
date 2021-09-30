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

class List {

    public:
        List();
        ~List();
        void insert(const int data);
        void remove(const int data);
        void printList() const;

    private:
        int* array;

    protected:
        int* getListArrayPointer() const;

};

#endif
