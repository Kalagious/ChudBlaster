#include "general.h"
#include "player.h"


Player* local;
Player* enemy;


// You may notice the enemy is much better equiped, you will always lose without some extra help

int main()
{
	// Allocate new players
	local = new Player(std::string("Chud"), 100, 10);
	enemy = new Player(std::string("Badguy"), 100, 15);

	// Create weapons for them
	Weapon* pistol = new Weapon(std::string("Pistol"), 20);
	Weapon* ar = new Weapon(std::string("AR"), 25);

	// Equip weapons
	local->EquipWeapon(pistol);
	enemy->EquipWeapon(ar);
	while (true)
	{

		// Run game loop until someone loses
		// Basic game loop, both players attack and print health results
		while (local->IsAlive() && enemy->IsAlive())
		{
			enemy->DealDamage(local);
			local->DealDamage(enemy);
			enemy->DisplayHealth();
			local->DisplayHealth();
			std::getchar();
		}

		// Check who lost
		if (local->IsAlive())
			printf("You killed the enemy first and won! Congrats!\n");
		else if (enemy->IsAlive())
			printf("You died first. You Lost!\n");

		printf("\nGame Restarting\n");

		local->health = 100;
		enemy->health = 100;
	}
	return 0;
}
