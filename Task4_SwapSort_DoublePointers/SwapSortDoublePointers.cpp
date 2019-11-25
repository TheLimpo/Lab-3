#include <iostream>


using namespace std;



//double pointers
void swap_sort(int** daptr, int** dbptr, int** dcptr, bool order)
{
	//Sort in ascending order
	if (order == 1)
	{
		if (**daptr > **dbptr)
		{
			int temp = **daptr;
			**daptr = **dbptr;
			**dbptr = temp;
		}

		if (**daptr > **dcptr)
		{
			int temp = **daptr;
			**daptr = **dcptr;
			**dcptr = temp;
		}

		if (**dbptr > **dcptr)
		{
			int temp = **dbptr;
			**dbptr = **dcptr;
			**dcptr = temp;
		}

	}


	//Sort in descending order
	if (order == 0)
	{
		if (**daptr < **dbptr)
		{
			int temp = **daptr;
			**daptr = **dbptr;
			**dbptr = temp;
		}

		if (**daptr < **dcptr)
		{
			int temp = **daptr;
			**daptr = **dcptr;
			**dcptr = temp;
		}

		if (**dbptr < **dcptr)
		{
			int temp = **dbptr;
			**dbptr = **dcptr;
			**dcptr = temp;
		}

	}

}




int main()
{
	int a, b, c;
	int* aptr = &a, * bptr = &b, * cptr = &c; //pointers
	int** daptr = &aptr, ** dbptr = &bptr, ** dcptr = &cptr; //double pointers
	bool order;

	//run till 0 is given in a
	while (true)
	{
		cout << "Give a (0 to quit): ";
		cin >> a;
		if (a == 0)
		{
			cout << "Bye bye!" << endl;
			break;
		}
		cout << "Give b: ";
		cin >> b;

		cout << "Give c: ";
		cin >> c;

		cout << "Sort ascending/descending(1/0): ";
		cin >> order;

		//call function
		swap_sort(daptr, dbptr, dcptr, order);

		cout << "Result: " << **daptr << ", " << **dbptr << ", " << **dcptr << endl;
		cout << endl;
	}

}
