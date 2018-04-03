#include "Ascending.h"

int main(int argc, char** argv)
{
	ifstream fi;
	fi.open(argv[2]);
	ofstream fo;
	fo.open(argv[3]);

	Ascending a(fi);
	unsigned int tt = atoi(argv[1]);
	if (tt==1) {a.SelectionSort(); a.Write(fo);}
	else if (tt==2) {a.InsertionSort(); a.Write(fo);}
	else if (tt==3) {a.HeapSort(); a.Write(fo);}
	else if (tt==4) {a.QuickSort(0, a.GetLength() - 1); a.Write(fo);}
	else if (tt==5) {a.MergeSort(0, a.GetLength() - 1); a.Write(fo);}
	fi.close();
	fo.close();
}