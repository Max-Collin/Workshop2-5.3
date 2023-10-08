// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boardgame.h"
#include "TileMap.generated.h"

UCLASS()
class WORKSHOP2_API ATileMap : public AActor
{
	GENERATED_BODY()

		/*UPROPERTY(EditAnywhere)
			TArray<ATileMap*> Mapx;
	UPROPERTY(EditAnywhere)
		TArray<ATileMap*> Mapy;*/
		

	
public:	
	// Sets default values for this actor's properties
	ATileMap();

	UFUNCTION(BlueprintCallable, Category = "Startup")
		void SpawnActor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Tiles")
		TSubclassOf<AActor> DefaultTile;
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Tiles")
		TSubclassOf<AActor> GoldTile;
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Tiles")
		TSubclassOf<AActor> MonsterTile;
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Tiles")
		TSubclassOf<AActor> WeaponTile ;
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Tiles")
		TSubclassOf<AActor> playerTile;
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Tiles")
		TSubclassOf<AActor> PotionTile;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FTransform spawnPos;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TArray<ABoardgame*> MapArray;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
