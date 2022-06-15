#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;


class SparseVector {

public:
	struct elements {   //I made it public for ease of use because there was no requirement specified..However, it would be better for some variables to be private due to oop rules.

		int index;
		double data;
	};

	vector<elements> v1;  //this vector contains struct objects
	int getv1();
	SparseVector(string fileName);
	SparseVector();
	friend SparseVector operator +(const SparseVector& object1, const SparseVector& object2);
	friend SparseVector operator -(const SparseVector& object1, const SparseVector& object2);
	friend SparseVector operator -(const SparseVector& object1);
	friend ostream& operator<<(ostream& os, const SparseVector& obj);
	SparseVector operator =(const SparseVector& object1);
};
