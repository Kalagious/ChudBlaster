#include "general.h"

class Weapon
{
public:
	Weapon(std::string newName, UINT64 newDamage);

	std::string name;
	UINT64 damage;

	UINT64 GetDamage();

};