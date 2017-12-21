#pragma once
#include <string>
#include <vector>
using namespace std;

class Interpreter
{
public:
	Interpreter(string file_name);
	~Interpreter();
	string BETRAY = "BETRAY";
	string SILENCE = "SILENCE";
	string RANDOM = "SILENCE";
	string interpret_strategy();
	void read_strategy(vector<vector<string>> items, string file_name);
	int value(string stg);
	int a, b, c, w, x, y, z, it, m;
	string l;
	string grid[10][14];
private:
	
};