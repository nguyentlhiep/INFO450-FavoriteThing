#include <iostream>
#include <string>
#include "Favorites.h"
#include "List.h"
using namespace std; 

const int items = 1000; 
int main()
{
	int i;
	List myList;
	int userinput = 0;

	// Introduction to app 

	cout << "Welcome to your makeup list!" << endl; 
	cout << "This app will help you keep track of your favorite products." << endl; 
	


	while (userinput != 5)
	{
		// main menu, looped until the user chooses to exit.
		cout << "Choose one of the following: " << endl;
		cout << "1. Add a new item to your list. " << endl;
		cout << "2. Display your list. " << endl;
		cout << "3. Have another list? Add to this list." << endl;
		cout << "4. Save your list to a new file. " << endl;
		cout << "5. Exit" << endl;
		cin >> userinput;
		cin.ignore();

		switch (userinput)
		{
		case 1: // add a new item to the list 
		{
			myList.addItem();
			break;
		}
		case 2: // display list
		{
			myList.showList();
			break;
		}
		case 3: // Add list from file to memory 
		{
			string filename;
			cout << "To add your file to the list, enter the full path of your file location." << endl;
			cout << "example of full path: 'c:\\users\\linh\\documents\\makeuplist.txt'" << endl;
			getline(cin, filename, '\n');
			myList.readFromFile(filename);
			break;
		}
		case 4: // save list from memory into a new text file
		{
			string filename;
			cout << "To save your list to a new file, enter the full path filename." << endl;
			cout << "example of full path: 'c:\\users\\linh\\documents\\makeuplist.txt'" << endl;
			cout << "If you do not have a list in memory,"
				<< " then the only text printed in the new document will be" <<
				" the title: 'My Favorite Makeup Products'" << endl;
			getline(cin, filename, '\n');
			myList.writeToFile(filename);
			break;
		}
		case 5: // exit app
		{
			break;
		}
		}
	}
	system("pause");
	return 0;
}
