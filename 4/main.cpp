#include <iostream>
#include <ctime>
using namespace std;
#include"robot.h"
#include"bulldozer.h"
#include"humanic.h"
#include"optimusprime.h"
#include"robocop.h"
#include"roomba.h"

int main() {		// driver program(main function)

	srand(time(NULL));

	roomba obj(10, 10);
	optimusprime obj2(10, 10);
	obj.fight(obj,obj2);
	cout << "**************************************************************" << endl;
	
	robocop obj3(10, 10);
	bulldozer obj4(10, 10);
	obj3.fight(obj3, obj4);
	cout << "**************************************************************" << endl;
	
	robocop obj5(10, 10);
	roomba obj6(10, 10);
	obj5.fight(obj5, obj6);
	cout << "**************************************************************" << endl;
	
	optimusprime obj7(10, 10);
	robocop obj8(10, 10);
	obj7.fight(obj7, obj8);
	cout << "**************************************************************" << endl;
	
	optimusprime obj9(10, 10);
	bulldozer obj10(10, 10);
	obj9.fight(obj9, obj10);
	cout << "**************************************************************" << endl;

} // Dogukan TASTAN 1901042627