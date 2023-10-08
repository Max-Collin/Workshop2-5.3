// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Boardgame.h"
#include "WeaponTile.generated.h"

class ABaseWeapon;

/**
 * 
 */
UCLASS()
class WORKSHOP2_API AWeaponTile : public ABoardgame
{
	GENERATED_BODY()

	
public:
	AWeaponTile();

	UPROPERTY(EditAnywhere)
	ABaseWeapon* Weapon;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> WeaponToSpawn;

	

	virtual void BeginPlay() override;

	virtual void Action(APlayerTile* thisPlayer) override;

};
