// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Boardgame.h"
#include "MonsterTile.generated.h"

/**
 * 
 */
UCLASS()
class WORKSHOP2_API AMonsterTile : public ABoardgame
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int hp;
	UPROPERTY(EditAnywhere)
		int goldDrop;
	UPROPERTY(EditAnywhere)
		int attackStrength;
public:
	AMonsterTile();

	virtual void Action(APlayerTile* thisPlayer) override;

	
};
