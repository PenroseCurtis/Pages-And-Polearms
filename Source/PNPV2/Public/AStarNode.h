// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PathfindingTile.h"
#include "AStarNode.generated.h"

/**
 * 
 */
UCLASS()
class PNPV2_API UAStarNode : public UObject
{
	GENERATED_BODY()
public:
	UAStarNode();
	~UAStarNode();
	float getF();
	float getG();
	float getH();
	int32 getPathLength();
	APathfindingTile* getPosition();
	UAStarNode* getParentNode();
	void buildNode(float aF, float aG, float aH, int32 pathLength, APathfindingTile* aPosition, UAStarNode* aParentNode);
private:
	UPROPERTY()
		float F;
	UPROPERTY()
		float G;
	UPROPERTY()
		float H;
	UPROPERTY()
		int32 pathLength;
	UPROPERTY()
		APathfindingTile* position;
	UPROPERTY()
		UAStarNode* parentNode;
};
