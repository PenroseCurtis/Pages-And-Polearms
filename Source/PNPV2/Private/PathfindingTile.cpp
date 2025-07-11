// Fill out your copyright notice in the Description page of Project Settings.


#include "PathfindingTile.h"

// Sets default values
APathfindingTile::APathfindingTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APathfindingTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APathfindingTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int APathfindingTile::getCostPf_Implementation()
{
	return 0;
}

bool APathfindingTile::getIsOccupiedPf_Implementation()
{
	return false;
}

APathfindingTile* APathfindingTile::getNeighborPf_Implementation(int32 direction)
{
	return nullptr;
}

int APathfindingTile::getXCoordinatePf_Implementation()
{
	return 0;
}

int APathfindingTile::getYCoordinatePf_Implementation()
{
	return 0;
}

