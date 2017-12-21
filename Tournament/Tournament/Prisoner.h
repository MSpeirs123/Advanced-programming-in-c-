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
	~Prisoner();
	string choice(string last, int itr, int mscr, int allw, int allx, int ally, int allz);
	int w, x, y, z, it, m;
	string l;
private:
	Interpreter* in;
	string file_name;
};

