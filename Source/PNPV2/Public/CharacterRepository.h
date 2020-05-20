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
		FString flipBookKey;
	UPROPERTY(BlueprintReadWrite)
		FString movementCompKey;
	UPROPERTY(BlueprintReadWrite)
		FString name;
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
		FString defaultWeaponKey;
	UPROPERTY(BlueprintReadWrite)
		TArray<FActionCost> actions;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> spells;
	UPROPERTY(BlueprintReadWrite)
		TArray<FOGenericEquippedItemStruct> equippedItems;
	UPROPERTY(BlueprintReadWrite)
		TArray<FOGenericItemStruct> inventory;
	UPROPERTY(BlueprintReadWrite)
		FOStatBlockStruct statBlock;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> actionsObjectCanTake;
	FOPageStatStruct()
	{
		name = "Clem";
		actionsObjectCanTake = { "Target", "Attack", "Set Stance", "View Inventory", "Ready Attack",
								"Unready Attack", "Examine", "Pass Turn", "Move To", "Pickup",
								"Drop", "Equip", "Unequip", "Equip To Dominant", "Equip To Off",
								"Use", "Unlock" };
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
