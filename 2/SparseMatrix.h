#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;


class SparseMatrix {

public:	//I made it public for ease of use because there was no requirement specified..However, it would be better for some variables to be private due to oop rules.


	vector<SparseVector> v2;		// here we use the sparseVector class. so we will get convenience in transactions
	vector<int> row_index;		//We keep the row information in a different vector

	SparseMatrix(string fileName);
	SparseMatrix();
	friend SparseMatrix operator +(const SparseMatrix& object1, const SparseMatrix& object2);
	friend SparseMatrix operator -(const SparseMatrix& object1, const SparseMatrix& object2);
	friend SparseMatrix operator -(const SparseMatrix& object1);
	friend ostream& operator<<(ostream& os, const SparseMatrix& obj);
	friend SparseMatrix operator *(const SparseMatrix& object1, const SparseMatrix& object2);
	SparseMatrix operator =(const SparseMatrix& object1);
	SparseMatrix transpose();
};
