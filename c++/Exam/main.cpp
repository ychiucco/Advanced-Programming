#include <iostream>
#include <math.h>
#include <typeinfo>
#include <vector>
#include <chrono>

#include "BST.h"

void example_balance();
void example_find();
int main()
{
	BST<int,int> bst;
	int n = 1500;
	
	for (int i = 0; i < n; ++i)
	{
		bst.AddLeaf(i, i);
	}
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < n; ++i)
	{
		bst.find(i);
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		<< " milliseconds\n";
	bst.Balance();

	auto t3 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < n; ++i)
	{
		bst.find(i);
	}
	auto t4 = std::chrono::high_resolution_clock::now();
	std::cout << "took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count()
		<< " milliseconds\n";

	
	std::cin.get();
	return 0;
}
/*
void example_find()
{
	BST<int, double> bst;
	int keys[11] = { 4,1,3,2,5,8,6,7,9,11,10 };
	for (int i = 0; i < 11; ++i)
	{
		bst.AddLeaf(keys[i], 0);
	}

	for (auto it = bst.begin(); it != bst.find(8); ++it)
	{
		std::cout << *it << std::endl;
	}

}
void example_balance()
{
	BST<int, double> bst;
	int keys[11] = { 4,1,3,2,5,8,6,7,9,11,10 };
	for (int i = 0; i < 11; ++i)
	{
		bst.AddLeaf(keys[i], 0);
	}
	std::cout << bst << std::endl;
	bst.PrintRoot();
	bst.PrintFamily(1);
	bst.PrintFamily(2);
	bst.PrintFamily(3);
	bst.PrintFamily(4);
	bst.PrintFamily(5);
	bst.PrintFamily(6);
	bst.PrintFamily(7);
	bst.PrintFamily(8);
	bst.PrintFamily(9);
	bst.PrintFamily(10);
	bst.PrintFamily(11);
	bst.balance();
	bst.PrintRoot();
	bst.PrintFamily(1);
	bst.PrintFamily(2);
	bst.PrintFamily(3);
	bst.PrintFamily(4);
	bst.PrintFamily(5);
	bst.PrintFamily(6);
	bst.PrintFamily(7);
	bst.PrintFamily(8);
	bst.PrintFamily(9);
	bst.PrintFamily(10);
	bst.PrintFamily(11);
}*/