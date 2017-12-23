#pragma once

#include <iostream>

using namespace std;

template <class T>
class TStack {
	T* arr;
	int size;
	int maxsize;
public:
	TStack(int _maxsize = 10) {
		if (_maxsize <= 0)
			throw _maxsize;
		maxsize = _maxsize;
		size = 0;
		arr = new T[maxsize];
	}

	TStack(const TStack& st) {
		maxsize = st.maxsize;
		size = st.size;
		arr = new T[maxsize];
		for (int i = 0; i < size; i++) {
			arr[i] = st.arr[i];
		}
	}

	~TStack() {
		delete[] arr;
	}

	TStack& operator=(const TStack& st) {
		if (this != &st) {
			if (maxsize != st.maxsize) {
				maxsize = st.maxsize;
				delete[] arr;
				arr = new T[maxsize];
			}
			size = st.size;
			for (int i = 0; i < size; i++) {
				arr[i] = st.arr[i];
			}
		}
		return *this;
	}

	int isfull() {
		if (size == maxsize) return 1;
		return 0;
	}

	int isempty() {
		if (size == NULL) return 1;
		return 0;
	}

	T top() {
		if (isempty()) throw "top error";
		return arr[size - 1];
	}

	T pop() {
		if (isempty()) throw "pop error";
		size--;
		return arr[size];
	}

	void push(const T& el) {
		if (isfull()) throw "push error";
		arr[size] = el;
		size++;
	}

	int getsize() {
		return size;
	}

	int getmaxsize() {
		return maxsize;
	}

	int operator==(const TStack& st) const {
		if (maxsize != st.maxsize)
			return 0;
		if (size != st.size)
			return 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] != st.arr[i])
				return 0;
		}
		return 1;
	}

	int operator!=(const TStack& st) const {
		return !(*this == st);
	}

	void clear() {
		size = 0;
	}
};