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

void And::setName(string Name) {
	name = Name;
}


string And::getName() {
	return name;
}

string And::get_in1_name() {
	return in1_name;
 }
string And::get_in2_name() {
	return in2_name;
 }
string And::get_output_name() {
	return output_name;
 }
int And::get_value() {
	return value;
 }
void And::set_in1_name(string Name) {
	in1_name = Name;
 }
void And::set_in2_name(string Name) {
	in2_name = Name;
 }
void And::set_output_name(string Name) {
	output_name = Name;
 }
void And::set_value(int val) {
	value = val;
 }
string And::getType() {
	return type;
}
void And::in1_set(gate* gat) {
	in1 = gat;
}
void And::in2_set(gate* gat) {
	in2 = gat;
}
gate* And::in1_get() {
	return in1;
}
gate* And::in2_get() {
	return in2;
}

bool And::eval() {

	bool a1 = in1->eval();
	bool a2 = in2->eval();
	return a1 && a2;
		
}