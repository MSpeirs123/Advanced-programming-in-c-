#include "Prisoner.h"
#include <fstream>
#include <string>
#include "Interpreter.h"
using namespace std;

Prisoner::Prisoner(Interpreter* i) :
	in(i)
{
}

Prisoner::~Prisoner()
{
}

string Prisoner::choice(string last, int itr, int mscr, int allw, int allx, int ally, int allz, int alla, int allb, int allc) {
	l = last;
	it = itr;
	m = mscr;
	w = allw;
	x = allx;
	y = ally;
	z = allz;
	a = alla;
	b = allb;
	c = allc;
	string result = in->interpret_strategy();
	return result;
}

bool Prisoner::is_a_spy(int x) {
	if (x == 1)
		return true;
	else
		return false;
}

