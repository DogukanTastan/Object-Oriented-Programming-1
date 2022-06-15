#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H


class optimusprime : public humanic {
private:
	string type = "optimusprime";
public:
	virtual int getDamage();
	virtual string getType();
	optimusprime(int newStrength, int newHit);
};

#endif