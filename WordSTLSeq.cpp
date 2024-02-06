/*!
    \file WordSTLSeq.cpp
    \brief Method implementations for the WordSTLSeq class.
*/

#include <sstream>
#include <iostream>
#include "WordSTLSeq.h"
#include "WordData.h"
#include "WordList.h"

using namespace std;
/*! 
    WordSTLSeq object constructor */
    //construct WordVectorList object
    WordSTLSeq::WordSTLSeq() {};
/*! 
    \fn seqSearch - searches the list to find matches for any unique tokens. If not found it returns false, if found increments count and returns true.
    \return bool - returns true or false whether or not the word was found in the list
    
*/  
    int WordSTLSeq::seqSearch(string key) {
        int index; 
        for (index = 0; index < vectorList.size() && vectorList[index].getWord() != key ; index++);
        if (index == vectorList.size()) return -1;
        return index;
    }
    
/*! 
    \fn parseIntoList - puts the word into the list if the condition that it was not already found is met.
    \param inf - passes the input file to the method
    \return bool - returns true or false if the Node is found in the list
*/    
    void WordSTLSeq::parseIntoList(ifstream &inf) {
        string key;
        int index = 0;
        while (inf >> key) {
            index = seqSearch(key);
            if (index > -1){
                vectorList[index]++;
            }
            else {
                vectorList.push_back(WordData(key,1));
            }
        }
    }

/*! 
    \fn printIteratively - prints the header and object vector list using a list iterator 
    
*/
    // Print the data iteratively 
    void WordSTLSeq::printIteratively() {
    //  void printObjectArrayIterator(WordData TheWords[], int numWords)
    cout<<"----------------------------"<<endl;
    cout<<"|Object  Vector   Iterative|"<<endl;
    cout<<"|Word           Occurences |"<<endl;  
    cout<<"----------------------------"<<endl;
    
    for(vector<WordData>:: iterator it = vectorList.begin(); it !=vectorList.end() ; it++){
    cout << " ";
    cout << *it;
    cout << endl;
    }
  }
/*! 
    \fn printRecursively - prints the header and object vector list using 
    a helper method that does the actual recursion 
    
*/
    void WordSTLSeq::printRecursively(){
        cout << "----------------------------" << endl;
        cout << "| Object  Vector  Recursive|" << endl;
        cout << "| Word          Occurences |" << endl;
        cout << "----------------------------" << endl;
       
        int index = 0;
        printRecursiveHelper(index); 
    }

/*! 
    \fn printRecursiveHelper - Method that uses recursion to print out the vectorList
    
*/  
    void WordSTLSeq:: printRecursiveHelper(int index){
        // Base case: if index is equal to the size of the vector, we have printed all the elements
       if (index == vectorList.size()) {
            return;
        }
    
        // Recursive case: print the element at the current index, then recursively print the rest of the vector
        cout <<" "<< vectorList[index] << endl ;
        printRecursiveHelper(index+1);
    }

