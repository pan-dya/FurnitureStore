#pragma once

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;

class FurnitureStore
{
private:
	string Code, Name, Type; 
	int Price, Stock ;

public:
	void createItem();
	string getCode();
	string getName();
	string getType();
	int getPrice();
	void stockUpdater();
	int getStock();
};

void FurnitureStore::createItem() {
	cout << "Inpute the code of the item: ";
	cin >> Code;
	cout << "Inpute the name of the item: ";
	getline(cin >> ws, Name);
	cout << "Inpute the type of the item: ";
	getline(cin >> ws, Type);
	cout << "Inpute the price of the item: ";
	cin >> Price;
	cout << "Inpute the number of stock of the item: ";
	cin >> Stock;
}
string FurnitureStore::getCode() {
	return Code;
}
string FurnitureStore::getName() {
	return Name;
}
string FurnitureStore::getType() {
	return Type;
}
int FurnitureStore::getPrice() {
	return Price;
}
void FurnitureStore::stockUpdater() {
	if (Stock == 0)return;
	--Stock;
}
int FurnitureStore::getStock() { 
	return Stock;
}

#endif