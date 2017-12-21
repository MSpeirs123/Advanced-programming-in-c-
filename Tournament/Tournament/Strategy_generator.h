#pragma once
#include <string>

using namespace std;

class Strategy_generator
{
public:
	Strategy_generator();
	~Strategy_generator();
	void build_strategy();
private:
	string choose_operand(int r);
	char choose_operator(int r);
	string choose_outcome(int r);

};

