#include <iostream>
#include <ctime>
using namespace std;
#include"robot.h"
#include"bulldozer.h"
#include"humanic.h"
#include"optimusprime.h"
#include"robocop.h"


Robot::Robot() {				/// consructors

}

Robot::Robot(int newStrength, int newHit) {
	
	strength = newStrength;
	hitpoints = newHit;
}

string Robot::getType() {	// Setter getter functions required to access private elements
	return type;
}


int Robot::getter_strength()
{
	return strength;
}

int Robot::getter_hitpoints()
{
	return hitpoints;
}

void Robot::setter_strength(int& new_strength)
{
	strength = new_strength;
}

void Robot::setter_hitpoints(int& new_hitpoints)
{
	hitpoints += new_hitpoints;
}


int Robot::getDamage() {
	int damage;
	damage = (rand() % strength) + 1;	// basic hit feature that applies to every robot

	cout << getType() << " attacks for " <<
		damage << " points!" << endl;

	return damage;
}

void Robot::fight(Robot& obj1, Robot& obj2) {		// By taking the objects as a reference, I ensured that they were taken as Robot type.
	
	int damage1=0, damage2=0,negDamage1=0,negDamage2=0;
	
	while (true) {

		damage1 = obj1.getDamage();			// I deduct the damage of the first item from the hp of the 2nd.
		negDamage1 = damage1 * -1;		// I'm taking the negative so I can easily subtract with the setter function
		obj2.setter_hitpoints(negDamage1);
		
		if ((obj2.getter_hitpoints() < obj1.getter_hitpoints()) && obj2.getter_hitpoints() <= 0) {	//after the first attack i check if the other one dies
			cout << obj1.getType() << " win\n" << obj1.getType() << " Hp:" << obj1.getter_hitpoints() << " " << obj2.getType() << " Hp:" << obj2.getter_hitpoints() << "\n";
			break;
		}
		damage2 = obj2.getDamage();		// if the war continues, it is the turn of the other robot.
		negDamage2 = damage2 * -1;
		obj1.setter_hitpoints(negDamage2);

		if ((obj1.getter_hitpoints()< obj2.getter_hitpoints()) && obj1.getter_hitpoints() <= 0) {
			cout << obj2.getType() << " win\n" << obj1.getType() << " Hp:" << obj1.getter_hitpoints() << " " << obj2.getType() << " Hp:" << obj2.getter_hitpoints() << "\n";
			break;
		}
	}
}