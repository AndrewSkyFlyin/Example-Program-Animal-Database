/**************************************************************

Andrew Nguyen

Animal Database with Hash function and search

Visual Studio 2012

Summary: An animal database with a hash function and a search
		 using a hash table.

***************************************************************/

#include <iostream>
using namespace std;
#include "LinkedList.h"


int main()
{
	LinkedLists list;
	
	char selection;
	int  condition = 0;
	int  UserInput_Count = 0;
	
	
	list.display_menu();

	while (condition != 1)
	{
		cin >> selection;
		{
			switch (selection)
			{
			case 'E': case 'e':
				if (UserInput_Count == 100)
					cout << "The database is full." << endl;
				else
					list.append_node(UserInput_Count);
				break;

			case 'D': case 'd':
				list.traverse_node();
				break;

			case 'C': case 'c':
				list.clear_list(UserInput_Count);
				break;

			case 'S': case 's':
				list.search_list();
				break;

			case 'Q': case 'q':
				condition = 1;
				break;

			default:
				cout << "That was not a valid input. " << endl;
				cout << "Please input either E, D, C, S, or Q. " << endl;
				break;
				return 0;
			}
		}
	}

	system("pause");

	return 0;



}


void LinkedLists::append_node(int &UserInput_Count)
{
	if (root == NULL) //checks if a list even exists yet, if not make one.
	{
		root = new NODE;
		root->next = 0;
		conductor = root; 
	}
	
	else  //else add node on the list
	{
		conductor->next = new NODE;  // Creates a node at the end of the list
		conductor = conductor->next; // Points to that node
		conductor->next = 0;         // Prevents it from going any further
	}

	UserInput_Count = UserInput_Count + 1;

	cout << "Enter the name of the pet. " << endl;
	cin >> conductor->pet_name;

	cout << "Enter the owner's last name. " << endl;
	cin >> conductor->owner_lastname;

	cout << "Enter 0 for dog, 1 for cat, 2 for bird, 3 for reptile, 4 for other." << endl;
	cin >> Pet_Holder;
	cin.ignore(256, '\n');

	cout << "Enter pet's date of birth.  Ex: 05-23-2004" << endl;
	cin.getline(conductor->dob, 12);

	cout << "Enter pet's color." << endl;
	cin >> conductor->pet_color;


	if (Pet_Holder == 0)
		conductor->animal = NODE::Dog;
	else if (Pet_Holder == 1)
		conductor->animal = NODE::Cat;
	else if (Pet_Holder == 2)
		conductor->animal = NODE::Bird;
	else if (Pet_Holder == 3)
		conductor->animal = NODE::Reptile;
	else
		conductor->animal = NODE::Other;

	conductor->index = hash(conductor->pet_name, conductor->owner_lastname); // hashing function

	cout << " " << endl;
	cout << "Data entered.  Returning to menu." << endl;

	system("pause");
	display_menu();

}


void LinkedLists::traverse_node()  //prints the list
{
	traveler = root;
	if (traveler == NULL)
		cout << "The database is empty." << endl;
	else
	{
		while (traveler != 0)
		{
			cout << "------------------" << endl;
			cout << "Pet name: " << traveler->pet_name << endl;
			cout << "Owner: " << traveler->owner_lastname << endl;
			cout << "Category: ";

			if (traveler->animal == traveler->Dog)
				cout << "Dog" << endl;
			else if (traveler->animal == traveler->Cat)
				cout << "Cat" << endl;
			else if (traveler->animal == traveler->Bird)
				cout << "Bird" << endl;
			else if (traveler->animal == traveler->Reptile)
				cout << "Reptile" << endl;
			else
				cout << "Other" << endl;

			cout << "Date of birth: " << traveler->dob << endl;
			cout << "Pet color: " << traveler->pet_color << endl;
			
			cout << "Index value: " << traveler->index << endl; //testing line
			
			cout << "------------------" << endl;

			traveler = traveler->next;
		}
	}

	cout << "End of file.  Returning to menu." << endl;

	system("pause");
	display_menu();
}


void LinkedLists::clear_list(int &UserInput_Count)  //deletes the entire list
{
	if (root == NULL)
	{
		cout << "Database is already empty." << endl;
		return;
	}

	UserInput_Count = 0;

	for (int i = 0; i < tableSize; i++)
	{
		hashTable[i].filled = false;
	}
		
	NODE *curr1 = root;
	NODE *curr2 = root->next;

	while (curr2 != 0)
	{
		delete curr1;
		curr1 = curr2;
		curr2 = curr2->next;
	}

	delete curr1;
	root = 0;
	
	cout << "Database cleared." << endl;
	cout << " " << endl;
	cout << "End of search.  Returning to menu." << endl;
	

	system("pause");
	display_menu();

}

int LinkedLists::hash(string pName, string LName)
{
	int hashy = 0;
	int table_size = 97;


	for (int i = 0; i < pName.length(); i++)
	{
		hashy = hashy + (int)pName[i];
	}

	for (int k = 0; k < LName.length(); k++)
	{
		hashy = hashy + (int)LName[k];
	}

	hashy = hashy % table_size;
	
	
		hashTable[hashy].node_adr = conductor;
		hashTable[hashy].filled = true;
	
	

	return hashy;
}

void LinkedLists::search_list()
{
	char p_name[20] = {};
	char l_name[30] = {};
	int  hashy = 0;
	int  table_size = 97;
	
	cout << " " << endl;
	cout << "----Pet Database Search----" << endl;
	cout << " " << endl;
	cout << "Enter the pet's name: ";
	cin >> p_name;

	cout << " " << endl;
	cout << "Enter owner's last name: ";
	cin >> l_name;
	cout << " " << endl;


	string pNames = string(p_name);
	string lNames = string(l_name);


	for (int i = 0; i < pNames.length(); i++)
	{
		hashy = hashy + (int)pNames[i];
	}

	for (int k = 0; k < lNames.length(); k++)
	{
		hashy = hashy + (int)lNames[k];
	}

	hashy = hashy % table_size;  

	if (hashTable[hashy].filled == false)
		cout << "---No match has been found.---" << endl;
	else if (hashTable[hashy].filled == true)
	{
		cout << "--Entry founded--" << endl;
		cout << "Owner's name: " << hashTable[hashy].node_adr->owner_lastname << endl;
		cout << "Pet's name: " << hashTable[hashy].node_adr->pet_name << endl;
	}
	
	cout << " " << endl;
	cout << "End of search. Returning to menu." << endl;
	system("pause");
	display_menu();

}

void LinkedLists::display_menu()
{
	cout << " " << endl;
	cout << "Press E to enter new pet data. " << endl;
	cout << "Press D to display all data in the database. " << endl;
	cout << "Press S to search the database. " << endl;
	cout << "Press C to clear out the entire database. " << endl;
	cout << "Press Q to quit. " << endl;
}