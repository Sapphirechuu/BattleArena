#pragma once
#include <iostream>

class Hero
{
public:
	bool isAlive = true;
	int health;
	int attack;
	std::string name;

	void takeDamage(int damage);
};

bool goodAlive(Hero * goodArr, int arrSize);