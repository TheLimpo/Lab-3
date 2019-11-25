#include<iostream>


using namespace std;



float average_salary(const int* arr, const int employ)
{
	float sum = 0;

	for (int i = 0; i < employ; i++)
	{
		sum = sum + arr[i];
	}

	float mean = sum / employ;
	cout << endl;

	return mean;
}



int main()
{
	int employ;

	cout << "How many employees work in this department?: ";
	cin >> employ; 
	cout << endl;

	int* arr = new int[employ];
	for (int i = 0; i < employ; i++)
	{
		cout << "What are their individual salaries?: ";
		cin >> arr[i];
	}

	cout << "Average salary for this department is " << average_salary(arr, employ) << endl;

	delete[] arr;
}