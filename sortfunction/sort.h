#ifndef _SORT_H_
#define _SORT_H_



#include <algorithm>
#include <utility>
#include <vector>

//selectionSort function
//sort a vector of integers using selection sort
//input: a vector of typename T
//output: a sorted vector of typename T
//the functuin sorts in ascending order
template <typename T>
void selectionSort(vector<T>& vect)
{
   for(int i = vect.begin(), i < vect.end(), i++)
   {
        int min = i;
        for(int j = i+1, j < vect.end(), j++)
        {
             if(vect[j] < vect[min])
                min = j;
        }
        swap(vect[i], vect[min]);
   }
}





#include <vector>
using namespace std;

#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

#endif
