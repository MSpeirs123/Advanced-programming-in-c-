#include "Matrix.h"
#include <string>

using namespace std;

Matrix::Matrix(int x, int y) :
	x_size(x), y_size(y) {
	cells = new string*[x_size];
	for (int i = 0; i < x_size; ++i) {
		cells[i] = new string[y_size];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}

string Matrix::get_element(int x, int y) const {
	return (cells[x][y]);
}

void Matrix::set_element(int x, int y, string elem) {
	cells[x][y] = elem;
}