// Fill out your copyright notice in the Description page of Project Settings.


#include "TileMap.h"

// Sets default values
ATileMap::ATileMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Mapx.Init(10, 0);
	//Mapy.Init(10, 0);

	

}

void ATileMap::SpawnActor() {
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	ABoardgame* Temp;
	Temp= nullptr;
	
	for (int i = 0; i< 9;i++ )
	{
		for (int j=0;j< 9;j++)
		{
			
			spawnPos.SetLocation(FVector3d(i*500,j*500,0));
			
			 Temp = (ABoardgame*) GetWorld()->SpawnActor<AActor>(DefaultTile, spawnPos, spawnParameters);
			
			MapArray.Add(Temp);
			Temp->SetMap(this);

			
		
		}
		
	}
	ABoardgame* start = MapArray[0];
	spawnPos.SetLocation(FVector(start->GetActorLocation().X,start->GetActorLocation().Y,start->GetActorLocation().Y+100));
	
	Temp = start->Loot;
	if(Temp != nullptr)
	{
		Temp->Destroy();
		start->Loot = nullptr;
	}
	
	
	
	Temp = (ABoardgame*) GetWorld()->SpawnActor<AActor>(playerTile,spawnPos,spawnParameters);

	Temp->SetMap(this);
	
}

// Called when the game starts or when spawned
void ATileMap::BeginPlay()
{
	Super::BeginPlay();

	SpawnActor();
	
}

// Called every frame
void ATileMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

