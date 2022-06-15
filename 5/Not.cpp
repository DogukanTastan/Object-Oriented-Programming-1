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

void Not::setName(string Name) {
	name = Name;
}
string Not::getName() {
	return name;
}
string Not::get_in1_name() {
	return in1_name;
}
string Not::get_in2_name() {
	return in2_name;
}
string Not::get_output_name() {
	return output_name;
}
int Not::get_value() {
	return value;
}
void Not::set_in1_name(string Name) {
	in1_name = Name;
}
void Not::set_in2_name(string Name) {
	in2_name = Name;
}
void Not::set_output_name(string Name) {
	output_name = Name;
}
void Not::set_value(int val) {
	value = val;
}
string Not::getType() {
	return type;
}
void Not::in1_set(gate* gat) {
	in1 = gat;
}
void Not::in2_set(gate* gat) {
	in2 = gat;
}
gate* Not::in1_get() {
	return in1;
}
gate* Not::in2_get() {
	return in2;
}
bool Not::eval() {  // recuirsive eval function

	bool a1 = in1->eval();
	if (a1)
		return 0;
	else
		return 1;
}