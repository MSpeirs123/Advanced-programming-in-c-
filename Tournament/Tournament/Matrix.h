#pragma once
#include <string>

//Code adapted from https://research.ncl.ac.uk/game/mastersdegree/programmingforgames/templates/templates.cpp 

using namespace std;

class Matrix
{
public:
	Matrix(int x = default_x, int y = default_y);
	~Matrix();
	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	string get_element(int x, int y) const;
	void set_element(int x, int y, string elem);
	static const int default_x = 10;
	static const int default_y = 14;
private:
	string** cells;
	int x_size;
	int y_size;
};

