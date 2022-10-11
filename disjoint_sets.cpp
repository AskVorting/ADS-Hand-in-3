#include "disjoint_sets.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjSets::DisjSets(int numElements):s(numElements, -1) {}

/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */
void DisjSets::unionSets(int root1, int root2) {
	if (s[root2] < s[root1])	// root2 is deeper
		s[root1] = root2;		// Make root2 new root
	else {
		if (s[root1] == s[root2])
			--s[root1];			// Update height if same
		s[root2] = root1;		// Make root1 new root
	}
}

/**
 * Perform a find in O(log N).
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find(int x) const {
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}

/**
 * Perform a find in logarithmic time with path compression.
 * It traverses the path twice, but complexity is the same up to constants.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find(int x) {
	if (s[x] < 0)
		return x;
	else
		return s[x] = find(s[x]);
}

//Iterative find function without path compression
int DisjSets::iterativeFind(int x) const {
	while(s[x] > -1){
		x = s[x];
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
void DisjSets::print(int x) {
	
}
