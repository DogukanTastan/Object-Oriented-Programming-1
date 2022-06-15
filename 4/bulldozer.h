#ifndef BULLDOZER_H
#define BULLDOZER_H


class bulldozer : public Robot {
private:
	string type = "bulldozer";
public:
	virtual int getDamage();
	virtual string getType();
	bulldozer(int newStrength, int newHit);
};
#endif