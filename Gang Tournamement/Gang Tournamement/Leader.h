#pragma once
#include "Prisoner.h"
#include "Gang.h"

class Leader : public Prisoner
{
public:
	Leader(Interpreter* i, Gang* gn);
	virtual ~Leader();
	bool virtual choose_spy(int pch);
protected:
	Gang* g;
};

