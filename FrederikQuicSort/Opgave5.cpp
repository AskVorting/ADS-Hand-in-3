#include <stdio.h>      // printf, scanf, puts, NULL
#include <stdlib.h>     // srand, rand
#include <iostream>
#include <vector>
#include <ctime>    // For time()
#include <utility> // swap
#include <algorithm> // *min_element
using namespace std;
#include "quick_sort.h"
#include "insertion_sort.h"





int main()
{

	//function that creates random vector and returns it
	
		vector<int> randomVector;
		srand(time(0));
		for (int i = 0; i < 10; i++)
		{
			randomVector.push_back(rand() % 10);
		}
		
		//print random vector
		for (int i = 0; i < randomVector.size(); i++)
		{
			cout << randomVector[i] << " ";
		}

		cout << endl;
		quickSort(randomVector);

		//print sorted vector
		for (int i = 0; i < randomVector.size(); i++)
		{
			cout << randomVector[i] << " ";
		}
	
	



	

	
    
	return 0;
}
