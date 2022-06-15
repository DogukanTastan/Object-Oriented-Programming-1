#include<iostream>
using namespace std;

class Course;

class Student {
private:
	string name;
	int id;
	int courseSize = 1;
public:
	Course* course_references;
	Student();
	Student(string name0, int id0);	// necessary definitions have been made.
	~Student();
	void set_name(string name0);
	void set_id(int id0);
	string get_name();
	int get_id();
};

Student::Student() {

}

Student::Student(string name0, int id0) {
	name = name0;
	id = id0;
}
Student::~Student() {

}
void Student::set_name(string name0) {		// getter setter functions
	name = name0;
}
void Student::set_id(int id0) {
	id = id0;
}
string Student::get_name() {
	return name;
}
int Student::get_id() {
	return id;
}

class Course {
private:
	string name;
	string code;
	int studentSize = 1;
public:
	Student* student_references;
	Course();
	Course(string code0, string name0);
	~Course();
	void set_name(string name0);
	void set_code(string code0);
	string get_name();
	string get_code();
	int getStudentSize();
	void add(Student obj);
	void drop(Student obj);
};

Course::Course() {

}
Course::Course(string code0, string name0) {
	name = name0;
	code = code0;
}
Course::~Course() {
	
}
void Course::add(Student obj) {

	Student* temp_references;
	temp_references = new Student[studentSize];

	for (int i = 0; i < studentSize - 1; i++) {
		temp_references[i] = student_references[i];		 //growing dynamic array made
	}
	temp_references[studentSize - 1] = obj;

	student_references = new Student[studentSize];


	for (int i = 0; i < studentSize; i++) {
		student_references[i] = temp_references[i];
	}

	delete[] temp_references;
}

void Course::drop(Student obj) {
	int removeIndex;
	for (int i = 0; i < studentSize; i++) {
		if (student_references[i].get_name() == obj.get_name() && student_references[i].get_id() == obj.get_id()) { // Comparing to find the index of the object to be removed
			removeIndex = i;
			break;
		}
	}

	Student* temp_references;
	temp_references = new Student[studentSize];

	for (int i = 0; i < removeIndex; i++) {
		temp_references[i] = student_references[i];
	}
	for (int i = removeIndex + 1; i < studentSize - 1; i++) {
		temp_references[i] = student_references[i];
	}

	student_references = new Student[studentSize - 1];

	for (int i = 0; i < studentSize - 1; i++) {
		student_references[i] = temp_references[i];
	}

	delete[] temp_references;

}


void Course::set_name(string name0) {
	name = name0;
}
void Course::set_code(string code0) {
	code = code0;
}
string Course::get_name() {
	return name;
}
string Course::get_code() {
	return code;
}
int Course::getStudentSize() {
	return studentSize;
}

class SchoolManagementSystem {
private:
	Student* student_references;
	int student_references_size = 1;
	Course* course_references;
	int Course_references_size = 1;
	Student selectStudent;
	Course selectCourse;
public:
	int main_function();
	SchoolManagementSystem();
	~SchoolManagementSystem();
	void addStudent_function(Student obj);
	void addCourse_function(Course obj);
	int compareStudentFunction(Student obj);
	int compareCourseFunction(Course obj);
	void deleteStudent(int i);
	void deleteCourse(int i);

};

SchoolManagementSystem::SchoolManagementSystem() {
	main_function();
}
SchoolManagementSystem::~SchoolManagementSystem() {
	delete[] student_references;
	delete[] course_references;
}

void SchoolManagementSystem::addStudent_function(Student obj) {

	Student* temp_references;
	temp_references = new Student[student_references_size];

	for (int i = 0; i < student_references_size - 1; i++) {
		temp_references[i] = student_references[i];			// Adding dynamically 
	}
	temp_references[student_references_size - 1] = obj;

	student_references = new Student[student_references_size];


	for (int i = 0; i < student_references_size; i++) {
		student_references[i] = temp_references[i];
	}

	delete[] temp_references;
	student_references_size++;
}
void SchoolManagementSystem::addCourse_function(Course obj) {

	Course* temp_references;
	temp_references = new Course[Course_references_size];

	for (int i = 0; i < Course_references_size - 1; i++) {
		temp_references[i] = course_references[i];
	}
	temp_references[student_references_size - 1] = obj;

	course_references = new Course[Course_references_size];


	for (int i = 0; i < Course_references_size; i++) {
		course_references[i] = temp_references[i];
	}

	delete[] temp_references;
	Course_references_size++;
}

void SchoolManagementSystem::deleteStudent(int x) {
	Student* temp_references;
	temp_references = new Student[student_references_size - 1];

	for (int i = 0; i < x; i++) {
		temp_references[i] = student_references[i];
	}
	for (int i = x + 1; i < student_references_size - 1; i++) {
		temp_references[i] = student_references[i];
	}

	student_references = new Student[student_references_size - 1];  // We are reducing the size because the array is losing elements

	for (int i = 0; i < student_references_size - 1; i++) {
		student_references[i] = temp_references[i];
	}

	delete[] temp_references;  // we are deleting the dynamic array element that we are done
	student_references_size--;
}

