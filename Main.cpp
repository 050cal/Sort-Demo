//Calvin Brooks
//Description: Program reads in train_companies.txt file and allows user to create Trains and sort trains by wagon weights (Linked List)
//Input: .txt file with below format:
//int companyAmount; int weightRangeLow; int weightRangeHigh;
//list companies line by line
//Output: display lists sorted as well as time it took to sort
#include <iostream>
#include <string>
#include <chrono>
#include "Train.h"
using namespace std;
using namespace std::chrono;

int main(){
	// ask for the list size
	// create Train list
	// ask for sorting method
	// do the sort using selected method
	// print the list (optional)
	cout << "Reading the train_companies.txt file..." << endl;
	cout << "Done." << endl;
	
	int userInputLength;
	cout << "Enter list length: ";
	
	while(!(cin >> userInputLength))//validate input
	{
	    cout << "Error: A number must be entered: ";//error message
	    cin.clear();
	    cin.ignore(42, '\n');
	}
	
	int tester = userInputLength;
	
	Train test(userInputLength);
	cout << "List of size " << tester << " is created." << endl << endl;
	
	
	int choice;
	cout << "1. Bubble sort" << endl;
	cout << "2. Insertion sort" << endl;
	cout << "Select sorting algorithm: ";
	cin >> choice;
	
	
	if(choice == 1)
	{
	    high_resolution_clock::time_point t1 = high_resolution_clock::now();
	    test.sortBubble();
	    high_resolution_clock::time_point t2 = high_resolution_clock::now();
	    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	    cout << "List has been sorted in a time of " << time_span.count() << " seconds." << endl;
	    cout << endl;
	    //test.display();
	}
	
	else if(choice == 2)
	{
	    high_resolution_clock::time_point t1 = high_resolution_clock::now();
	    test.sortInsertion();
	    high_resolution_clock::time_point t2 = high_resolution_clock::now();
	    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        cout << "List has been sorted in a time of " << time_span.count() << " seconds." << endl;
        cout << endl;
        //test.display();
	}
	
	else if(choice != 1 && choice != 2)
	{
	    cout << "Incorrect choice. Please choose 1 or 2." << endl;
	}
	

}


