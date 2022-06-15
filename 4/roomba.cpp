#include <iostream>
#include <ctime>
using namespace std;
#include"robot.h"
#include"bulldozer.h"
#include"humanic.h"
#include"optimusprime.h"
#include"robocop.h"
#include"roomba.h"


roomba::roomba(int newStrength, int newHit) {  // constructor
	setter_strength(newStrength);
	setter_hitpoints(newHit);
}

int roomba::getDamage() {
	int damage = 0;
	damage+=Robot::getDamage();
	damage+=Robot::getDamage();

	return damage;
}

string roomba::getType(){
	return type;
}