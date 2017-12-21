#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Interpreter.h"
#include "Prisoner.h"
#include "Matrix_Outcome.h"
#include <algorithm>
#include "Strategy_generator.h"

using namespace std;

int main() {
	Strategy_generator r_gen;
	r_gen.build_strategy();			//generate random strategies

	vector<vector<string>> items;
	Interpreter* intr[10];			//read interpret strategies
	
	intr[1] = new Interpreter("strategy2.txt");
	intr[2] = new Interpreter("strategy3.txt");
	intr[3] = new Interpreter("strategy4.txt");
	intr[4] = new Interpreter("strategy5.txt");
	intr[5] = new Interpreter("strategy6.txt");
	intr[6] = new Interpreter("strategy7.txt");
	intr[7] = new Interpreter("strategy8.txt");
	intr[8] = new Interpreter("strategy9.txt");
	intr[9] = new Interpreter("strategy10.txt");

	try {
		
		intr[1]->read_strategy(items, "strategy2.txt");
		intr[2]->read_strategy(items, "strategy3.txt");
		intr[3]->read_strategy(items, "strategy4.txt");
		intr[4]->read_strategy(items, "strategy5.txt");
		intr[5]->read_strategy(items, "strategy6.txt");
		intr[6]->read_strategy(items, "strategy7.txt");
		intr[7]->read_strategy(items, "strategy8.txt");
		intr[8]->read_strategy(items, "strategy9.txt");
		intr[9]->read_strategy(items, "strategy10.txt");
	}

	catch (const invalid_argument& iae) {
		cout << "unable to read data: " << iae.what() << endl;
		exit(1);
	}
	

	Matrix_Outcome m_out;			//Matrix to show outcomes
	int n[10] = { 0,0,0,0,0,0,0,0,0,0 };
	char d;
	char c;
	int e ;
	int f ;
	string ufile;

	cout << "Welcome to the prisoner's dilemma" << endl;
	cout << "Would you like to use your own strategy? y/n" << endl;
	cin >> d;
	if (d == 'y') {
		cout << "You have chosen to use your own strategy, please enter in name of strategy" << endl;
		cin >> ufile;
		intr[0] = new Interpreter(ufile);
		try {
			intr[0]->read_strategy(items, ufile);
		}
		catch (const invalid_argument& iae) {
			cout << "unable to read data: " << iae.what() << endl;
			exit(1);
		}
	}
	else {
		cout << "You haven chosen not to write your own strategy" << endl;
		intr[0] = new Interpreter("strategy1.txt");
		try {
			intr[0]->read_strategy(items, "strategy1.txt");
		}
		catch (const invalid_argument& iae) {
			cout << "unable to read data: " << iae.what() << endl;
			exit(1);
		}
	}

	cout << "How many strategies would you like to compete? Choose a number between 2 and 10" << endl;
	cin >> e;

	cout << "Would you like to run" << endl << "a) Some Games" << endl << "b) A Tournament" << endl;
	cin >> c;
	if (c == 'a') {
		cout << "How many games would you like to run?" << endl;
		cin >> f;
	}
	else {
		cout << "Now running tournament" << endl;
		f = 200;
	}

	Prisoner* p[10];				//Prisoners being assigned to each strategy

	p[0] = new Prisoner(intr[0]);
	p[1] = new Prisoner(intr[1]);
	p[2] = new Prisoner(intr[2]);
	p[3] = new Prisoner(intr[3]);
	p[4] = new Prisoner(intr[4]);
	p[5] = new Prisoner(intr[5]);
	p[6] = new Prisoner(intr[6]);
	p[7] = new Prisoner(intr[7]);
	p[8] = new Prisoner(intr[8]);
	p[9] = new Prisoner(intr[9]);


	for (int i = 0; i < e; ++i) {
		for (int j = 0; j < e; ++j) {
			string l[2] = { "a", "a" };
			int it = 0;
			int m[2] = { 0, 0 };
			int w[2] = { 0, 0 };
			int x[2] = { 0, 0 };
			int y[2] = { 0, 0 };
			int z[2] = { 0, 0 };
			int s[2] = { 0, 0 };
			for (int k = 0; k < f; ++k) {
				p[i]->choice(l[0], it, m[0], w[0], x[0], y[0], z[0]);
				p[j]->choice(l[1], it, m[1], w[1], x[1], y[1], z[1]);
				if (p[i]->choice(l[0], it, m[0], w[0], x[0], y[0], z[0]) == "BETRAY" && p[j]->choice(l[1], it, m[1], w[1], x[1], y[1], z[1]) == "BETRAY") {
					l[0] = l[1] = "Z";
					s[0] = s[1] = 4;
					z[0] = z[0] + 1;
					z[1] = z[1] + 1;
				}
				else if (p[i]->choice(l[0], it, m[0], w[0], x[0], y[0], z[0]) == "BETRAY" && p[j]->choice(l[1], it, m[1], w[1], x[1], y[1], z[1]) == "SILENCE") {
					l[0] = "Y";
					l[1] = "X";
					s[0] = 0;
					s[1] = 5;
					y[0] = y[0] + 1;
					x[1] = x[1] + 1;
				}
				else if (p[i]->choice(l[0], it, m[0], w[0], x[0], y[0], z[0]) == "SILENCE" && p[j]->choice(l[1], it, m[1], w[1], x[1], y[1], z[1]) == "BETRAY") {
					l[0] = "X";
					l[1] = "Y";
					s[0] = 5;
					s[1] = 0;
					x[0] = x[0] + 1;
					y[1] = y[1] + 1;
				}
				else if (p[i]->choice(l[0], it, m[0], w[0], x[0], y[0], z[0]) == "SILENCE" && p[j]->choice(l[1], it, m[1], w[1], x[1], y[1], z[1]) == "SILENCE") {
					l[0] = l[1] = "W";
					s[0] = s[1] = 2;
					w[0] = w[0] + 1;
					w[1] = w[1] + 1;
				}
				it = k + 1;
				m[0] = m[0] + s[0];
				m[1] = m[1] + s[1];
			}
			m_out.set_element(i, j, m[0]);
		}
	}
	
	for (int i = 0; i < e; ++i) {
		for (int j = 0; j < e; ++j) {
			if (m_out.get_element(i, j) < m_out.get_element(j, i))
				cout << "Strategy " << i << " beat strategy " << j << endl;
			else if (m_out.get_element(i, j) > m_out.get_element(j, i))
				cout << "Strategy " << i << " lost to strategy " << j << endl;
			else if (m_out.get_element(i, j) == m_out.get_element(j, i))
				cout << "Strategy " << i << " drew with strategy " << j << endl;
		}
	}

	cout << endl << "Table of results of tournament" << endl << endl;			//outputting score of player i on row i against player j on column j

	for (int i = 0; i < e; ++i) {
		for (int j = 0; j < e; ++j) {
			cout << m_out.get_element(i, j) << " ";
			if (m_out.get_element(i, j) < m_out.get_element(j, i))
				n[i] = n[i] + 1;
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < e; ++i) {
		cout << "Strategy " << i << " beat " << n[i] << " strategies" << endl;
	}
	cout << endl;
	int *best = max_element(begin(n), end(n));
	int k = 0;
	while (n[k] != *best)
		k++;

	cout << "Strategy " << k << " is the best strategy" << endl;




	ofstream outputFile;
	outputFile.open("Tournament_Results.txt");

	for (int i = 0; i < e; ++i) {
		for (int j = 0; j < e; ++j) {
			if (m_out.get_element(i, j) < m_out.get_element(j, i))
				outputFile << "Strategy " << i << " beat strategy " << j << endl;
			else if (m_out.get_element(i, j) > m_out.get_element(j, i))
				outputFile << "Strategy " << i << " lost to strategy " << j << endl;
			else if (m_out.get_element(i, j) == m_out.get_element(j, i))
				outputFile << "Strategy " << i << " drew with strategy " << j << endl;
		}
	}


	for (int i = 0; i < e; ++i) {
		for (int j = 0; j < e; ++j) {
			outputFile << m_out.get_element(i, j) << " ";
			if (m_out.get_element(i, j) < m_out.get_element(j, i))
				n[i] = n[i] + 1;
		}
		outputFile << endl;
	}
	outputFile << endl;
	for (int i = 0; i < e; ++i) {
		outputFile << "Strategy " << i << " beat " << n[i] << " strategies" << endl;
	}
	outputFile << endl;
	outputFile << "Strategy " << k << " is the best strategy" << endl;
	outputFile.close();

	for (int i = 0; i < 10; ++i) {
		delete p[i];
		p[i] = NULL;
		delete intr[i];
		intr[i] = NULL;
	}
	return 0;
}