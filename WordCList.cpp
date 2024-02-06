/*!
    \file WordCList.cpp
    \brief This file contains the implementations for a WordCList container Object
    which involves searching a list to find same word occurences and print the
    circular linked list iteratively and recursively 
    
*/

#include <sstream>
#include <iostream>
#include "WordCList.h"
#include "WordData.h"
#include "WordList.h"

using namespace std;
/*! \fn constructor 
    constructs a WordCList Object
*/
    WordCList::WordCList() {};
    
/*! \fn circSearch 
    search method to find matches for unqiue tokens from the text file and increments their counts accordingly.
    The method returns true if the key is not found and false if it is found. If it is found it incrments the count for that node and keeps going while it hasn't reached the first node, meaning it hasn't completed a full search through the list. 
    \param key - WordData object that contains unique tokens, looking to match for
    \return index - returns true or false based on whether or not the key was found
*/
    bool WordCList::circSearch(const WordData& key){
        ListIterator<WordData> iter(CircularList);
        int count = 0;
        
        if(!CircularList.find(key)){
            return true;
        }
	iter.begin();
	do {
	  if(*iter == key){ // if the iter is the same as the key that was passed from the file
	    (*iter).incCount(); // increment its count 
	    return false; // return false
          }
	  iter++; // move to the next node
	} while(!iter.isFirstNode());	// check while the iter is not on the first node meaning it didn't completely go through the list
        return false; 
   }

/*! \fn parseIntoList 
    This method inserts the file into a string and sets the keys counts to 1 once it reads the word. If the list is empty it inserts the words and begins traversing the list, otherwise it calls the circSearch method to insert the word into the list and increment the count of the found word. 
    \param inf - passes in input file stream to the method
*/
    void WordCList::parseIntoList(ifstream& inf){
        string key;
        WordData word;
        ListIterator <WordData> iter(CircularList);
        
        while(inf >> key){
	  word.setWord(key);
	  word.setCount(1);
            if (iter.isEmpty()) {
                CircularList.insert(word);
		iter.begin();
	    }
	    else {
	      if(circSearch(word)){
		CircularList.insert(word);
	      }
	    }
	}
    }

/*! \fn printIteratively 
    search method to find matches for unqiue tokens from the text file
    \param key - string that contains unique tokens, looking to match for
*/
void WordCList::printIteratively() {
    cout << "----------------------------" << endl;
    cout << "| Object Circular Iterative|" << endl;
    cout << "| Word  Linked  Occurences |" << endl;
    cout << "----------------------------" << endl;
    ListIterator<WordData> iter(CircularList);
    
    if (iter.isEmpty()) {
        cout << "Empty List" << endl;
        return;
    }
    iter.begin();
    do {
        cout << " ";
        cout << *iter;
        cout << endl;
        iter++;
    } while (!iter.isLastNode());
    cout << " ";
    cout << *iter;
    cout << endl;
    
    /*if (iter.isEmpty() == true) {
       cout << "Empty List" << endl;
        return;
    }
    for (iter.begin(); !iter.isLastNode(); iter++){
    cout << " ";
    cout << *iter;
    cout << endl;
    return;
    } */
    
    /*if (iter.isEmpty() == true) {
        cout << "Empty List" << endl;
        return;
    }
    for (iter.begin(); !iter.isLastNode(); iter++){
        cout << " ";
        cout << *iter;
        cout << endl;
    }
    cout << " ";
    cout << *iter;
    cout << endl;*/
}
/*! \fn printRecursively - prints the circular linked list and 
    the header using a recursive helper method
*/
void WordCList::printRecursively() {
    cout << "----------------------------" << endl;
    cout << "| Object Circular Recursive|" << endl;
    cout << "| Word  Linked  Occurences |" << endl;
    cout << "----------------------------" << endl;
    int index;
    ListIterator <WordData> iter(CircularList);
    
    if (iter.isEmpty()) {
        cout << "Empty List" << endl;
        return;
    }
    iter.begin();
    printRecursiveHelper(iter);
    
    //iter.begin();
    //printRecursiveHelper(iter);
}
/*! \fn printRecursiveHelper 
    Method that uses recursion to print out the circular linked list
*/
void WordCList::printRecursiveHelper(ListIterator<WordData>& iter) {
    cout << " " << *iter << endl;
    iter++;
    if (!iter.isFirstNode()) {
        printRecursiveHelper(iter);
    }
    /*if(iter.isLastNode()){
        cout << *iter << endl;
        return;
    }
    cout << *iter << endl;
    iter++;
    printRecursiveHelper(iter);*/
} 