/****************************************************************/
/*   Filename:       WordData.h                                 */
/*   Purpose:        The Only Addition i made to this file was  */ 
/*                   an overloading of the << operator.         */
/****************************************************************/

/*
    \file WordData.h 
    \brief Class file for a WordData object used by the three other 
    container types in the inheritance hierarchy.
    
*/
#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;

/*
    \class WordData
    \brief WordData class declaration, defintions of methods are in WordData.cpp.
    Contains gets and sets for counting occurences for words of an input file.
*/
class WordData {

public:

        //Constructor
/*
    \fn Constructor 
    This is the constructor for a WordData object. It sets the data which is a string 
    for the words and an integer to keep the occurence count. 
*/
        WordData(string wrd = "", int cnt = 1);

        //Sets
        
/*!
    setWord - sets the word of a unique token - facilitator 
*/
        void setWord(string wrd);
/*!
    setCount - sets the count of a unique token - facilitator 
*/
        void setCount(int cnt);

        //Set Whole WordData Object
        
/*!
    setWordData - sets the word of a unique token and its count using the setCount and setWord methods - facilitator 
*/
        void setWordData(string,int);

        //Gets
/*!
    getWord - gets the word of a unique token - inspector 
*/
        string getWord() const;
/*!
    getCount - gets the count of a unique token - inspector 
*/
        int getCount() const;

        //Increment
/*!
    incCount - increments the count of a word's occurence counter - mutator  
*/
        void incCount(int inc = 1);

        //testing 
/*!
    \overload operator ++
    overloads the pre increment operator by incrementing the occurence count
*/
        void operator++();	// prefix increment
/*!
    \overload operator ++ (int)
    \param int - takes in an integer to differentiate between pre and post
    overloads the post increment operator by incrementing the occurence count
*/
        void operator++(int);	// postfix increment
/*!                                                                                                               
    \overload operator >
    overloads the greater than operator by comparing the words object being passed in tp the getWord() method on the WordData 
    object being passed in. 
    \param words - WordData abstract type object as a const reference                                                                         
*/
        bool operator>(const WordData&) const;
/*!                                                                                                               
    \overload operator <
    overloads the less than operator by comparing the words object being passed in tp the getWord() method on the WordData 
    object being passed in. 
    \param words - WordData abstract type object as a const reference                                                                         
*/
        bool operator <(const WordData&) const;
/*!                                                                                                               
    \overload operator ==
    overloads the equality operator by comparing the words object being passed in tp the getWord() method on the WordData 
    object being passed in. 
    \param words - WordData abstract type object as a const reference                                             
*/
        bool operator == (const WordData&) const;
/*!                                                                                                               
    \overload operator !=
    overloads the not equal to operator by comparing the words object being passed in tp the getWord() method on the WordData 
    object being passed in. 
    \param words - WordData abstract type object as a const reference                                            
*/
        bool operator != (const WordData&) const;

private:

        //variables
        string word; /*! variable to hold the string for each unqiue token */
        int count; /*! variable to hold the integer count for each unqiue token */


};
/*!
    \overload operator<<
    \param output - reference to ouput stream 
    \param words - reference to WordData abstract type list 
    overloads the stream insertion operator and returns a reference to the output stream 
*/
ostream &operator<<(ostream& output, const WordData &words);

#endif