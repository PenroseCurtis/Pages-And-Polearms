// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "json.h"
#include "DataLoader.h"
#include "ItemRepository.h"
#include "CharacterRepository.h"
#include "SceneryStateRepository.h"
#include "MapStateRepository.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FCoordinates
{
	GENERATED_BODY()
	public:
		UPROPERTY(BlueprintReadWrite)
			int32 XCoordinate;
		UPROPERTY(BlueprintReadWrite)
			int32 YCoordinate;
};

USTRUCT(BlueprintType)
struct FSceneryState
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite)
		FString sceneryId;
	UPROPERTY(BlueprintReadWrite)
		bool state;
};

USTRUCT(BlueprintType)
struct FInitialCharacterSpawnStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString characterStatKey;
	UPROPERTY(BlueprintReadWrite)
		FCoordinates coordinates;
};

USTRUCT(BlueprintType)
struct FCharacterSpawnStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FOPageStatStruct characterStats;
	UPROPERTY(BlueprintReadWrite)
		FCoordinates coordinates;
};
USTRUCT(BlueprintType)
struct FItemState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FOGenericItemStruct itemState;
	UPROPERTY(BlueprintReadWrite)
		FCoordinates coordinates;
};

USTRUCT(BlueprintType)
struct FMovableBlockState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FCoordinates coordinates;
};

USTRUCT(BlueprintType)
struct FInitialLevelState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString backgroundSpritePath;
	UPROPERTY(BlueprintReadWrite)
		TArray<FItemState> initialItemStates;
	UPROPERTY(BlueprintReadWrite)
		TArray<FInitialCharacterSpawnStruct> initialEnemySpawns;
	UPROPERTY(BlueprintReadWrite)
		TArray<FInitialCharacterSpawnStruct> initialNPCSpawns;
};

USTRUCT(BlueprintType)
struct FLevelState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString backgroundSpritePath;
	UPROPERTY(BlueprintReadWrite)
		TArray<FItemState> itemStates;
	UPROPERTY(BlueprintReadWrite)
		TArray<FCharacterSpawnStruct> enemyStates;
	UPROPERTY(BlueprintReadWrite)
		TArray<FCharacterSpawnStruct> npcStates;
	UPROPERTY(BlueprintReadWrite)
		TArray<FSceneryState> sceneryStates;
	UPROPERTY(BlueprintReadWrite)
		TArray<FChestState> chestStates;
	UPROPERTY(BlueprintReadWrite)
		TArray<FDoorState> doorStates;
	UPROPERTY(BlueprintReadWrite)
		TArray<FEnchanterState> enchanterStates;
	UPROPERTY(BlueprintReadWrite)
		TArray<FSceneryState> tileStates;
	UPROPERTY(BlueprintReadWrite)
		TArray<FMovableBlockState> blockStates;
};

UCLASS()
class PNPV2_API UMapStateRepository : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable)
		static FInitialLevelState getInitialLevelState(FString key);
};
