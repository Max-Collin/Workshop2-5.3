// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Boardgame.h"
#include "PotionTile.generated.h"

/**
 * 
 */
UCLASS()
class WORKSHOP2_API APotionTile : public ABoardgame
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
		int healValue;

public:
	APotionTile();

	virtual void Action(APlayerTile* thisPlayer) override;
};
