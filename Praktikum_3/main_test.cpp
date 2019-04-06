#include "MyAlgorithms.h"


int notmain()
{
	std::vector<int> A = { 98,44,30,22,64,63,11,23,8,18 };

	int size = A.size();

	//MyAlgorithms::QuickSort(A, 0, A.size()-1);

	//MyAlgorithms::MergeSort(A, 0, A.size);

	//MyAlgorithms::HeapSort(A, 0); 

	MyAlgorithms::ShellSort(A, A.size()); 

	for (int i = 0; i < size; i++)
	{
		std::cout << A[i] << " ";
	}

	std::cout << std::endl;

	system("PAUSE");
	return 0;
}

void cout_matrix(vector<double> M, int n)
{
	for (int i = 0; i < n*n; i++) {
		cout << M[i] << endl;
	}
	cout << "*************************************" << endl;
}
/*
int main()
{
	int n = 2;

	vector<double> A, B, C;
	A.resize(n*n);
	B.resize(n*n);
	C.resize(n*n);

	A[0] = 1;
	A[1] = 2;
	A[2] = 3;
	A[3] = 4;

	cout_matrix(A, n);

	B[0] = 5;
	B[1] = 6;
	B[2] = 7;
	B[3] = 8;

	cout_matrix(B, n);

	MyAlgorithms::MatrixMul_ColMajor(A, B, C, n, 1);

	cout_matrix(C, n);

	system("PAUSE");
	return 0;
}
*/