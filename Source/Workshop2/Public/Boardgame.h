// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boardgame.generated.h"


class APlayerTile;
class ATileMap;

class APotionTile;
class AWeaponTile;
class AMonsterTile;
class AGoldTile;


UCLASS()
class WORKSHOP2_API ABoardgame : public AActor
{
	GENERATED_BODY()




	
	
public:	
	// Sets default values for this actor's properties
	ABoardgame();



public:
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

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		ABoardgame* Loot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTransform spawnPos;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable)
		void SetMap(ATileMap* thisMap);

	UFUNCTION(BlueprintCallable)
		bool HasLoot();

	UPROPERTY(EditAnywhere)
		ATileMap* OwnerMap;

	UPROPERTY(EditAnywhere)
		int Type;
	
	UFUNCTION()
		virtual  void  Action(APlayerTile* thisPlayer);


	UPROPERTY(EditAnywhere)
		ABoardgame* ParentTile;
	UFUNCTION(Blueprintable)
		void spawnGold();
	
};

