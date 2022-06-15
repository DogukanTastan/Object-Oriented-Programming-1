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

void decoder::setName(string Name) {
	name = Name;
}
string decoder::getName() {
	return name;
}
string decoder::get_in1_name() {
	return in1_name;
 }
string decoder::get_in2_name() {	// Getter setters must be defined in every subclass because they are defined as virtual
	return in2_name;
 }
string decoder::get_output_name() {
	return output_name;
 }
int decoder::get_value() {
	return value;
 }
void decoder::set_in1_name(string Name) {
	in1_name = Name;
 }
void decoder::set_in2_name(string Name) {
	in2_name = Name;
 }
void decoder::set_output_name(string Name) {
	output_name = Name;
 }
void decoder::set_value(int val) {
	value = val;
 }
string decoder::getType() {
	return type;
}
bool decoder::eval() {
	bool a1 = in1->eval();	//The recursive eval function calculates the required value
	bool a2 = in2->eval();
	
	if (a1 == 0 && a2 == 0) {	//The decoder prints the result according to the incoming input.
		cout << "1 0 0 ";
		return 0;
	}
		
	if (a1 == 0 && a2 == 1) {
		cout << "0 1 0 ";		// Since the return value will be written to the screen, the last digit is displayed as the return value.
		return 0;
	}
		
	if (a1 == 1 && a2 == 0) {
		cout << "0 0 1 ";
		return 0;
	}
		
	if (a1 == 1 && a2 == 1) {
		cout << "0 0 0 ";
		return 1;
	}
	return 0;
}
void decoder::in1_set(gate* gat) {
	in1 = gat;
}
void decoder::in2_set(gate* gat) {  // Getter setters must be defined in every subclass because they are defined as virtual
	in2 = gat;
}
gate* decoder::in1_get() {
	return in1;
}
gate* decoder::in2_get() {
	return in2;
}