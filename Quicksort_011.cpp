#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0; //number of comparasion
int mov_count = 0; //number of data movements
int n;

void  input() {
	while (true)
	{
		cout << "Masukan panjang element array : ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
//swaps the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
void q_sort(int low, int high)
{
	int pivot, i, j;
	if (low > high)
		return;														// langkah 1

	//Partition the list into two parts:
	// one containing elements less that or equal to pivot
	//Outher containing elements greather than pivot 

	pivot = arr[low];											    //Langkah 2

    i = low + 1;													//Langkah 3
	j = high;														//Langkah 4

	while (i <= j)
	{
		//search for an element greater than pivot
		while ((arr[i] <= pivot) && (i <= high))					//Langkah 5
		{
			i++;													//Langkah 6				
			cmp_count++;
		}
		cmp_count++;
		//search for an element less than or rqual to pivot
		while ((arr[j] > pivot) && (j >= low))						//Langkah 7
		{
			j--;
			cmp_count++;											//Langkah 8
		}
		cmp_count++;
																	//Langkah 9
		if (i < j) //if the greater element is on the left of the element
		{
			//swap the element at index i whit the element at index
			swap(i, j);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < j)													//Langkah 11
	{
		//move the pivot to its correct potition in the list
		swap(low, j);
		mov_count++;
	}
	q_sort(low, j - i);												//Langkah 12

	//sort the list on the right of pivot using quick sort
	q_sort(j + i, high);											//Langkah 13
}