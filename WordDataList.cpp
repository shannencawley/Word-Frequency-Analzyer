/*! \File: WordDataList.cpp
  Container of WordData objects 
  Implementations of member functions including inherited pure virtual fns.
*/
#include <sstream>
#include <iostream>
#include "WordDataList.h"

using namespace std;
/*! 
    Constructor for a WordDataList object that is inherited from a WordList class.
    Sets the number of words in use to 0. 
*/
  WordDataList::WordDataList()
  { numWords=0; }
  
/*! 
    \fn incMatch returns true or false based on whether or not the temp matches the word in the list. 
    It returns true if the word is found and false if not. 
    \param temp - string that holds the words to be looked for from the file. 
*/
  bool WordDataList::incMatch(string temp)
  { for(int i=0; i<numWords; i++) {
      if (temp==TheWords[i].getWord()) {
        TheWords[i].incCount();
        return true;
      }
    }  
    return false;
  }
/*! 
    \fn parseIntoList puts the word into the list if the condition that it was not already found
    and if the list is less than 10. In the array implementation of the WordList object, only 
    10 elements are allowed in the array. 
    \param inf - passes the file thorugh the input stream to the method
*/
  void WordDataList::parseIntoList(ifstream &inf)
  { string temp;
    while (inf >> temp) 
      if (!incMatch(temp) && numWords < 10) {
          TheWords[numWords].setWord(temp);
          TheWords[numWords++].setCount(1);
      }
  }
/*! 
    \fn printIteratively - prints the array of words and their number of occurences
    using iterations.
*/
  // Print the data iteratively
  void WordDataList::printIteratively()
  
  {
    cout<<"--------------------------"<<endl;
    cout<<"|Object  Array  Iterative|"<<endl;
    cout<<"|Word         Occurences |"<<endl;  
    cout<<"--------------------------"<<endl;
    for(int i=0; i<numWords; i++)
    cout<<" "<<TheWords[i]<<endl;
  }

/*! 
    \fn printRecursively - prints the array of words and their number of occurences
    using recursion.
    \param numWords - keeps track of the number of words in use, goes up until 10
*/
  // Print the data recursively
  void WordDataList::printRecursivelyWorker(int numWords)
  //void printObjectArrayRecursive(WordData TheWords[], int numWords)
  {if (numWords==1) {
      cout<<"--------------------------"<<endl;
      cout<<"|Object  Array  Recursive|"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      cout<<" "<<TheWords[numWords-1]<<endl;
      return;
    }
    printRecursivelyWorker(numWords-1);
    cout<<" "<<TheWords[numWords-1]<<endl;
  }
/*! 
    \fn printRecursively - calls the recursion helper function 
    to print the array of words and their number of occurences.
*/
  // Call worker function to print the data recursively
  void WordDataList::printRecursively()
  {  printRecursivelyWorker(numWords); }

/*! 
    \fn printPtrWorker - Uses pointers and recursion to output 
    the array of words and their number of occurences.
    
    \param numWords - integer of the number of words in use
*/
  // Print the data recursively with a pointer
  void WordDataList::printPtrWorker(int numWords)
  //void printObjectArrayPointerRecursive(WordData* TheWords, int numWords)
  {if (!numWords)
    { cout<<"--------------------------"<<endl;
      cout<<"|Object  Array  Pointer  |"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      return;
    }
    printPtrWorker(numWords-1);
    cout<<" "<<*(TheWords+(numWords-1))<<endl;
  }

/*! 
    \fn printPtr - calls the helper method to output 
    the array of words and their number of occurences.
    
*/
  // Call worker function to print the data recursively
  void WordDataList::printPtr()
  { printPtrWorker(numWords); }