#ifndef HUMANIC_H
#define HUMANIC_H


class humanic : public Robot {

public:
	virtual int getDamage()=0;	// This class is abstract since we will not create an object humanic.
};
#endif