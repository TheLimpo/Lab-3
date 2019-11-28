#include <iostream>
#include <vector>
#include <string>
#include<fstream>


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






// Save vectornames to file
void save(const vector<string>* database)
{
	ofstream outfile;
	string out;

	cout << "Name the file you want to save to: ";
	cin >> out;
	outfile.open(out);

	for (auto e : *database)
	{
		outfile << e << endl;
		
	}
	outfile.close();
	cout << "File saved" << endl << endl;
	
}





// load names from file to vector
bool load(vector<string>* database)
{
	
	string str, in, data;
	cout << "To be able to load you need to clear your vector." << endl << "Do you want to do that?(yes/no): ";
	cin >> str;

	if (str == "yes" || str == "Yes")
	{
		database->clear();
		ifstream infile;
		cout << "Name the file you want to load: ";
		cin >> in;
		infile.open(in);

		if (!infile) //check if file does not exists
		{
			infile.close();
			cout << endl;
			cout << "File does not exist" << endl;
			cout << endl;
			return false;
		}
		
		
		while(getline(infile, data)) //write to vector
		{
			
			database->push_back(data);

		}
		infile.close();
		cout << endl;
		cout << "File loaded" << endl;
		cout << endl;
		return true;
	}
	else
	{
		cout << endl;
		cout << "File not loaded" << endl;
		cout << endl;
		return true;
	}

}





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
		cout << "1. Initialise/clear database" << endl << "2. Insert" << endl << "3. Search" << endl;
		cout << "4. Delete" << endl << "5. Print" << endl << "6. Save" << endl; 
		cout << "7. Load" << endl << "8. Quit" << endl << endl;
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

		case '6': //save vector to file
		{
			save(database);
			break;
		}

		case '7': //load names to vector
		{
			load(database);
			break;
		}

		case '8': //ends program
		{
			cout << "Goodbye!" << endl;
			goto exit_loop;
		}

		default:
			cout << "Not allowed, choose a number 1-8" << endl;
		}

	}

exit_loop:;

}



int main()
{

	menu_vector_database();

}