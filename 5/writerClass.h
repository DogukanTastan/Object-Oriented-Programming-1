#ifndef WRITERCLASS_H
#define WRITERCLASS_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "gate.h"
using namespace std;
class writerClass : public gate {
private:
	gate* in1=nullptr;	// This class is for printing only. These data are not used.
	gate* in2=nullptr;
public:
	writerClass(string name, vector<int> inputs) : gate(name,inputs)  { // The data received here is sent to the base class constructor.
		
	}
	writerClass();
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
	virtual bool eval();
	virtual string getType();
	virtual void in1_set(gate*);
	virtual void in2_set(gate*);
	virtual gate* in1_get();
	virtual gate* in2_get();
};
#endif // WRITERCLASS_H