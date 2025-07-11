#pragma once
#include "CoreMinimal.h"
#include "PathfindingTile.generated.h"

UINTERFACE(BlueprintType)
class UPathfindingTile : public UInterface
{
	GENERATED_BODY()
};

class PNPV2_API IPathfindingTile {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	int getTileMovementCost();
};