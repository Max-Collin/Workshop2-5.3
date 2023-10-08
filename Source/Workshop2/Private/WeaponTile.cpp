// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponTile.h"

#include "BaseWeapon.h"
#include "PlayerTile.h"

AWeaponTile::AWeaponTile() {

	
	
	Type=1;
	Weapon = nullptr;
	
	
	
	
}

void AWeaponTile::BeginPlay()
{
	Super::BeginPlay();
	
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	spawnPos.SetLocation(FVector(0.f,0.f,0.f));
	
	Weapon= (ABaseWeapon*) GetWorld()->SpawnActor<AActor>(WeaponToSpawn, spawnPos,spawnParameters);
	
}

void AWeaponTile::Action(APlayerTile* thisPlayer)
{
	Super::Action(thisPlayer);

	thisPlayer->weaponType=Weapon;
	Destroy();
}
