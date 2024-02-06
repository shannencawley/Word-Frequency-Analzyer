/*!
    \file WordCList.h
    \brief The declaration of the WordCList class, inherited by the WordList class.
    This file contains the method declarations for the implementation in the WordCList.cpp file
*/
    
#ifndef WORDCLIST_H
#define WORDCLIST_H
#include "CircularList.h"
#include "WordList.h"
#include "WordData.h"
#include "assert.h"
#include <iostream>

using namespace std;
/*!
  \class WordCList 
  \brief Defines a WordCList container of WordData type that inherits the methods associated with the WordList class and WordCList being one of its' subclasses. 
*/
class WordCList : public WordList {
    public:
/*! \fn constructor 
    constructs a WordCList Object
*/    
        WordCList();
/*! \fn parseIntoList 
    puts the key words into the circular linked list if the key is not already found and increments its count.
    \param inf - passes in input file stream to the method
*/    
        virtual void parseIntoList(ifstream &inf);
/*! \fn printIteratively 
    search method to find matches for unqiue tokens from the text file
    \param key - string that contains unique tokens, looking to match for
*/    
        virtual void printIteratively();
/*! \fn printRecursively - prints the circular linked list and 
    the header using a recursive helper method
*/       
        virtual void printRecursively();
    
    private:
        CLinkedList<WordData> CircularList; /*! Declares a CircularList which is a CLinkedList object of WordData type */
/*! \fn printRecursiveHelper 
    Method that uses recursion to print out the circular linked list
*/        
        void printRecursiveHelper(ListIterator<WordData>& iter);
/*! \fn circSearch 
    search method to find matches for unqiue tokens from the text file and increments their counts accordingly.
    The method returns -1 if the key is found adn returns the Node at which it was found if not.
    \param key - string that contains unique tokens, looking to match for
    \return index - returns index -1 if the word is found
*/        
        bool circSearch (const WordData& key);
};

#endif