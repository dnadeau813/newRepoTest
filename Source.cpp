//I declare that the following source code was 
//written solely by me. I understand that copying 
//any source code, in whole or in part,
//constitutes cheating, and that I will 
//receive a zero on this project if I am found in 
//violation of this policy.

// Author: Daniel Nadeau
// Assignment: Project 9
// Instructor: Craig Sharp
// Class:    CS 1410  Section: 004   
// Date Written: 4/24/17
// Description: Template Dynamic array project

#include <iostream>
#include "DynArray.h"
using namespace std;

int main()
{
	
	const char START = 'A';
	const int MAX = 12;

	// create a vector of doubles
	DynArray<char> vectD;

	// push some values into the vector
	for (int i = 0; i < MAX; i++)
	{
		vectD.push_back(START + i);
	}

	// remove the last element
	vectD.pop_back();

	// add another value
	vectD.push_back('Z');

	// test memory management
	DynArray<char> vectD2 = vectD;
	// display the contents
	cout << "\n[";
	for (int i = 0; i < vectD2.size() - 1; i++)
	{
		cout << vectD2[i] << ", ";
	}

	cout << "..., " << vectD2.last() << "]\n";
	cin.get();
}
