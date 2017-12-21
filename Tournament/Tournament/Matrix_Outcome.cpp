#include "Matrix_Outcome.h"


using namespace std;

Matrix_Outcome::Matrix_Outcome(int x, int y) :
	x_size(x), y_size(y) {
	cells = new int*[x_size];
	for (int i = 0; i < x_size; ++i) {
		cells[i] = new int[y_size];
	}
}

Matrix_Outcome::~Matrix_Outcome() {
	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}

int Matrix_Outcome::get_element(int x, int y) const {
	return (cells[x][y]);
}

void Matrix_Outcome::set_element(int x, int y, int elem) {
	cells[x][y] = elem;
}