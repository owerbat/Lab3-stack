#pragma once
template <class T>
class TStack {
	T* arr;
	int size;
	int maxsize;
public:
	TStack(int _maxsize = 10) {
		if (_maxsize <= 0) throw maxsize;
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

	T top() {                             // возвращает вершину
		if (isempty()) throw - 1;
		return arr[size - 1];
	}

	T pop() {                             // удаляет верхний элемент и возвращает его
		if (isempty()) throw - 1;
		size--;
		return arr[size];
	}

	void push(const T& el) {              // добавляет элемент
		if (isfull()) throw - 1;
		arr[size] = el;
		size++;
	}
};