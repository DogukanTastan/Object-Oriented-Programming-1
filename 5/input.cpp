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

void input::setName(string Name) {
	name = Name;
}
string input::getName() {
	return name;
}
string input::get_in1_name() {			// // necessary getter setter functions. The reason they are virtual is because each class contains these functions uniquely.
	return in1_name;
}
string input::get_in2_name() {
	return in2_name;
}
string input::get_output_name() {
	return output_name;
}
int input::get_value() {
	return value;
}
void input::set_in1_name(string Name) {
	in1_name = Name;
}
void input::set_in2_name(string Name) {
	in2_name = Name;
}
void input::set_output_name(string Name) {
	output_name = Name;
}
void input::set_value(int val) {
	value = val;
}
string input::getType() {
	return type;
}
bool input::eval() {

	return value;
}
void input :: in1_set(gate* gat) {
	in1 = gat;
 }
void input :: in2_set(gate* gat) {
	in2 = gat;
 }
gate* input :: in1_get() {
	return in1;
 }
gate* input :: in2_get() {
	return in2;
 }