#pragma once
//Code adapted from https://research.ncl.ac.uk/game/mastersdegree/programmingforgames/templates/templates.cpp 

using namespace std;

class Matrix_Outcome  
{
public:
	Matrix_Outcome(int x = default_x, int y = default_y);
	~Matrix_Outcome();
	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	int get_element(int x, int y) const;
	void set_element(int x, int y, int elem);
	static const int default_x = 10;
	static const int default_y = 10;
private:
	int** cells;
	int x_size;
	int y_size;
};

