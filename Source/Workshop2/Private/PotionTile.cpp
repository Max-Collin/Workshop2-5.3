// Fill out your copyright notice in the Description page of Project Settings.


#include "PotionTile.h"

#include "PlayerTile.h"

APotionTile::APotionTile() {
	healValue = (rand() % 30) + 10;
	Type = 2;
}

void APotionTile::Action(APlayerTile* thisPlayer)
{
	Super::Action(thisPlayer);
	if(thisPlayer->hp +healValue >= 100)
	{
		thisPlayer->hp=100;
	}
	else
	{
		thisPlayer->hp+=healValue;
		
	}
	Destroy();
}




