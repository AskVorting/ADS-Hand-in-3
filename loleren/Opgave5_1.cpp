#include <stdio.h>      // printf, scanf, puts, NULL
#include <stdlib.h>     // srand, rand
#include <iostream>
#include <vector>
#include <ctime>    // For time()
#include <chrono>
#include <algorithm>

using namespace std;
#include "Opgave5_1.h"



vector<int> make_vector(int size, int max, int min){
    max = max-min;
	vector<int> newvec;
    srand(time(0));
	for(int i = 0; i < size; i++)
	{
		newvec.push_back(rand()%max + min);
	}
return newvec;
}

void print(vector<int> &vec){
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main(){

    int size = 1000000;
    int times = 3;

    chrono::duration<double> time_InsertionSort;
    chrono::duration<double> time_QuickSort;
    chrono::duration<double> time_OurSort;
    chrono::duration<double> time_Sort;

    for (int i = 0; i < times; i++)
    {
        vector<int> myvector;
        myvector = make_vector(size, 1000, 0);

        auto start = chrono::steady_clock::now();
        OurSort(myvector);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_OurSort = time_OurSort + elapsed_seconds;
    }
    chrono::duration<double> time_OurSort_avg = time_OurSort / times;
    cout << "Time for OurSort(" << size << ") is " << time_OurSort_avg.count() << "s on average\n";


/*     for (int i = 0; i < times; i++)
    {
        vector<int> myvector;
        myvector = make_vector(size, 1000, 0);

        auto start = chrono::steady_clock::now();
        insertionSort(myvector);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_InsertionSort = time_InsertionSort + elapsed_seconds;
    }
    chrono::duration<double> time_InsertoinSort_avg = time_InsertionSort / times;
    cout << "Time for Insertionsort(" << size << ") is " << time_InsertoinSort_avg.count() << "s on average\n";
 */

    for (int i = 0; i < times; i++)
    {
        vector<int> myvector;
        myvector = make_vector(size, 10000, 0);

        auto start = chrono::steady_clock::now();
        quickSort(myvector);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_QuickSort = time_QuickSort + elapsed_seconds;
    }
    chrono::duration<double> time_QuickSort_avg = time_QuickSort / times;
    cout << "Time for QuickSort(" << size << ") is " << time_QuickSort_avg.count() << "s on average\n";

        for (int i = 0; i < times; i++)
    {
        vector<int> myvector;
        myvector = make_vector(size, 10000, 0);

        auto start = chrono::steady_clock::now();
        sort(myvector.begin(), myvector.end());
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_Sort = time_Sort + elapsed_seconds;
    }
    chrono::duration<double> time_Sort_avg = time_Sort / times;
    cout << "Time for Sort(" << size << ") is " << time_Sort_avg.count() << "s on average\n";


}