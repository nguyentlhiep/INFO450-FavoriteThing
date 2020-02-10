#include <iostream>
#include <string>
#include "Favorites.h"	
using namespace std; 

FavoriteThings::FavoriteThings()
{
	brand = "";
	name = "";
	shade = ""; 
	type = 0;
	price = 0;
}
FavoriteThings::FavoriteThings(string n, string b, string s, int t, int p)
{
	brand = b; 
	name = n; 
	type = t;
	shade = s; 
	price = p;
}
string FavoriteThings::getBrand()
{
	return brand;
}
string FavoriteThings::getName()
{
	return name; 
}
int FavoriteThings::getType()
{
	return type;
}

string FavoriteThings::getShade()
{
	return shade;
}
int FavoriteThings::getPrice()
{
	return price;
}
void FavoriteThings::setPrice(int p)
{
	price = p;
}
void FavoriteThings::setType(int t)
{
	type = t;
}

void FavoriteThings::setName(string n)
{
	name = n;
}
void FavoriteThings::setBrand(string b)
{
	brand = b; 
}
void FavoriteThings::setShade(string s)
{
	shade = s;
}
//method to get user input
void FavoriteThings::getFavoritesInput()
{
	cout << "Choose Makeup Type: " << endl; 
	cout << "1. Foundation/eyeliner/lips" << endl;
	cout << "2. Eyeshadow Palette" << endl;
	cin >> type;
	cin.ignore();
	switch (type)
	{
	case 1: // Foundation, eyeliner, lipstick
		cout << "Enter Brand: " << endl;
		getline(cin, brand);
		cout << "Enter Name: " << endl;
		getline(cin, name);
		cout << "Enter Shade: " << endl;
		getline(cin, shade);
		cout << "Price: " << endl;
		cin >> price;
		cin.ignore();
		break;
	case 2: // Eyeshadow Palette
		cout << "Enter Brand: " << endl;
		getline(cin, brand, '\n');
		cout << "Palette Name: " << endl;
		getline(cin, name, '\n');
		cout << "Price: " << endl;
		cin >> price;
		cin.ignore();
		break;
	}
}
//method to print out item
ostream& operator<<(ostream &output,  FavoriteThings& f)
{
	if (f.shade == "")
	{
		output << f.brand << " - " << f.name << " | $" << f.price << endl;
	}
	else
	{
		output << f.brand << " - " << f.name << " - " << f.shade << " | $"
			<< f.price << endl;
	}
	return output;

} 