#include <iostream>
#include <ctime>
using namespace std;
#include"robot.h"
#include"bulldozer.h"
#include"humanic.h"
#include"optimusprime.h"
#include"robocop.h"
#include"roomba.h"


optimusprime::optimusprime(int newStrength, int newHit) {
	setter_hitpoints(newHit);
	setter_strength(newStrength);
}

int optimusprime::getDamage() {
	int damage = 0;
	int chance = 0;
	damage+=humanic::getDamage();	// Optimusprime's status due to being humanic is calculated here
	chance = rand() % 100;

	if (chance <15) {			// Optimusprime's own feature, with a 15% chance, is added by calculating double hits here.
		damage *= 2;

		cout << getType() << " 15% Chance to double the attack  " <<
			damage << " points!" << endl;
	}
	return damage;
}

string optimusprime::getType() {
	return type;
}
