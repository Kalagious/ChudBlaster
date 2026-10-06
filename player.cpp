#pragma once

#include "player.h"

// Player Function Definitions

Player::Player(std::string newName, INT64 newHealth, INT64 newArmor)
{
	name = newName;
	health = newHealth;
	armor = newArmor;

	printf("New player %s created!\n", name.c_str());
}


void Player::EquipWeapon(Weapon* weapon)
{
	if (!weapon)
	{
		printf("%s failed to equip weapon, invalid!", name.c_str());
		return;
	}

	heldWeapon = weapon;
	printf("%s equipped %s!\n", name.c_str(), weapon->name.c_str());
}

void Player::TakeDamage(INT64 dmg)
{
	INT64 finalDmg = dmg - armor;

	health -= finalDmg;

	printf("%s took %d damage\n", name.c_str(), finalDmg);
}

void Player::DealDamage(Player* target)
{
	INT64 dmg = heldWeapon->GetDamage();
	target->TakeDamage(dmg);
}

void Player::DisplayHealth()
{
	printf("%s's health is %d\n", name.c_str(), health);
}

bool Player::IsAlive()
{
	return health > 0;
}