#include "Interpreter.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

Interpreter::Interpreter(string file_name)
{
}

Interpreter::~Interpreter()
{
}

void Interpreter::read_strategy(vector<vector<string>> items, string file)
{
	const string file_name = file;
	string temp;
	ifstream data_file;
	data_file.open(file_name.c_str());

	if (data_file.fail())
		throw invalid_argument("no file exists " + file_name);

	while (getline(data_file, temp)) {
		vector<string> line;
		istringstream ls(temp);
		string item;
		while (ls >> item) {
			line.push_back(item);
		}
		items.push_back(line);
	}
	int i = 0;
	for (auto it1 = items.begin(); it1 != items.end(); ++it1) {

		int j = 0;
		for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) {

			grid[i][j] = *it2;

			++j;

		}
		++i;
	}
}

int Interpreter::value(string stg) {
	if (stg == "AllOUTCOMES_W")
		return w;
	else if (stg == "AllOUTCOMES_X")
		return x;
	else if (stg == "AllOUTCOMES_Y")
		return y;
	else if (stg == "AllOUTCOMES_Z")
		return z;
	else if (stg == "ITERATIONS")
		return it;
	else if (stg == "MYSCORE")
		return m;
}

string Interpreter::interpret_strategy() {
	bool f = false;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 14; ++j) {
			if (grid[i][j] == "BETRAY") {
				f = true;
				return "BETRAY";
				break;
			}
			else if (grid[i][j] == "SILENCE") {
				f = true;
				return "SILENCE";
				break;
			}
			else if (grid[i][j] == "RANDOM") {
				f = true;
				int r = rand() % 2;
				if (r == 0)
					return "BETRAY";
				else
					return "SILENCE";
				break;
			}
			else if (grid[i][j] == "IF") {
				if (grid[i][j + 2] == "<") {
					if (value(grid[i][j + 1]) < value(grid[i][j + 3])) {
						string ref = grid[i][j + 5];
						int k = 0;
						while (grid[k][0] != ref) {
							j = 0;
							k++;
							i = k;
						}
					}
					else
						i = i + 1, j = 0;
				}
				if (grid[i][j + 2] == ">") {
					if (value(grid[i][j + 1]) > value(grid[i][j + 3])) {
						string ref = grid[i][j + 5];
						int k = 0;
						while (grid[k][0] != ref) {
							j = 0;
							k++;
							i = k;
						}
					}
					else
						i = i + 1, j = 0;
				}
				if (grid[i][j + 2] == "=") {
					if (grid[i][j + 1] == "LASTOUTCOME") {
						if (grid[i][j + 3] == l) {
							string ref = grid[i][j + 5];
							int k = 0;
							while (grid[k][0] != ref) {
								j = 0;
								k++;
								i = k;
							}
						}
						else
							i = i + 1, j = 0;
					}
					else if (grid[i][j + 3] == "LASTOUTCOME") {
						if (grid[i][j + 1] == l) {
							string ref = grid[i][j + 5];
							int k = 0;
							while (grid[k][0] != ref) {
								j = 0;
								k++;
								i = k;
							}
						}
						else
							i = i + 1, j = 0;
					}
					else if (value(grid[i][j + 1]) < value(grid[i][j + 3])) {
						string ref = grid[i][j + 7];
						int k = 0;
						while (grid[k][0] != ref) {
							j = 0;
							k++;
							i = k;
						}
					}
					else
						i = i + 1, j = 0;
				}
				else if (value(grid[i][j + 1]) > value(grid[i][j + 3])) {
					string ref = grid[i][j + 5];
					int k = 0;
					while (grid[k][0] != ref) {
						j = 0;
						k++;
						i = k;
					}
				}
				else
					i = i + 1, j = 0;
			}
		}


		if (f == true)
			break;
	}
	int r = rand() % 2;
	if (r == 0)
		return "BETRAY";
	else
		return "SILENCE";
}



