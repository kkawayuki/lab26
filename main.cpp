// COMSC-210 | lab 25 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>    //for vector
#include <list>      //for list
#include <set>       //for set
#include <algorithm> //for sort
#include <iomanip>   //for formatting
using namespace std;
using namespace std::chrono;

// function prototypes
auto vRead(vector<string> &);
auto vSort(vector<string> &);
auto vInsert(vector<string> &);
auto vDelete(vector<string> &);
auto lRead(list<string> &);
auto lSort(list<string> &);
auto lInsert(list<string> &);
auto lDelete(list<string> &);
auto sRead(set<string> &);
auto sSort(set<string> &);
auto sInsert(set<string> &);
auto sDelete(set<string> &);
const void printRecords(vector<string>, list<string>, set<string>);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    // declare vector/string objects
    vector<string> myVec;
    list<string> myList;
    set<string> mySet;
    
    //the printRecords function calls and formats all other functions. 
    printRecords(myVec, myList, mySet);

    return 0;
}

/************************************************
 * Functions: vector
 ************************************************/
auto vRead(vector<string> &myVec)
{
    string buf;
    auto start = high_resolution_clock::now();

    ifstream fin("codes.txt");
    while (getline(fin, buf))
        myVec.push_back(buf); // add all elements to vec

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

auto vSort(vector<string> &myVec)
{
    auto start = high_resolution_clock::now();

    sort(myVec.begin(), myVec.end()); // sorts entire vector

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

auto vInsert(vector<string> &myVec)
{
    auto start = high_resolution_clock::now();

    myVec.insert(myVec.begin() + (myVec.size() / 2), "TESTCODE"); // insert roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

auto vDelete(vector<string> &myVec)
{
    auto start = high_resolution_clock::now();

    myVec.erase(myVec.begin() + (myVec.size() / 2)); // erase roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

/************************************************
 * Functions: list
 ************************************************/
auto lRead(list<string> &myList)
{
    auto start = high_resolution_clock::now();

    string buf;
    ifstream fin("codes.txt");
    while (getline(fin, buf))
    {
        myList.push_back(buf); // add all elements to vec
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

auto lSort(list<string> &myList)
{
    auto start = high_resolution_clock::now();

    myList.sort(); // sort correctly

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

auto lInsert(list<string> &myList)
{
    auto start = high_resolution_clock::now();

    auto it = myList.begin();
    for (int i = 0; i < myList.size() / 2; ++it, i++) // iterate "it" to correct location
    {
    }
    myList.insert(it, "TESTCODE"); // insert roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

auto lDelete(list<string> &myList)
{
    auto start = high_resolution_clock::now();

    auto it = myList.begin();
    for (int i = 0; i < myList.size() / 2; ++it, i++) // iterate "it" to correct location
    {
    }
    myList.erase(it); // delete roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

/************************************************
 * Functions: set
 ************************************************/
auto sRead(set<string> &mySet)
{
    auto start = high_resolution_clock::now();

    string buf;
    ifstream fin("codes.txt");
    while (getline(fin, buf))
    {
        mySet.insert(buf); // inserts buf if unique
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

auto sSort(set<string> &mySet) // already sorted, return -1
{
    return (-1);
}

auto sInsert(set<string> &mySet)
{
    auto start = high_resolution_clock::now();

    mySet.insert("TESTCODE"); // insert roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

auto sDelete(set<string> &mySet)
{
    auto start = high_resolution_clock::now();

    auto it = mySet.begin();
    for (int i = 0; i < mySet.size() / 2; ++it, i++) // iterate "it" to correct location
    {
    }

    mySet.erase(it); // erase near middle value

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return (duration.count());
}

/************************************************
 * Function: printRecords
 ************************************************/
const void printRecords(vector<string> myVec, list<string> myList, set<string> mySet)
{
    const int width = 10; //spacing on output
    cout << setw(width) << "Operation" << right << setw(width) << "Vector" << right << setw(width) << "List" << right << setw(width) << "Set\n";
    cout << right << setw(width) << "Read" << right << setw(width) << vRead(myVec) << right << setw(width) << lRead(myList) << right << setw(width) << sRead(mySet) <<"\n";
    cout << right << setw(width) << "Sort" << right << setw(width) << vSort(myVec) << right << setw(width) << lSort(myList) << right << setw(width) << sSort(mySet) <<"\n";
    cout << right << setw(width) << "Insert" << right << setw(width) << vInsert(myVec) << right << setw(width) << lInsert(myList) << right << setw(width) << sInsert(mySet) <<"\n";
    cout << right << setw(width) << "Delete" << right << setw(width) << vDelete(myVec) << right << setw(width) << lDelete(myList) << right << setw(width) << sDelete(mySet) <<"\n";
}
//because I'm running my code on a relatively expensive desktop PC, the ms runtime for me is very low. 