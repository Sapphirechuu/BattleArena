#pragma once
#include <iostream>

class Villain
{
public:
	bool isAlive = true;
	int health;
	int attack;
	std::string name;

	void takeDamage(int damage);
};

bool badAlive(Villain * badArr, int arrSize);