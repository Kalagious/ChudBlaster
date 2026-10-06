#pragma once

#include "general.h"
#include "weapon.h"

class Player
{
public:
	Player(std::string newName, UINT64 newHealth, UINT64 newArmor);

	UINT64 health;
	UINT64 armor;
	std::string name;
	Weapon* heldWeapon;


	void EquipWeapon(Weapon* weapon);

	void TakeDamage(UINT64 dmg);
	void DealDamage(Player* target);

	void DisplayHealth();
	bool IsAlive();
};