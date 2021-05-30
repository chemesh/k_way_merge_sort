#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

//a utility function that recieves an int as a lower bound and return the input from 
//the user if and only if the input is an int bigger then the lower bound.
//default lower bound is 0. 
//if the input does not meet requirements, an 'invalid argument' exception is thrown.
int getPosIntFromInput(int lowBound = 0);

//a utility function that recieves a relative/full path to a file containing only integer values,
//in the form of a string, and the number of lines that should be read from it.
//the function return a long int n-sized array.
//upon any kind of ambiguity/error, an 'invalid argument' exception is thrown.
long int* getArrFromFile(const string& filename, const int& n);

//a utility funtion that recieves a relative/full path to a file in the form of a string,
//and a long int, n-sized array, and prints its contents to the file in n rows.
void printArrToFile(const string& filename, long int arr[], const int& n);

//a utility function called before std::stol() to perofrm a check on the input stringified.
//it throws 'invalid argument' exception if the string cant be transleted to a numeric value.
long int preStol(string str);