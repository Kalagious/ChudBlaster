#include "weapon.h"


Weapon::Weapon(std::string newName, INT64 newDamage)
{
	name = newName;
	damage = newDamage;
}


INT64 Weapon::GetDamage()
{
	return damage;
}