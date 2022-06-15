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

writerClass::writerClass() {

}
void writerClass::setName(string Name) {
	
}
string  writerClass::getName() {
	return "writer";
}
string  writerClass::get_in1_name() {
	return "writer";
}
string writerClass::get_in2_name() {
	return "writer";
}
string writerClass::get_output_name() {   // // necessary getter setter functions. The reason they are virtual is because each class contains these functions uniquely.
	return "writer";
}
int writerClass::get_value() {
	return 1;
}
void writerClass::set_in1_name(string Name) {
	
}
void writerClass::set_in2_name(string Name) {
	
}
void writerClass::set_output_name(string Name) {
	
}
void writerClass::set_value(int val) {
	
}
string writerClass::getType() {
	return "writer";
}
void writerClass::in1_set(gate* gat) {
	
}
void writerClass::in2_set(gate* gat) {
	
}
gate* writerClass::in1_get() {
	return in1;
}
gate* writerClass::in2_get() {
	return in2;
}
bool writerClass::eval(){
	for (int i = 0; i <size; i++) {
		if (full_objects[i]->get_in1_name() == outName && full_objects[i]->getType() == "OUTPUT") {
			cout << full_objects[i]->eval() <<"\n";
		}
	}
	return 0;
}