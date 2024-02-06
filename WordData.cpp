/***************************************
 *    File:    WordData.cpp            *
 *    Purpose:                      *
 *                                     *
 ***************************************/

/*! \file WordData.cpp
    \brief Word Data is an instance of the WordList class
    
    This contains the defintions of the get/set methods declared in WordData.h
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;
/*! 
    \fn Constructor 
    This is the constructor for a WordData object. It sets the data which is a string 
    for the words and an integer to keep the occurence count. 
*/
WordData::WordData(string wrd, int cnt)
{
        setWordData(wrd, cnt);
}
/*!
    setWord - sets the word of a unique token - facilitator 
*/
void WordData::setWord(string wrd)
{
        word = wrd;
}
/*!
    setCount - sets the count of a unique token - facilitator 
*/
void WordData::setCount(int cnt)
{
        count = cnt;
}
/*!
    setWordData - sets the word of a unique token and its count using the setCount and setWord methods - facilitator 
*/
void WordData::setWordData(string wrd, int cnt)
{
        setWord(wrd);
        setCount(cnt);
}
/*!
    getWord - gets the word of a unique token - inspector 
*/
string WordData::getWord() const
{
        return(word);
}
/*!
    getCount - gets the count of a unique token - inspector 
*/
int WordData::getCount() const
{
        return(count);
}
/*!
    incCount - increments the count of a word's occurence counter - mutator  
*/
void WordData::incCount(int inc)
{
        count+=inc;
}

/*!
    \overload operator ++
    overloads the pre increment operator by incrementing the occurence count
*/

void WordData::operator++() {
    ++count;
}
/*!
    \overload operator ++ (int)
    \param int - takes in an integer to differentiate between pre and post
    overloads the post increment operator by incrementing the occurence count
*/
void WordData::operator++(int) {
    count++;
}

/*!                                                                                                               
    \overload operator>
    overloads the greater than operator by comparing the words object being passed in tp the getWord() method on the WordData 
    object being passed in. 
    \param words - WordData abstract type object as a const reference                                            
*/
bool WordData::operator>(const WordData& words) const{
    return (word > words.getWord());
}
/*!                                                                                                               
    \overload operator<
    overloads the less than operator by comparing the words object being passed in tp the getWord() method on the WordData 
    object being passed in. 
    \param words - WordData abstract type object as a const reference                                            
*/
bool WordData::operator <(const WordData& words) const{
    return (word < words.getWord());
}
/*!                                                                                                               
    \overload operator ==
    overloads the equality  operator by comparing the words object being passed in tp the getWord() method on the WordData 
    object being passed in. 
    \param words - WordData abstract type object as a const reference                                            
*/
bool WordData::operator == (const WordData& words) const{
    return word == words.getWord();
}
/*!                                                                                                               
    \overload operator !=
    overloads the not equal to operator by comparing the words object being passed in tp the getWord() method on the WordData 
    object being passed in. 
    \param words - WordData abstract type object as a const reference                                             
*/
bool WordData::operator != (const WordData& words) const{
    return word!= words.getWord();
}

/*!
    \overload operator<<
    \param output - reference to ouput stream 
    \param words - reference to WordData abstract type list 
    overloads the stream insertion operator and returns a reference to the output stream 
*/
ostream &operator<<(ostream& output, const WordData &words)
{
  output<<words.getWord()<<"\t\t"<<words.getCount();
  return output;
}