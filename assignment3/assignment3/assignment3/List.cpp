#include <iostream>
#include <string>
#include "List.h"
#include "Favorites.h"
#include <fstream>
using namespace std; 

List::List()
{
	numProd = 0; 
	
}
void List::addItem()
{
	int i;
	products[numProd].getFavoritesInput();
	//check for duplicate entries
	for (i = 0; i < numProd; i++)
	{
		if (products[numProd].getName() == products[i].getName())
		{
			cout << "You already have this item!" << endl;
			products[numProd].getFavoritesInput();
		}
	}
	numProd++;
}
//method to print out entire list of items
void List::showList()
{
	cout << "My Favorite Makeup Products" << endl; 
	int j;
	for (j = 0; j < numProd; j++)
	{
		cout << products[j];
	}

}

int List::readFromFile(string filename)
{
string name, brand, shade;
int price;
string inputstring;

ifstream inputFile;
inputFile.open(filename, ios::in);
if (!inputFile)
{
	cout << "Error: can't open file." << endl;
	cout << "You will be redirected to the menu."<< endl;
	return -2;
}
while (!inputFile.eof())
{

	getline(inputFile, brand, '-');
	getline(inputFile, name, '-');
	getline(inputFile, shade, '|');
	getline(inputFile, inputstring, '$');
	getline(inputFile, inputstring, '\n');
	price = stoi(inputstring);

	products[numProd].setBrand(brand);
	products[numProd].setName(name);
	products[numProd].setShade(shade);
	products[numProd].setPrice(price);
	numProd++;
}
inputFile.close();
return 0;
}
// method to save list into new text file. 
int List::writeToFile(string filename)
{
	int i;
	ofstream outputFile;
	outputFile.open(filename, ios::trunc);
	if (!outputFile)
	{
		cout << "Error - file open failed." << endl;
		cout << "You'll be redirected back to the menu." << endl;
		return -2;
	}
	outputFile << "My Favorite Makeup Products: " << endl; 
	for (i = 0; i < numProd; i++)
	{
		if (products[i].getShade() == "")
		{
			outputFile << products[i].getBrand() << " - ";
			outputFile << products[i].getName() << " | ";
			outputFile << "$" << products[i].getPrice() << endl;
		}
		else
		{
			outputFile << products[i].getBrand() << " - ";
			outputFile << products[i].getName() << " - ";
			outputFile << products[i].getShade() << " | ";
			outputFile << "$" << products[i].getPrice() << endl;
		}

	}
	outputFile.close();
	return 0;

}

