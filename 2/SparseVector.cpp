#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "SparseVector.h"
using namespace std;


SparseVector::SparseVector(string fileName) {  // constructor takes filename and starts processing
	ifstream file;
	file.open(fileName);
	int a, max_a = 0;
	double b;
	char c;
	elements object;

	while (file >> a >> c >> b) {  //first we go to the end of the file and find the max values

		if (a > max_a)
			max_a = a;
	}

	file.close();			// we close and open the file to go back to the beginning
	file.open(fileName);

	for (int i = 0; i <= max_a; i++) {  // We go up to the maximum value we found and put 0 in them.
		object.index = i;
		object.data = 0;
		v1.push_back(object);
	}

	while (file.peek() != EOF) {   // then we read the file again and add the existing values

		file >> a >> c >> b;

		v1[a].data = b;
	}
}

SparseVector::SparseVector() {   // empty constructor

}

SparseVector operator +(const SparseVector& object1, const SparseVector& object2) {  // + overloading

	SparseVector temp_SparseVector;
	SparseVector::elements temp_elements;

	if (object1.v1.size() >= object2.v1.size()) {	  //In order to add to the ones whose dimensions are not the same, we first go to the end of the short one and then add the elements of the longer one.
		for (int i = 0; i < object2.v1.size(); i++) {
			temp_elements.data = object1.v1[i].data + object2.v1[i].data;
			temp_elements.index = object1.v1[i].index;

			temp_SparseVector.v1.push_back(temp_elements);
		}
		for (int j = object2.v1.size(); j < object1.v1.size(); j++) {
			temp_elements.data = object1.v1[j].data;
			temp_elements.index = object1.v1[j].index;

			temp_SparseVector.v1.push_back(temp_elements);
		}
	}
	else {												//Similar actions are taken for other cases.
		for (int i = 0; i < object1.v1.size(); i++) {
			temp_elements.data = object1.v1[i].data + object2.v1[i].data;
			temp_elements.index = object1.v1[i].index;

			temp_SparseVector.v1.push_back(temp_elements);
		}
		for (int j = object1.v1.size(); j < object2.v1.size(); j++) {
			temp_elements.data = object2.v1[j].data;
			temp_elements.index = object2.v1[j].index;

			temp_SparseVector.v1.push_back(temp_elements);
		}
	}
	return temp_SparseVector;  // the generated vector is being returned
}

SparseVector operator -(const SparseVector& object1, const SparseVector& object2) {  // - overolading
	SparseVector temp_SparseVector;
	SparseVector::elements temp_elements;

	if (object1.v1.size() >= object2.v1.size()) {
		for (int i = 0; i < object2.v1.size(); i++) {
			temp_elements.data = object1.v1[i].data - object2.v1[i].data;	//Here, a similar operation is performed as in the + operator, the only difference being -
			temp_elements.index = object1.v1[i].index;

			temp_SparseVector.v1.push_back(temp_elements);
		}
		for (int j = object2.v1.size(); j < object1.v1.size(); j++) {
			temp_elements.data = object1.v1[j].data;
			temp_elements.index = object1.v1[j].index;

			temp_SparseVector.v1.push_back(temp_elements);
		}
	}
	else {
		for (int i = 0; i < object1.v1.size(); i++) {
			temp_elements.data = object1.v1[i].data - object2.v1[i].data;
			temp_elements.index = object1.v1[i].index;

			temp_SparseVector.v1.push_back(temp_elements);
		}
		for (int j = object1.v1.size(); j < object2.v1.size(); j++) {
			temp_elements.data = object2.v1[j].data;
			temp_elements.index = object2.v1[j].index;

			temp_SparseVector.v1.push_back(temp_elements);
		}
	}
	return temp_SparseVector;   // the generated vector is being returned
}

SparseVector operator -(const SparseVector& object1) {  // operator - overolading
	SparseVector temp_SparseVector;
	SparseVector::elements temp_elements;

	for (int i = 0; i < object1.v1.size(); i++) {
		temp_elements.index = object1.v1[i].index;		//here we add the data again by multiplying it by -1 so we got the negative
		temp_elements.data = object1.v1[i].data * (-1);

		temp_SparseVector.v1.push_back(temp_elements);
	}
	return temp_SparseVector;
}

SparseVector SparseVector::operator =(const SparseVector& object1) {
	elements temp_elements;

	for (int i = 0; i < object1.v1.size(); i++) {
		temp_elements.index = object1.v1[i].index; // We copy the elements of the other object one by one and return the current object
		temp_elements.data = object1.v1[i].data;

		v1.push_back(temp_elements);
	}
	return *this;
}

ostream& operator<<(ostream& os, const SparseVector& obj) {	// printing is in progress
	for (int i = 0; i < obj.v1.size(); i++) {
		if (obj.v1[i].data != 0)
			os << obj.v1[i].index << ":" << obj.v1[i].data << " ";
	}
	return os;
}

double dot(SparseVector object1, SparseVector object2) {  // function that calculates the multiplication value
	int min;
	double result = 0;

	if (object1.getv1() < object2.getv1())
		min = object1.getv1();
	else
		min = object2.getv1();

	for (int i = 0; i < min; i++) {
		result += object1.v1[i].data * object2.v1[i].data;
	}
	return result;
}

int SparseVector::getv1() {  // get function used to access size information of vector
	return v1.size();
}
