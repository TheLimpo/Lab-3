#include <iostream>


using namespace std;



//Pointers
void swap_sort(int *aptr, int *bptr, int *cptr, bool order)
{
	//Sort in ascending order
	if (order == 1)
	{
		if (*aptr > *bptr)
		{
			int temp = *aptr;
			*aptr = *bptr;
			*bptr = temp;
		}

		if (*aptr > *cptr)
		{
			int temp = *aptr;
			*aptr = *cptr;
			*cptr = temp;
		}

		if (*bptr > *cptr)
		{
			int temp = *bptr;
			*bptr = *cptr;
			*cptr = temp;
		}

	}


	//Sort in descending order
	if (order == 0)
	{
		if (*aptr < *bptr)
		{
			int temp = *aptr;
			*aptr = *bptr;
			*bptr = temp;
		}

		if (*aptr < *cptr)
		{
			int temp = *aptr;
			*aptr = *cptr;
			*cptr = temp;
		}

		if (*bptr < *cptr)
		{
			int temp = *bptr;
			*bptr = *cptr;
			*cptr = temp;
		}

	}

}




int main()
{
	int a, b, c;
	int* aptr = &a, * bptr = &b, * cptr = &c;
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
		swap_sort(aptr, bptr, cptr, order);

		cout << "Result: " << *aptr << ", " << *bptr << ", " << *cptr << endl;
		cout << endl;
	}

}
