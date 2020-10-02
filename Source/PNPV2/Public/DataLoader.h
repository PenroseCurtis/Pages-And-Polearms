// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "json.h"
#include "Engine.h"
#include "PaperSprite.h"
#include "PaperFlipbook.h"
#include <unordered_map>
#include "DataLoader.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct FStanceLevel
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString stanceName;
	UPROPERTY(BlueprintReadWrite)
		int32 level;
};

USTRUCT(BlueprintType)
struct FActionCost
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString action;
	UPROPERTY(BlueprintReadWrite)
		int32 cost;

	FActionCost()
	{
		action = "";
		cost = 0;
	};

	FActionCost(FString anAction, int32 aCost)
	{
		action = anAction;
		cost = aCost;
	};
};

USTRUCT(BlueprintType)
struct FTransitionCost
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString stanceName;
	UPROPERTY(BlueprintReadWrite)
		int32 Cost;
};

USTRUCT(BlueprintType)
struct FOStatBlockStruct
{
	GENERATED_BODY()
	//GENERATED_USTRUCT_BODY()
	public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		int32 power;
	UPROPERTY(BlueprintReadWrite)
		int32 speed;
	UPROPERTY(BlueprintReadWrite)
		int32 guard;
	UPROPERTY(BlueprintReadWrite)
		float intelligence;
	UPROPERTY(BlueprintReadWrite)
		float wisdom;
	UPROPERTY(BlueprintReadWrite)
		float spirit;
	UPROPERTY(BlueprintReadWrite)
		int32 woundLimit;
	UPROPERTY(BlueprintReadWrite)
		float woundRegeneration;
	UPROPERTY(BlueprintReadWrite)
		float stamina;
	UPROPERTY(BlueprintReadWrite)
		float staminaTotal;
	UPROPERTY(BlueprintReadWrite)
		float staminaRegeneration;
	UPROPERTY(BlueprintReadWrite)
		float mana;
	UPROPERTY(BlueprintReadWrite)
		float manaTotal;
	UPROPERTY(BlueprintReadWrite)
		float manaRegeneration;
	UPROPERTY(BlueprintReadWrite)
		float opacity;
	UPROPERTY(BlueprintReadWrite)
		int32 reach;
	UPROPERTY(BlueprintReadWrite)
		int32 armorPenetrationBonus;
	UPROPERTY(BlueprintReadWrite)
		int32 woundingPotentialBonus;
	UPROPERTY(BlueprintReadWrite)
		int32 paddingBonus;
	UPROPERTY(BlueprintReadWrite)
		int32 excellentHitProtectionBonus;
	FOStatBlockStruct()
	{
		power = 0;
		speed = 0;
		guard = 0;
		intelligence = 0;
		wisdom = 0;
		spirit = 0;
		woundLimit = 0;
		woundRegeneration = 0;
		stamina = 0;
		staminaTotal = 0;
		staminaRegeneration = 0;
		mana = 0;
		manaTotal = 0;
		manaRegeneration = 0;
		armorPenetrationBonus = 0;
		woundingPotentialBonus = 0;
		paddingBonus = 0;
		excellentHitProtectionBonus = 0;
	}
};

USTRUCT(BlueprintType)
struct FWeaponStatBlock
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		int32 power;
	UPROPERTY(BlueprintReadWrite)
		int32 speed;
	UPROPERTY(BlueprintReadWrite)
		int32 woundingPotential;
	UPROPERTY(BlueprintReadWrite)
		int32 armorPenetration;
	UPROPERTY(BlueprintReadWrite)
		int32 guard;
};

USTRUCT(BlueprintType)
struct FArmorStatBlock
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		int32 padding;
	UPROPERTY(BlueprintReadWrite)
		int32 woundProtection;
};

