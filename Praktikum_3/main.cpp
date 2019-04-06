#include <iostream>
#include <fstream> 
#include <iomanip> 
#include <vector>
#include <omp.h>
#include "MyAlgorithms.h"

using namespace std;

int main(int argc, char** argv) {

	//***************
	// file streams *
	//***************
	//ofstream quicksort;
	//ofstream heapsort;
	//ofstream mergesort;
	//ofstream shellsort;
	ofstream matrix_col_1;
	ofstream matrix_col_max;
	ofstream matrix_row_1;
	ofstream matrix_row_max;

	/*
	quicksort.open("quicksort.txt", ios::out | ios::app);
	heapsort.open("quicksort.txt", ios::out | ios::app);
	mergesort.open("quicksort.txt", ios::out | ios::app);
	shellsort.open("quicksort.txt", ios::out | ios::app);
	*/
	matrix_col_1.open("mergesort.txt", ios::out | ios::app);
	


	//******************** 
	//benchmark settings *
	//********************

	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;
	int numThreads = 2; //only for matrix multiplication

						//********************************************************************
						//data structures for sorting algorithms (int) and matrices (double) *
						//********************************************************************

	vector<int> array, temp_array;
	vector<double> A, B, C;


	//********************************************************
	//benchmark main loop (run only ONE algorithm at a time) *
	//********************************************************

	for (int n = n_start; n<n_end; n += n_step) {
		//cout << "n: " << n << endl;

		//***************************************
		//init data structure with random values*
		//***************************************

		//sorting algorithms
		MyAlgorithms::randomizeArray(array, n);

		//matrix multiplication
		//if (n>800) { n_step=11; }
		//MyAlgorithms::randomizeMatrix(A,n);
		//MyAlgorithms::randomizeMatrix(B,n);
		//C.resize(n*n);

		
		//****************
		//  start clock  *
		//**************** 
		dtime = omp_get_wtime();

		//**********************
		//  execute algorithm  *
		//**********************
		/*
		MyAlgorithms::QuickSort(array, 0, array.size() - 1);
		MyAlgorithms::HeapSort(array, 0);
		MyAlgorithms::MergeSort(array, 0, (array.size() - 1));
		MyAlgorithms::ShellSort(array, 0);
		*/
		//MyAlgorithms::MatrixMul_RowMajor(A, B, C, n, 2);
		MyAlgorithms::MergeSort(array, 0, (array.size() - 1));

		//***************
		//  stop clock  *
		//***************
		dtime = omp_get_wtime() - dtime;

		//*************************
		//  write results to file *
		//*************************
		/*
		quicksort << n << "\t" << setprecision(10) << scientific << dtime << endl;
		heapsort << n << "\t" << setprecision(10) << scientific << dtime << endl;
		mergesort << n << "\t" << setprecision(10) << scientific << dtime << endl;
		shellsort << n << "\t" << setprecision(10) << scientific << dtime << endl;
		*/
		matrix_col_1 << n << "\t" << setprecision(10) << scientific << dtime << endl;

	}

	//**********************
	//  close file handles *
	//**********************

	matrix_col_1.close();
}
