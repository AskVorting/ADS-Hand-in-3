#include "insertion_sort.h"
#include "quick_sort.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <utility>


/*
class MyInstroSort
{
    private:
        vector<int> input;
        vector<int> output;
        int size;
        int max;

    public:
    //constructer of vector
    void initialize_random_vector(int size , int max)
    {
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            input.push_back(rand() % max);
        }
    }

    template <typename Iterator, typename Comparator>
    void insertionSort(const Iterator& begin, const Iterator& end, Comparator less)
    {
        if (begin == end)
            return;

        for (Iterator j, p = begin + 1; p != end; ++p) {
            auto tmp = std::move(*p);
            for (j = p; j != begin && less(tmp, *(j - 1)); --j)
                *j = std::move(*(j - 1));
            *j = std::move(tmp);
        }
    }
  
     
};
 */ 
using namespace std;
int main()
{
    vector<int> a = { 1, 2, 3, 6, 1, 4, 2, 9, 3, 10 };
    quickSort(a);

    //print vector a
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;



}
