#include "Spy.h"
#include "Interpreter.h"
#include "Gang.h"


Spy::Spy(Interpreter* i, Gang* gn):
	Prisoner(i), g(gn)
{
}


Spy::~Spy()
{
}

string Spy::choice(string last, int itr, int mscr, int allw, int allx, int ally, int allz, int alla, int allb, int allc)
{
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
	if ((result == "BETRAY") && (g->n_of_SIL() < 3 )) {
		return "SILENCE";
	}
	else if ((result == "SILENCE") && (g->n_of_BTY() < 3)) {
		return "BETRAY";
	}
}