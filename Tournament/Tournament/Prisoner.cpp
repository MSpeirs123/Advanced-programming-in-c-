#include "Prisoner.h"
#include <fstream>
#include <string>
#include "Interpreter.h"
using namespace std;

Prisoner::Prisoner(Interpreter* i):
	in(i)
{
}

Prisoner::~Prisoner()
{
}

string Prisoner::choice(string last, int itr, int mscr, int allw, int allx, int ally, int allz) {
	l = last;
	it = itr;
	m = mscr;
	w = allw;
	x = allx;
	y = ally;
	z = allz;
	string result = in->interpret_strategy();
	return result;
}

