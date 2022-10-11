#include "disjoint_sets.h"
#include <iostream>
using namespace std;

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 * Node and next is used to enable the functionality of print function
 */
DisjSets::DisjSets(int numElements):s(numElements) {
	for (int i = 0; i < numElements; i++)
	{
		s[i].next = i;
		s[i].value = -1; 
	}
}

/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */
void DisjSets::unionSets(int root1, int root2) 
{
	// Makes sure that the roots of two sets are used
	root1 = DisjSets::find(root1);
	root2 = DisjSets::find(root2);

	if (s[root2].value < s[root1].value)	// root2 is deeper
		s[root1].value = root2;		// Make root2 new root
	else 
	{
		if (s[root1].value == s[root2].value)
			--s[root1].value;			// Update height if same
		s[root2].value = root1;		// Make root1 new root
	}
	//This links the elements together in a circle
	int temp = s[root1].next;
	s[root1].next = s[root2].next;
	s[root2].next = temp;
}


/**
 * Perform a find in O(log N).
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::findNo(int x) const {
	if (s[x].value < 0)
		return x;
	else
		return findNo(s[x].value);
}

/**
 * Perform a find in logarithmic time with path compression.
 * It traverses the path twice, but complexity is the same up to constants.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find(int x) {
	if (s[x].value < 0)
		return x;
	else
		return s[x].value = find(s[x].value);
}

//Iterative find function without path compression
int DisjSets::iterativeFindNo(int x) const {
	while(s[x].value > -1){
		x = s[x].value;
	}
	return x;	
}

//Iterative find function with path compression
int DisjSets::iterativeFind(int x) {
	int temp = x;
	while(s[x].value > -1){
		x = s[x].value;
	}
	//Sets the value of the original x to be the root of the set
	s[temp].value = x;
	return x;	
}

//Print all members in same set as node x
//Since the members are in a 'circle' it simply prints all elements until it reaches the starting point.
void DisjSets::print(int x) {
	int temp = x;
	while(s[temp].next != x){
		cout << s[temp].next << " ";
		temp = s[temp].next;
	}
	std::cout << "(" << x << ")" << endl;
}

int main(){
	DisjSets set(9);

	set.unionSets(6,7);
	set.unionSets(4,3);
	set.unionSets(4,5);
	set.unionSets(4,6);

	int x = set.iterativeFind(7);

	cout << x << "\n";

	for (int i = 0; i < set.s.size(); i++)
	{
		cout << set.s[i].value << " ";
	}

	cout << endl;

	set.print(4);
	

}

