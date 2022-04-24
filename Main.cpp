#include <iostream>
#include <string>
#include "arrayListType.h"
#include "item.h"

using namespace std;

class FurnitureShop
{
private:
	arrayListType<FurnitureStore> FList;
	FurnitureStore FStore;
	string codeSearch;
	int x = 0;

public:
	void addItem();
	void displayItem();
	void sellItem();
	void itemRemove();
	void priceCalc(int price);
};

void FurnitureShop::addItem() {
	if (FList.isFull()) {
		cerr << "unable to add item, the list is full \n" << endl;
	}
	else {
		FStore.createItem();
		FList.insertAt(x, FStore);
		x++;
		cout << endl;
		cout << "Item ID: " << FStore.getCode() << " Has been added to the list. \n" << endl;
	}
}

void FurnitureShop::displayItem() {
	if (FList.isEmpty()) {
		cerr << "The list is empty \n" << endl;
	}
	else {
		cout << "List of all item" << endl;
		FList.printAll();
		cout << endl;
	}
}

void FurnitureShop::sellItem(){
	int found;
	if (FList.isEmpty()) {
		cerr << "The list is empty \n" << endl;
	}
	else {
		cout << "Item code to buy: " << endl;
		cin >> codeSearch;
		found = FList.itemSearch(codeSearch);

		if (found != -1) {
			FList.printItem(found);
		}
		else {
			cout << "Unable to find the item" << endl;
		}
	}
	char numItems, yn;
	int price, amountBought = 0;
	if (FList.stockGet(found) < 1) {
		cout << "Out of stock" << endl;
		FList.removeItem(codeSearch);
	}
	else if (FList.stockGet(found) == 1) {
		price = FList.priceGet(found);
		priceCalc(price);
		amountBought = 1;
		cout << "confirm purchase (y/n): ";
		cin >> yn;
		if (yn == 'n') {
			cout << "Purchase cancelled" << endl;
		}
		else if (yn == 'y') {
			FList.updateStock(found);
			cout << "Thank you for your purchase!" << endl;
		}
		else {
			cerr << "Error" << endl;
		}
	}
	else {
		cout << "How many items would you like to buy (1/2): ";
		cin >> numItems;
			switch (numItems) {
			case '1':
			{
				price = FList.priceGet(found);
				priceCalc(price);
				amountBought = 1;
				break;
			}
			case '2':
			{
				price = FList.priceGet(found) * 2;
				priceCalc(price);
				amountBought = 2;
				break;
			}
			}
			cout << "confirm purchase (y/n): ";
			cin >> yn;
			if (yn == 'n') {
				cout << "Purchase cancelled" << endl;
			}
			else if (yn == 'y') {
				if (amountBought == 1) {
					FList.updateStock(found);
				}
				else {
					FList.updateStock(found);
					FList.updateStock(found);
				}
				cout << "Thank you for your purchase!" << endl;
			}
			else {
				cerr << "Error" << endl;
			}
	}
}

void FurnitureShop::priceCalc(int price) {
	int priceTotal = price;
	int discount;
	if (priceTotal < 5000000) {
		cout << "Total cost of furniture: " << price << endl;
	}
	else if (5000000 < priceTotal < 10000000) {
		discount = priceTotal * 95 / 100;
		cout << "Total cost before discount: " << price << endl;
		cout << "Total cost after discount:" << discount << endl;
	}
	else {
		discount = priceTotal * 90 / 100;
		cout << "Total cost before discount: " << price << endl;
		cout << "Total cost after discount:" << discount << endl;
	}
}

void FurnitureShop::itemRemove() {
	if (FList.isEmpty()) {
		cerr << "The list is empty" << endl;
	}
	else {
		cout << "Code of item to be removed: ";
		cin >> codeSearch;
		int found = FList.itemSearch(codeSearch);

		if (found != -1) {
			FList.printItem(found);
		}
		else {
			cout << "Unable to find the item" << endl;
		}

		FList.removeItem(codeSearch);
	}

}

int main() {
	char op;
	FurnitureShop FShop;
	do
	{
		cout << "Furniture Store" << endl;
		cout << "1. Add Furniture" << endl;
		cout << "2. Display Furniture" << endl;
		cout << "3. Sell Furniture" << endl;
		cout << "4. Delete Furniture" << endl;
		cout << "5. exit" << endl;
		cout << "Pick your choice (1-5): ";
		cin >> op;
		cout << "\n" << endl;

		switch (op) {
		case '1':
		{
			FShop.addItem();
			break;
		}
		case '2':
		{
			FShop.displayItem();
			break;
		}
		case '3':
		{
			FShop.sellItem();
			break;
		}
		case '4':
		{
			FShop.itemRemove();
			break;
		}
		}
	} while (op != '5');
	
	return 0;
}
