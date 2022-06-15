#ifndef DECODER_H
#define DECODER_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "gate.h"
using namespace std;
class decoder : public gate {
private:
	string name;
	string in1_name;
	string in2_name;
	string output_name;
	string type="DECODER";
	int value;
	gate* in1 = nullptr;
	gate* in2 = nullptr;
public:
	virtual void setName(string Name);
	virtual string getName();
	virtual string get_in1_name();
	virtual string get_in2_name();
	virtual string get_output_name();
	virtual int get_value();
	virtual void set_in1_name(string Name);
	virtual void set_in2_name(string Name);
	virtual void set_output_name(string Name);
	virtual void set_value(int val);
	virtual bool eval();				// // necessary getter setter functions. The reason they are virtual is because each class contains these functions uniquely.
	virtual string getType();
	virtual void in1_set(gate*);
	virtual void in2_set(gate*);
	virtual gate* in1_get();
	virtual gate* in2_get();
};
#endif // DECODER_H