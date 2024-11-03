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

// function prototypes
void vRead(vector<string> &);
void vSort(vector<string> &);
void vInsert(vector<string> &);
void vDelete(vector<string> &);
void lRead(list<string> &);
void lSort(list<string> &);
void lInsert(list<string> &);
void lDelete(list<string> &);
void sRead(set<string> &);
void sSort(set<string> &);
void sInsert(set<string> &);
void sDelete(set<string> &);
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

    // the printRecords function calls and formats all other functions.
    printRecords(myVec, myList, mySet);

    // create map to store values
    map<string, int> runTimes = {{"vRead", 0}, {"lRead", 0}, {"sRead", 0}, {"vSort", 0}, {"lSort", 0}, {"sSort", -1}, {"vInsert", 0}, {"lInsert", 0}, {"sInsert", 0}, {"vDelete", 0}, {"lDelete", 0}, {"sDelete", 0}};

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
 * Function: printRecords
 ************************************************/
const void printRecords(map<string, int> runTimes) // reference for both
{
    // figure out formatting later
    for (const auto &pair : runTimes)
        cout << pair.first << " took " << pair.second << " microseconds." << endl;
}
