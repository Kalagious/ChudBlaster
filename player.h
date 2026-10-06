#pragma once

#include "general.h"
#include "weapon.h"

class Player
{
public:
	Player(std::string newName, INT64 newHealth, INT64 newArmor);

	INT64 health;
	INT64 armor;
	std::string name;
	Weapon* heldWeapon;


	void EquipWeapon(Weapon* weapon);

	void TakeDamage(INT64 dmg);
	void DealDamage(Player* target);

	void DisplayHealth();
	bool IsAlive();
};