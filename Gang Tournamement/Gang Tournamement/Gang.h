#pragma once
#include "Prisoner.h"
class Gang
{
public:
	Gang(Prisoner* pr1, Prisoner* pr2, Prisoner* pr3, Prisoner* pr4, Prisoner* pr5);
	~Gang();
	int n_of_BTY();
	int n_of_SIL();
	int n_of_BTY_ws();
	int n_of_SIL_ws();
	bool p1_leader_choice(int lch, int s);
private:
	Prisoner* p1;
	Prisoner* p2;
	Prisoner* p3;
	Prisoner* p4;
	Prisoner* p5;
	int w, x, y, z, it, m, a, b, c;
	string l;
	int s;
	string p5_spy_outcome(string last, int itr, int mscr, int allw, int allx, int ally, int allz, int alla, int allb, int allc);
	int pre_spy_n_of_SIL();
	int pre_spy_n_of_BTY();
};

