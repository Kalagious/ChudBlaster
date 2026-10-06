#include "general.h"

class Weapon
{
public:
	Weapon(std::string newName, INT64 newDamage);

	std::string name;
	INT64 damage;

	INT64 GetDamage();

};