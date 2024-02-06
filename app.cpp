
/*! \file app.cpp
*   \brief This is the application for the abstract WordList container class.
*
*    This application reads an input file and counts the occurences of each word in the file.
*    
*    The list can be expressed as an array, a circularly linked list, and a vector.
*    These three containers inherit the abstract class WordList
*/


#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>

// include these subclass headers
#include "WordList.h"
#include "WordDataList.h"
#include "WordSTLSeq.h"
#include "WordCList.h"

#include "WordData.h"       // app only knows about the lists!

using namespace std::chrono;
using namespace std;

void printArrayTimes(ifstream &inf,WordList *TheList);
void printCTimes(ifstream &inf,WordList *TheList);
void printSTLTimes(ifstream &inf,WordList *TheList);
/*! 
    \fn displayMenu
    The displayMenu function displays the 8 menu options for the container types
*/
void displayMenu();
/*********************************************************************/
/*   Function Name: displayMenu()                                    */
/*                                                                   */
/*   Description: Displays the menu on the screen.                   */
/*********************************************************************/

/*! 
    \param inf Takes the file stream as a reference parameter
    \param TheList The abstract list of WordList type that will be manipulated
    
    \fn printEverything
    The printEverything function displays all 7 output options for the 
    three container types (array, vector, circular linked list)
*/
void printEverything(ifstream &inf,WordList *TheList);
/*********************************************************************/
/*                                                                   */
/*   Function Name: printEverything                                  */
/*                                                                   */
/*   Description: Takes in a sentence and sends it through every     */
/*                parsing and printing function                      */
/*                                                                   */
/*   Parameters:  string sentence - sent to every function           */
/*                WordDataList TheList - The array of object         */
/*********************************************************************/


int main(int argc,char *argv[])
{ ifstream inf;
  WordList *theList;
  
  if(argc>1) //if there was an input on the command line
    {
      inf.open(argv[1]); //try and open the file
      if (inf.fail())       //if the file does not open
        {                    //terminate
          cout<<"Sorry, the file failed to open."<<endl;
          return 0;
        }
      printEverything(inf,theList);
      return 0;
    }

  char selection;
  string fileName;
  cout<<"Please enter a file name:"<<endl;
  getline(cin,fileName);
  inf.open(fileName.c_str());
  
  // TheList is a pointer to a WordList that is pointed at a WordList subclass
   // Apply polymorphism
  
  while (true)
    {
      
      displayMenu();
      cin>>selection;
      switch(selection)
        { case '1':
          case '2':
          case '3':
            theList=new WordDataList;
            theList->parseIntoList(inf);
            break;
          case '4':
          case '5':
            theList=new WordCList;
            theList->parseIntoList(inf); 
            break;
          case '6':
          case '7':
            theList=new WordSTLSeq;
            theList->parseIntoList(inf); //polymorphism
            break;
          case '8':
            cout<<"Goodbye"<<endl;
            return 0;
          default:
            cout<<"I cannot understand "<<selection<<".  Try again."<<endl;
            break;
        }
      switch(selection)
        { case '1':
          case '4':
          case '6':
            theList->printIteratively();
            break;
          case '2':
          case '5':
          case '7':
            theList->printRecursively();
            break;
          case '3':
            theList->printPtr();
            break;
          case '8':
            cout<<"Goodbye"<<endl;
            return 0;
          default:
            cout<<"I cannot understand "<<selection<<".  Try again."<<endl;
            break;
        }
        inf.clear();
        inf.seekg(0);
    }
  return 0;
}
/*! \fn displayMenu
    Displays the menu options 
*/

