#ifndef ROOMBA_H
#define ROOMBA_H


class roomba : public Robot {
private:
	string type = "roomba";
public:
	virtual int getDamage();
	virtual string getType();
	roomba(int newStrength, int newHit);
	
};

#endif