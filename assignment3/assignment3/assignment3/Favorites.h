#pragma once
#include <iostream>
#include <string>
using namespace std;
//class declaration for FavoriteThings

class FavoriteThings
{
private:
	string brand; // makeup brand
	string name; // name of item 
	int type; // type of makeup item 
	string shade; 
	int price; // price for item 
	 
public: 
	FavoriteThings(); 
	FavoriteThings(string n, string b, string s, int t, int p);
	string getBrand();
	string getName();
	int getType(); 
	string getShade(); 
	int getPrice(); 
	void setType(int t);
	void setName(string n);
	void setBrand(string b); 
	void setShade(string s); 
	void setPrice(int p);
	void getFavoritesInput();	
	friend ostream& operator<<(ostream &output,  FavoriteThings &f);
};
