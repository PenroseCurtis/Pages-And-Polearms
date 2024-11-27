// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataLoader.h"
#include "ItemRepository.h"
#include "CharacterRepository.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FOPageStatStruct
{
	GENERATED_BODY()		
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString classKey;
	UPROPERTY(BlueprintReadWrite)
		FString flipBookKey;
	UPROPERTY(BlueprintReadWrite)
		FString movementCompKey;
	UPROPERTY(BlueprintReadWrite)
		FString name;
	UPROPERTY(BlueprintReadWrite)
		FString dialogKey;
	UPROPERTY(BlueprintReadWrite)
		TArray<FStanceLevel> stances;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> attacks;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> statuses;
	UPROPERTY(BlueprintReadWrite)
		int level;
	UPROPERTY(BlueprintReadWrite)
		int experience;
	UPROPERTY(BlueprintReadWrite)
		TArray<FActionCost> actions;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> spells;
	UPROPERTY(BlueprintReadWrite)
		FOStatBlockStruct statBlock;
	UPROPERTY(BlueprintReadWrite)
		FInventoryStruct inventoryStruct;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> actionsObjectCanTake;
	UPROPERTY(BlueprintReadWrite)
		int32 movementLogicControllerState;
	FOPageStatStruct()
	{
		key = "Default";
		flipBookKey = "Page";
		name = "Default_Page";
		stances = {
			FStanceLevel("Unarmed", 1),
			FStanceLevel("Basic 1H", 1),
			FStanceLevel("Basic 2H", 1),
			FStanceLevel("Two Weapon Fighting", 1),
			FStanceLevel("Vulnerable", 1)
		},
		level = 1,
		experience = 0,
		actionsObjectCanTake = { "Target", "Attack", "Change Stance", "View Inventory", "Ready Attack",
								"Unready Attack", "Examine", "Pass Turn", "Move To", "Pickup",
								"Drop", "Equip", "Unequip", "Equip To Dominant", "Equip To Off",
								"Use", "Unlock", "Open", "Close", "Read", "Drink", "Cast", "Grab",
								"Release", "Talk", "Trade", "Buy", "Sell", "Rest", "Heal", "Give", 
								"Recruit", "Dismiss" };
		actions = {
			FActionCost("Target", 0),
			FActionCost("Examine", 0),
			FActionCost("Move To", 1)
		};
		statBlock = FOStatBlockStruct(3, 3, 10, 10, 1, 1);
		movementLogicControllerState = 0;
	}
};
UCLASS()
class PNPV2_API UCharacterRepository : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:
		UFUNCTION(BlueprintCallable)
			static FOPageStatStruct GetPageStatStruct(FString key);
	
};
