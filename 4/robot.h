#ifndef ROBOT_H
#define ROBOT_H


class Robot {
private:
	string type;
	int strength=0;
	int hitpoints=0;
public:
	Robot();
	Robot(int newStrength, int newHit);
	virtual int getDamage();
	virtual string getType()=0;				// This class is an abstract class because no object will be derived from the robot class.
	int getter_strength();
	int getter_hitpoints();
	void setter_strength(int& new_strength);	// Setter getter functions required to access private elements
	void setter_hitpoints(int& new_hitpoints);
	void fight(Robot& obj1, Robot& obj2);
};

#endif