void SchoolManagementSystem::deleteCourse(int x) {
	Course* temp_references;
	temp_references = new Course[student_references_size - 1];

	for (int i = 0; i < x; i++) {
		temp_references[i] = course_references[i];
	}
	for (int i = x + 1; i < Course_references_size - 1; i++) {
		temp_references[i] = course_references[i];
	}

	student_references = new Student[Course_references_size - 1];

	for (int i = 0; i < Course_references_size - 1; i++) {
		course_references[i] = temp_references[i];
	}

	delete[] temp_references;
	Course_references_size--;
}



int SchoolManagementSystem::compareStudentFunction(Student obj) {

	for (int i = 0; i < student_references_size; i++) {
		if ((student_references[i].get_name() == obj.get_name()) && (student_references[i].get_id() == obj.get_id())) {
			return i;  // returns the found index
		}
	}
	return -1;
}

int SchoolManagementSystem::compareCourseFunction(Course obj) {

	for (int i = 0; i < Course_references_size; i++) {
		if ((course_references[i].get_name() == obj.get_name()) && (course_references[i].get_code() == obj.get_code())) {
			return i;  // returns the found index
		}
	}
	return -1;
}


int SchoolManagementSystem::main_function() {
	int input = -1, int_input_2 = -1, int_input_3, flag = 0;
	string string_input1, string_input2, string_input3, string_input4, string_input5;
	while (true) {
		cout << "Main_menu\n0 exit\n1 student\n2 course\n3 list_all_students\n4 list_all_courses\n>> ";
		cin >> input;
		if (input == 0) {
			break;
		}
		if (input == 1) {
			while (true) {
				cout << "0 up\n1 add_student\n2 select_student";
				cin >> int_input_2;
				if (int_input_2 == 0 || flag == -1) {  // I used flag to exit the loop outside
					break;
				}
				if (int_input_2 == 1) {
					cin >> string_input1 >> string_input2 >> int_input_2;
					string_input3 = string_input1 + " " + string_input2;

					Student obj(string_input3, int_input_2);
					addStudent_function(obj);
					continue;
				}
				if (int_input_2 == 2) {
					cin >> string_input1 >> string_input2 >> int_input_2;
					string_input3 = string_input1 + " " + string_input2;
					Student obj(string_input3, int_input_2);
					if (compareStudentFunction(obj) != -1) {  // If the function does not return anything out of range, we understand that there is no problem.
						selectStudent = obj;
					}

					while (true) {
						cout << "0 up\n1 delete_student\n3 add_selected_student_to_a_course\n4 drop_selected_student_from_a_course\n";
						cin >> int_input_2;
						if (int_input_2 == 0)
							break;
						if (int_input_2 == 1) {
							deleteStudent(compareStudentFunction(obj));
							flag = -1;
							break;
						}
						if (int_input_2 == 3) {
							cout << "0 up\n";
							for (int i = 0; i < Course_references_size; i++) {
								cout << i << course_references[i].get_code() << " " << course_references[i].get_name() + "\n";
							}
							cin >> int_input_3;
							course_references[int_input_3].add(selectStudent);

						}
						if (int_input_2 == 4) {
							cout << "0 up\n";
							for (int i = 0; i < Course_references_size; i++) {
								cout << i << course_references[i].get_code() << " " << course_references[i].get_name() + "\n";
							}
							cin >> int_input_3;
							course_references[int_input_3].drop(selectStudent);
						}
					}
				}
			}
		}
		if (input == 2) {
			while (true) {
				cout << "0 up\n1 add_course\n2 select_course";
				cin >> int_input_2;
				if (int_input_2 == 0 || flag == -1)
					break;
				if (int_input_2 == 1) {
					cin >> string_input1 >> string_input2 >> string_input3 >> string_input4;
					string_input5 = string_input2 + string_input3 + string_input4;  //string operations
					Course obj(string_input1, string_input5);
					addCourse_function(obj);
					continue;
				}
				if (int_input_2 == 2) {
					cin >> string_input1 >> string_input2 >> string_input3 >> string_input4;
					string_input5 = string_input2 + string_input3 + string_input4;
					Course obj(string_input1, string_input5);
					if (compareCourseFunction(obj) != -1) {
						selectCourse = obj;
					}
					else
						continue;
					while (true) {
						cout << "0 up\n1 delete_course\n2 list_students_registered_to_the_selected_course\n";
						cin >> int_input_2;
						if (int_input_2 == 0)
							break;
						if (int_input_2 == 1) {
							deleteCourse(compareCourseFunction(obj));
							flag = -1; // I used flag to exit the loop outside
							break;
						}
						if (int_input_2 == 2) {
							
						}
					}
				}
			}
		}
		if (input == 3) {
			for (int i = 0; i < student_references_size - 1; i++) {
				cout << i + 1 << " " << student_references[i].get_name() + " " << student_references[i].get_id() << "\n";
			}
		}
		if (input == 4) {
			for (int i = 0; i < Course_references_size - 1; i++) {
				cout << i + 1 << " " << course_references[i].get_code() + " " << course_references[i].get_name() << "\n";
			}
		}
	}

	return 0;
}


int main() {

	SchoolManagementSystem obj;  

	return 0;
}
// Dogukan TASTAN 1901042627