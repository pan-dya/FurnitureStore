#pragma once

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of array-based lists.
//***********************************************************

#ifndef _ARRAYLIST_TYPE_H_
#define _ARRAYLIST_TYPE_H_
#include <cassert>
#include <string>
using namespace std;
template <class elemType>
class arrayListType
{
public:
	arrayListType(int size = 100);
	//constructor
	//Creates an array of the size specified by the 
	//parameter size. The default array size is 100.
	//Postcondition: The list points to the array, length = 0, 
	//               and maxSize = size
	const arrayListType<elemType>& operator=
	(const arrayListType<elemType>&);
		//Overload the assignment operator
	bool isEmpty() const;
		//Function to determine whether the list is empty
		//Postcondition: Returns true if the list is empty; 
		// otherwise, returns false.
	bool isFull() const;
		//Function to determine whether the list is full
		//Postcondition: Returns true if the list is full; 
		// otherwise, returns false.
	int listSize() const;
		//Function to determine the number of elements in the list
		//Postcondition: Returns the value of length.
	int maxListSize() const;
		//Function to determine the size of the list
		//Postcondition: Returns the value of maxSize.
	void print() const;
		//Function to output the elements of the list
		//Postcondition: Elements of the list are output on the 
		// standard output device.
	bool isItemAtEqual(int location, const elemType& item) const;
		//Function to determine whether the item is the same 
		//as the item in the list at the position specified by
		//Postcondition: Returns true if the list[location] 
		// is the same as the item; otherwise, 
		// returns false.

	//ADDED FUNCTION TO PRINT ONE ITEM
	void printItem(int x) const;
		//prints one specific contact

	//ADDED FUNCTION TO PRINT ALL ITEMS IN A LIST
	void printAll() const;
		//prints all item in a list

	//ADDED FUNCTION TO SEARCH FOR ONE ITEM
	int itemSearch(string code) const;
		//searches for a specific item

	//ADDED FUNCTION TO REMOVE AN ITEM
	void removeItem(string code);
		//removes the item with the same ID in the list if found

	//ADDED FUNCTION TO GET PRICE
	int priceGet(int i)const;
		//return the price of the item

	//ADDED FUNCTION TO UPDATE THE STOCK AFTER BUYING ITEM
	void updateStock(int i) const;
	//update the stock on the list

	//ADDED FUNCTION TO RETREIVE STOCK
	int stockGet(int i) const;
	//return the number of stock

	void insertAt(int location, const elemType& insertItem);
		//Function to insert an item in the list at the 
		//position specified by location. The item to be inserted 
		//is passed as a parameter to the function.
		//Postcondition: Starting at location, the elements 
		// of the list are shifted down, 
		// list[location] = insertItem;, and
		// length++;    
		// If the list is full or location is out of
		// range, an appropriate message is displayed.    
	void insertEnd(const elemType& insertItem);
		//Function to insert an item at the end of the list 
		//The parameter insertItem specifies the item to be 
		//inserted.
		//Postcondition: list[length] = insertItem; and length++;
		// If the list is full, an appropriate 
		// message is displayed.
	void removeAt(int location);
		//Function to remove the item from the list at the 
		//position specified by location 
		//Postcondition: The list element at list[location] is 
		// removed and length is decremented by 1.
		// If location is out of range, an appropriate message
		// is displayed.
	void retrieveAt(int location, elemType& retItem);
		//Function to retrieve the element from the list at the  
		//position specified by location 
		//Postcondition: retItem = list[location] 
		// If location is out of range, an appropriate 
		// message is displayed.
	void replaceAt(int location, const elemType& repItem);
		//Function to replace the elements in the list at the 
		//position specified by location. The item to be replaced 
		//is specified by the parameter repItem.
		//Postcondition: list[location] = repItem 
		// If location is out of range, an appropriate 
		// message is displayed.
	void clearList();
		//Function to remove all the elements from the list 
		//After this operation, the size of the list is zero.
		//Postcondition: length = 0;
	int seqSearch(const elemType& item);
		//Function to search the list for a given item. 
		//Postcondition: If the item is found, returns the location 
		// in the array where the item is found; 
		// otherwise, returns -1.
	void insert(const elemType& insertItem);
		//Function to insert the item specified by the parameter 
		//insertItem at the end of the list. However, first the
		//list is searched to see whether the item to be inserted 
		//is already in the list. 
		//Postcondition: list[length] = insertItem and length++
		// If the item is already in the list or the list
		// is full, an appropriate message is displayed.
	void remove(const elemType& removeItem);
		//Function to remove an item from the list. The parameter 
		//removeItem specifies the item to be removed.
		//Postcondition: If removeItem is found in the list,
		// it is removed from the list and length is 
		// decremented by one.



	arrayListType(const arrayListType<elemType>& otherList);
	//copy constructor

	~arrayListType();
	//destructor
	//Deallocates the memory occupied by the array.

protected:
	elemType* list; 	//array to hold the list elements
	int length;		//to store the length of the list
	int maxSize;		//to store the maximum size of the list
};


