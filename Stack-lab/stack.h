#pragma once
template <class T>
class TStack {
	T* arr;
	int size;
	int maxsize;
public:
	TStack(int _maxsize = 10) {
		maxsize = _maxsize;
		size = 0;
		arr = new T[maxsize];
	}
};