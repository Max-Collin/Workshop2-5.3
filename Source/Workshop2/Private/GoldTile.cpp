// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldTile.h"

#include "PlayerTile.h"

AGoldTile::AGoldTile() {
	value = (rand() % 10) + 1;
	Type=4;
}

void AGoldTile::Action(APlayerTile* thisPlayer)
{
	Super::Action(thisPlayer);

	thisPlayer->gold += value;


	Destroy();
	
}
