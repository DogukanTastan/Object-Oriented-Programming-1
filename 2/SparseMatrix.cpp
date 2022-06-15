#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "SparseVector.h"  //Since I used SparseVector in SparseMatrix, I had to include SparseVector.h as well.
#include "SparseMatrix.h"
using namespace std;


void findmaxindex(string str, int& a_max, int& d_max) { // this function allows us to find the max values that we will use to set 0

	int a, d = 0, flag = 0;
	double b;
	char c;

	istringstream iss(str);  // It uses the sstream library to easily separate the incoming string

	while (!iss.fail()) {				// Read operations continue until the end of the string.
		if (flag == 0) {
			iss >> d >> a >> c >> b;
			if (d > d_max)	//I used flag because it only needs to enter here 1 time
				d_max = d;
			a_max = a;
			flag = 1;
		}
		else {
			iss >> a >> c >> b;
			if (a > a_max)
				a_max = a;
		}					// the function does not return anything because it just takes the reference of the variables
	}
}

SparseMatrix::SparseMatrix(string fileName) {  // The consturctor of the SparseMatrix class works similarly to the sparseVector.
	ifstream file;
	file.open(fileName);
	int a, a_max = 0, d, d_max = 0, flag = 0;
	double b;
	char c;
	string str;
	SparseVector::elements object;
	SparseVector sps;

	while (file.peek() != EOF) {		//each row is taken and sent to the findmaxindex function
		getline(file, str);
		findmaxindex(str, a_max, d_max);
	}

	for (int i = 0; i <= d_max; i++) {
		for (int j = 0; j <= a_max; j++) {

			object.index = j;
			object.data = 0;			// then 0 is added to make the rows and columns equal size
			sps.v1.push_back(object);
		}
		row_index.push_back(i);
		v2.push_back(sps);
	}

	file.close();				// closing and reopening the file to return to the beginning of the file
	file.open(fileName);

	while (file.peek() != EOF) {
		getline(file, str);
		flag = 0;
		istringstream iss(str);

		while (!iss.fail()) {
			if (flag == 0) {
				iss >> d >> a >> c >> b;	// I used flag to enter here 1 time
				flag = 1;
			}
			else {
				iss >> a >> c >> b;
			}

			v2[d].v1[a].data = b;	// read values are added
		}
	}
}

SparseMatrix::SparseMatrix() {  // empty consructor

}

ostream& operator<<(ostream& os, const SparseMatrix& obj) {   // printing

	int flag = 0;

	for (int i = 0; i < obj.v2.size(); i++) {
		flag = 0;
		for (int j = 0; j < obj.v2[i].v1.size(); j++) {
			if (flag == 0) {
				if (obj.v2[i].v1[j].data != 0) {
					os<<obj.row_index[i]<<"        ";
					os << obj.v2[i] << endl;
					flag = 1;
				}
			}
		}
	}
	return os;
}

SparseMatrix operator +(const SparseMatrix& object1, const SparseMatrix& object2) {  // + overolading

	SparseMatrix sps;

	if (object1.v2.size() >= object2.v2.size()) {

		for (int i = 0; i < object2.v2.size(); i++) {
			sps.row_index.push_back(i);
			sps.v2.push_back(object1.v2[i] + object2.v2[i]);		// Since we have already prepared the + operator in SparseVector, we can use it here
		}
		for (int j = object2.v2.size(); j < object1.v2.size(); j++) {
			sps.row_index.push_back(j);
			sps.v2.push_back(object1.v2[j]);
		}
	}
	else {
		for (int i = 0; i < object1.v2.size(); i++) {				// Options are also available for other situations.
			sps.row_index.push_back(i);
			sps.v2.push_back(object2.v2[i] + object1.v2[i]);
		}
		for (int j = object1.v2.size(); j < object2.v2.size(); j++) {
			sps.row_index.push_back(j);
			sps.v2.push_back(object2.v2[j]);
		}
	}
	return sps;
}

SparseMatrix operator -(const SparseMatrix& object1, const SparseMatrix& object2) {  // Here too, similar operations to + 

	SparseMatrix sps;

	if (object1.v2.size() >= object2.v2.size()) {

		for (int i = 0; i < object2.v2.size(); i++) {
			sps.row_index.push_back(i);
			sps.v2.push_back(object1.v2[i] - object2.v2[i]);
		}
		for (int j = object2.v2.size(); j < object1.v2.size(); j++) {
			sps.row_index.push_back(j);
			sps.v2.push_back(object1.v2[j]);
		}
	}
	else {
		for (int i = 0; i < object1.v2.size(); i++) {
			sps.row_index.push_back(i);
			sps.v2.push_back(object2.v2[i] - object1.v2[i]);
		}
		for (int j = object1.v2.size(); j < object2.v2.size(); j++) {
			sps.row_index.push_back(j);
			sps.v2.push_back(object2.v2[j]);
		}
	}
	return sps;
}


SparseMatrix operator -(const SparseMatrix& object1) {

	SparseMatrix sps;

	for (int i = 0; i < object1.v2.size(); i++) {
		sps.row_index.push_back(i);
		sps.v2.push_back(-object1.v2[i]);   // We easily complete the negative conversion using the - operator for sparseVector
	}
	return sps;
}

SparseMatrix SparseMatrix::operator =(const SparseMatrix& object1) {

	v2.resize(object1.v2.size());

	for (int i = 0; i < object1.v2.size(); i++) {
		row_index.push_back(i);
		v2[i] = object1.v2[i];					// For synchronization processing, we can easily do it by using the operator = of sparseVector.
	}
	return *this;
}


SparseMatrix operator *(const SparseMatrix& object1, const SparseMatrix& object2) {
	SparseMatrix sps;
	sps.v2.resize(object1.v2.size());

	for (int i = 0; i < object1.v2.size(); i++) {
		sps.v2[i].v1.resize(object2.v2[0].v1.size());
	}

	for (int j = 0; j < object1.v2.size(); j++) {
		sps.row_index.push_back(j);
		for (int k = 0; k < object2.v2[0].v1.size(); k++) {
			for (int p = 0; p < object1.v2[0].v1.size(); p++) {
				sps.v2[j].v1[k].data += object1.v2[j].v1[p].data * object2.v2[p].v1[k].data;
			}
			
			sps.v2[j].v1[k].index = k;
		}
	}
	return sps;
}

SparseMatrix SparseMatrix::transpose() {

	SparseMatrix temp_SparseMatrix;
	temp_SparseMatrix.v2.resize(v2[0].v1.size());

	for (int k = 0; k < v2[0].v1.size(); k++) {					// First we do the space clearance
		temp_SparseMatrix.v2[k].v1.resize(v2.size());
	}

	for (int i = 0; i < v2.size(); i++) {
		for (int j = 0; j < v2[0].v1.size(); j++) {
			temp_SparseMatrix.v2[j].v1[i].index = v2[i].v1[j].index;		// we get the transpose by adding the data in reverse
			temp_SparseMatrix.v2[j].v1[i].data = v2[i].v1[j].data;
		}
		temp_SparseMatrix.row_index.push_back(i);
	}

	return temp_SparseMatrix;
}

