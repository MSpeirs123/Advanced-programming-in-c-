#pragma once
#include "Prisoner.h"
#include "Interpreter.h"
#include <string>
#include "Gang.h"

class Spy : public Prisoner
{
public:
	Spy(Interpreter* i, Gang* gn);
	virtual~Spy();
	virtual string choice(string last, int itr, int mscr, int allw, int allx, int ally, int allz, int alla, int allb, int allc);
protected:
	Gang* g;
};

