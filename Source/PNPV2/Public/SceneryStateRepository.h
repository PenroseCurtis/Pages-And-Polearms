// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataLoader.h"
#include "SceneryStateRepository.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FChestState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		bool isLocked;
	UPROPERTY(BlueprintReadWrite)
		TArray<FOGenericItemStruct> itemsInChest;
	UPROPERTY(BlueprintReadWrite)
		FString id;
};

USTRUCT(BlueprintType)
struct FDoorState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		bool isLocked;
	UPROPERTY(BlueprintReadWrite)
		bool isOpen;
	UPROPERTY(BlueprintReadWrite)
		FString id;
};

USTRUCT(BlueprintType)
struct FEnchanterState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString enchantmentKey;
	UPROPERTY(BlueprintReadWrite)
		FString id;
};

UCLASS()
class PNPV2_API USceneryStateRepository : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};
