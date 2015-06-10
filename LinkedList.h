

#ifndef HOMEWORK_4_H
#define HOMEWORK_4_H

class LinkedLists
{
	static const int tableSize = 97;
	
	struct NODE
	{
		char dob[12];
		char pet_color[12];
		char pet_name[20];
		char owner_lastname[30];
		int  index;

		enum pet_type { Dog, Cat, Bird, Reptile, Other };

		pet_type animal;

		NODE *next;  //tail of the node

		NODE() : index(NULL) {}
	};


public:

	struct item
	{
		bool  filled;
		item *forward; //beta
		NODE *node_adr;

		item() : filled(false) {}
	};

	item hashTable[tableSize];

	NODE *conductor; //used to add nodes
	NODE *traveler;  //used to print data
	NODE *root;  //head of the list
	
	int Pet_Holder;

	LinkedLists() : conductor(NULL), 
					traveler(NULL), 
					root(NULL), 
					Pet_Holder(NULL)  {}
	
	
	int  hash(string pName, string LName);
	void append_node(int &UserInput_Count);
	void traverse_node();
	void clear_list(int &UserInput_Count);
	void search_list();
	void display_menu();




};
#endif