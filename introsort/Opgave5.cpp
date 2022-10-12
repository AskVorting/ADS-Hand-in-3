#include <stdio.h>      // printf, scanf, puts, NULL
#include <stdlib.h>     // srand, rand
#include <iostream>
#include <vector>
#include <ctime>    // For time()
#include <utility> // swap
#include <algorithm> // *min_element
using namespace std;
#include "quick_sort.h"



class SortClass
{
	public:
		vector<int> input;
		//create a vector with random numbers
		void initialize_random_vector(int size)
		{
			for (int i = 0; i < size; i++)
			{
				input.push_back(i);
			}    
		}
		//permute the vector	
		void permute(vector<int>& a) 
		{
			for (int j = 1; j < a.size(); ++j) {
				swap(a[j], a[rand() % j]);
			}
		}
		//print vector
		void print()
		{
			for (int i = 0; i < input.size(); i++)
				{
					cout << input[i] << " ";
				}
				cout << endl;
		}

		//check if the vector is sorted
		void checkSort(const vector<int>& a) 
		{
			for (int i = 0; i < a.size() - 1; ++i) {
				if (a[i] >= a[i + 1]) {
					cout << "Error at " << i << endl;
				}
			}
			cout << "Finished checksort \n" << endl;
		}

		template <typename Iterator, typename Comparator>
		void insertionSort(vector<Comparator>& a, int begin, int end){
			if (begin == end)
				return;

			for (Iterator j, p = begin + 1; p != end; ++p) {
				auto tmp = std::move(*p);
				for (j = p; j != begin && less(tmp, *(j - 1)); --j)
					*j = std::move(*(j - 1));
				*j = std::move(tmp);
			}

};

			

		//introsort
		void introSort(vector<int>&a, int left, int right )
		{
			int n = right - left + 1;
			for(int i = n;  i == 0 ; i--)
			{
				if(n <= 16)
				{
					cout<<"elements not sorted"<< n <<"insertion sort"<<endl;
					insertionSort(a, left, right);
				}
				else
				{
					quickSort(a, left, right);
				}
			}
		}
};


int main()
{
	SortClass sort;
	sort.initialize_random_vector(100);
	sort.permute(sort.input);
	cout<<"input vector after permutation"<<endl;
	sort.print();

	cout<<"input vector after introsort"<<endl;
	sort.introSort(sort.input, 0, sort.input.size()-1);
	sort.print();
	sort.checkSort(sort.input);

	

	return 0;
}
