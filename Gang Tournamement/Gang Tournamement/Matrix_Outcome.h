#pragma once
////Code adapted from https://research.ncl.ac.uk/game/mastersdegree/programmingforgames/operatoroverloading/operator_overloading.cpp
#include <iostream>

using namespace std;

template <typename T>
class Matrix_Outcome
{
public:
	Matrix_Outcome(int x = default_x, int y = default_y);
	Matrix_Outcome(const Matrix_Outcome<T>& src);
	~Matrix_Outcome();
	Matrix_Outcome<T>& operator=(const Matrix_Outcome<T>& rhs);
	template <typename E>
	friend ostream& operator<<(ostream& ostr, const Matrix_Outcome<E>& mtx);
	template <typename E>
	friend Matrix_Outcome<E> operator-(const Matrix_Outcome<E>& a, const Matrix_Outcome<E>& b);

	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	T get_element(int x, int y) const;
	void set_element(int x, int y, T elem);
	static const int default_x = 10;
	static const int default_y = 10;
protected:
	T** cells;
	int x_size;
	int y_size;
};

template <typename T>
Matrix_Outcome<T>::Matrix_Outcome(int x, int y) :
	x_size(x), y_size(y) {
	cells = new T*[x_size];
	for (int i = 0; i < x_size; ++i) {
		cells[i] = new T[y_size];
		memset(cells[i], 0, (y_size * sizeof(T)));
	}
}

template <typename T>
Matrix_Outcome<T>::Matrix_Outcome(const Matrix_Outcome<T>& src) :
	x_size(src.x_size), y_size(src.y_size)
{
	cells = new T*[x_size];
	for (int i = 0; i < x_size; ++i)
	{
		cells[i] = new T[y_size];
		memcpy_s(cells[i], (y_size * sizeof(T)), src.cells[i], (y_size * sizeof(T)));
		//memcpy(cells[i], src.cells[i], y_size * sizeof(T)); // same but less safe than memcpy_s
	}
}

template <typename T>
Matrix_Outcome<T>::~Matrix_Outcome() {
	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}

template <typename T>
Matrix_Outcome<T>& Matrix_Outcome<T>::operator=(const Matrix_Outcome<T>& rhs)
{
	if (this == &rhs) return (*this);

	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;

	cells = new T*[rhs.x_size];
	for (int i = 0; i < rhs.x_size; ++i) {
		cells[i] = new T[rhs.y_size];
		memset(cells[i], 0, (rhs.y_size * sizeof(T)));
	}

	for (int i = 0; i < rhs.x_size; ++i) {
		for (int j = 0; j < rhs.y_size; ++j) {
			cells[i][j] = rhs.cells[i][j];
		}
	}
	return *this;
}

template <typename E>
ostream& operator<<(ostream& ostr, const Matrix_Outcome<E>& mtx) {
	for (int i = 0; i < mtx.x_size; ++i) {
		for (int j = 0; j < mtx.y_size; ++j) {
			ostr << mtx.cells[j][i] << ", ";
		}
		ostr << "\n";
	}
	ostr << "\n";
	return ostr;
}

template <typename E>
Matrix_Outcome<E> operator-(const Matrix_Outcome<E>& a, const Matrix_Outcome<E>& b) {
	Matrix_Outcome<E> result(a.x_size, b.y_size);
	for (int i = 0; i < a.x_size; ++i) {
		for (int j = 0; j < b.y_size; ++j) {
			result.cells[i][j] = (a.cells[i][j] - b.cells[i][j]);
		}
	}
	return result;
}

template <typename T>
T Matrix_Outcome<T>::get_element(int x, int y) const {
	return (cells[x][y]);
}

template <typename T>
void Matrix_Outcome<T>::set_element(int x, int y, T elem) {
	cells[x][y] = elem;
}