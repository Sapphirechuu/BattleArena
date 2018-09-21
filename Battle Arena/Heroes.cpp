#include <iostream>
#include "Heroes.h"

void Hero::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}

	if (health == 0)
	{
		isAlive = false;
	}
}
