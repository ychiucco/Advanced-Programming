#include <iostream>
#include <math.h>
#include <typeinfo>
#include <vector>
#include <chrono>

#include "BST.h"

int main()
{
        int v[9] = { 4,2,1,3,9,5,7,6,8 };
	BST<int,double> bst;
	for (int i = 0; i < 9; ++i) { bst.AddLeaf(v[i], 0); }

        bst.PrintInOrder();
        
        std::cout << bst << std::endl;

        for (auto it = bst.begin(); it != bst.end(); ++it)
        {
            std::cout << *it << " --> " << bst[*it] << std::endl;
        }

        bst.RemoveNode(4);

        bst.PrintInOrder();

        bst.Balance();
          
        bst.PrintInOrder();

        return 0;
}