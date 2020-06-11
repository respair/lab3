#include <iostream>
#include <cassert>
#include <complex>
#include "Queue.hpp"
#include "BinarHeap.hpp"
#include "BinaryTree.hpp"


void TestBinarHeap() {
	std::cout << " -> test add item: " << std::endl;
	{
		BinaryHeap<int> h(2);
		int tmp[1] = { 2 };
		int* temp = new int[h.getSize()];
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
		assert(tmp[j] == temp[j]);
		std::cout << "BINARY HEAP: TEST 1.1: OK" << std::endl;
	}
	{
		BinaryHeap<int> h((2,0));
		for (auto i = 2; i < 5; i++) h.Add((i,0));
		std::complex<int> tmp[4] = { (4,0),(2,0),(3,0),(2,0) };
		std::complex<int>* temp = new std::complex<int>[h.getSize()];
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "BINARY HEAP: TEST 1.2: OK" << std::endl;
	}
	{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		int tmp[6] = { 4,2,3,0,2,1 };
		int* temp = new int[h.getSize()];
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "BINARY HEAP: TEST 2.1: OK" << std::endl;
	}
	{
		double temp[6] = { 2.1,0.3,1.22,2.5,3.01,4 };
		BinaryHeap<double> h(temp, 6);
		double tmp[6] = { 4,2.5,3.01,0.3,2.1,1.22 };
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "BINARY HEAP: TEST 2.2: OK" << std::endl;
	}
	{
		BinaryHeap<int> h(0);
		for (auto i = 0; i < 10; i++) h.Add(i);
		int tmp[11] = { 9, 8, 4, 5, 7, 0, 3, 0, 2, 1, 6 };
		int* temp = new int[h.getSize()];
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "BINARY HEAP: TEST 3.0: OK" << std::endl;
	}
	std::cout << std::endl;
	std::cout << " -> test delete item: " << std::endl;
	{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		h.deleteIn(0);
		int tmp[5] = { 3,2,2,0,1 };
		int* temp = new int[5];
		temp[0] = 0;
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "BINARY HEAP: TEST 4.0: OK" << std::endl;
	}
	{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		h.deleteIn(3);
		int tmp[5] = { 4,2,3,1,2 };
		int* temp = new int[5];
		temp[0] = 0;
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.searchValue(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "BINARY HEAP: TEST 5.0: OK" << std::endl;
	}
	std::cout << std::endl;
	std::cout << " -> test find item/index/min/max: " << std::endl;
	{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		int temp = h.searchValue(3);
		int tmp = 0;
	    assert(tmp == temp);
		std::cout << "BINARY HEAP: TEST 6.1: OK" << std::endl;
	}
	{
		double temp[6] = { 2.1,0.3,1.22,2.5,3.01,4 };
		BinaryHeap<double> h(temp, 6);
		double temp_ = h.searchValue(3);
		double tmp = 0.3;
		assert(tmp == temp_);
		std::cout << "BINARY HEAP: TEST 6.2: OK" << std::endl;
	}
	{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		int temp = h.searchIndex(0);
		int tmp = 3;
		assert(tmp == temp);
		std::cout << "BINARY HEAP: TEST 7.0: OK" << std::endl;
	}
	{
		double temp[6] = { 2.1,0.3,1.22,2.5,3.01,4 };
		BinaryHeap<double> h(temp, 6);
		double temp_ = h.getMin();
		double tmp = 0.3;
		assert(tmp == temp_);
		std::cout << "BINARY HEAP: TEST 8.1: OK" << std::endl;
	}
	{
		double temp[6] = { 2.1,0.3,1.22,2.5,3.01,4 };
		BinaryHeap<double> h(temp, 6);
		int temp_ = h.GetIndexMin();
		int tmp = 3;
		assert(tmp == temp_);
		std::cout << "BINARY HEAP: TEST 8.2: OK" << std::endl;
	}
	{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		int temp = h.getMax();
		int tmp = 4;
		assert(tmp == temp);
		std::cout << "BINARY HEAP: TEST 9.1: OK" << std::endl;
	}
	{
		BinaryHeap<int> h(2);
		for (auto i = 0; i < 5; i++) h.Add(i);
		int temp = h.GetIndexMax();
		int tmp = 0;
		assert(tmp == temp);
		std::cout << "BINARY HEAP: TEST 9.2: OK" << std::endl;
	}
	std::cout << std::endl;
}
void TestBinarTree() {
	std::cout << " -> test add item: " << std::endl;
	{
		BinaryTree<int> h(0);
		bool quest = h.beornot(0);
		if(true)
		    std::cout << "BINARY TREE: TEST 1.1: OK" << std::endl;
		else
	        std::cout << "BINARY TREE: TEST 1.1: ERROR" << std::endl;
	}
	{
		BinaryTree<int> h(2);
		bool quest = false;
		for (auto i = 0; i < 100; i++) h.add(i);
		for (int j = 0; j < h.getSize() - 1; j++) {
			quest = h.beornot(j);
			if (quest == false) {
				std::cout << "BINARY TREE: TEST 1.2: ERROR" << std::endl;
				break;
			}
		}
		if (quest == true)
			std::cout << "BINARY TREE: TEST 1.2: OK" << std::endl;
	}
	{
		BinaryTree<int> h(2);
		bool quest = false;
		for (auto i = 0; i < 15; i++) h.add(i);
		for (int j = 0; j < h.getSize()-1; j++) {
			quest = h.beornot(j);
			if (quest == false) {
				std::cout << "BINARY TREE: TEST 2.1: ERROR" << std::endl;
				break;
			}
		}
		if(quest == true)
		    std::cout << "BINARY TREE: TEST 2.1: OK" << std::endl;
	}
	{
		BinaryTree<double> h(2.3);
		bool quest = false;
		double i = 0.1;
		while (i < 5) {
			h.add(i);
			i = i + 1;
		}
		i = 0.1;
		while (i < 5) {
			quest = h.beornot(i);
			if (quest == false) {
				std::cout << "BINARY TREE: TEST 2.2: ERROR" << std::endl;
				break;
			}
			i = i + 1;
		}
		if (quest == true)
		    std::cout << "BINARY TREE: TEST 2.2: OK" << std::endl;
	}
	std::cout << std::endl;
	std::cout << " -> test delete item: " << std::endl;
	{
		BinaryTree<int> h(2);
		for (auto i = 0; i < 10; i++) h.add(i);
		h.erase(0);
		bool quest = h.beornot(0);
		if(quest == false)
		    std::cout << "BINARY TREE: TEST 3.1: OK" << std::endl;
		else
			std::cout << "BINARY TREE: TEST 3.1: ERROR" << std::endl;
	}
	{
		BinaryTree<int> h(2);
		for (auto i = 0; i < 5; i++) h.add(i);
		h.erase(3);
		bool quest = h.beornot(3);
		if (quest == false)
			std::cout << "BINARY TREE: TEST 3.2: OK" << std::endl;
		else
			std::cout << "BINARY TREE: TEST 3.2: ERROR" << std::endl;
	}
	std::cout << std::endl;
	std::cout << " -> test find min/max: " << std::endl;
	{
		BinaryTree<int> h(2);
		for (auto i = 0; i < 5; i++) h.add(i);
		int temp = h.min();
		int tmp = 0;
		assert(tmp == temp);
		std::cout << "BINARY TREE: TEST 4.1: OK" << std::endl;
	}
	{
		BinaryTree<double> h(2.3);
		double i = 1.1;
		while (i < 6) {
			h.add(i);
			i = i + 1;
		}
		double temp = h.min();
		double tmp = 1.1;
		assert(tmp == temp);
		std::cout << "BINARY TREE: TEST 4.2: OK" << std::endl;
	}
	{
		BinaryTree<int> h(2);
		for (auto i = 0; i < 5; i++) h.add(i);
		int temp = h.max();
		int tmp = 4;
		assert(tmp == temp);
		std::cout << "BINARY TREE: TEST 5.1: OK" << std::endl;
	}
	{
		BinaryTree<double> h(6.3);
		double i = 1.1;
		while (i < 6) {
			h.add(i);
			i = i + 1;
		}
		double temp = h.max();
		double tmp = 6.3;
		assert(tmp == temp);
		std::cout << "BINARY TREE: TEST 5.2: OK" << std::endl;
	}
	std::cout << std::endl;
}
void TestQueue() {
	std::cout << " -> test add item: " << std::endl;
	{
		Queue<int> h(0,2);
		pair<int> tmp[1] = { {0,2} };
		pair<int>* temp = new pair<int>[h.getSize()];
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.search(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "QUEUE_HEAP: TEST 1.1: OK" << std::endl;
	}
	{
		Queue<std::complex<int>> h({ 2,(2, 0) });
		for (int i = 3; i < 5; i++) h.add(i,(i,0));
		pair<std::complex<int>> tmp[3] = { {4,(4,0)},{2,(2,0)},{3,(3,0)} };
		pair<std::complex<int>>* temp = new pair<std::complex<int>>[h.getSize()];
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.search(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "QUEUE_HEAP: TEST 1.2: OK" << std::endl;
	}
	{
		Queue<int> h(2,1);
		for (auto i = 0; i < 5; i++) h.add(i,i);
		pair<int> tmp[6] = { {4,4 },{ 2,1 }, {3,3 }, { 0,0 }, { 2,2 }, { 1,1 } };
		pair<int>* temp = new pair<int>[h.getSize()];
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.search(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "QUEUE_HEAP: TEST 2.1: OK" << std::endl;
	}
	{
		pair<double> temp[6] = { {2,2.1 }, {0,0.3 }, {1,1.22}, {2,2.5}, {3,3.01}, {4,4 } };
		Queue<double> h(temp, 6);
		pair<double> tmp[6] = { {4,4},{2,2.1},{3,3.01},{0,0.3},{2,2.5},{1,1.22} };
		for (int j = 0; j < h.getSize(); j++) {
			temp[j] = h.search(j);
		}
		for (int j = 0; j < h.getSize(); j++)
			assert(tmp[j] == temp[j]);
		std::cout << "QUEUE_HEAP: TEST 2.2: OK" << std::endl;
	}
	std::cout << std::endl;
	std::cout << " -> test delete item: " << std::endl;
	{
		Queue<int> h(2,1);
		for (auto i = 0; i < 5; i++) h.add(i,i);
		h.deleTe(0);
		bool tmp = h.beornot({ 4,4 });
			assert(tmp == false);
		std::cout << "QUEUE_HEAP: TEST 3.1: OK" << std::endl;
	}
	{
		Queue<int> h(2,1);
		for (auto i = 0; i < 5; i++) h.add(i, i);
		h.deleTe(2);
		bool tmp = h.beornot({ 3,3 });
		assert(tmp == false);
		std::cout << "QUEUE_HEAP: TEST 3.2: OK" << std::endl;
	}
	std::cout << std::endl;
	std::cout << " -> test find item/min/max: " << std::endl;
	{
		Queue<int> h(2,1);
		for (auto i = 0; i < 5; i++) h.add(i,i);
		pair<int> temp = h.search(2);
		pair<int> tmp = { 3,3 };
		assert(tmp == temp);
		std::cout << "QUEUE_HEAP: TEST 4.1: OK" << std::endl;
	}
	{
		pair<double> temp[6] = { {2,2.1},{0,0.3},{1,1.22},{2,2.5},{3,3.01},{4,4} };
		Queue<double> h(temp, 6);
		pair<double> temp_ = h.search(1);
		pair<double> tmp = { 2,2.1 };
		assert(tmp == temp_);
		std::cout << "QUEUE_HEAP: TEST 4.2: OK" << std::endl;
	}
	{
		Queue<int> h(2, 1);
		for (auto i = 0; i < 5; i++) h.add(i, i);
		pair<int> temp = h.getMinPriority();
		pair<int> tmp = { 0,0 };
		assert(tmp == temp);
		std::cout << "QUEUE_HEAP: TEST 5.1: OK" << std::endl;
	}
	{
		pair<double> temp[6] = { {2,2.1},{0,0.3},{1,1.22},{2,2.5},{3,3.01},{4,0} };
		Queue<double> h(temp, 6);
		pair<double> temp_ = h.getMaxPriority();
		pair<double> tmp = { 4,0 };
		assert(tmp == temp_);
		std::cout << "QUEUE_HEAP: TEST 5.2: OK" << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "Tests for binary heap: " << std::endl;
	std::cout << std::endl;
	TestBinarHeap();
	std::cout << "Tests for binary tree: " << std::endl;
	std::cout << std::endl;
	TestBinarTree();
	std::cout << "Tests for queue (using a binary heap): " << std::endl;
	std::cout << std::endl;
	TestQueue();
}
