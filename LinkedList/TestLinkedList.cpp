/* 
 * Maira Soomro, CS 202, Assn 06
 * This program will implement a Linked List and 
 * be able to sort a list, copy a list, find the length
 * and perform other functions 
 */

#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main()
{

    LinkedList<int> list1; 
    LinkedList<int> list2; 
    LinkedList<int> list3; 
    LinkedList<int> list4; 

    cout << "************" << endl; 
    cout << "Linked Lists"<< endl;
    cout << "************" << endl<<endl;
    list1.insert(30);
    list1.insert(28);
    list1.insert(35);
    list1.insert(12);
    list1.insert(5);
    list1.insert(18);
    list1.insert(34);

    cout << "List 1: ";    
    list1.print(); 
    if (list1.isSortedList())
      cout << "\nThis list is sorted." << endl;
    else 
      cout << "\nThis list is not sorted." << endl; 
 
    cout << endl; 
    list1.sortList(); 
    cout << "List 1: ";
    list1.print();
    
    if (list1.isSortedList())
    cout << "\nThis list is sorted" << endl;
    else 
        cout << "\nThis list is not sorted" << endl; 
        
    cout << "\nList 1 has " << list1.length() << " integers." << endl; 

    cout << "\nDelete number 18 from list: ";
    list1.deleteNode(18); 

    cout << "\nList 1: "; 
    list1.print(); 

    cout << "\n********"<<endl; 
    cout << "List 2: "; 
    list2.print();
    if (list2.isEmptyList())
      cout << "\nList 2 is empty." << endl; 
    else 
      cout <<"\nList 2 is not empty."<<endl; 

    list2.insert(23);
    list2.insert(12);
    list2.insert(12);
    list2.insert(5);
    list2.insert(8);
    list2.insert(13); 

    cout << endl << "List 2: "; 
    list2.print();

    if (list2.isSortedList())
      cout << "\nThis list is sorted." << endl;
    else
      cout << "\nThis list is not sorted." << endl;

    list2.sortList();
    cout << "\nList 2: "; 
    list2.print();
    cout << endl; 

    cout << "Search list 2 for integer 5: ";

    if(list2.search(5)) 
      cout << "integer is in list. "<< endl; 
    else
      cout << "integer is not in list. " << endl;
    
    cout << "Search list 2 for integer 25: ";

    if(list2.search(25))
      cout << "integer is in list. "<< endl;
    else
      cout << "integer is not in list. " << endl;

    list3.copyList(list1); 
    cout << endl << endl << "List 3 :";
    list3.print(); 
    
    
    cout << endl; 
    list4.insert(4);
    list4.insert(5);

    cout << "List 4: " ;
list4.print(); 

cout << "\nAssign list 4 to list 3" << endl; 
list3 = list4; 

cout<<"\nList 3: ";
 list3.print();
 cout << endl; 
 
 cout << "*********" << endl; 
    return 0;
}

