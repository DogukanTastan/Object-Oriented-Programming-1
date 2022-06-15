#include "gate.h"
#include "input.h"
#include "output.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "flipflop.h"
#include "decoder.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

void flipflop::setName(string Name) {
	name = Name;
}
string flipflop::getName() {
	return name;
}
string flipflop::get_in1_name() {
	return in1_name;
}
string flipflop::get_in2_name() {
	return in2_name;
}
string flipflop::get_output_name() {
	return output_name;
}
int flipflop::get_value() {
	return value;
}
void flipflop::set_in1_name(string Name) {
	in1_name = Name;
}
void flipflop::set_in2_name(string Name) {
	in2_name = Name;
}
void flipflop::set_output_name(string Name) {
	output_name = Name;
}
void flipflop::set_value(int val) {
	value = val;
}
string flipflop::getType() {
	return type;
}
void flipflop::in1_set(gate* gat) {
	in1 = gat;
}
void flipflop::in2_set(gate* gat) {
	in2 = gat;
}
gate* flipflop::in1_get() {
	return in1;
}
gate* flipflop::in2_get() {
	return in2;
}
bool flipflop::eval() {		// recuirsive eval function

	if (former_out == 0 && in1->eval() == 0)
		return 0;
	else if (former_out == 1 && in1->eval() == 0)
		return 1;
	else if (former_out == 0 && in1->eval() == 1) {
		return 1;
		former_out == 1;
	}
	else if (former_out == 1 && in1->eval() == 1){
		return 0;
		former_out == 0;
	}
	return 0;
}