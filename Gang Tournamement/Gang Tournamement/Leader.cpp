#include "Leader.h"
#include "Gang.h"
#include "Prisoner.h"

Leader::Leader(Interpreter* i, Gang* gn):
	Prisoner(i), g(gn)
{
}


Leader::~Leader()
{
}

bool Leader::choose_spy(int pch) {
	if ((pch == 0) || (pch == 5))
		return true;
	else
		return false;
}