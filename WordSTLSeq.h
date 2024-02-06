/*! 
    \file WordSTLSeq.h
    \brief Class defintion that inherits the methods of the WordList class
    Container object for an STL object, a vector in this case

*/
#ifndef WORDSTLSEQ_H
#define WORDSTLSEQ_H

#include "WordList.h"
#include "WordData.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;
/*! 
    \class WordSTLSeq 
    \brief class declaration for a WordSTLSeq object that is a subclass of WordList
    and inherits its' methods. 
    
*/
class WordSTLSeq : public WordList {
	
 public:  //PUBLIC FUNCTIONS
/*! 
    WordSTLSeq object constructor 
    
*/
  WordSTLSeq();
/*! 
    \fn parseIntoList - puts the word into the list if the condition that it was not already found is met.
    \param inf - passes the input file to the method
    \return bool - returns true or false if the Node is found in the list
*/
  //put string of strings into vector list 
  virtual void parseIntoList(ifstream&inf);
 
/*! 
    \fn printIteratively - prints the header and object vector list using a list iterator 
    
*/
  virtual void printIteratively();
/*! 
    \fn printRecursively - prints the header and object vector list using 
    a helper method that does the actual recursion 
    
*/
  virtual void printRecursively();
  
  private:
    vector<WordData> vectorList; /*! Declares a vectorList of WordData type */
    
/*! 
    \fn seqSearch - searches the list to find matches for any unique tokens. If not found it returns false, if found increments count and returns true.
    \return bool - returns true or false whether or not the word was found in the list
    
*/    
    // look for match and increment if found
    int seqSearch (string key);
/*! 
    \fn printRecursiveHelper - Method that uses recursion to print out the vectorList
    
*/  
    void printRecursiveHelper(int index);
  
  //friend ostream &operator<< (ostream &output, const WordVectorList& word); // operator overload
};
  
#endif