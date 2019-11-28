#include<iostream>

using namespace std;


void replace_chars(char* str, char out, char in)
{
	//This solution feels like it can be 100 times better
	for (int i = 0; i = (*str != '\0'); str++)
	{
		if (*str == out) //This is needed to change the first character in the string
		{
			*str = in;
		}


		if (*(str + i) == out)
		{
			*(str + i) = in;

		}
	}
}



int main()
{
	char out, in;

	char arr[] = "aibohphobia";
	char* str = arr;

	cout << "Char array is: " << str << endl << endl;

	cout << "What character do you want to replace?: ";
	cin >> out;

	cout << "What character do you want to replace that with?: ";
	cin >> in;

	replace_chars(str, out, in);
	cout << endl;

	cout << "Char array is " << str << endl;
	
}