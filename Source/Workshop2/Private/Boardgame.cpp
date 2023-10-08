// Fill out your copyright notice in the Description page of Project Settings.


#include "Boardgame.h"



// Sets default values
ABoardgame::ABoardgame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ParentTile = nullptr;

}

// Called when the game starts or when spawned
void ABoardgame::BeginPlay()
{
	Super::BeginPlay();


	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	
	ABoardgame* Temp;
	Temp = nullptr;
	int RandomNumber = 0;
	RandomNumber = rand()%12;

	
	spawnPos.SetLocation(FVector(GetActorLocation().X,GetActorLocation().Y,GetActorLocation().Z + 100)) ;
	switch (RandomNumber)
	{
	

	case 1:
		Temp = (ABoardgame*) GetWorld()->SpawnActor<AActor>(GoldTile, spawnPos, spawnParameters);
			
		break;
	case 2:
		
		
		Temp = (ABoardgame*) GetWorld()->SpawnActor<AActor>(MonsterTile, spawnPos, spawnParameters);
			
		
		break;
	case 3:
		Temp = (ABoardgame*) GetWorld()->SpawnActor<AActor>(PotionTile, spawnPos, spawnParameters);
				
		break;
	case 4:
		Temp = (ABoardgame*) GetWorld()->SpawnActor<AActor>(WeaponTile, spawnPos, spawnParameters);
				
		break;
	default: ;
	}
	if(Temp)
	{
		Loot = Temp;
		Temp->ParentTile = this;
	}
	
	
}

// Called every frame
void ABoardgame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoardgame::SetMap(ATileMap* thisMap)
{
	OwnerMap = thisMap;
}

bool ABoardgame::HasLoot()
{
	if (Loot)
	{
		return true;
	}
	return false;
}

void ABoardgame::Action(APlayerTile* thisPlayer)
{
	

	
}

void ABoardgame::spawnGold()
{


	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	
	ABoardgame* Temp;
	Temp = nullptr;
	
	spawnPos.SetLocation(FVector(GetActorLocation().X,GetActorLocation().Y,GetActorLocation().Z + 100)) ;
	
	Temp = (ABoardgame*) GetWorld()->SpawnActor<AActor>(GoldTile, spawnPos, spawnParameters);
	Loot = Temp;
	Temp->ParentTile = this;
}

