// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PathfindingTile.generated.h"

UCLASS()
class PNPV2_API APathfindingTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APathfindingTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		int getCostPf();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		bool getIsOccupiedPf();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		APathfindingTile* getNeighborPf(int32 direction);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		int getXCoordinatePf();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		int getYCoordinatePf();
};
