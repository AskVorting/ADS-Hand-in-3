#include <iostream>
//#include "disjoint_sets.h"
#include "disjoint_sets.cpp"


int main(){
    DisjSets::DisjSets(9);
    
    DisjSets::unionSets(4,5);
    DisjSets::unionSets(6,7);
    DisjSets::unionSets(4,6);

    std::cout << "EqClass: ";
    for (int i = 0; i < 9; i++)
    {
        std::cout << s[i] ;
    }
    
    
    return 0;
}