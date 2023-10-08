// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterTile.h"

#include "BaseWeapon.h"
#include "PlayerTile.h"

AMonsterTile::AMonsterTile() {
	hp = 20;
	goldDrop = 5;
	attackStrength = 5;
	Type = 3;

}

void AMonsterTile::Action(APlayerTile* thisPlayer)
{
	Super::Action(thisPlayer);

	if(thisPlayer->weaponType)
	{
		hp-=thisPlayer->weaponType->weaponDamage;
		if(hp<=0)
		{
			if(ParentTile)
			{
				ParentTile->Loot= nullptr;
				ParentTile->spawnGold();
				Destroy();
			}
			
		}
	}
	else
	{
		hp-=1;
	}

	thisPlayer->hp -= attackStrength;
	if(thisPlayer->hp<=0)
	{
		thisPlayer->Destroy();
	}
	
}
