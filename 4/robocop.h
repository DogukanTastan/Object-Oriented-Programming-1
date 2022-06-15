#ifndef ROBOCOP_H
#define ROBOCOP_H


class robocop : public humanic {
private:
	string type = "robocop";
public:
	virtual int getDamage();
	virtual string getType();
	robocop(int newStrength, int newHit);
};
#endif