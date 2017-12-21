#include "Gang.h"
#include "Prisoner.h"
#include "Spy.h"


Gang::Gang(Prisoner* pr1, Prisoner* pr2, Prisoner* pr3, Prisoner* pr4, Prisoner* pr5):
	p1(pr1), p2(pr2), p3(pr3), p4(pr4), p5(pr5)
{
}


Gang::~Gang()
{
}

int Gang::n_of_BTY() {
	int n = 0;
	if (p1->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p2->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p3->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p4->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p5->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	return n;
}

int Gang::pre_spy_n_of_BTY() {
	int n = 0;
	if (p1->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p2->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p3->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p4->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	return n;
}

int Gang::n_of_BTY_ws() {
	int n = 0;
	if (p1->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p2->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p3->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (p4->choice(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	if (Gang::p5_spy_outcome(l, it, m, w, x, y, z, a, b, c) == "BETRAY")
		n = n + 1;
	return n;
}

int Gang::n_of_SIL() {
	int n = 0;
	if (p1->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p2->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p3->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p4->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p5->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	return n;
}

int Gang::pre_spy_n_of_SIL() {
	int n = 0;
	if (p1->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p2->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p3->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p4->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	return n;
}

int Gang::n_of_SIL_ws() {
	int n = 0;
	if (p1->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p2->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p3->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (p4->choice(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	if (Gang::p5_spy_outcome(l, it, m, w, x, y, z, a, b, c) == "SILENCE")
		n = n + 1;
	return n;
}

string Gang::p5_spy_outcome(string last, int itr, int mscr, int allw, int allx, int ally, int allz, int alla, int allb, int allc) {
	
	string result = p5->choice(last, itr, mscr, allw, allx, ally, allz, alla, allb, allc);
	if (p5->is_a_spy(x) == true) {
		if ((result == "BETRAY") && (Gang::pre_spy_n_of_SIL() < 3)) {
			return "SILENCE";
		}
		else if ((result == "SILENCE") && (Gang::pre_spy_n_of_BTY() < 3)) {
			return "BETRAY";
		}
	}
	else 
		return result;
}

bool Gang::p1_leader_choice(int lch, int s) {
	if (lch == s)
		return true;
	else
		return false;
}