template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive. Creating "
			<< "an array of size 100. " << endl;

		maxSize = 100;
	}
	else
		maxSize = size;

	length = 0;

	list = new elemType[maxSize];
	assert(list != NULL);
}

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
	return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
	return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
	return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
	return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual 
(int location, const elemType& item) const
{
	return(list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{
	if (location < 0 || location >= maxSize)
		cerr << "The position of the item to be inserted "
		<< "is out of range." << endl;
	else
		if (length >= maxSize)  //list is full
			cerr << "Cannot insert in a full list" << endl;
		else
		{
			for (int i = length; i > location; i--)
				list[i] = list[i - 1];	//move the elements down

			list[location] = insertItem;	//insert the item at the 
										//specified position

			length++;	//increment the length
		}
} //end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
	if (length >= maxSize)  //the list is full
		cerr << "Cannot insert in a full list." << endl;
	else
	{
		list[length] = insertItem;	//insert the item at the end
		length++;	//increment length
	}
} //end insertEnd

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be removed "
		<< "is out of range." << endl;
	else
	{
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];

		length--;
	}
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt
(int location, elemType& retItem)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be retrieved is "
		<< "out of range." << endl;
	else
		retItem = list[location];
} // retrieveAt

template <class elemType>
void arrayListType<elemType>::replaceAt
(int location, const elemType& repItem)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be replaced is "
		<< "out of range." << endl;
	else
		list[location] = repItem;

} //end replaceAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
	length = 0;
} // end clearList

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item)
{
	int loc;
	bool found = false;

	for (loc = 0; loc < length; loc++)
		if (list[loc] == item)
		{
			found = true;
			break;
		}

	if (found)
		return loc;
	else
		return -1;
} //end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem) //insert to the end with NO DUPLICATES
{
	int loc;

	if (isFull())
		cout << "Cannot insert in a full list." << endl;
	else
	{
		loc = seqSearch(insertItem);

		if (loc == -1)   //the item to be inserted 
							//does not exist in the list
			list[length++] = insertItem;
		else
			cerr << "the item to be inserted is already in "
			<< "the list. No duplicates are allowed." << endl;
	}
} //end insert

template <class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
	int loc;

	loc = seqSearch(removeItem);

	if (loc != -1)
		removeAt(loc);
	else
		cout << "The tem to be deleted is not in the list."
		<< endl;
} //end remove



template <class elemType>
arrayListType<elemType>::~arrayListType()
{
	delete[] list;
}

//copy constructor
template <class elemType>
arrayListType<elemType>::arrayListType
(const arrayListType<elemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new elemType[maxSize]; 	//create the array
	assert(list != NULL);	//terminate if unable to allocate
							 //memory space

	for (int j = 0; j < length; j++)  //copy otherList
		list[j] = otherList.list[j];
}//end copy constructor


template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
(const arrayListType<elemType>& otherList)
{
	if (this != &otherList)	//avoid self-assignment
	{
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;

		list = new elemType[maxSize];
		assert(list != NULL);

		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}

	return *this;	//for cascading				   	   
}

template <class elemType>
void arrayListType<elemType>::printItem(int i) const
{
	cout << "Code\t\t:" << list[i].getCode() << endl;
	cout << "Name\t\t:" << list[i].getName() << endl;
	cout << "Type\t\t:" << list[i].getType() << endl;
	cout << "Price\t\t:" << list[i].getPrice() << endl;
	cout << "Stock\t\t:" << list[i].getStock() << endl;
	cout << "\n" << endl;
}

template <class elemType>
void arrayListType<elemType>::printAll() const
{
	for (int i = 0; i < length; i++) {
		cout << "/////////////////////////////" << endl;
		cout << "Code\t\t:" << list[i].getCode() << endl;
		cout << "Name\t\t:" << list[i].getName() << endl;
		cout << "Type\t\t:" << list[i].getType() << endl;
		cout << "Price\t\t:" << list[i].getPrice() << endl;
		cout << "Stock\t\t:" << list[i].getStock() << endl;
		cout << "/////////////////////////////" << endl;
		cout << "\n" << endl;
	}
}

template <class elemType>
int arrayListType<elemType>::priceGet(int i) const
{
	int x = list[i].getPrice();
	return x;
}

template <class elemType>
void arrayListType<elemType>::updateStock(int i) const
{
	list[i].stockUpdater();
}

template <class elemType>
int arrayListType<elemType>::stockGet(int i) const
{
	int x = list[i].getStock();
	return x;
}

template <class elemType>
int arrayListType<elemType>::itemSearch(string code) const
{
	int i = 0;
	bool found = false;
	for (i = 0; i < length; i++) {
		if (list[i].getCode() == code)
		{
			found = true;
			break;
		}
	}
	if (found = true)
		return i;
	else
		return -1;
}

template <class elemType>
void arrayListType<elemType>::removeItem(string code)
{
	int i;
	i = itemSearch(code);
	if (i != 1) {
		removeAt(i);
		cout << endl;
		cout << code << " is removed from the list. \n" << endl;
	}
	else {
		cout << endl;
		cout << "Unable to find the item.";
	}
}
#endif