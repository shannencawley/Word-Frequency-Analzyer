/*!                                                                                          
    \file CircluarList.h                                                                     
    \brief The declaration and defintions for the Node, CLinkedList, and ListIterator classe\
s                                                                                            
*/

#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H
#include "assert.h"
#include <iostream>

using namespace std;

template<class T> class ListIterator;
template <typename T> class CLinkedList;
template <typename eltType> ostream& operator<<(ostream&, const CLinkedList<eltType>&);

/*!                                                                                          
    \class Node                                                                              
    \brief Defines a Node for a circular linked list, CLinkedList                            
*/
// NODE CLASS                                                                                
template <typename eltType> class Node {
    private:
                Node(eltType info, Node* link = NULL ) :
                                               data(info), next(link)
                {};
                eltType data;
                Node *next;
                /*! CLinkedList is a friend of the Node class */
        friend class CLinkedList<eltType>;
        /*! ListIterator is a friend of the Node class */
        friend class ListIterator<eltType>;
};

/*!                                                                                          
    \class CLinkedList                                                                       
    \brief Defines a CLinkedList container object along with the included methods            
*/
// CLINKEDLIST CLASS                                                                         
template <typename eltType> class CLinkedList {
public:
/*!                                                                                          
    constructor for a CLinkedList, sets the last to NULL                                     
*/
    // constructor, no definiton needed because it is declared here                          
    CLinkedList() : last(NULL) {}
    //copy constructor                                                                       
/*!                                                                                          
    copy constructor for a CLINKEDLIST                                                       
    \param value - reference variable to abstract CLikedList object                          
*/
   CLinkedList(const CLinkedList<eltType>& value);
/*!                                                                                          
    deconstructor for a CLinkedList                                                          
    destroys all the nodes in the list                                                       
*/
    //deconstructor                                                                          
    ~CLinkedList();
/*!                                                                                          
    \fn empty - returns true or false based on whether or not the list is empty              
*/
    //returns true or false if list is empty                                                 
    bool empty() const;
/*!                                                                                          
    \fn insert - inserts a new node into the list, in numeric order                          
    \param value - reference variable of eltType                                             
*/
    // allows insert new node                                                                
    void insert(const eltType& value);
/*!                                                                                          
    \fn remove - removes a Node in the list                                                  
    \param value - reference variable of eltType                                             
*/
    // allows to remove a node                                                               
    void remove(const eltType& value);
/*!                  
    \fn reverse - reverses all the Nodes in the list                                         
    \param CLinkedList - reference to the abstract list type itself                          
*/
    // allows to reverse the linked list                                                     
    void reverse(CLinkedList <eltType>&);
/*!  defines a pointer named last to the last Node in the list */
    Node<eltType> *last;

    bool find(eltType);
private:
/*!                                                                                          
    \fn destroy - destroys all the nodes in the list, called in the deconstructor            
    \param Node - pointer to the Nodes in the list                                           
*/
    // destroys all nodes                                                                    
    void destroy (Node<eltType>*);
/*!                                                                                          
    \fn reverseList - helper method used to reverse all the Nodes in the list                
    \param Node - pointer to the Nodes in the list                                           
*/
    // recursive method used in reverse method                                               
    void reverseList(Node<eltType> *);
/*!                     
   \fn copy - does a deep copy of every Node in the list                                    
    \param Node - pointer to the Nodes in the list                                           
*/
    // gets deep copy of a Node                                                              
    Node<eltType>* copy(Node<eltType>*);
/*!  defines a pointer named last to the last Node in the list */
   // Node<eltType> *last;                                                                   
/*! makes the output stream operator a friend of the CLinkedList class */
friend ostream& operator<< <eltType>(ostream& os, const CLinkedList<eltType>& list);
/*! makes the ListIterator class a friend of the CLinkedList class */
friend class ListIterator<eltType>;
};


template <typename eltType>
    bool CLinkedList<eltType>::find(eltType x){
        if(last == NULL){
          return false;
        }
        Node<eltType> *p = last -> next;

        while (p != last && p->data != x)
          p = p->next;
        if(p->data != x)
          p=p->next;
        return (p->data == x);
    }
////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      operator <<                                                           
//   Description:      overloaded stream insertion operator, allows                          
//                     cout in tabular form                                                  
//   Member Type:      facilitator                                                           
//   Parameters:       ostream os(output), object of CLinkedList(input)                      
//   Return Value:     returns ostream                                                       
//                                                                                           
////////////////////////////////////////////////////////////////////////                     
// overloaded stream insertion operator                                                      
/*!                                                                                          
    \overload operator << overloads the stream insertion operator                            
    Allows printing to console in tabular form                                               
    Type - facilitator                                                                       
    \return - returns reference to output stream operator                                    
                                                                                             
*/
template <typename eltType>
        ostream& operator<<(ostream &os,const CLinkedList<eltType> &l) {
        ListIterator<eltType> iter(l);
        for (iter.begin(); !iter.isLastNode(); ++iter)
            os << (*iter) << " " ;
        os << (*iter);
        return os;


}
////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      CLinkedList                                                           
//   Description:      copy constructor for CLinkedList class                                
//   Member Type:      Inspector                                                             
//   Parameters:       object of CLinkedList                                                 
//   Return Value:     none                                                                  
//                                                                                           
////////////////////////////////////////////////////////////////////////                     
//copy constructor                                                                           
/*!                                                                                          
    copy constructor                                                                         
    creates a copy of the CLinkedList object                                                 
    Type - Inspector                                                                         
                                                                                             
*/
template<class T>
CLinkedList<T>::CLinkedList(const CLinkedList<T>& other)
    {last = copy( other.last );}

