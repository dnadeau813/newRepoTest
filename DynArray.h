#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "assert.h"

using namespace std;

template <class T>
class DynArray
{
private:
	int n;
	int theSize;
	int cap;
	T* myArray;
public:
	
	DynArray()
	{
		const int SIZE = 2;
		cap = SIZE;
		myArray = new T[cap];
		theSize = 0;
	};

	
	DynArray(int n)
	{
		cap = n;
		myArray = new T[cap];
		theSize = 0;
	};

	
	~DynArray()
	{
		delete[] myArray;
	};

	//copy con
	DynArray(const DynArray &n)
	{
		theSize = n.theSize;
		myArray = new T[theSize];
		memcpy(myArray, n.myArray, sizeof(T) * theSize);
	};

	// The = operator
	// Purpose: This is the assignment opertator, 
	// which allocates new heap space for the new object 
	// it is copying from the object passed as its parameter. 
	// It also deletes its old heap space.
	// Parameters: DynArray &arr 
	// Returns: The new heap space for the object
	DynArray& operator=(const DynArray &arr)
	{
		
		if (this != &arr) 
		{
			theSize = arr.theSize;
			delete[] myArray;
			myArray = new T[theSize];

			for (int i = 0; i < theSize; i++)
			{
				myArray[i] = arr.myArray[i];
			}
		}
		return *this;
	};

	// The size() method
	// Purpose: This returns theSize
	// Parameters: none
	// Returns: The size for the array
	int size()
	{
		return theSize;
	};

	// The capacity() method
	// Purpose: This returns cap
	// Parameters: none
	// Returns: The capacity for the array
	int capacity()
	{
		return cap;
	};

	// The clear() method
	// Purpose: This deletes the old array and resets to a new starting array
	// Parameters: none
	// Returns: none
	void clear()
	{
		const int SIZE = 2;
		delete[] myArray;
		cap = SIZE;
		myArray = new T[cap];
		theSize = 0;
		return;
	};

	// The push_back() method
	// Purpose: This increases the size of the array
	// and adds a new variable
	// Parameters: int n (the new variable to add)
	// Returns: nothing
	void push_back(T n)
	{
		myArray[theSize] = n;
		theSize++;
		//if the size and capacity are equal it can't store more values
		//this will create an array with double capacity
		if (theSize == cap)
		{
			cap *= DynArray::size();
			T* tempArray = new T[cap + 1];

			for (int i = 0; i < theSize; i++)
			{
				tempArray[i] = myArray[i];//copies data over
			}
			//destroys old array and implements the new one 
			delete[] myArray;
			myArray = tempArray;
		}
		return;
		//add user input into the vector
	};

	// The pop_back() method
	// Purpose: This decreases the size of the array to fit the variables within it already
	// Parameters: none
	// Returns: none
	void pop_back()
	{
		myArray[theSize];
		theSize--;
		//if the size and capacity are equal it can't store more values
		//this will create an array with less capacity
		if (theSize == cap)
		{
			cap *= DynArray::size();
			T* tempArray = new T[cap - 1];

			for (int i = 0; i < theSize; i--)
			{
				tempArray[i] = myArray[i];//copies data over
			}
			//destroys old array and implements the new one 
			delete[] myArray;
			myArray = tempArray;
		}
		return;
		//add user input into the vector
	};

	// The at() method
	// Purpose: This returns the value from the correct index
	// Parameters: none
	// Returns: myArray
	T at(T n) const
	{
		//catch an error if found
		if (n >= cap - 1)
		{
			throw runtime_error("ERROR: The value is outside the scope of the array.");
		}

		if (n <= theSize && n >= 0)
			return myArray[n];
	};

	// The last() method
	// Purpose: This is to return the last value within the array
	// while checking to see if variables are stored
	// Parameters: none
	// Returns: The last value in array
	T last()
	{
		if (theSize == 0)
		{
			runtime_error("ERROR: The value is outside the scope of the array.");
		}

		else
		{
			return myArray[theSize - 1];
		}
	};

	// The size() method
	// Purpose: This returns the first value within the array
	// Parameters: none
	// Returns: The first value of array
	T front()
	{
		if (theSize == 0)
		{
			runtime_error("ERROR: The value is outside the scope of the array.");
		}

		else
		{
			return myArray[0];
		}
	};

	// The operator [] overload
	// Purpose: This overloads the [ ] operator we use to index into an array.
	// Parameters: int i
	// Returns: myArray
	T operator[](int i)
	{
		assert((i >= 0) && (i < theSize));
		return myArray[i];
	};


};