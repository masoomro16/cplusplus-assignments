/*
Maira Soomro
Assignment #6
CS 302 Section 1002

This program will count the number of perfect, deficient and abundant 
numbers between 2 and a user-provided limit from the command line (inclusive 
of the limit). It will also run the program on a user-provided number of 
threads, which also for multiple thread processing. 
*/

#include <iostream> 
#include <chrono> 
#include <thread> 
#include <atomic>
#include <mutex>
using namespace std; 

// declare mutex for locking 
mutex	myMutex; 

// store command line arguments 
// for limit and thread count 
int limit, threadC; 

// initialize count variables
// for perfect, abundant and deficient 
int perfectNum = 0; 
int abundantNum = 0; 
int deficientNum = 0; 

// start number from 2 
int countNum = 2; 


/*
perfectNumber 
parameters: n/a 
description: increments the perfect number count 
*/ 
void perfectNumber() { 
	lock_guard<mutex> guard(myMutex); 
		perfectNum++; 
} 

/*
deficientNumber
parameters: n/a 
description: increments the deficient number count 
*/ 
void deficientNumber(){
	lock_guard<mutex> guard(myMutex); 
		deficientNum++; 
}

/*
abundantNumber
parameters: n/a 
description: increments the abundant number count 
*/ 
void abundantNumber(){ 
	lock_guard<mutex> guard(myMutex); 
		abundantNum++; 
}

/*
getNext
parameters: n/a 
return type: int
description: increments the deficient number count 
*/ 
int getNext() { 
	lock_guard<mutex> guard(myMutex); 
		++countNum;
	return countNum; 
} 

/*
count 
parameters: n/a 
Finds the divisors of a number, sums them, and checks to 
see if the number is a perfect, abundant or deficient 
number, and calls the required functions to count them
*/
void count() {
	//getNext(); 
	int num = 0;
	while (num<= limit) { 	
        
        // grab the next number 
		num = getNext(); 
		if (num <= limit) {
            
            // divSum stores the sum of all the divisors 
			int divSum = 0; 
            
			// find divisors
			for (int i = 1; i<=num; i++) {
				if(num%i==0 && num!=i) { 
					divSum = divSum + i;
				}
			}
            
            // check for perfect, deficient or abundant 
            // call appropriate functions
			if (divSum == num) 
				perfectNumber();	
			if (divSum < num)
				deficientNumber();  
			if (divSum > num)
				abundantNumber();  	
		
		}  
	}
}

int main(int argc, char *argv[]) {
    
    //  Verify command line arguments.

	if (argc == 1) {
		cout << "Usage: main -th <threadCount> -lm <limitValue>" << endl;
		return 0;
	}

	if (argc != 5) {
		cout << "Error, invalid command line options." << endl;
		return	0;
	}

	if (string(argv[1]) != "-th") {
		cout << "Error, invalid thread count number." << endl;
		return	0;
	}

	if (string(argv[3]) != "-lm") {
		cout << "Error, invalid limit value." << endl;
		return	0;
	}


    // store command line arguments into appropriate variables 
	threadC = atoi(argv[2]);
	limit = atoi(argv[4]);


	// start timer...
	auto t1 = chrono::high_resolution_clock::now(); 

	// start thread
 	// pointer, allocate --> threadC
	thread *thd1 = new thread[threadC]; 

	// for each thread, call count function 
	for (int i =0; i < threadC; i++) { 
		thd1[i] = std::thread(count);
	
	}
    
	// then join threads
	for (int i = 0; i < threadC; i++) { 
		thd1[i].join(); 
 	}


	// show results with times 
	auto t2 = chrono::high_resolution_clock::now(); 

    // show counts for each type of number 
	cout << "Perfect number count: " << perfectNum << endl; 
	cout << "Deficient number count: " << deficientNum << endl; 
	cout << "Abundant number count: " << abundantNum << endl;
    
    // show time the process took 
	cout << "Program took: " << 
	std::chrono::duration_cast<std::chrono::milliseconds> (t2 - t1).count() << " milliseconds" << endl; 

    // release 
	delete[] thd1;

return 0;
} 



