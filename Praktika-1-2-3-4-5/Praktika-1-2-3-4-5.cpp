
#include <chrono>
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <windows.h>
#include <future>
using namespace std;

void PrintArray(int arr[], int size)
{
	cout << "Згенерований масив| " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	for (int i = size - 5; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}


void SortArray(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


void CountingSort(int arr[], int size)
{
	const int maximum = 501;
	int sortarray[maximum] = {};
	for (int i = 0; i < size; i++)
	{
		sortarray[arr[i]]++;
	}

	int index = 0;
	for (int i = 0; i < maximum; i++)
	{
		while (sortarray[i] > 0)
		{
			arr[index] = i;
			++index;
			sortarray[i]--;
		}

	}
}

void QuickSort(int arr[], int first, int last)
{
	int k = first;
	int n = last;
	int central = arr[(first + last) / 2];
	while (n >= k)
	{
		while (arr[k] < central)
		{
			k++;
		}
		while (arr[n] > central)
		{
			n--;
		}
		if (k <= n)
		{
			swap(arr[k], arr[n]);
			k++;
			n--;
		}
	}
	if (first < n)
	{
		QuickSort(arr, first, n);
	}
	if (k < last)
	{
		QuickSort(arr, k, last);
	}
}

void asinhron(int arr[], int first, int last)
{
	int k = first;
	int n = last;
	int central = arr[(first + last) / 2];
	while (n >= k)
	{
		while (arr[k] < central)
		{
			k++;
		}
		while (arr[n] > central)
		{
			n--;
		}
		if (k <= n)
		{
			swap(arr[k], arr[n]);
			k++;
			n--;
		}
	}
	if (last - first > 10000);
	{
		future<void> left_half;
	}
	if (first < n)
	{
		auto left_half = std::async(std::launch::async, asinhron, arr, first, n);
	}
	if (k < last)
	{
		asinhron(arr, k, last);
	}
}


void GenerateArray(int arr[], int size)
{
	int min = 50;
	int max = 500;
	for (int i = 0; i < size; i++) {

		arr[i] = rand() % (max - min + 1) + min;


	}
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	srand(time(NULL));


	int sizes[] = { 18, 160, 1024, 4096, 32600, 128000 };
	int numSizes = 6;
	int choise;
	cout << "Введіть яким методом хочете посортувати" << endl << "1 Швидке сортування " << endl << "2 Сортування підрахунком" << endl << "3 Сортування вставкою" << endl << " 4	Асинхронне швидке сортування " << endl;
	cin >> choise;
	for (int i = 0; i < numSizes; i++)
	{
		int currentsize = sizes[i];
		int* dinamik = new int[currentsize];

		GenerateArray(dinamik, currentsize);
		auto start = chrono::high_resolution_clock::now();
		switch (choise)
		{
		case 1:
			QuickSort(dinamik, 0, currentsize - 1);
			break;
		case 2:
			CountingSort(dinamik, currentsize);
			break;
		case 3:
			SortArray(dinamik, currentsize);
			break;
		case 4:
			asinhron(dinamik, 0, currentsize - 1);
			break;
		default:
			cout << "Ясно ж сказано, ввести 1 2 або 3 " << endl;
			break;
		}
		auto end = chrono::high_resolution_clock::now();
		PrintArray(dinamik, currentsize);
		delete[] dinamik;
		chrono::duration<double, milli> time_taken = end - start;
		cout << "Час сортування " << time_taken.count() << " мс" << endl;
	}



}