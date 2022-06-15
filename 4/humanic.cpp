#include <iostream>
#include <ctime>
using namespace std;
#include"robot.h"
#include"bulldozer.h"
#include"humanic.h"
#include"optimusprime.h"
#include"robocop.h"
#include"roomba.h"


int humanic::getDamage() {
	int damage=0;
	int chance=0;
	damage+=Robot::getDamage();		
	chance = rand() % 100;			// +50 damage, which is characteristic of the humanic ones, is added here

	if (chance <10) {
		damage += 50;
		
		cout << getType() << " attacks for tactical nuke attack +50 damage " <<
			damage << " points!" << endl;
	}
	return damage;
}
