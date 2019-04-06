#include "MyAlgorithms.h"
#include <omp.h>
#include <cmath>

namespace MyAlgorithms {

  //************
  // QuickSort *
  //************  
	void QuickSort(vector<int> &arr, int left, int right) {
		int i = left, j = right;
		int tmp;
		int pivot = arr[(left + right) / 2];
		//partition
		while (i <= j) {
			while (arr[i] < pivot)
			{
				i++;
				std::cout << "arr[i] = " << arr[i];
			}
			while (arr[j] > pivot)
				j--;
			if (i <= j) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i++;
				j--;
			}
		}
		/* recursion */
		if (left < j)
		QuickSort(arr, left, j);
		if (i < right)
		QuickSort(arr, i, right);
	}
  //************
  // MergeSort *
  //************
  void MergeSort(vector<int> &a, int low, int high) {
	  if (high-low>1)
	  {
		  int middle = (low + high) / 2;
		  MyAlgorithms::MergeSort(a, low, middle);
		  MyAlgorithms::MergeSort(a, middle + 1, high);
		  MyAlgorithms::Merge(a, low, middle, high);
	  }
	  else
		  return;
  }
  void Merge(vector<int> &a, int l, int m, int r){
	  int n1 = m - l;
	  int n2 = r - m;
	  vector<int> links(n1);
	  vector<int> rechts(n2);

	  int first = 0, second = 0, merged = 0;

	  //Links befuellen
	  for (first = 0; first < n1; first++)  
	  {
		  links[first] = a[l + first];
	  }
	  //rechts befuellen
	  for (second = 0; second < n2; second++)
	  {
		  rechts[second] = a[(m + 1) + second]; 
	  }

	  while (first < n1 && second < n2)
	  {
		  if (links[first] <= rechts[second])
		  {
			  a[merged] = links[first];
			  first++;
		  }
		  else
		  {
			  a[merged] = rechts[second];
			  second++;
		  }
		  merged++;
	  }
	  while (first < n1)
	  {
		  a[merged] = links[first];
		  first++; 
		  merged++;
	  }
	  while (second < n2)
	  {
		  a[merged] = rechts[second];
		  second++;
		  merged++;
	  }

  }


  //************
  // Heapsort  *
  //************

  void HeapSort(vector<int> &A, int n) { 
	  n = A.size();
	  int i = n / 2; 

	  while (i >= 0)
	  {
		  percDown(A, i, n);
		  i = i - 1;
	  }

	  int j = n - 1;

	  while (j > 0)
	  {
		  std::swap(A[0], A[j]);
		  percDown(A, 0, j);
		  j = j - 1;
	  }
  }

  void percDown(vector<int> &A, int p, int r)
  {
	  int child = p;
	  int tmp = A[p];
	  int j = p;
	  int n = r - p;

	  while (leftChild(j) < n)
	  {
		  child = leftChild(j);
		  if (child != (n - 1) && A[child] < A[child+1])
		  {
			  child = child + 1;
		  }
		  if (tmp < A[child])
		  {
			  std::swap(A[j], A[child]);
			  j = child;
		  }
		  else
			  return;
	  }
  }

  int leftChild(int i)
  {
	  return 2 * i + 1;
  }

  //************
  // Shellsort *
  //************
  void ShellSort(vector<int> &a, int n) {
	  n = a.size();
	  int hibbard = 0;
	  int hibbard_alt = 0;

	  while (hibbard < n)
	  {
		  hibbard_alt = hibbard;
		  hibbard = 2 * hibbard + 1;
	  }
	  for (int gap = hibbard_alt; gap > 0; gap = (gap - 1) / 2)
	  {
		  for (int i = gap; i < n; i++)
		  {
			  int tmp = a[i];
			  int j = i;
			  while (j >= gap && tmp < a[j - gap])
			  {
				  a[j] = a[j - gap];
				  j = j - gap;
			  }
			  a[j] = tmp;
		  }
	  }
  }
 
  //************************************
  //Matrix Multiplication Column Major *
  //************************************

  void MatrixMul_ColMajor(vector<double> &A, 
			  vector<double> &B, 
			  vector<double> &C, 
			  int n, 
			  int numThreads)
  {
    //lda, ldb, ldc are leading dimensions of matrices A,B and C
    int lda = n;
    int ldb = n;
    int ldc = n;
    double s = 0.0;

	omp_set_num_threads(2);
	#pragma omp parallel for
    for (int i=0; i<n ; i++) {
      for (int j=0; j<n ; j++) {
	s = 0.0;
	for (int k=0; k<n; k++) {
		s += A[k + lda * i] * B[j + ldb * k];
	}
	C[i+ldc*j]=s;
      }
    }
  }

  //*********************************
  //Matrix Multiplication Row Major *
  //*********************************

  void MatrixMul_RowMajor(vector<double> &A, 
			  vector<double> &B, 
			  vector<double> &C, 
			  int n,
			  int numThreads)
  {
	  int lda = n;
	  int ldb = n;
	  int ldc = n;
	  double s = 0.0;
	  omp_set_num_threads(2);
		#pragma omp parallel for
	  for (int i = 0; i < n; i++) {
		  for (int j = 0; j < n; j++) {
			  s = 0;
			  for (int k = 0; k < n; k++) {
				  s += A[k + lda * i] * B[j + ldb * k];
			  }
			  C[j + ldc * i] = s;
		  }
	  }


  }

  //********************
  // helper functions  *
  //********************
  double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
  }

  void randomizeMatrix(vector<double> &matrix, int n) {
    matrix.resize(n*n);
    int i;
    for (i=0;i<matrix.size();i++)
      matrix[i]=fRand(-1000,1000);
  }

  void randomizeArray(vector<int> &array, int n) {
    array.resize(n);

    for(int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }
}
