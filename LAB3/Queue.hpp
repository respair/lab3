#pragma once
#include "pairForQueue.hpp"
#include "BinarHeap.hpp"

template <class T>
class Queue
{
private:
	BinaryHeap<pair<T>>* queue;
	int size = 0;
public:
	Queue(const int priority, const T data) {
		this->queue = new BinaryHeap<pair<T>>(pair<T>(priority, data));
		this->size = 1;
	}
	Queue(pair<T>* p, int size) {
		if (size <= 0) throw std::length_error(NegativeSize);
		this->queue = new BinaryHeap<pair<T>>( p, size);
		this->size = size;
	}
	bool operator == (Queue& q) {
		if (q.queue == this->queue)
			return true;
		else return false;
	}
	void add(const int priority, const T value)
	{
		this->queue->Add(pair<T>(priority, value));
		this->size++;
	}
	void deleTe(int priority)
	{
		this->queue->deleteIn(priority);
		this->size--;
	}
	pair<T> search(int priority) {
		return this->queue->searchValue(priority);
	}
	bool beornot(pair<T> value) {
		bool answ = this->queue->beornot(value);
		return answ;
	}
	pair<T> getMinPriority() {
		return this->queue->getMin();
	}
	pair<T> getMaxPriority() {
		return this->queue->getMax();
	}
	int getSize() {
		return this->size;
	}
	void Show() {
		this->queue->Show();
	}
	~Queue() = default;
};


