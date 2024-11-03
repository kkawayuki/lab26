// COMSC-210 | lab 26 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>    //for vector
#include <list>      //for list
#include <set>       //for set
#include <algorithm> //for sort
#include <iomanip>   //for formatting
#include <map>
using namespace std;
using namespace std::chrono;

const int ITERATIONS = 15;

// function prototypes
void vRead(vector<string> &, map<string, int>&);
void vSort(vector<string> &, map<string, int>&);
void vInsert(vector<string> &, map<string, int>&);
void vDelete(vector<string> &, map<string, int>&);
void lRead(list<string> &, map<string, int>&);
void lSort(list<string> &, map<string, int>&);
void lInsert(list<string> &, map<string, int>&);
void lDelete(list<string> &, map<string, int>&);
void sRead(set<string> &, map<string, int>&);
void sSort(set<string> &, map<string, int>&);
void sInsert(set<string> &, map<string, int>&);
void sDelete(set<string> &, map<string, int>&);
void runTests(int, vector<string> &, list<string> &, set<string> &, map<string, int> &);
const void printRecords(map<string, int>);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    // declare vector/string objects
    vector<string> myVec;
    list<string> myList;
    set<string> mySet;

    // create map to store values
    map<string, int> runTimes = {{"vRead", 0}, {"lRead", 0}, {"sRead", 0}, {"vSort", 0}, {"lSort", 0}, {"sSort", -1}, {"vInsert", 0}, {"lInsert", 0}, {"sInsert", 0}, {"vDelete", 0}, {"lDelete", 0}, {"sDelete", 0}};

    // run tests 15 times
    runTests(15, myVec, myList, mySet, runTimes);
    printRecords(runTimes);

    return 0;
}

/************************************************
 * Functions: vector
 ************************************************/
void vRead(vector<string> &myVec, map<string, int> &runTimes)
{
    string buf;
    auto start = high_resolution_clock::now();

    ifstream fin("codes.txt");
    while (getline(fin, buf))
        myVec.push_back(buf); // add all elements to vec

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    runTimes["vRead"] += duration.count();
}

void vSort(vector<string> &myVec, map<string, int> &runTimes)
{
    auto start = high_resolution_clock::now();

    sort(myVec.begin(), myVec.end()); // sorts entire vector

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    runTimes["vSort"] += duration.count();
}

void vInsert(vector<string> &myVec, map<string, int> &runTimes)
{
    auto start = high_resolution_clock::now();

    myVec.insert(myVec.begin() + (myVec.size() / 2), "TESTCODE"); // insert roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    runTimes["vInsert"] += duration.count();
}

void vDelete(vector<string> &myVec, map<string, int> &runTimes)
{
    auto start = high_resolution_clock::now();

    myVec.erase(myVec.begin() + (myVec.size() / 2)); // erase roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    runTimes["vDelete"] += duration.count();
}

/************************************************
 * Functions: list
 ************************************************/
void lRead(list<string> &myList, map<string, int> &runTimes)
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
    runTimes["lRead"] += duration.count();
}

void lSort(list<string> &myList, map<string, int> &runTimes)
{
    auto start = high_resolution_clock::now();

    myList.sort(); // sort correctly

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    runTimes["lSort"] += duration.count();
}

void lInsert(list<string> &myList, map<string, int> &runTimes)
{
    auto start = high_resolution_clock::now();

    auto it = myList.begin();
    for (int i = 0; i < myList.size() / 2; ++it, i++) // iterate "it" to correct location
    {
    }
    myList.insert(it, "TESTCODE"); // insert roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    runTimes["lInsert"] += duration.count();
}

void lDelete(list<string> &myList, map<string, int> &runTimes)
{
    auto start = high_resolution_clock::now();

    auto it = myList.begin();
    for (int i = 0; i < myList.size() / 2; ++it, i++) // iterate "it" to correct location
    {
    }
    myList.erase(it); // delete roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    runTimes["lDelete"] += duration.count();
}

/************************************************
 * Functions: set
 ************************************************/
void sRead(set<string> &mySet, map<string, int> &runTimes)
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
    runTimes["sRead"] += duration.count();
}

void sSort(set<string> &mySet, map<string, int> &runTimes)
{
    // already sorted, value is set to -1
}

void sInsert(set<string> &mySet, map<string, int> &runTimes)
{
    auto start = high_resolution_clock::now();

    mySet.insert("TESTCODE"); // insert roughly middle element

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    runTimes["sInsert"] += duration.count();
}

void sDelete(set<string> &mySet, map<string, int> &runTimes)
{
    auto start = high_resolution_clock::now();

    auto it = mySet.begin();
    for (int i = 0; i < mySet.size() / 2; ++it, i++) // iterate "it" to correct location
    {
    }

    mySet.erase(it); // erase near middle value

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    runTimes["sDelete"] += duration.count();
}

/************************************************
 * Function:
 ************************************************/
void runTests(int num, vector<string> &myVec, list<string> &myList, set<string> &mySet, map<string, int> &runTimes)
{
    for (int i = 0; i < num; i++)
    {
        // Run vector tests
        vRead(myVec, runTimes);
        vSort(myVec, runTimes);
        vInsert(myVec, runTimes);
        vDelete(myVec, runTimes);

        // Run list tests
        lRead(myList, runTimes);
        lSort(myList, runTimes);
        lInsert(myList, runTimes);
        lDelete(myList, runTimes);

        // Run set tests
        sRead(mySet, runTimes);
        sSort(mySet, runTimes);
        sInsert(mySet, runTimes);
        sDelete(mySet, runTimes);
    }
    //average out values by dividing by number of iterations
    for (auto &pair : runTimes)
        pair.second /= num; 
}

/************************************************
 * Function: printRecords
 ************************************************/
const void printRecords(map<string, int> runTimes) // reference for both
{
    // outputs data stored in the map according to its key, also helps make the print function more readable    
    const int width = 10; //spacing on output
    cout << setw(width) << "Operation" << right << setw(width) << "Vector" << right << setw(width) << "List" << right << setw(width) << "Set\n"; //row1
    cout << right << setw(width) << "Read" << right << setw(width) << runTimes["vRead"] << right << setw(width) << runTimes["lRead"] << right << setw(width) << runTimes["sRead"] <<"\n";
    cout << right << setw(width) << "Sort" << right << setw(width) << runTimes["vSort"] << right << setw(width) << runTimes["lSort"] << right << setw(width) << runTimes["sSort"] <<"\n";
    cout << right << setw(width) << "Insert" << right << setw(width) << runTimes["vInsert"] << right << setw(width) << runTimes["lInsert"] << right << setw(width) << runTimes["sInsert"] <<"\n";
    cout << right << setw(width) << "Delete" << right << setw(width) << runTimes["vDelete"] << right << setw(width) << runTimes["lDelete"] << right << setw(width) << runTimes["sDelete"] <<"\n";
}
