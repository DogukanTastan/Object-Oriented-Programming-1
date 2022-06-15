#include <iostream>
#include <ctime>
using namespace std;
#include"robot.h"
#include"bulldozer.h"
#include"humanic.h"
#include"optimusprime.h"
#include"robocop.h"
#include"roomba.h"

robocop::robocop(int newStrength, int newHit) {
	setter_hitpoints(newHit);
	setter_strength(newStrength);
}

int robocop::getDamage() {
	int damage = 0;
	damage+=humanic::getDamage();	// Since the only feature of robocop is humanic robot, humanic is also used in calculations.

	return damage;
}
string robocop::getType() {
	return type;
}