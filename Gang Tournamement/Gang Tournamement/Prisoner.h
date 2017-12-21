#pragma once
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include "Interpreter.h"

using namespace std;

class Prisoner
{
public:
	Prisoner(Interpreter* i);
	virtual ~Prisoner();
	virtual string choice(string last, int itr, int mscr, int allw, int allx, int ally, int allz, int alla, int allb, int allc);
	int w, x, y, z, it, m, a, b, c;
	string l;
	bool is_a_spy(int x);
protected:
	Interpreter* in;
	string file_name;
};

