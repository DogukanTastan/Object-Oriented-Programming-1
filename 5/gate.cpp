#include "gate.h"
#include "input.h"
#include "output.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "flipflop.h"
#include "decoder.h"
#include "writerClass.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

gate::gate() {
}
gate::gate(string name, vector<int> inputs) {
	reader_function(name, inputs); // The constructor calls the function that will do the reading and storing.
}
void gate::setName(string Name) {	// // necessary getter setter functions. The reason they are virtual is because each class contains these functions uniquely.
}
string  gate::getName() {
	return "gate";
}
string  gate::get_in1_name() {
	return "gate";
}
string gate::get_in2_name() {
	return "gate";
}
string gate::get_output_name() {
	return "gate";
}
int gate::get_value() {
	return 1;
}
void gate::set_in1_name(string Name) {
}
void gate::set_in2_name(string Name) {
}
void gate::set_output_name(string Name) {
}
void gate::set_value(int val) {
}
string gate::getType() {
	return "gate";
}
bool gate::eval() {
	return 0;
}
void gate::in1_set(gate* gat) {
}
void gate::in2_set(gate* gat) {
}
gate* gate::in1_get() {
	return in1;
}
gate* gate::in2_get() {
	return in2;
}
void gate::reader_function(string name, vector<int> inputs) {
	fstream f;
	string line = "";
	string word = "";
	string keyword = "";
	vector<string> list;

	f.open(name, ios::in);  //circuit txt opened
	while (!f.eof()) {

		while (getline(f, line)) { // whole row is taken
			stringstream s(line); // then the received row gets fragmented

			list.clear();
			while (!s.fail())
			{
				s >> word;    // store words
				if (word == "INPUT" || word == "OUTPUT" || word == "AND" || word == "OR" || word == "NOT" || word == "FLIPFLOP" || word == "DECODER") {
					keyword = word;  // The first word of the line read is processed separately because it has a keyword feature.
				}
				else
					list.push_back(word); // these parts are stored with the help of vectors for convenience.
			}
			for (int i = 0; i < list.size() - 1; i++) { // Since each of the inputs and outputs is an object, they are all produced as objects.

				if (keyword == "INPUT") {

					input* obj = new input;  // A new object is created with the help of a pointer of type base class.
					obj->setName("INPUT");
					obj->set_value(inputs[i]);			// Necessary assignments are made.
					obj->set_output_name(list[i]);
					gate** temp = new gate * [size + 1];  // Address of objects is stored in dynamically growing array

					for (int i = 0; i < size; i++)
						temp[i] = full_objects[i];	// Dynamic growth processes

					temp[size] = obj;
					delete[] full_objects;
					full_objects = temp;

					size++;
				}
				else if (keyword == "OUTPUT") {

					output* obj = new output;
					obj->setName("OUTPUT");
					obj->set_in1_name(list[i]);
					outName = list[0];
					obj->set_output_name(list[i]);
					gate** temp = new gate * [size + 1];

					for (int i = 0; i < size; i++)
						temp[i] = full_objects[i];

					temp[size] = obj;
					delete[] full_objects;
					full_objects = temp;

					size++;
				}
			}
			if (keyword == "AND") {

				And* obj = new And;

				obj->setName("AND");				// The operations here are performed similarly to the above.
				obj->set_output_name(list[0]);
				obj->set_in1_name(list[1]);
				obj->set_in2_name(list[2]);

				gate** temp = new gate * [size + 1];

				for (int i = 0; i < size; i++)
					temp[i] = full_objects[i];

				temp[size] = obj;
				delete[] full_objects;
				full_objects = temp;

				size++;
			}
			else if (keyword == "OR") {

				Or* obj = new  Or;
				obj->setName("OR");
				obj->set_output_name(list[0]);
				obj->set_in1_name(list[1]);
				obj->set_in2_name(list[2]);
				gate** temp = new gate * [size + 1];

				for (int i = 0; i < size; i++)
					temp[i] = full_objects[i];

				temp[size] = obj;
				delete[] full_objects;
				full_objects = temp;

				size++;
			}
			else if (keyword == "NOT") {

				Not* obj = new Not;
				obj->setName("NOT");
				obj->set_output_name(list[0]);
				obj->set_in1_name(list[1]);
				gate** temp = new gate * [size + 1];

				for (int i = 0; i < size; i++)
					temp[i] = full_objects[i];

				temp[size] = obj;
				delete[] full_objects;
				full_objects = temp;

				size++;
			}
			else if (keyword == "FLIPFLOP") {

				flipflop* obj = new flipflop;
				obj->setName("FLIPFLOP");
				obj->set_output_name(list[0]);
				obj->set_in1_name(list[1]);
				gate** temp = new gate * [size + 1];

				for (int i = 0; i < size; i++)
					temp[i] = full_objects[i];

				temp[size] = obj;
				delete[] full_objects;
				full_objects = temp;

				size++;
			}
			else if (keyword == "DECODER") {
				decoder* obj = new decoder;
				obj->setName("DECODER");
				obj->set_output_name(list[0]);
				obj->set_in1_name(list[4]);
				obj->set_in2_name(list[5]);
				gate** temp = new gate * [size + 1];

				for (int i = 0; i < size; i++)
					temp[i] = full_objects[i];

				temp[size] = obj;
				delete[] full_objects;
				full_objects = temp;

				size++;
			}
		}
	}
	for (int i = 0; i < size; i++) {		// In this section, necessary binding operations are performed.
		for (int j = 0; j < size; j++) {
			if (full_objects[i]->getType() == "AND" || full_objects[i]->getType() == "OR" || full_objects[i]->getType() == "DECODER") {
				if (full_objects[i]->get_in1_name() == full_objects[j]->get_output_name()) {
					full_objects[i]->in1_set(full_objects[j]);
				}
				else if (full_objects[i]->get_in2_name() == full_objects[j]->get_output_name()) {
					full_objects[i]->in2_set(full_objects[j]);
				}
			}
			else if (full_objects[i]->getType() == "NOT" || full_objects[i]->getType() == "OUTPUT" || full_objects[i]->getType() == "FLIPFLOP") {
				if (full_objects[i]->get_in1_name() == full_objects[j]->get_output_name()) {
					full_objects[i]->in1_set(full_objects[j]);
				}
			}
		}
	}
}