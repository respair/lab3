#pragma once
#include <ostream>

template <class T>
class pair
{
public:
	T item = 0;
	int priority = 0;
	pair() {
		this->priority = 0;
		this->item = 0;
	}
	pair(int priority, T value) {
		this->priority = priority;
		this->item = value;
	}
	pair& operator = (const pair& pair) {
		this->item = pair.item;
		this->priority = pair.priority;
		return *this;
	}
	bool operator == (pair& pair) {
		if (this->priority == pair.priority && this->item == pair.item) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator > (pair& pair) {
		if (this->priority > pair.priority) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator < (const pair& pair) {
		if (this->priority < pair.priority) {
			return true;
		}
		else {
			return false;
		}
	}
	std::ostream& operator << (std::ostream& out) {
		out << "(" << this->priority << " - ";
		out << this->item << ")";
		return out;
	};
	~pair() = default;
};

template <class T>
std::ostream& operator << (std::ostream& out, pair<int>& p) {
	out << "(" << p.priority << " - ";
	out << p.item << ")";
	return out;
};