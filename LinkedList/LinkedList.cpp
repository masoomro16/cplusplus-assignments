//**************************************************************
// IMPLEMENTATION FILE (LinkedList.cpp)
// This file gives the specification of the LinkedList abstract 
// data type.
//*****************************************************************

#include <iostream>
#include "LinkedList.h"

template <class Type>
bool LinkedList<Type>::isEmptyList() const
{
    return(first == NULL);
}

template <class Type>

  /* LinkedList: constructor
   * parameters: n/a
   * return value: n/a
   */
LinkedList<Type>::LinkedList() //default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
}


  /* destroyList: destroys list 
   * parameters: n/a
   * return value: n/a
   */
template <class Type>
void LinkedList<Type>::destroyList()
{
    nodeType<Type> *temp;   //pointer to deallocate the memory
    //occupied by the node
    while (first != NULL)   //while there are nodes in the list
    {
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL; first has already
    //been set to NULL by the while loop
    count = 0;
}


  /* initializeList: initializes list 
   * parameters: n/a
   * return value: n/a
   */
template <class Type>
void LinkedList<Type>::initializeList()
{
    destroyList(); //if the list has any nodes, delete them
}


  /* print: prints linked list
   * parameters: n/a
   * return value: n/a
   */
template <class Type>
void LinkedList<Type>::print() const
{
    nodeType<Type> *current; //pointer to traverse the list
    
    current = first;    //set current so that it points to
    //the first node
    while (current != NULL) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}//end print


  /* length: counts list 
   * parameters: n/a
   * return value: length
   */
template <class Type>
int LinkedList<Type>::length() const
{
    return count;
}  //end length


  /* copyList: copies one list onto another
   * parameters: LinkedList<Type>& otherList
   * return value: n/a
   */
template <class Type>
void LinkedList<Type>::copyList
(const LinkedList<Type>& otherList)
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list
    
    if (first != NULL) //if the list is nonempty, make it empty
        destroyList();
    
    if (otherList.first == NULL) //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the
        //list to be copied
        count = otherList.count;
        
        //copy the first node
        first = new nodeType<Type>;  //create the node
        
        first->info = current->info; //copy the info
        first->link = NULL;        //set the link field of
        //the node to NULL
        last = first;              //make last point to the
        //first node
        current = current->link;     //make current point to
        //the next node
        
        //copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>;  //create a node
            newNode->info = current->info; //copy the info
            newNode->link = NULL;       //set the link of
            //newNode to NULL
            last->link = newNode;  //attach newNode after last
            last = newNode;        //make last point to
            //the actual last node
            current = current->link;   //make current point
            //to the next node
        }//end while
    }//end else
}//end copyList

  /* search: searches for info in list 
   * parameters: Type& searchItem
   * return value: bool valye
   */
template <class Type>
bool LinkedList<Type>::
search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = first; //set current to point to the first
    //node in the list
    
    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
    //the next node
    return found;
}//end search

  /* insert: inserts node into list
   * parameters: Type& newItem 
   * return value: n/a
   */
template <class Type>
void LinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node
    
    newNode = new nodeType<Type>; //create the new node

    
    newNode->info = newItem;  //store the new item in the node
    newNode->link = NULL;     //set the link field of newNode
    //to nullptr /* change to NULL*/ 
    
    /* change to NULL*/
    if (first == NULL)  //if the list is empty, newNode is
        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual
        //last node in the list
        count++;        //increment count
    }
}//end insert

  /* deleteNode: deletes node in list 
   * parameters: Type& deleteNode
   * return value: n/a
   */
template <class Type>
void LinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;
    
    if (first == NULL)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
        << endl;
    else
    {
        if (first->info == deleteItem) //Case 2
        {
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
            //to the first node
            current = first->link; //set current to point to
            //the second node
            
            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while
            
            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;
                
                if (last == current)   //node to be deleted
                    //was the last node
                    last = trailCurrent; //update the value
                //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

  /* isSortedList: determines whether list is sorted or not 
   * parameters: n/a
   * return value: bool value
   */
template <class Type>
bool LinkedList<Type>::isSortedList() const
{
  int count = 0; 
  nodeType<Type> *current = first;


  while(current->link) { 
    if (current->info > current->link->info)
      return false; 
    current = current->link; 
  } 
  return true; 
}

  /* sortList: sorts List 
   * parameters: n/a
   * return value: n/a
   */
template <class Type>
void LinkedList<Type>::sortList()
{
  nodeType<Type> *tempNode = first; 
  int count = 0; 
  Type tempInfo;
  while(tempNode) { 
    tempNode = tempNode->link;
    count++; 
  }
  tempNode = first; 
 
  for (int j = 0; j<count; j++) { 
    tempNode = first; 
    for(int i=0; i<count; i++) { 
      while (tempNode->link) {
        	 if(tempNode->info > tempNode->link->info) { 
        	   tempInfo = tempNode->info; 
        	   tempNode->info = tempNode->link->info;
        	   tempNode->link->info = tempInfo;
	         }
	         
            else tempNode = tempNode->link;
      }
    }
  }
  tempNode = first; // reset 
}


  /* ~LinkedList:destructor
   * parameters: n/a 
   * return value: n/a
   */
template <class Type>
LinkedList<Type>::~LinkedList() //destructor
{
    destroyList();
}//end destructor


  /* linkedList: copy consuctor 
   * parameters: LinkedList<Type>& otherList
   * return value: n/a
   */
template <class Type>
LinkedList<Type>::LinkedList
(const LinkedList<Type>& otherList)
{
    first = NULL;
    copyList(otherList);
}//end copy constructor

  /* operator = : overloads = operator 
   * parameters: LinkedList<Type>& otherList
   * return value: n/a
   */
//overload the assignment operator
template <class Type>
const LinkedList<Type>& LinkedList<Type>::operator=
(const LinkedList<Type>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else
    
    return *this;
}
