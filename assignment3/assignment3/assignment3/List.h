#pragma once
#include <iostream>
#include <string>
#include "Favorites.h"
using namespace std; 
//class declaration for List
class List
{
protected:
	FavoriteThings products[1000];
	int numProd;
public: 
	List();
	void addItem(); 
	void showList();
	int readFromFile(string filename);
	int writeToFile(string filename);
};
