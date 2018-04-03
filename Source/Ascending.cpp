#pragma once
#include "Ascending.h"

Ascending::Ascending(ifstream &fi)
{
	fi >> _length;
	_arr = new int[_length];
	for (int i = 0;i < _length;i++)
	{
		fi >> *(_arr + i);
	}
}

Ascending::~Ascending()
{
	delete[] _arr;
}

int Ascending::GetLength()
{
	return _length;
}

void Ascending::SelectionSort()
{
	int	min;
	for (int i = 0;i < _length;i++)
	{
		min = i;
		for (int j = i + 1;j < _length;j++)
		{
			if (*(_arr + min) > *(_arr + j))
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = *(_arr + i);
			*(_arr + i) = *(_arr + min);
			*(_arr + min) = temp;
		}
	}
}

void Ascending::InsertionSort()
{
	for (int i = 0;i < _length;i++)
	{
		int key = *(_arr + i);
		int j = i - 1;
		while (j >= 0 && *(_arr + j) > key)
		{
			*(_arr + j + 1) = *(_arr + j);
			j--;
		}
		*(_arr + j + 1) = key;
	}
}

void Swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void Heapify(int *_arr, int _length, int i)
{
	while (i <= _length / 2 - 1)
	{
		int child1 = 2 * i + 1;
		int child2 = 2 * i + 2;
		int lc = child1;
		if ((child2 < _length) && (*(_arr + child2) > *(_arr + lc)))
			lc = child2;
		if (*(_arr + i) < *(_arr + lc))
			Swap(*(_arr + i), *(_arr + lc));
		i = lc;
	}
}


void Ascending::HeapSort()
{
	for (int i = _length / 2 - 1;i >= 0;i--) //BuildHeap
		Heapify(_arr, _length, i);
	for (int i = _length - 1;i > 0;i--)
	{
		Swap(*(_arr), *(_arr + i));
		Heapify(_arr, i, 0);
	}
}

void Ascending::QuickSort(int left, int right)
{
	int i = left;
	int j = right;
	int x = *(_arr + (left + right) / 2);
	while (i < j)
	{
		while (*(_arr + i) < x) i++;
		while (*(_arr + j) > x) j--;
		if (i <= j)
		{
			int t = *(_arr + i);
			*(_arr + i) = *(_arr + j);
			*(_arr + j) = t;
			i++;
			j--;
		}
	}
	if (left < j) QuickSort(left, j);
	if (right > i) QuickSort(i, right);
}

void merge(int *_arr, int left, int m, int right)
{
	int *temp = new int[right - left + 1];
	int i = left;
	int j = m + 1;	
	for (int k = 0;k <= right - left;k++)
	{
		if (*(_arr + i) < *(_arr + j))
		{
			*(temp + k) = *(_arr + i);
			i++;
		}
		else
		{
			*(temp + k) = *(_arr + j);
			j++;
		}

		if (i == m + 1)
		{
			while (j <= right)
			{
				k++;
				*(temp + k) = *(_arr + j);
				j++;
			}
			break;
		}

		if (j == right + 1)
		{
			while (i <= m)
			{
				k++;
				*(temp + k) = *(_arr + i);
				i++;
			}
			break;
		}
	}

	for (int k = 0;k <= right - left;k++)
	{
		*(_arr + left + k) = *(temp + k);
	}
	
	delete temp;
}

void Ascending::MergeSort(int left, int right)
{
	if (left < right)
	{

		int m = left + (right - left) / 2;

		MergeSort(left, m);
		MergeSort(m + 1, right);

		merge(_arr, left, m, right);
	}
}

void Ascending::Write(ofstream &fo)
{
	for (int i = 0;i < _length;i++)
	{
		fo << *(_arr + i) << " ";
	}
}