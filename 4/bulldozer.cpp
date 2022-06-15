#include <iostream>
#include <ctime>
using namespace std;
#include"robot.h"
#include"bulldozer.h"
#include"humanic.h"
#include"optimusprime.h"
#include"robocop.h"
#include"roomba.h"



bulldozer::bulldozer(int newStrength, int newHit) {	// assigning initial values
	setter_hitpoints(newHit);
	setter_strength(newStrength);
}

int bulldozer::getDamage() {
	int damage = 0;
	damage+=Robot::getDamage();	// Since the only feature of the bulldozer is that it is a robot, only this value is taken.

	return damage;
}

string bulldozer::getType() {
	return type;
}
