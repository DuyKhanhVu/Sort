#pragma once
#include <fstream>
#include <stdlib.h>
using namespace std;

class Ascending
{
private:
	int _length;
	int *_arr;
public:
	Ascending(ifstream &fi);
	~Ascending();

	int GetLength();

	void SelectionSort();
	void InsertionSort();
	void HeapSort();
	void QuickSort(int left, int right);
	void MergeSort(int left, int right);
	void ShellSort();
	
	void Write(ofstream &fo);
};

