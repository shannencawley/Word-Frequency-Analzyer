// File: WordList.h
// Abstract base class for containers of word data
// Known subclasses:
//      WordDataList

/*! 
    \file WordList.h
    \brief Abstract base class for containers of WordData type.
    Subclasses are WordDataList, WordCList, WordVectorList. 
*/

#ifndef WORDLIST_H
#define WORDLIST_H

#include <fstream>
#include <string>

using namespace std;
/*! 
  \class WordList
  \brief This declares the methods for the WordList class which is the parent class of the WordCList, WordDataList, and WordSTLSeq subclasses. 
*/
class WordList {
public:

/*! 
    \fn parseIntoList - puts the text from the file into the abstract WordList type 
    \param inf - passes the input stream as a parameter, the file read in
*/
  // Place the line of text into the data structure
  virtual void parseIntoList(ifstream &inf)=0;
/*! 
    \fn printIteratively - prints the abstract type list using iteration/iterators  
*/
  // Print the data iteratively
  virtual void printIteratively()=0;
/*! 
    \fn printRecursively - prints the abstract type list using recursion and a recursive helper method   
*/  
  // Print the data recursively
  virtual void printRecursively()=0;
/*! 
    \fn printPtr - prints the abstract type list using pointers (only for the array object)
*/  
  // Print the data recursively with a pointer
  virtual void printPtr() {}   // not pure virtual; why?
    
};
  
#endif