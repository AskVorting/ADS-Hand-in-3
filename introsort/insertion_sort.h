#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_
#include <stdio.h>      // printf, scanf, puts, NULL
#include <stdlib.h>     // srand, rand
#include <iostream>
#include <vector>
#include <ctime>    // For time()
#include <utility> // swap
#include <algorithm> // *min_element
using namespace std;





void insertionSort(vector<int>& a, int begin, int end)
		{
			for (int p = begin + 1; p != end; ++p) 
			{
				int tmp = std::move(p);
				int j;
				for (j  = p; 0<j && p< a[j-1]; --j)
					a[j] = std::move(a[j - 1]);
				a[j] = std::move(tmp);
			}
		}

#endif
