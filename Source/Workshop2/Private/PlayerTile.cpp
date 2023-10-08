// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTile.h"

#include "MonsterTile.h"
#include "TileMap.h"

APlayerTile::APlayerTile(){

	hp = 100;
	gold = 0;
	x = 0;
	y = 0;

	weaponType=nullptr;
	

}

void APlayerTile::MoveRight()
{
	ABoardgame* Temp;
	
	
	if(x+1<81 && x%9 !=  8)
	{
		Temp = OwnerMap->MapArray[x+1];
		
		if(Temp->Loot)
		{
			if(Temp->Loot->Type== 3)
			{
				Temp->Loot->Action(this);
				return;
			}
			else
             		{
             			Temp->Loot->Action(this);
             		}
		}
		
		x= x+1;
		SetActorLocation(FVector(OwnerMap->MapArray[x]->GetActorLocation().X,OwnerMap->MapArray[x]->GetActorLocation().Y,OwnerMap->MapArray[x]->GetActorLocation().Z+100));
		
	}
	
}

void APlayerTile::MoveLeft()
{
	ABoardgame* Temp;	
	if(x-1>=0 && x%9 != 0)
	{
		Temp = OwnerMap->MapArray[x-1];
		
		if(Temp->Loot)
		{
			if(Temp->Loot->Type== 3)
			{
				Temp->Loot->Action(this);
				return;
			}
			else
			{
				Temp->Loot->Action(this);
			}
		}	
		x= x-1;
		SetActorLocation(FVector(OwnerMap->MapArray[x]->GetActorLocation().X,OwnerMap->MapArray[x]->GetActorLocation().Y,OwnerMap->MapArray[x]->GetActorLocation().Z+100));
	
	}
	
}

void APlayerTile::MoveUp()
{
	ABoardgame* Temp;
	if(x+9<81)
	{
		Temp = OwnerMap->MapArray[x+9];
		
		if(Temp->Loot)
		{
			if(Temp->Loot->Type == 3)
			{
				Temp->Loot->Action(this);
				return;
			}
			else
			{
				Temp->Loot->Action(this);
			}
		}
		

		
		x= x + 9;
		SetActorLocation(FVector(OwnerMap->MapArray[x]->GetActorLocation().X,OwnerMap->MapArray[x]->GetActorLocation().Y,OwnerMap->MapArray[x]->GetActorLocation().Z+100));
		
	}
}

void APlayerTile::MoveDown()
{
	ABoardgame* Temp;
	if(x-9>=0)
	{

		Temp = OwnerMap->MapArray[x-9];
		
		if(Temp->Loot)
		{
			if(Temp->Loot->Type== 3)
			{
				Temp->Loot->Action(this);
				return;
			}
			else
			{
				Temp->Loot->Action(this);
			}
		}
		
		x= x - 9;
		SetActorLocation(FVector(OwnerMap->MapArray[x]->GetActorLocation().X,OwnerMap->MapArray[x]->GetActorLocation().Y,OwnerMap->MapArray[x]->GetActorLocation().Z+100));
		
	} 
}


