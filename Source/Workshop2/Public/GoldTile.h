// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Boardgame.h"
#include "GoldTile.generated.h"

/**
 * 
 */
UCLASS()
class WORKSHOP2_API AGoldTile : public ABoardgame
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int value;
public:
	AGoldTile();

	virtual void Action(APlayerTile* thisPlayer) override;
};