////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      ~CLinkedList                                                          
//   Description:      destroys all the nodes                                                
//   Member Type:      Inspector                                                             
//   Parameters:       none                                                                  
//   Return Value:     none                                                                  
//                                                                                           
////////////////////////////////////////////////////////////////////////                     
// deconstructor                                                                             
/*!                                                                                          
    deconstructor                                                                            
    destroys all the nodes in the list                                                       
    Type - Inspector                                                                         
                                                                                             
*/
template<class T>
CLinkedList<T>::~CLinkedList() {
    {destroy(last);}
}

////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      ~CLinkedList                                                          
//   Description:      destroys all the nodes                                                
//   Member Type:      Inspector                                                             
//   Parameters:       none                                                                  
//   Return Value:     none                                                                  
//                                                                                           
////////////////////////////////////////////////////////////////////////    
/*!                                                                                          
    \fn copy                                                                                 
    does a deep copy of the CLinkedList                                                      
    Type - Inspector                                                                         
    \return the pointer to the first Node in the list                                        
                                                                                             
*/
template <typename eltType>
Node<eltType>* CLinkedList<eltType>::copy(Node<eltType> *l)
{       Node<eltType>* first = last -> next;    // ptr to beginning of copied LinkedList     
        Node<eltType>* last = NULL;     // ptr to last item insert in the copy               
        if (first != last){
    assert((first = last = new Node<eltType>(l->data, first -> next)) != NULL);
                for (Node<eltType>* source=l->next;source!=last;source=source->next,first=fi\
rst->next){
                    last->next = new Node<eltType>(source->data,first-> next);
                        assert(last->next);
                }
        }
        return first;
}
////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      isEmpty()                                                             
//   Description:      checks if the list is empty                                           
//   Member Type:      Inspector                                                             
//   Parameters:       none                                                                  
//   Return Value:     bool - if the list is empty or not                                    
//                                                                                           
////////////////////////////////////////////////////////////////////////                     
 // checks if list is empty                                                                  
/*!                                                                                          
    \fn empty                                                                                
    checks if the list is empty or not                                                       
    Type - Inspector                                                                         
    \return reutrns if the last is NULL meaning the list is empty                            
                                                                                             
*/
template<typename T>
bool CLinkedList<T>::empty() const {
return last == NULL;
}
////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      reverse                                                               
//   Description:      traverses the list and reverses the nodes.                            
//   Member Type:      Inspector                                                             
//   Parameters:       none                                                                  
//   Return Value:     none                                                                  
//                                                                                           
////////////////////////////////////////////////////////////////////////                     
/*!                                                                                          
    \fn reverse - traverses the list and reverses the nodes using the helper method          
    Type - Inspector                                                                         
*/
template <typename eltType>
void CLinkedList<eltType>::reverse(CLinkedList<eltType>& list) {
    if(last ==NULL) {
        return;
    }
    Node<eltType> *p = last -> next;
    reverseList(p);
}
////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      reverseList                                                           
//   Description:      assists in the reversal of the list, using recursion                  
//   Member Type:      Inspector                                                             
//   Parameters:       none                                                                  
//   Return Value:     none                                                                  
//                                                                                           
////////////////////////////////////////////////////////////////////////                     
/*!                                                                                          
    \fn reverseList - uses recurison to reverse the data in the list in numeric order        
    Type - Inspector                                                                         
                                                                                             
*/
template <typename T>
void CLinkedList<T>::reverseList(Node<T>* p) {
    if (p == last) {
        cout << p -> data << " ";
        return;
    }
    reverseList(p->next);
    cout << p-> data << " ";
}
////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      insert                                                                
//   Description:      inserts a new node into the list                                      
//   Member Type:      mutator                                                               
//   Parameters:       ClinkedList object of T data type                                     
//   Return Value:     void - none                                                           
//                                                                                           
////////////////////////////////////////////////////////////////////////                     
/*!                                                                                          
    \fn insert - inserts a new Node into the list, based on numeric order                    
    Type - mutator                                                                           
                                                                                             
*/
template<typename T>
void CLinkedList<T>::insert(const T& data) {
     Node<T>* newNode = new Node<T>(data);
    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    }
    else {
        Node<T>* current = last->next;
        Node<T>* previous = last;
        while (current != last && current->data < data) {
            previous = current;
            current = current->next;
        }
        if (current->data > data || current->data == data) {
            newNode->next = current;
            previous->next = newNode;
        }
        else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
}
////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      remove                                                                
//   Description:      removes a node from the list                                          
//   Member Type:      mutator                                                               
//   Parameters:       object CLinkedList of T type                                          
//   Return Value:     void - none                                                           
//                                                                                           
////////////////////////////////////////////////////////////////////////                     
/*!                                                                                          
    \fn remove - removes a Node from the list                                                
    Type - mutator                                                                           
                                                                                             
*/

