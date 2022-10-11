#include "disjoint_sets.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
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
void DisjSets::unionSets(int root1, int root2) {
	if (s[root2].value < s[root1].value)	// root2 is deeper
		s[root1].value = root2;		// Make root2 new root
		s[root1].next = root2;
	else {
		if (s[root1].value == s[root2].value)
			--s[root1].value;			// Update height if same
		s[root2].value = root1;		// Make root1 new root
		s[root2].next = root1;
	}
}

/**
 * Perform a find in O(log N).
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find(int x) const {
	if (s[x].value < 0)
		return x;
	else
		return find(s[x].value);
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
int DisjSets::iterativeFind(int x) const {
	while(s[x].value > -1){
		x = s[x].value;
	}
	return x;	
}

//Iterative find function with path compression
int DisjSets::iterativeFind(int x) {
	while(s[x] > -1){
		if(s[s[x]] > -1){
		s[x] = s[s[x]];
		}
		x = s[x];
	}
	return x;	
}

//Print all members in same set as node x
void DisjSets::print(Node x) {
	Node temp = s[x];
	while(s[temp].next != s[x]){
		cout << s[temp]
	}
}


