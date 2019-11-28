#include <iostream>
#include <vector>
#include <string>

using namespace std;





//clears the vector
void initialise_database(vector<string>* database) 
{
	string str;
	cout << "Are you sure?(yes/no): ";
	cin >> str;

	if (str == "yes" || str == "Yes")
	{
		database->clear();
		cout << "Vector initialised" << endl;
		cout << endl;
	}
	else
	{
		cout << "Vector NOT initialised" << endl;
		cout << endl;
	}
	


}

//insert names in the vector
void insert(vector<string>* database)
{
	string str;
	while (str != "Q" && str != "q")
	{
		cout << "Insert a name (Q to quit): ";
		cin >> str;

		if (str != "Q" && str != "q")
		{
			database->push_back(str);
			cout << "Name has been inserted" << endl;
		}

	}
	cout << "Q has been pressed. You have exited." << endl;
	cout << endl;
}

//search the vector for names beginning with
bool search(const vector<string>* database)
{
	bool t = 0;
	string str;
	cout << "What name do you want to search?: ";
	cin >> str;
	int len = str.length();

	for (auto e : *database)
	{
		if (str == e.substr(0, len))
		{
			cout << e << endl;
			t = 1;
		}
	}
	cout << endl;
	return t;



	/*
	
	
	
	for (int i = 0; i < database->size(); i++)
	{
		if (str == *((database + i)->substr(0, len)))
		{
			cout << (database + i) << endl;
		}
	}
	
	
	
	
	*/
}

//delete single names
bool name_delete(vector<string>* database)
{
	bool t = 0;
	string str;
	cout << "What name do you want to delete?: ";
	cin >> str;
	cout << endl;

	int i = 0;
	for (auto e : *database)
	{
		
		if (e == str)
		{
			database->erase(database->begin() + i);
			cout << "Name deleted" << endl;
			t = 1;
			break;
		}
		i++;
	}
	cout << endl;
	return t;


	//the other for I haven't solved how to syntax
	/*for (int i = 0; i < database->size(); database++)
	{
		if (*(database + i) == str)
		{
			database->erase(database->begin() + i);
			break;
		}

	}
	*/



}


//prints the names in the vector
bool print(const vector<string>* database)
{
	bool t = 0;
	for (auto e : *database)
	{
		cout << e << endl;
		t = 1;
	}
	cout << endl;
	return t;
}
/*//the other for I haven't solved how to syntax

int i = 0; i < database->size(); i++)
	{
		cout << *(database + i) << endl;

*/



void menu_vector_database()
{
	bool t = 0;
	char choise;
	vector<string> v;
	vector<string>* database = &v;


	while (true)
	{
		//Menu
		cout << "MENU:" << endl;
		cout << "1. Initialise database" << endl << "2. Insert" << endl << "3. Search" << endl;
		cout << "4. Delete" << endl << "5. Print" << endl << "6. Quit" << endl << endl;
		cout << "Make your choise: ";
		cin >> choise;
		cout << endl;


		switch (choise)
		{

		case '1': //clears the vector
		{
			initialise_database(database);
			break;
		}

		case '2': //insert names in the vector
		{
			insert(database);
			break;
		}

		case '3': //search the vector for names beginning with
		{
			t = search(database);
			if (t == 0)
			{
				cout << "No names found" << endl;
				cout << endl;
			}

			
			break;
		}

		case '4': //delete single names
		{
			t = name_delete(database);
			if (t == 0)
			{
				cout << "No name deleted" << endl;
				cout << endl;
			}

			
			break;
		}

		case '5': //prints the names in the vector
		{
			t = print(database);
			if (t == 0)
			{
				cout << "No names found" << endl;
				cout << endl;
			}
			
			break;
		}

		case '6': //ends program
		{
			cout << "Goodbye!" << endl;
			goto exit_loop;
		}

		default:
			cout << "Not allowed, choose a number 1-6" << endl;
		}

	}

exit_loop:;


}



int main()
{

	menu_vector_database();

}