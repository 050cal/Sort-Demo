//Calvin Brooks
//Description: Program reads in train_companies.txt file and allows user to create Trains and sort trains by wagon weights (Linked List)
//Input: .txt file with below format:
//int companyAmount; int weightRangeLow; int weightRangeHigh;
//list companies line by line
//Output: display lists sorted as well as time it took to sort
#include <iostream>
#include <fstream>
#include <string>
#include "Train.h"
using namespace std;

//Train(): default constructor reads in file and creates linked list based off user input
//parameters: int size of linked list
//return value: void
Train::Train(int wagonAmount)
{
    ifstream trainFile;//input stream object
    
    try//exception handling for file name
    {
        trainFile.open("train_companies.txt");//hard-coded to open this file, per assignment PDF
        
        if(trainFile.fail())
        {
            int z;
            throw z;
        }
    }
    catch(int z)
    {
        cout << "File train_companies.txt not found" << endl;
        return;
    }

        
    //given file formatting, the first line will determine how much more memory we will have to allocate for company names
    string firstLine;
    trainFile >> firstLine;
        
    //first, we will extract the number of train companies
    int semicolon = firstLine.find(";");//finds ";" delimiter
    string stringCompanyAmount = firstLine.substr(0, semicolon);//creates a string of amount of company names
    int companyAmount = stoi(stringCompanyAmount);//we will use this int to dynamically allocate company names temp array
        
    //now we will extract the weight range from file
    int x = firstLine.length();
    string range = firstLine.substr((semicolon + 1), (x - semicolon));
    semicolon = range.find(";");
    string stringRangeLow = range.substr(0, semicolon);
    int rangeLow = stoi(stringRangeLow);//range low as an int extracted using find, substr, and stoi functions
    x = range.length();
    string tempString = range.substr((semicolon + 1), (x - semicolon));
    semicolon = tempString.find(";");
    string stringRangeHigh = tempString.substr(0, semicolon);
    int rangeHigh = stoi(stringRangeHigh);//range high as an int extracted using find, substr, and stoi functions
    
    string *trainInfo = new string[companyAmount];//dynamically allocating temp array to hold company names

    
    //HAD TO THROW AWAY A LINE TO SOLVE FORMATTING ISSUES FROM INPUT FILE
    string trash;
    getline(trainFile, trash);
        
    //we will now feed company names from file into the array 
    for(int i = 0; i < companyAmount; i++)
    {
        string name;
        getline(trainFile, name);
        trainInfo[i] = name;
    }
    
    
    //RANDOM METHODS BELOW ARE NOT 'TRULY' RANDOM
    //we will now build the linked list using parameter value to control loop
    for(int j = 0; j < wagonAmount; j++)
    {
        Wagon *newWagon = new Wagon;//create new wagon element
            
        //assigning random number from designated range to new Wagon element
        newWagon->load = rangeLow + rand() % (rangeHigh - rangeLow);

        //finding random number from range of our array-given by parameter
        
        int randomNumber = 0 + (rand() % companyAmount);

        //assigning company name from array to new element using randomNumber from above
        newWagon->company = trainInfo[randomNumber];
            
        newWagon->next = head;//place new element at the beginning
        head = newWagon;//update the head pointer of the list
            
    }
    
    
}

//display(): this function displays the linked list 
//parameters: none
//return value: void
void Train::display()
{
    Wagon* current;
    current = head;
    
    while(current != nullptr)
    {
        //if-else statements to match output formatting
        if(current->next == nullptr)//if last wagon, no comma after
        {
            cout << current->company << " " << current->load;
            current = current->next;
        }
        
        //if-else statements to match output formatting
        else
        {
            cout << current->company << " " << current->load << ", ";
            current = current->next;
        }
    }

    
}

//compare(const Wagon* first, const Wagon* second): this function compares two Wagon pointers based on their load
//parameters: two Wagon pointers
//return value: returns -1 if p1 lighter than p2, 0 if equivalent, and 1 if p1 is heavier than p2
int Train::compare(const Wagon* first, const Wagon* second)
{
    //else if statements to handle all three scenarios
    if(first->load == second->load)
    {
        return 0;//return 0 if wagon loads equivalent
    }
    
    else if(first->load > second->load)
    {
        return 1;//return greater than 0 if ptr1 is heavier than ptr2
    }
    
    else if(second->load > first->load)
    {
        return -1;//return less than 0 if ptr1 is lighter than ptr2
    }
}

//swap(Wagon* first, Wagon* second): this function swaps two elements of a linked list
//parameters: the two Wagons to be swapped
//return value: void
void Train::swap(Wagon* first, Wagon* second)
{
    string tempCompany = first->company;
    int tempLoad = first->load;
    first->company = second->company;
    first->load = second->load;
    second->company = tempCompany;
    second->load = tempLoad;
}

//sortBubble(): this function sorts a linked list using bubble sort approach
//parameters: none
//return value: void
void Train::sortBubble()
{
    Wagon *currentptr;
    Wagon *lastptr = nullptr;
    do
    {
        currentptr = head;
        while(currentptr->next != nullptr)
        {
            int y = compare(currentptr, currentptr->next);
            if(y > 0)
            {                
                swap(currentptr, currentptr->next);
            }
            currentptr = currentptr->next;
        }
        lastptr = currentptr;
        if(lastptr == head)
        {
            break;
        }
    }
    while(currentptr != nullptr);
    
}


//sortInsertion(): this function sorts the linked list using the insertion approach
//parameters: none
//return value: void
void Train::sortInsertion()
{
    Wagon *temp = head;
    while(temp){
        Wagon *min = temp;
        Wagon *current = temp->next;
        
        while(current){
            int x = compare(min, current);
            if(x > 0)
                min = current;
                current = current->next;
        }
        swap(temp, min);
        temp=temp->next;
    }
}







