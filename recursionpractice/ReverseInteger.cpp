/* 
 * Maira Soomro, CS 202, Assn 07
 * This program will implement a recursive function
 * Input: this program expects an integer 
 * Output: The program wil reverse the integer inputted 
 * by the user
 */

#include <iostream>

using namespace std;

/* 
 * reverseInteger: takes two arguments and 
 * reverses the integer 
 * paramters: int, int 
 * 
 */

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
    if(num==0) // base case 
        return n; 
    return reverseInteger(num/10,n*10 + num%10); // *10 to multiply each time 
}
