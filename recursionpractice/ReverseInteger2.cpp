/* 
 * Maira Soomro, CS 202, Assn 07
 * This program will implement a recursive function
 *
 */

#include <iostream>

using namespace std;

int reverseInteger (int, int); 

int main()
{

    int num; 

    cout << "Please enter an integer > "; 
    cin >> num; 
    
    cout <<"\nThe reverse of " << num << " is " <<  reverseInteger(num,0) <<"."<< endl;
   

    return 0;
}

int reverseInteger (int num, int n) { 
    if(num==0)
        return n; 
    return reverseInteger(num/10,n*10 + num%10); 
}
