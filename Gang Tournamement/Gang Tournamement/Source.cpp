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
#include "Gang.h"
#include "Spy.h"
#include "Leader.h"
#include <time.h>


using namespace std;



bool s_chance(int x) {
	if ((rand() % 100) < x)
		return true;
	else
		return false;
}

int main() {
	Strategy_generator r_gen;
	r_gen.build_strategy();			//generate random strategies

	vector<vector<string>> items;
	Interpreter* intr[10];			//read interpret strategies
	intr[0] = new Interpreter("strategy1.txt");
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
		intr[0]->read_strategy(items, "strategy1.txt");
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

	Matrix_Outcome<double> m_out_nc_nc;			//Matricies to show outcomes
	Matrix_Outcome<double> m_out_c_c;
	Matrix_Outcome<double> m_out_c_nc;
	//int n[10] = { 0,0,0,0,0,0,0,0,0,0 };

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

	Gang* g[2];

	char c;
	int sch;
	cout << "Welcome to the Prisoner's Gang Dilemma" << endl;
	cout << "Would you like to implement a spy? y/n" << endl;
	cin >> c;
	if (c == 'y') {
		cout << "What percentage of the time would you like a spy to be present?" << endl;
		cin >> sch;
	}
	else
		sch = 0;


	srand(time(NULL));
	for (int i = 0; i < 10; ++i) {
		g[0] = new Gang(p[i], p[(i + 1) % 10], p[(i + 2) % 10], p[(i + 3) % 10], p[(i + 4) % 10]);

		for (int j = 0; j < 10; ++j) {

			g[1] = new Gang(p[j], p[(j + 1) % 10], p[(j + 2) % 10], p[(j + 3) % 10], p[(j + 4) % 10]);
			string l[6] = { "", "", "", "", "", "" };
			int it = 0;
			double m[6] = { 0, 0, 0, 0, 0, 0 };
			double s[6] = { 0, 0, 0, 0, 0, 0 };
			int w[6] = { 0, 0, 0, 0, 0, 0 };
			int x[6] = { 0, 0, 0, 0, 0, 0 };
			int y[6] = { 0, 0, 0, 0, 0, 0 };
			int z[6] = { 0, 0, 0, 0, 0, 0 };
			int a[6] = { 0, 0, 0, 0, 0, 0 };
			int b[6] = { 0, 0, 0, 0, 0, 0 };
			int c[6] = { 0, 0, 0, 0, 0, 0 };

			for (int k = 0; k < 200; ++k) {
				int lch1 = rand() % 12; //Probability of chosing spy by not changing choise (leader cannot choose himself). Calculated by hand
				int lch2 = rand() % 12;
				int lch3 = rand() % 4; //Probability of chosing spy by changing choise (leader cannot choose himself). Calculated by hand
				int lch4 = rand() % 4;
				int lch5 = rand() % 4;
				int lch6 = rand() % 12;
				
				if (s_chance(sch) == true) {
					p[i + 4]->is_a_spy(1);
					p[j + 4]->is_a_spy(1);

					if ((g[0]->n_of_BTY_ws() == g[1]->n_of_BTY_ws()) && (g[0]->n_of_BTY_ws() == 5)) {
						l[0] = l[1] = l[2] = l[3] = l[4] = l[5] =  "Z";
						s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = 4;
						z[0] = z[0] + 1;
						z[1] = z[1] + 1;
						z[2] = z[2] + 1;
						z[3] = z[3] + 1;
						z[4] = z[4] + 1;
						z[5] = z[5] + 1;
					}
					if ((g[0]->n_of_BTY_ws() == g[1]->n_of_BTY_ws()) && (g[0]->n_of_BTY_ws() == 0)) {
						l[0] = l[1] = l[2] = l[3] = l[4] = l[5] = "W";
						s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = 2;
						w[0] = w[0] + 1;
						w[1] = w[1] + 1;
						w[2] = w[2] + 1;
						w[3] = w[3] + 1;
						w[4] = w[4] + 1;
						w[5] = w[5] + 1;
					}
					if ((g[0]->n_of_BTY_ws() == 0) && (g[1]->n_of_BTY_ws() == 5)) {
						l[0] = l[2] = l[4] = "X";
						l[1] = l[3] = l[5] = "Y";
						s[0] = s[2] = s[4] = 5;
						s[1] = s[3] = s[5] = 0;
						x[0] = x[0] + 1;
						x[2] = x[2] + 1;
						x[4] = x[4] + 1;
						y[1] = y[1] + 1;
						y[3] = y[3] + 1;
						y[5] = y[5] + 1;
					}
					if ((g[0]->n_of_BTY_ws() == 5) && (g[1]->n_of_BTY_ws() == 0)) {
						l[0] = l[2] = l[4] = "Y";
						l[1] = l[3] = l[5] = "X";
						s[0] = s[2] = s[4] = 0;
						s[1] = s[3] = s[5] = 5;
						y[0] = y[0] + 1;
						y[2] = y[2] + 1;
						y[4] = y[4] + 1;
						x[1] = x[1] + 1;
						x[3] = x[3] + 1;
						x[5] = x[5] + 1;
					}
					if (!((g[0]->n_of_BTY_ws() == 5) && (g[1]->n_of_SIL_ws() == 0)) && (g[0]->n_of_BTY_ws() > g[1]->n_of_BTY_ws())) {
						l[0] = l[2] = l[4] = "A";
						l[1] = l[3] = l[5] = "B";
						s[0] = s[2] = s[4] = 2.5;
						s[1] = s[3] = s[5] = 3;
						a[0] = a[0] + 1;
						a[2] = a[2] + 1;
						a[4] = a[4] + 1;
						b[1] = b[1] + 1;
						b[3] = b[3] + 1;
						b[5] = b[5] + 1;
					}
					if (!((g[0]->n_of_BTY_ws() == 5) && (g[1]->n_of_SIL_ws() == 0)) && (g[0]->n_of_BTY_ws() < g[1]->n_of_BTY_ws())) {
						l[0] = l[2] = l[4] = "B";
						l[1] = l[3] = l[5] = "A";
						s[0] = s[2] = s[4] = 3;
						s[1] = s[3] = s[5] = 2.5;
						b[0] = b[0] + 1;
						b[2] = b[2] + 1;
						b[4] = b[4] + 1;
						a[1] = a[1] + 1;
						a[3] = a[3] + 1;
						a[5] = a[5] + 1;
					}
					if (!((g[0]->n_of_BTY_ws() == 5) && (g[1]->n_of_SIL_ws() == 0)) && (g[1]->n_of_BTY_ws() == g[1]->n_of_BTY_ws())) {
						l[0] = l[1] = l[2] = l[3] = l[4] = l[5] = "C";
						s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = 2;
						c[0] = c[0] + 1;
						c[1] = c[1] + 1;
						c[2] = c[2] + 1;
						c[3] = c[3] + 1;
						c[4] = c[4] + 1;
						c[5] = c[5] + 1;
					}
					if ((g[0]->p1_leader_choice(lch1, 0) == true) && (g[1]->p1_leader_choice(lch2, 0) == false)) {
						s[0] = 0;
						s[1] = 5;
					}
					if ((g[0]->p1_leader_choice(lch1, 0) == false) && (g[1]->p1_leader_choice(lch2, 0) == true)) {
						s[0] = 5;
						s[1] = 0;
					}
					if ((g[0]->p1_leader_choice(lch1, 0) == true) && (g[1]->p1_leader_choice(lch2, 0) == true)) {
						s[0] = s[1] = 6;
					}
					if ((g[0]->p1_leader_choice(lch3, 0) == true) && (g[1]->p1_leader_choice(lch4, 0) == false)) {
						s[3] = 2;
						s[4] = 5;
					}
					if ((g[0]->p1_leader_choice(lch3, 0) == false) && (g[1]->p1_leader_choice(lch4, 0) == true)) {
						s[3] = 5;
						s[4] = 2;
					}
					if ((g[0]->p1_leader_choice(lch3, 0) == true) && (g[1]->p1_leader_choice(lch4, 0) == true)) {
						s[0] = s[1] = 6;
					}

					if ((g[0]->p1_leader_choice(lch5, 0) == true) && (g[1]->p1_leader_choice(lch6, 0) == false)) {
						s[0] = 2;
						s[1] = 5;
					}
					if ((g[0]->p1_leader_choice(lch5, 0) == false) && (g[1]->p1_leader_choice(lch6, 0) == true)) {
						s[0] = 5;
						s[1] = 0;
					}
					if ((g[0]->p1_leader_choice(lch2, 0) == true) && (g[1]->p1_leader_choice(lch2, 0) == true)) {
						s[0] = s[1] = 6;
					}
				}
				else {
					if ((g[0]->n_of_BTY() == g[1]->n_of_BTY()) && (g[0]->n_of_BTY() == 5)) {
						l[0] = l[1] = l[2] = l[3] = l[4] = l[5] = "Z";
						s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = 4;
						z[0] = z[0] + 1;
						z[1] = z[1] + 1;
						z[2] = z[2] + 1;
						z[3] = z[3] + 1;
						z[4] = z[4] + 1;
						z[5] = z[5] + 1;
					}
					if ((g[0]->n_of_BTY() == g[1]->n_of_BTY()) && (g[0]->n_of_BTY() == 0)) {
						l[0] = l[1] = l[2] = l[3] = l[4] = l[5] = "W";
						s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = 2;
						w[0] = w[0] + 1;
						w[1] = w[1] + 1;
						w[2] = w[2] + 1;
						w[3] = w[3] + 1;
						w[4] = w[4] + 1;
						w[5] = w[5] + 1;
					}
					if ((g[0]->n_of_BTY() == 0) && (g[1]->n_of_BTY() == 5)) {
						l[0] = l[2] = l[4] = "X";
						l[1] = l[3] = l[5] = "Y";
						s[0] = s[2] = s[4] = 5;
						s[1] = s[3] = s[5] = 0;
						x[0] = x[0] + 1;
						x[2] = x[2] + 1;
						x[4] = x[4] + 1;
						y[1] = y[1] + 1;
						y[3] = y[3] + 1;
						y[5] = y[5] + 1;
					}
					if ((g[0]->n_of_BTY() == 5) && (g[1]->n_of_BTY() == 0)) {
						l[0] = l[2] = l[4] = "Y";
						l[1] = l[3] = l[5] = "X";
						s[0] = s[2] = s[4] = 0;
						s[1] = s[3] = s[5] = 5;
						y[0] = y[0] + 1;
						y[2] = y[2] + 1;
						y[4] = y[4] + 1;
						x[1] = x[1] + 1;
						x[3] = x[3] + 1;
						x[5] = x[5] + 1;
					}
					if (!((g[0]->n_of_BTY() == 5) && (g[1]->n_of_SIL() == 0)) && (g[0]->n_of_BTY() > g[1]->n_of_BTY())) {
						l[0] = l[2] = l[4] = "A";
						l[1] = l[3] = l[5] = "B";
						s[0] = s[2] = s[4] = 2.5;
						s[1] = s[3] = s[5] = 3;
						a[0] = a[0] + 1;
						a[2] = a[2] + 1;
						a[4] = a[4] + 1;
						b[1] = b[1] + 1;
						b[3] = b[3] + 1;
						b[5] = b[5] + 1;
					}
					if (!((g[0]->n_of_BTY() == 5) && (g[1]->n_of_SIL() == 0)) && (g[0]->n_of_BTY() < g[1]->n_of_BTY())) {
						l[0] = l[2] = l[4] = "B";
						l[1] = l[3] = l[5] = "A";
						s[0] = s[2] = s[4] = 3;
						s[1] = s[3] = s[5] = 2.5;
						b[0] = b[0] + 1;
						b[2] = b[2] + 1;
						b[4] = b[4] + 1;
						a[1] = a[1] + 1;
						a[3] = a[3] + 1;
						a[5] = a[5] + 1;
					}
					if (!((g[0]->n_of_BTY() == 5) && (g[1]->n_of_SIL() == 0)) && (g[1]->n_of_BTY() == g[1]->n_of_BTY())) {
						l[0] = l[1] = l[2] = l[3] = l[4] = l[5] = "C";
						s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = 2;
						c[0] = c[0] + 1;
						c[1] = c[1] + 1;
						c[2] = c[2] + 1;
						c[3] = c[3] + 1;
						c[4] = c[4] + 1;
						c[5] = c[5] + 1;
					}
				}

				it = k + 1;
				m[0] = m[0] + s[0];
				m[1] = m[1] + s[1];
				m[2] = m[2] + s[2];
				m[3] = m[3] + s[3];
				m[4] = m[4] + s[4];
				m[5] = m[5] + s[5];
			}
			m_out_nc_nc.set_element(i, j, m[0]);
			m_out_c_c.set_element(i, j, m[2]);
			m_out_c_nc.set_element(i, j, m[4]);
			delete g[1];
			g[1] = NULL;
		}
		delete g[0];
		g[0] = NULL;
	}


	cout << endl << "Table of results of tournament when neither leader changes choice of spy" << endl << endl;

	cout << m_out_nc_nc << endl;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (m_out_nc_nc.get_element(i, j) < m_out_nc_nc.get_element(j, i))
				cout << "Strategy combination " << i << " beat strategy combination " << j << endl;
			else if (m_out_nc_nc.get_element(i, j) > m_out_nc_nc.get_element(j, i))
				cout << "Strategy combination " << i << " lost to strategy combination " << j << endl;
			else if (m_out_nc_nc.get_element(i, j) == m_out_nc_nc.get_element(j, i))
				cout << "Strategy combination " << i << " drew with strategy combination " << j << endl;
		}
	}

	int n1[10];
	double Tot1 = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (m_out_nc_nc.get_element(i, j) < m_out_nc_nc.get_element(j, i))
				n1[i] = n1[i] + 1;
			Tot1 = Tot1 + m_out_nc_nc.get_element(i, j);
		}
	}
	cout << endl;
	for (int i = 0; i < 10; ++i) {
		cout << "Strategy where prisoner 1 chose strategy " << i <<
			"Strategy where prisoner 2 chose strategy " << (i + 1) % 10 <<
			"Strategy where prisoner 3 chose strategy " << (i + 2) % 10 <<
			"Strategy where prisoner 4 chose strategy " << (i + 3) % 10 <<
			"Strategy where prisoner 5 chose strategy " << (i + 4) % 10 <<
			" beat " << n1[i] << " strategy combinations" << endl;
	}
	cout << endl;
	int *best1 = max_element(begin(n1), end(n1));
	int k1 = 0;
	while (n1[k1] != *best1)
		k1++;

	cout << "Strategy " << k1 << " is the best strategy" << endl;



	cout << endl << "Table of results of tournament when both leaders change choice of spy" << endl << endl;

	cout << m_out_c_c << endl;


	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (m_out_c_c.get_element(i, j) < m_out_c_nc.get_element(j, i))
				cout << "Strategy combination " << i << " beat strategy combination " << j << endl;
			else if (m_out_c_c.get_element(i, j) > m_out_c_c.get_element(j, i))
				cout << "Strategy combination " << i << " lost to strategy combination " << j << endl;
			else if (m_out_c_c.get_element(i, j) == m_out_c_c.get_element(j, i))
				cout << "Strategy combination " << i << " drew with strategy combination " << j << endl;
		}
	}

	int n2[10];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (m_out_c_c.get_element(i, j) < m_out_c_c.get_element(j, i))
				n2[i] = n2[i] + 1;
		}
	}
	cout << endl;
	for (int i = 0; i < 10; ++i) {
		cout << "Strategy where prisoner 1 chose strategy " << i <<
			"Strategy where prisoner 2 chose strategy " << (i + 1) % 10 <<
			"Strategy where prisoner 3 chose strategy " << (i + 2) % 10 <<
			"Strategy where prisoner 4 chose strategy " << (i + 3) % 10 <<
			"Strategy where prisoner 5 chose strategy " << (i + 4) % 10 <<
			" beat " << n2[i] << " strategy combinations" << endl;
	}
	cout << endl;
	int *best2 = max_element(begin(n2), end(n2));
	int k2 = 0;
	while (n2[k2] != *best2)
		k2++;

	cout << "Strategy " << k2 << " is the best strategy" << endl;



	cout << endl << "Table of results of tournament when leader 1 changes choice of spy but leader 2 does not" << endl << endl;

	cout << m_out_c_nc << endl;
	
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (m_out_c_nc.get_element(i, j) < m_out_c_nc.get_element(j, i))
				cout << "Strategy combination " << i << " beat strategy combination " << j << endl;
			else if (m_out_c_nc.get_element(i, j) > m_out_c_nc.get_element(j, i))
				cout << "Strategy combination " << i << " lost to strategy combination " << j << endl;
			else if (m_out_c_nc.get_element(i, j) == m_out_c_nc.get_element(j, i))
				cout << "Strategy combination " << i << " drew with strategy combination " << j << endl;
		}
	}

	int n3[10];
	double Tot2 = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (m_out_c_nc.get_element(i, j) < m_out_c_nc.get_element(j, i))
				n3[i] = n3[i] + 1;
			Tot2 = Tot2 + m_out_c_nc.get_element(i, j);
		}
	}
	cout << endl;
	for (int i = 0; i < 10; ++i) {
		cout << "Strategy where prisoner 1 chose strategy " << i <<
			"Strategy where prisoner 2 chose strategy " << (i + 1) % 10 <<
			"Strategy where prisoner 3 chose strategy " << (i + 2) % 10 <<
			"Strategy where prisoner 4 chose strategy " << (i + 3) % 10 <<
			"Strategy where prisoner 5 chose strategy " << (i + 4) % 10 <<
			" beat " << n1[i] << " strategy combinations" << endl;
	}
	cout << endl;
	int *best3 = max_element(begin(n3), end(n3));
	int k3 = 0;
	while (n3[k3] != *best3)
		k3++;

	cout << "Strategy " << k3 << " is the best strategy" << endl << endl << endl;

	cout << "Average score (against leader who doesn't change choice) when leader doesn't change choice is " << Tot1 / 100 << endl;
	cout << "Average score (against leader who doesn't change choice) when leader changes choice is " << Tot2 / 100 << endl;
	if ((Tot1 / 100) < (Tot2 / 100))
		cout << "Thus optimal solution is when leader doesn't change choice" << endl;
	else if ((Tot1 / 100) > (Tot2 / 100))
		cout << "Thus optimal solution is when leader changes choice" << endl;

	ofstream outputFile;
	outputFile.open("Spy20%.txt");

	outputFile << endl << "Table of results of tournament when neither leader changes choice of spy" << endl << endl;

	outputFile << m_out_nc_nc << endl;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (m_out_nc_nc.get_element(i, j) < m_out_nc_nc.get_element(j, i))
				outputFile << "Strategy combination " << i << " beat strategy combination " << j << endl;
			else if (m_out_nc_nc.get_element(i, j) > m_out_nc_nc.get_element(j, i))
				outputFile << "Strategy combination " << i << " lost to strategy combination " << j << endl;
			else if (m_out_nc_nc.get_element(i, j) == m_out_nc_nc.get_element(j, i))
				outputFile << "Strategy combination " << i << " drew with strategy combination " << j << endl;
		}
	}

	outputFile << endl;
	for (int i = 0; i < 10; ++i) {
		outputFile << "Strategy where prisoner 1 chose strategy " << i <<
			"Strategy where prisoner 2 chose strategy " << (i + 1) % 10 <<
			"Strategy where prisoner 3 chose strategy " << (i + 2) % 10 <<
			"Strategy where prisoner 4 chose strategy " << (i + 3) % 10 <<
			"Strategy where prisoner 5 chose strategy " << (i + 4) % 10 <<
			" beat " << n1[i] << " strategy combinations" << endl;
	}
	outputFile << endl;

	outputFile << "Strategy " << k1 << " is the best strategy" << endl;



	outputFile << endl << "Table of results of tournament when both leaders change choice of spy" << endl << endl;

	outputFile << m_out_c_c << endl;


	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (m_out_c_c.get_element(i, j) < m_out_c_nc.get_element(j, i))
				outputFile << "Strategy combination " << i << " beat strategy combination " << j << endl;
			else if (m_out_c_c.get_element(i, j) > m_out_c_c.get_element(j, i))
				outputFile << "Strategy combination " << i << " lost to strategy combination " << j << endl;
			else if (m_out_c_c.get_element(i, j) == m_out_c_c.get_element(j, i))
				outputFile << "Strategy combination " << i << " drew with strategy combination " << j << endl;
		}
	}

	outputFile << endl;
	for (int i = 0; i < 10; ++i) {
		outputFile << "Strategy where prisoner 1 chose strategy " << i <<
			"Strategy where prisoner 2 chose strategy " << (i + 1) % 10 <<
			"Strategy where prisoner 3 chose strategy " << (i + 2) % 10 <<
			"Strategy where prisoner 4 chose strategy " << (i + 3) % 10 <<
			"Strategy where prisoner 5 chose strategy " << (i + 4) % 10 <<
			" beat " << n2[i] << " strategy combinations" << endl;
	}
	outputFile << endl;

	outputFile << "Strategy " << k2 << " is the best strategy" << endl;



	outputFile << endl << "Table of results of tournament when leader 1 changes choice of spy but leader 2 does not" << endl << endl;

	outputFile << m_out_c_nc << endl;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (m_out_c_nc.get_element(i, j) < m_out_c_nc.get_element(j, i))
				outputFile << "Strategy combination " << i << " beat strategy combination " << j << endl;
			else if (m_out_c_nc.get_element(i, j) > m_out_c_nc.get_element(j, i))
				outputFile << "Strategy combination " << i << " lost to strategy combination " << j << endl;
			else if (m_out_c_nc.get_element(i, j) == m_out_c_nc.get_element(j, i))
				outputFile << "Strategy combination " << i << " drew with strategy combination " << j << endl;
		}
	}

	outputFile << endl;
	for (int i = 0; i < 10; ++i) {
		outputFile << "Strategy where prisoner 1 chose strategy " << i <<
			"Strategy where prisoner 2 chose strategy " << (i + 1) % 10 <<
			"Strategy where prisoner 3 chose strategy " << (i + 2) % 10 <<
			"Strategy where prisoner 4 chose strategy " << (i + 3) % 10 <<
			"Strategy where prisoner 5 chose strategy " << (i + 4) % 10 <<
			" beat " << n1[i] << " strategy combinations" << endl;
	}
	outputFile << endl;

	outputFile << "Strategy " << k3 << " is the best strategy" << endl << endl << endl;

	outputFile << "Average score (against leader who doesn't change choice) when leader doesn't change choice is " << Tot1 / 100 << endl;
	outputFile << "Average score (against leader who doesn't change choice) when leader changes choice is " << Tot2 / 100 << endl;
	if ((Tot1 / 100) < (Tot2 / 100))
		outputFile << "Thus optimal solution is when leader doesn't change choice" << endl;
	else if ((Tot1 / 100) > (Tot2 / 100))
		outputFile << "Thus optimal solution is when leader changes choice" << endl;

	outputFile.close();

	for (int i = 0; i < 10; ++i) {
		delete p[i];
		p[i] = NULL;
		delete intr[i];
		intr[i] = NULL;
	}
	for (int i = 0; i < 2; ++i) {
		delete g[i];
		g[i] = NULL;
	}
}
