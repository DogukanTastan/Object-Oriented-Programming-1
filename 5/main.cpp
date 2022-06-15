#include "gate.h"
#include "input.h"
#include "output.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "flipflop.h"
#include "writerClass.h"
#include "decoder.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<int> inputs;   // Vector object created for easy storage of data read from input txt
	fstream f_inputs;
	string line = "";
	int value;
	f_inputs.open("input.txt", ios::in);

	while (!f_inputs.eof()) {
		while (getline(f_inputs, line)) {
			inputs.clear();
			stringstream s(line);
			while (!s.fail())
			{
				s >> value;
				inputs.push_back(value);
			}
			writerClass obj("circuit.txt", inputs);	// A new object is created for each input line.
			obj.eval();
			cout << endl;
		}
	}
	return 0;
}