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

void Or::setName(string Name) {
	name = Name;
}
string Or::getName() {
	return name;
}
string Or::get_in1_name() {
	return in1_name;
}
string Or::get_in2_name() {
	return in2_name;
}
string Or::get_output_name() {
	return output_name;
}
int Or::get_value() {
	return value;
}
void Or::set_in1_name(string Name) {
	in1_name = Name;
}
void Or::set_in2_name(string Name) {
	in2_name = Name;
}
void Or::set_output_name(string Name) {
	output_name = Name;
}
void Or::set_value(int val) {
	value = val;
}
string Or::getType() {
	return type;
}
void Or::in1_set(gate* gat) {
	in1 = gat;
}
void Or::in2_set(gate* gat) {
	in2 = gat;
}
gate* Or::in1_get() {
	return in1;
}
gate* Or::in2_get() {
	return in2;
}
bool Or::eval() {
	
	bool a1 = in1->eval();
	bool a2 = in2->eval();
	return a1 || a2;
}