#include <iostream>

using namespace std;

int string_length(char* ptr)
{
	int count = 0;
	//This looks weird but it works. You'll see an even weirder at Task 5.
	for (int i = 0; i = (*ptr != '\0'); ptr++)
	{
		count++;
	}

	return count;
}


int main()
{

	char arr[] = "computergames";
	char* ptr = arr;

	cout << string_length(ptr) << endl;

}