USTRUCT(BlueprintType)
struct FOAttackStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString classKey;
	UPROPERTY(BlueprintReadWrite)
		int32 minTargets;
	UPROPERTY(BlueprintReadWrite)
		int32 maxTargets;
	UPROPERTY(BlueprintReadWrite)
		int32 minRange;
	UPROPERTY(BlueprintReadWrite)
		int32 maxRange;
	UPROPERTY(BlueprintReadWrite)
		int32 initiativeCost;
	UPROPERTY(BlueprintReadWrite)
		float staminaCost;
	UPROPERTY(BlueprintReadWrite)
		float manaCost;
	UPROPERTY(BlueprintReadWrite)
		bool selfTargettable;
	UPROPERTY(BlueprintReadWrite)
		int32 speed;
	UPROPERTY(BlueprintReadWrite)
		int32 armorPenetration;
	UPROPERTY(BlueprintReadWrite)
		int32 woundingPotential;
	UPROPERTY(BlueprintReadWrite)
		int32 power;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> mainHandRequirements;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> offHandRequirements;
	UPROPERTY(BlueprintReadWrite)
		bool bothRequirementsNeeded;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> targetTypes;
	UPROPERTY(BlueprintReadWrite)
		FString widgetKey;
	UPROPERTY(BlueprintReadWrite)
		int32 attackHeight;
	UPROPERTY(BlueprintReadWrite)
		int32 wieldType;
	UPROPERTY(BlueprintReadWrite)
		FString description;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> advantageTags;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> disadvantageTags;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> heightAdvantage;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> heightDisadvantage;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> weaponTypeAdvantage;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> weaponTypeDisadvantage;
	UPROPERTY(BlueprintReadWrite)
		FString stanceChange;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> possibleTriggerConditions;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> woundsInflicted;
	FOAttackStruct()
	{
		classKey = "Attack";
		minTargets = 1;
		maxTargets = 1;
		minRange = 1;
		maxRange = 1;
		selfTargettable = false;
		targetTypes = { 0 };
		staminaCost = 0;
		manaCost = 0;
	}
};

USTRUCT(BlueprintType)
struct FOStanceStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString classKey;
	UPROPERTY(BlueprintReadWrite)
		FString name;
	UPROPERTY(BlueprintReadWrite)
		int32 level;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> attacks;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> mainHandWeaponTypes;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> offHandWeaponTypes;
	UPROPERTY(BlueprintReadWrite)
		int32 power;
	UPROPERTY(BlueprintReadWrite)
		int32 speed;
	UPROPERTY(BlueprintReadWrite)
		int32 guard;
	UPROPERTY(BlueprintReadWrite)
		int32 guardHeight;
	UPROPERTY(BlueprintReadWrite)
		int32 gripType;
	UPROPERTY(BlueprintReadWrite)
		FString description;
	UPROPERTY(BlueprintReadWrite)
		TArray<FTransitionCost> transitions;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> tags;
};

USTRUCT(BlueprintType)
struct FCombatStateStats
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString Key;
	UPROPERTY(BlueprintReadWrite)
		FString ClassKey;
};

USTRUCT(BlueprintType)
struct FRoundStateStats
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString Key;
	UPROPERTY(BlueprintReadWrite)
		FString ClassKey;
	UPROPERTY(BlueprintReadWrite)
		bool allowRespawn;
};

USTRUCT(BlueprintType)
struct FMatchStateStats
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString Key;
	UPROPERTY(BlueprintReadWrite)
		FString ClassKey;
	UPROPERTY(BlueprintReadWrite)
		int32 numberOfRounds;
};

UCLASS()
class PNPV2_API UDataLoader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:
		UFUNCTION(BlueprintCallable)
			static FOStanceStruct GetStanceStruct(FString key, int32 level);
		UFUNCTION(BlueprintCallable)
			static FOAttackStruct GetAttackStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static UTexture2D* MyLoadTextureFromPath(const FString& Path);
		UFUNCTION(BlueprintCallable)
			static UPaperSprite* MyLoadSpriteFromPath(const FString& Path);
		UFUNCTION(BlueprintCallable)
			static UPaperFlipbook* LoadFlipbookFromPath(const FString& Path);
		UFUNCTION(BlueprintCallable)
			static void LoadAssetsForCooking();
		UFUNCTION(BlueprintCallable)
			static APlayerController* GetMainController(const UObject* WorldContextObject);
	private:
		static std::unordered_map<FString, UPaperFlipbook*> flipBookCache;
		const static int cacheSizeLimit = 20;
};




