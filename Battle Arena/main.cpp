#include <iostream>
#include "Heroes.h"
#include "Villains.h"
#include <string>

using std::cout;
using std::endl;

int main()
{
	Hero goodTeam[5];
	Villain badTeam[5];
	int goodTeamSize = 5;
	int badTeamSize = 5;
	goodTeam[0].name = "Kirby";
	goodTeam[0].health = 70;
	goodTeam[0].attack = 5;
	goodTeam[1].name = "Link";
	goodTeam[1].health = 50;
	goodTeam[1].attack = 15;
	goodTeam[2].name = "Red";
	goodTeam[2].health = 50;
	goodTeam[2].attack = 15;
	goodTeam[3].name = "Mario";
	goodTeam[3].health = 40;
	goodTeam[3].attack = 20;
	goodTeam[4].name = "Sonic";
	goodTeam[4].health = 40;
	goodTeam[4].attack = 20;
	badTeam[0].name = "King Dedede";
	badTeam[0].health = 70;
	badTeam[0].attack = 5;
	badTeam[1].name = "Ganondorf";
	badTeam[1].health = 60;
	badTeam[1].attack = 10;
	badTeam[2].name = "Giovanni";
	badTeam[2].health = 40;
	badTeam[2].attack = 20;
	badTeam[3].name = "Bowser";
	badTeam[3].health = 40;
	badTeam[3].attack = 20;
	badTeam[4].name = "Dr. Eggman";
	badTeam[4].health = 30;
	badTeam[4].attack = 25;
	cout << "It was a time of peace. Our Heroes are all relaxing together.\nThese Heroes are:" << endl;
	for (int i = 0; i < goodTeamSize; i++)
	{
		if (i < goodTeamSize - 1)
		{
			cout << goodTeam[i].name << ", ";
		}
		else
		{
			cout << "and " << goodTeam[i].name << "." << endl;
		}
	}
	cout << "\nThe enemies of our heroes are coming!\nAmong them are:" << endl;
	for (int i = 0; i < badTeamSize; i++)
	{
		if (i < badTeamSize - 1)
		{
			cout << badTeam[i].name << ", ";
		}
		else
		{
			cout << "and " << badTeam[i].name << "." << endl;
		}
	}
	cout << "\nOnce our heroes see these villains, they jump into action!" << endl;

	while ((goodAlive(goodTeam, goodTeamSize)) && (badAlive(badTeam, badTeamSize)))
	{
		if (goodAlive(goodTeam, goodTeamSize))
		{
			for (int i = 0; i < goodTeamSize; i++)
			{
				if (goodTeam[i].isAlive)
				{
					if (!badAlive(badTeam, badTeamSize))
					{
						break;
					}
					for (int j = 0; j < badTeamSize; j++)
					{
						if (badTeam[j].isAlive)
						{
							cout << goodTeam[i].name << " attacks " << badTeam[j].name << "!" << endl;
							//cout << goodTeam[i].name << endl;
							int damage = goodTeam[i].attack;
							badTeam[j].takeDamage(damage);
							cout << badTeam[j].name << " took " << damage << " damage!\n" << badTeam[j].name << " has " << badTeam[j].health << " health remaining!" << endl;
							if (!badTeam[j].isAlive)
							{
								cout << badTeam[j].name << " has been defeated." << endl;
							}
							break;
						}
					}
				}
			}
		}

		if (badAlive(badTeam, badTeamSize))
		{
			for (int i = 0; i < badTeamSize; i++)
			{
				if (badTeam[i].isAlive)
				{
					if (!goodAlive(goodTeam, goodTeamSize))
					{
						break;
					}
					for (int j = 0; j < goodTeamSize; j++)
					{
						if (goodTeam[j].isAlive)
						{
							cout << badTeam[i].name << " attacks " << goodTeam[j].name << "!" << endl;
							int damage = badTeam[i].attack;
							goodTeam[j].takeDamage(damage);
							cout << goodTeam[j].name << " took " << damage << " damage!\n" << goodTeam[j].name << " has " << goodTeam[j].health << " health remaining!" << endl;
							if (!goodTeam[j].isAlive)
							{
								cout << goodTeam[j].name << " has been defeated." << endl;
							}
							break;
						}
					}
				}
			}
		}
	}
	if (goodAlive(goodTeam, goodTeamSize))
	{
		cout << "The Heroes win! Peace has been restored to their relaxing day." << endl;
	}
	else
	{
		cout << "The villains win! They have successfully ruined our heroes relaxing day!" << endl;
	}
	cout << "Press Enter to quit." << endl;
	std::cin.get();
	return 0;
}

bool goodAlive(Hero * goodArr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (goodArr[i].isAlive)
		{
			return true;
		}
	}
	return false;
}

bool badAlive(Villain * badArr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (badArr[i].isAlive)
		{
			return true;
		}
	}
	return false;
}