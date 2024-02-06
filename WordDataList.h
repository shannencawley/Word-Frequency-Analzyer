// File: WordDataList.h
// Container of WordData objects. 
// Printing can be iterative or recursive. 
/* 
    \file WordDataList.h
    \brief This is the class file for the WordDataList that 
    uses arrays to read words from a file to count the number of occurences for
    the first 10 unqiue words.
*/

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;
/*
    \class WordDataList
    \brief class declaration for a WordDataList object that is a subclass of WordList
    and inherits its' methods. 
*/
class WordDataList : public WordList {
public:
/*! 
    Object constructor
*/
  WordDataList();
/*
    \fn parseIntoList puts the word into the list if the condition that it was not already found
    and if the list is less than 10. In the array implementation of the WordList object, only 
    10 elements are allowed in the array. 
    \param inf - passes the file thorugh the input stream to the method
*/
  // Put a string of strings into the list object
  virtual void parseIntoList(ifstream &inf);
/*
    \fn printIteratively - prints the array of words and their number of occurences
    using iterations.
*/
  // Print the data iteratively
  virtual void printIteratively();
/*
    \fn printRecursively - calls the recursion helper function 
    to print the array of words and their number of occurences.
*/ 
  // Print the data recursively
  virtual void printRecursively();
/*
    \fn printPtr - calls the helper method to output 
    the array of words and their number of occurences.
*/  
  // Print the data recursively with a pointer
  
  virtual void printPtr();

private:
  WordData TheWords[10]; /*! Declaration of an array named TheWords of WordData type */
  int numWords; /*! Decaration of an integer type variable that holds the number of words in use*/

/* 
    \fn incMatch returns true or false based on whether or not the temp matches the word in the list. 
    It returns true if the word is found and false if not. 
    \param temp - string that holds the words to be looked for from the file. 
*/
  // Look for a match and increment if found
  bool incMatch(string temp);
/*
    \fn printRecursively - prints the array of words and their number of occurences
    using recursion.
    \param numWords - keeps track of the number of words in use, goes up until 10
*/  
  // Function to actually perform recursive print
  void printRecursivelyWorker(int numWords);
/*
    \fn printPtrWorker - Uses pointers and recursion to output 
    the array of words and their number of occurences.
    
    \param numWords - integer of the number of words in use
*/
  // Function to actually perform recursive print using pointer
  void printPtrWorker(int numWords);


};
  
#endif