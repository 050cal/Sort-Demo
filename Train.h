//Calvin Brooks
//Description: Program reads in train_companies.txt file and allows user to create Trains and sort trains by wagon weights (Linked List)
//Input: .txt file with below format:
//int companyAmount; int weightRangeLow; int weightRangeHigh;
//list companies line by line
//Output: display lists sorted as well as time it took to sort
#include <iostream>
using namespace std;

//Wagon: contains information relating to a single Wagon
//constructors: none
//public functions: none
//static members: none
struct Wagon
{
    string company;
    int load;
    Wagon *next;
};


//Train: class that builds a linked list from above Wagon struct
//constructors: 
//Train(int): constructor used to build the linked list dependent on size in parameter
//public functions: 
//void display();
//int compare(const Wagon*, const Wagon*);
//void swap(Wagon*, Wagon*);
//void sortBubble();
//void sortInsertion();
//static members: none
class Train
{
    public:
    Wagon *head;//pointer to the first element of the linked list
    
    Train(int);//constructor used in main, passed users input
    
    //~Train();//memory deallocation done here
    
    void display();//displays all the elements of the list
    
    int compare(const Wagon*, const Wagon*);
    
    void swap(Wagon*, Wagon*);
    
    void sortBubble();
    
    void sortInsertion();
    
};