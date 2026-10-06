#include "weapon.h"


Weapon::Weapon(std::string newName, UINT64 newDamage)
{
	name = newName;
	damage = newDamage;
}


UINT64 Weapon::GetDamage()
{
	return damage;
}