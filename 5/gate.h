#ifndef GATE_H
#define GATE_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class gate {				//The gate class is the base class. Other objects derive from here.
protected:
	 gate** full_objects=nullptr;  // double pointer structure holding the address of objects
	 int size=0;
	 gate* in1=nullptr;
	 gate* in2=nullptr;
	 string outName;
public:
	gate();
	gate(string name, vector<int> inputs); // The vector structure contains the input data from the main while the name circuit gets the filename
	void reader_function(string name, vector<int> inputs);  // function where information is processed and prepared
	virtual string getName() ;
	virtual void setName(string Name);
	virtual string get_in1_name() ;
	virtual string get_in2_name() ;		// necessary getter setter functions. The reason they are virtual is because each class contains these functions uniquely.
	virtual string get_output_name() ;
	virtual string getType();
	virtual int get_value();
	virtual void set_in1_name(string Name) ;
	virtual void set_in2_name(string Name) ;
	virtual void set_output_name(string Name) ;
	virtual void set_value(int val) ;
	virtual bool eval();
	virtual void in1_set(gate*);
	virtual void in2_set(gate*);
	virtual gate* in1_get();
	virtual gate* in2_get();
};
#endif // GATE_H