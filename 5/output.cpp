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

void output::setName(string Name) {
	name = Name;
}
string output::getName() {
	return name;
}
string output::get_in1_name() {
	return in1_name;
}
string output::get_in2_name() {
	return in2_name;
}
string output::get_output_name() { 	// necessary getter setter functions. The reason they are virtual is because each class contains these functions uniquely.
	return output_name;
}
int output::get_value() {
	return value;
}
void output::set_in1_name(string Name) {
	in1_name = Name;
}
void output::set_in2_name(string Name) {
	in2_name = Name;
}
void output::set_output_name(string Name) {
	output_name = Name;
}
void output::set_value(int val) {
	value = val;
}
string output::getType() {
	return type;
}
void output::in1_set(gate* gat) {
	in1 = gat;
}
void output::in2_set(gate* gat) {
	in2 = gat;
}
gate* output::in1_get() {
	return in1;
}
gate* output::in2_get() {
	return in2;
}
bool output::eval() {   // recuirsive eval function
	
	bool a1 = in1->eval();
	return a1;
}