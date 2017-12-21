#include "Strategy_generator.h"
#include <string>
#include <fstream>

using namespace std;

Strategy_generator::Strategy_generator()
{
}


Strategy_generator::~Strategy_generator()
{
}

string Strategy_generator::choose_operand(int r)
{
	switch (r) {
	case 0: {
		return "ALLOUTCOMES_W";
		break;
	}
	case 1: {
		return "ALLOUTCOMES_X";
		break;
	}
	case 2: {
		return "ALLOUTCOMES_Y";
		break;
	}
	case 3: {
		return "ALLOUTCOMES_Z";
		break;
	}
	case 4: {
		return "ITERATIONS";
		break;
	}
	case 5: {
		return "MYSCORE";
		break;
	}
	}
}

char Strategy_generator::choose_operator(int r)
{
	switch (r) {
	case 0: {
		return '<';
		break;
	}
	case 1: {
		return '>';
		break;
	}
	case 2: {
		return '=';
		break;
	}
	}
}

string Strategy_generator::choose_outcome(int r) {
	switch (r) {
	case 0: {
		return "BETRAY";
		break;
	}
	case 1: {
		return "SILENCE";
		break;
	}
	case 2: {
		return "RANDOM";
	}
	}
}

void Strategy_generator::build_strategy() {
	string file_names[10];
	file_names[0] = "strategy1.txt";
	file_names[1] = "strategy2.txt";
	file_names[2] = "strategy3.txt";
	file_names[3] = "strategy4.txt";
	file_names[4] = "strategy5.txt";
	file_names[5] = "strategy6.txt";
	file_names[6] = "strategy7.txt";
	file_names[7] = "strategy8.txt";
	file_names[8] = "strategy9.txt";
	file_names[9] = "strategy10.txt";

	int margin[5] = { 10, 20, 30, 40, 50 };

	for (int i = 0; i < 7; ++i) {
		int r1 = rand() % 6;
		int r2 = rand() % 3;
		int r3 = rand() % 3;
		int r4 = rand() % 6;
		int r5 = rand() % 6;
		int r6 = rand() % 3;
		int r7 = rand() % 3;
		int r8 = rand() % 3;
		int r9 = rand() % 3;

		ofstream outputFile;
		outputFile.open(file_names[i]);
		outputFile << margin[0] << " IF " << choose_operand(r1) << " " << choose_operator(r2) << " " << choose_operand(r4) << " GOTO 30" << endl;
		outputFile << margin[1] << " " << choose_outcome(r3) << endl;
		outputFile << margin[2] << " IF " << choose_operand(r5) << " " << choose_operator(r6) << " " << choose_operand(r7) << " GOTO 50" << endl;
		outputFile << margin[3] << " " << choose_outcome(r8) << endl;
		outputFile << margin[4] << " " << choose_outcome(r9) << endl;
		outputFile.close();

	}
	ofstream outputFile;
	outputFile.open(file_names[7]);
	outputFile << margin[0] << " BETRAY" << endl;
	outputFile.close();


	outputFile.open(file_names[8]);
	outputFile << margin[0] << " SILENCE" << endl;
	outputFile.close();


	outputFile.open(file_names[9]);
	outputFile << margin[0] << " RANDOM" << endl;
	outputFile.close();
}