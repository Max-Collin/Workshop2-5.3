// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Boardgame.h"
#include "WeaponTile.h"
#include "PlayerTile.generated.h"



/**
 * 
 */
UCLASS()
class WORKSHOP2_API APlayerTile : public ABoardgame
{
	GENERATED_BODY()
	
	

public:
	APlayerTile();

	UFUNCTION(BlueprintCallable)
		void MoveRight();
	UFUNCTION(BlueprintCallable)
		void MoveLeft();
	UFUNCTION(BlueprintCallable)
		void MoveUp();
	UFUNCTION(BlueprintCallable)
		void MoveDown();

	UPROPERTY(EditAnywhere)
	int x;
	UPROPERTY(EditAnywhere)
	int y;
	UPROPERTY(EditAnywhere)
	ABaseWeapon* weaponType;
	UPROPERTY(EditAnywhere)
	int gold;
	UPROPERTY(EditAnywhere)
	int hp;
	
	
};
