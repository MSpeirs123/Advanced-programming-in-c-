#pragma once
#include <string>
#include <vector>
using namespace std;

class Interpreter
{
public:
	Interpreter(string file_name);
	~Interpreter();
	string interpret_strategy();
	void read_strategy(vector<vector<string>> items, string file_name);
	int value(string stg);
	int w, x, y, z, it, m;
	string l;
	string grid[10][14];
	
private:
	const string BETRAY = "BETRAY";
	const string SILENCE = "SILENCE";
	const string RANDOM = "SILENCE";
};

