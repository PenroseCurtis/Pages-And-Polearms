// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PathfindingTile.h"
#include "AStarNode.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "pathFinder.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FPathfindingResults
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		TArray<APathfindingTile*> path;
	UPROPERTY(BlueprintReadWrite)
		int32 result;
	UPROPERTY(BlueprintReadWrite)
		int32 pathLength;
	UPROPERTY(BlueprintReadWrite)
		int32 cost;

	FPathfindingResults() 
	{
		path = {};
		result = 0;
		pathLength = 0;
		cost = 0;
	};
	FPathfindingResults(TArray<APathfindingTile*> aPath, int32 aResult, int32 aPathLength, int32 aCost) 
	{
		path = aPath;
		result = aResult;
		pathLength = aPathLength;
		cost = aCost;
	};
};

UCLASS()
class PNPV2_API UPathFinder : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION()
		static float calculateH(APathfindingTile* successorTile, APathfindingTile* destination);
	UFUNCTION()
		static bool shouldNodeBeAdded(UAStarNode* node, TArray<UAStarNode*> nodes);
	UFUNCTION(BlueprintCallable)
		static FPathfindingResults findPath(APathfindingTile* start, APathfindingTile* destination, int32 maxCost, int32 maxPathLength);
};
