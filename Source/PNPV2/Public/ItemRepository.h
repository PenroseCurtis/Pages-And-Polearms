// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataLoader.h"
#include "ItemRepository.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FOItemStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString classKey;
	UPROPERTY(BlueprintReadWrite)
		float weight;
	UPROPERTY(BlueprintReadWrite)
		float opacity;
	UPROPERTY(BlueprintReadWrite)
		FString description;
	UPROPERTY(BlueprintReadWrite)
		FString spritePath;
	UPROPERTY(BlueprintReadWrite)
		FString iconPath;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> statuses;
	UPROPERTY(BlueprintReadWrite)
		TArray<FActionCost> actions;
	UPROPERTY(BlueprintReadWrite)
		int32 equipableType;
	UPROPERTY(BlueprintReadWrite)
		bool inDominantHand;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> actionsObjectCanTake;
	UPROPERTY(BlueprintReadWrite)
		float value;
	FOItemStruct()
	{
		key = "Default";
		classKey = "Default";
		weight = 0.0;
		opacity = 0.0;
		description = "Default object, perhaps something has run amok...";
		spritePath = "Default";
		iconPath = "Default";
		equipableType = 0;
	}
};

USTRUCT(BlueprintType)
struct FOGenericItemStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString itemKey;
	UPROPERTY(BlueprintReadWrite)
		FString classKey;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> enchantmentKeys;
};

USTRUCT(BlueprintType)
struct FOGenericEquippedItemStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FOGenericItemStruct itemStruct;
	UPROPERTY(BlueprintReadWrite)
		bool isEquippedToDominantHand;
};

USTRUCT(BlueprintType)
struct FInventoryStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		TArray<FOGenericItemStruct> items;
	UPROPERTY(BlueprintReadWrite)
		TArray<FOGenericEquippedItemStruct> equippedItems;
	UPROPERTY(BlueprintReadWrite)
		int32 gold;
	UPROPERTY(BlueprintReadWrite)
		int32 maxInventorySize;
	UPROPERTY(BlueprintReadWrite)
		FString defaultWeaponKey;
};

USTRUCT(BlueprintType)
struct FOWeaponStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString flipBookKey;
	UPROPERTY(BlueprintReadWrite)
		float damage;
	UPROPERTY(BlueprintReadWrite)
		float accuracy;
	UPROPERTY(BlueprintReadWrite)
		float contact;
	UPROPERTY(BlueprintReadWrite)
		float guard;
	UPROPERTY(BlueprintReadWrite)
		float piercing;
	UPROPERTY(BlueprintReadWrite)
		float bludgeon;
	UPROPERTY(BlueprintReadWrite)
		TArray<FStanceLevel> stances;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> specialAttacks;
	UPROPERTY(BlueprintReadWrite)
		float weight;
	UPROPERTY(BlueprintReadWrite)
		FString description;
	UPROPERTY(BlueprintReadWrite)
		FString spritePath;
	UPROPERTY(BlueprintReadWrite)
		FString iconPath;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> statuses;
	UPROPERTY(BlueprintReadWrite)
		TArray<FActionCost> actions;
	UPROPERTY(BlueprintReadWrite)
		int32 equipableType;
	UPROPERTY(BlueprintReadWrite)
		float layer;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> weaponTypes;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> actionCosts;
	UPROPERTY(BlueprintReadWrite)
		float value;
	FOWeaponStruct()
	{
		key = "Default";
		weight = 0.0;
		description = "Default object, perhaps something has run amok...";
		spritePath = "Default";
		iconPath = "Default";
		equipableType = 0;
	}
};

USTRUCT(BlueprintType)
struct FOArmorStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		float coverage;
	UPROPERTY(BlueprintReadWrite)
		float maxCoverage;
	UPROPERTY(BlueprintReadWrite)
		float hardness;
	UPROPERTY(BlueprintReadWrite)
		float padding;
	UPROPERTY(BlueprintReadWrite)
		float deflection;
	UPROPERTY(BlueprintReadWrite)
		float weight;
	UPROPERTY(BlueprintReadWrite)
		FString description;
	UPROPERTY(BlueprintReadWrite)
		FString spritePath;
	UPROPERTY(BlueprintReadWrite)
		FString iconPath;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> statuses;
	UPROPERTY(BlueprintReadWrite)
		TArray<FActionCost> actions;
	UPROPERTY(BlueprintReadWrite)
		int32 equipableType;
	UPROPERTY(BlueprintReadWrite)
		float layer;
	UPROPERTY(BlueprintReadWrite)
		bool wrapsAround;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> actionCosts;
	UPROPERTY(BlueprintReadWrite)
		float value;
	FOArmorStruct()
	{
		key = "Default";
		weight = 0.0;
		description = "Default object, perhaps something has run amok...";
		spritePath = "Default";
		iconPath = "Default";
		equipableType = 0;
	}
};

USTRUCT(BlueprintType)
struct FOConsumableStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString description;
	UPROPERTY(BlueprintReadWrite)
		TArray<FActionCost> actions;
	UPROPERTY(BlueprintReadWrite)
		FString spritePath;
	UPROPERTY(BlueprintReadWrite)
		FString iconPath;
	UPROPERTY(BlueprintReadWrite)
		float weight;
	UPROPERTY(BlueprintReadWrite)
		float value;
	UPROPERTY(BlueprintReadWrite)
		float healthChange;
	UPROPERTY(BlueprintReadWrite)
		FString statusKey;
	UPROPERTY(BlueprintReadWrite)
		FOGenericItemStruct replacementItem;
};

USTRUCT(BlueprintType)
struct FOScrollStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString description;
	UPROPERTY(BlueprintReadWrite)
		TArray<FActionCost> actions;
	UPROPERTY(BlueprintReadWrite)
		FString spritePath;
	UPROPERTY(BlueprintReadWrite)
		FString iconPath;
	UPROPERTY(BlueprintReadWrite)
		float weight;
	UPROPERTY(BlueprintReadWrite)
		float value;
	UPROPERTY(BlueprintReadWrite)
		int32 type;
	UPROPERTY(BlueprintReadWrite)
		FString lessonKey;
};

UCLASS()
class PNPV2_API UItemRepository : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:
		UFUNCTION(BlueprintCallable)
			static FOItemStruct GetItemStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOWeaponStruct GetWeaponStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOArmorStruct GetArmorStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOConsumableStruct GetConsumableStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOScrollStruct GetScrollStruct(FString key);
};