void displayMenu()
{
  cout<<endl;
  cout<<"How do you want to print your sentence elements?"<<endl;
  cout<<"------------------------------------------------"<<endl;
  cout<<"1. Object Array Iterative"<<endl;
  cout<<"2. Object Array Recursive"<<endl;
  cout<<"3. Object Array Pointer Recursive"<<endl;
  cout<<"4. Circular List Iterator"<<endl;
  cout<<"5. Circular List Recursive"<<endl;
  cout<<"6. STL Vector Iterative"<<endl;
  cout<<"7. STL Vector Recursive"<<endl;
  cout<<"8. Exit"<<endl;
}

/*! \fn printEverything
    Prints out all 7 menu option lists in the various container types with the number of microseconds it takes to parse the file into the list and also print out the tables in the various ways using functions (printArrayTimes, printCTimes, printSTLTimes)
*/
void printEverything(ifstream &inf,WordList *theList)
{
  printArrayTimes(inf,theList);

  inf.clear();
  inf.seekg(0);

  printCTimes(inf, theList);

  inf.clear();
  inf.seekg(0);

  printSTLTimes(inf,theList);
}
void printArrayTimes(ifstream &inf,WordList *theList){
  theList=new WordDataList;
  auto begin = high_resolution_clock::now() ;
  theList->parseIntoList(inf);
  auto end = high_resolution_clock::now() ;
  auto ticks = duration_cast<microseconds>(end-begin) ;

  auto start = high_resolution_clock::now() ;
  theList->printIteratively();
  auto finish = high_resolution_clock::now() ;
  auto time= duration_cast<microseconds>(finish-start) ;

  auto b = high_resolution_clock::now() ;
  theList->printRecursively();
  auto e = high_resolution_clock::now() ;
  auto t= duration_cast<microseconds>(e-b) ;

  auto s = high_resolution_clock::now() ;
  theList->printPtr();
  auto f= high_resolution_clock::now() ;
  auto c = duration_cast<microseconds>(f-s) ;
  cout << "It took " << ticks.count() << " microseconds to parse into the list.\n" ;
  cout << "It took " << time.count() << " microseconds to print iteratively.\n" ;
  cout << "It took " << t.count() << " microseconds to print recursively.\n" ;
  cout << "It took " << c.count() << " microseconds to print using a pointer.\n" ;
  
}

void printCTimes(ifstream &inf,WordList *theList){
  theList=new WordCList;
  auto begin = high_resolution_clock::now() ;
  theList->parseIntoList(inf);
  auto end = high_resolution_clock::now() ;
  auto ticks = duration_cast<microseconds>(end-begin) ;
  
  auto start = high_resolution_clock::now() ;
  theList->printIteratively();
  auto finish = high_resolution_clock::now() ;
  auto time = duration_cast<microseconds>(finish-start) ;

  auto b = high_resolution_clock::now() ;
  theList->printRecursively();
  auto f = high_resolution_clock::now() ;
  auto t = duration_cast<microseconds>(f-b) ;
  cout << "It took " << ticks.count() << " microseconds to parse into the list.\n" ;
  cout << "It took " << time.count() << " microseconds to print iteratively.\n";
  cout << "It took " << t.count() << " microseconds to print recursively.\n";
}

void printSTLTimes(ifstream &inf,WordList *theList){
  theList=new WordSTLSeq;
  auto begin = high_resolution_clock::now() ;
  theList->parseIntoList(inf);
  auto end = high_resolution_clock::now() ;
  auto ticks = duration_cast<microseconds>(end-begin) ;
  
  auto start = high_resolution_clock::now() ;
  theList->printIteratively();
  auto finish = high_resolution_clock::now() ;
  auto time = duration_cast<microseconds>(finish-start) ;

  auto b = high_resolution_clock::now() ;
  theList->printRecursively();
  auto f = high_resolution_clock::now() ;
  auto t = duration_cast<microseconds>(f-b);
  cout << "It took " << ticks.count() << " microseconds to parse into the list.\n" ;
  cout << "It took " << time.count() << " microseconds to print iteratively." << endl;
  cout << "It took " << t.count() << " microseconds to print recursively." << endl;
 
}