template<class eltType>
void CLinkedList<eltType>::remove(const eltType& value) {
    if (last == nullptr) {
    return;
    }
    Node<eltType>* current = last->next; // start from the first node                        
    Node<eltType>* prev = last;
    do {
        if (current->data == value) { // if the node is found                                
            if (current == last) { // if it's the last node                                  
                if (last->next == last) { // if it's the only node                           
                    last = prev;
                    last = nullptr;
                } else {
                    last = prev; // update the last pointer                                  
                }
            }
prev->next = current->next; // remove the node from the list                     
            Node<eltType>* temp = current;
            current = current->next;
            delete temp; // delete the node                                                  
        } else {
            prev = current;
            current = current->next;
        }
    } while (last != nullptr && current != last->next);
    }

////////////////////////////////////////////////////////////////////////                     
//                                                                                           
//   Method name:      destroy                                                               
//   Description:      removes all the nodes in the linked list                              
//   Member Type:      mutator                                                               
//   Parameters:       Node of eltType                                                       
//   Return Value:     void - none                                                           
//                                                                                           
////////////////////////////////////////////////////////////////////////                     
/*!                                                                                          
    \fn destroy - destroys Nodes in the CLinkedList                                          
    Type - mutator                                                                           
                                                                                             
*/
template <typename eltType>
void CLinkedList<eltType>::destroy(Node<eltType> *l) {
    if (last == NULL) {
        return;
    }
    destroy(l->next);
    delete l;
}

/*!                                                                                          
    \class ListIterator                                                                      
    \brief Class defintion for creating a list iterator.                                     
    Enables traversing troversing through the CLinkedList, along with its' included methods  
                                                                                             
*/
// LIST ITERATOR CLASS AND IMPLEMENTATIONS ALL IN ONE !!                                     
template<class T>
class ListIterator {
private:
    const CLinkedList<T>& list;
    Node<T>* current;

public:
    ListIterator(const CLinkedList<T>& theList) : list(theList), current(theList.last) {}
    ListIterator(const CLinkedList<T>& theList, Node<T>* theCurrent) : list(theList), curren\
t(theCurrent) {}


// Move curr to next node                                                                    
void next(void){
    assert( current != NULL );
    current = current->next;
}
// Set curr to point at itr's head                                                           

void start(void){
    current = list.last;}
/*!                                                                                          
    \overload operator++ - overloads the pre increment operator                              
    advances the pointer to the next node in the list, if there is one                       
    Type - Inspector                                                                         
    \return returns pointer to node in the list                                              
                                                                                             
*/
    ListIterator<T>& operator++() {
        this->current = this -> current->next;
        return *this; // pointer to current -> next node                                     
    }

/*!                                                                                          
    \overload operator++ - overloads the post increment operator                             
    Second version of operator++ to satisfy the left hand rule.                              
    post increment advances the pointer to the next node in the list, if there is one        
    Type - Inspector                                                                         
    \param int - differentiates pre and post imcrements (input)                              
    \return returns temp which is a pointer to this*                                         
                                                                                             
*/
   ListIterator<T> operator++(int) {
        ListIterator<T> temp(*this);
        current = current->next;
        return temp;
    }


/*!                                                                                          
    \overload operator* - overloads the * operator, const                                    
    const version of overloaded * operator to satisfy the left hand rule                     
    Type - Inspector                                                                         
    \return returns pointer to current node's data                                           
                                                                                             
*/
    const T& operator*() const {
        return current->data;
    }

/*!                                                                                          
    \overload operator* - overloads the * operator, non const                                
    non const version of overloaded * operator to satisfy the left hand rule                 
    Type - Inspector                                                                         
    \return returns the data to the current Node                                             
                                                                                             
*/
    T& operator*() {
        return current->data;
    }


/*!                                                                                          
    \fn begin - sets the iterator to the first node of the linked list (or NULL if the list \
is empty).                                                                                   
    Type - Inspector                                                                         
*/

    void begin() {
        current = list.last -> next;
    }


/*!                                                                                          
    \fn isFirstNode - checks if the current node is the first one                            
    Type - Inspector                                                                         
    \return true or false if its the first node                                              
*/
    bool isFirstNode() const {
        return current == list.last->next;
    }

/*!                                                                                          
    \fn isLastNode - checks whether or not the current points to a Node is the last one in t\
he list                                                                                      
    Type - Inspector                                                                         
    \return true or false if its the last node                                               
*/
    bool isLastNode() const {
        return current == list.last;
    }

/*!                                                                                          
    \fn isEmpty - checks if list is empty                                                    
    Type - Inspector                                                                         
    \return true or false if the list is empty                                               
*/
bool isEmpty() {
    return current == NULL;
}

friend class CLinkedList<T>;
};

#endif
