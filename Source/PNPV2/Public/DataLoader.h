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
		int32 Cost;
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
struct FCombatStats
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		float accuracy;
	UPROPERTY(BlueprintReadWrite)
		float avoidance;
	UPROPERTY(BlueprintReadWrite)
		float bludgeon;
	UPROPERTY(BlueprintReadWrite)
		float contact;
	UPROPERTY(BlueprintReadWrite)
		float damage;
	UPROPERTY(BlueprintReadWrite)
		float guard;
	UPROPERTY(BlueprintReadWrite)
		float piercing;
	FCombatStats() {
		accuracy = 0;
		avoidance = 0;
		bludgeon = 0;
		contact = 0;
		damage = 0;
		guard = 0;
		piercing = 0;
	}
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
		float strength;
	UPROPERTY(BlueprintReadWrite)
		float dexterity;
	UPROPERTY(BlueprintReadWrite)
		float constitution;
	UPROPERTY(BlueprintReadWrite)
		float intelligence;
	UPROPERTY(BlueprintReadWrite)
		float wisdom;
	UPROPERTY(BlueprintReadWrite)
		float spirit;
	UPROPERTY(BlueprintReadWrite)
		float vitality;
	UPROPERTY(BlueprintReadWrite)
		float vitalityTotal;
	UPROPERTY(BlueprintReadWrite)
		float vitalityRegeneration;
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
	FOStatBlockStruct()
	{
		strength = 0;
		dexterity = 0;
		constitution = 0;
		intelligence = 0;
		wisdom = 0;
		spirit = 0;
		vitality = 0;
		vitalityTotal = 0;
		vitalityRegeneration = 0;
		stamina = 0;
		staminaTotal = 0;
		staminaRegeneration = 0;
		mana = 0;
		manaTotal = 0;
		manaRegeneration = 0;
	}
};

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
struct FOPageStatStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
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
		FOItemStruct mainHandWeapon;
	UPROPERTY(BlueprintReadWrite)
		FOItemStruct offHandWeapon;
	UPROPERTY(BlueprintReadWrite)
		FOItemStruct mainHandRing;
	UPROPERTY(BlueprintReadWrite)
		FOItemStruct offHandRing;
	UPROPERTY(BlueprintReadWrite)
		TArray<FOItemStruct> equippedItems;
	UPROPERTY(BlueprintReadWrite)
		TArray<FOItemStruct> inventory;
	UPROPERTY(BlueprintReadWrite)
		FOStatBlockStruct statBlock;
	FOPageStatStruct()
	{
		name = "Clem";
	}
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
		int32 range;
	UPROPERTY(BlueprintReadWrite)
		int32 initiativeCost;
	UPROPERTY(BlueprintReadWrite)
		float staminaCost;
	UPROPERTY(BlueprintReadWrite)
		float vitalityCost;
	UPROPERTY(BlueprintReadWrite)
		float manaCost;
	UPROPERTY(BlueprintReadWrite)
		bool selfTargettable;
	UPROPERTY(BlueprintReadWrite)
		float accuracy;
	UPROPERTY(BlueprintReadWrite)
		float piercing;
	UPROPERTY(BlueprintReadWrite)
		float damage;
	UPROPERTY(BlueprintReadWrite)
		float contact;
	UPROPERTY(BlueprintReadWrite)
		float bludgeon;
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
	FOAttackStruct()
	{
		minTargets = 1;
		maxTargets = 1;
		range = 1;
		accuracy = 1;
		damage = 1;
		contact = 1;
		bludgeon = 1;
		mainHandRequirements = { 0 };
		offHandRequirements = { 0 };
		targetTypes = { 0 };
		widgetKey = "null";
		vitalityCost = 0;
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
		FCombatStats combatStats;
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
struct FOStatusStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString classKey;
	UPROPERTY(BlueprintReadWrite)
		FString iconKey;
	UPROPERTY(BlueprintReadWrite)
		FOStatBlockStruct statChange;
	UPROPERTY(BlueprintReadWrite)
		FCombatStats combatStatChange;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> attacks;
	UPROPERTY(BlueprintReadWrite)
		bool isTemporary;
	UPROPERTY(BlueprintReadWrite)
		int32 duration;
	UPROPERTY(BlueprintReadWrite)
		FString description;
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
		static FString GetMessage();
		UFUNCTION(BlueprintCallable)
			static FCombatStats GetCombatStats(FString key);
		UFUNCTION(BlueprintCallable)
			static FOStatBlockStruct GetStatBlock(FString key);
		UFUNCTION(BlueprintCallable)
			static FOItemStruct GetItemStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOWeaponStruct GetWeaponStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOArmorStruct GetArmorStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOStanceStruct GetStanceStruct(FString key, int32 level);
		UFUNCTION(BlueprintCallable)
			static FOAttackStruct GetAttackStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOPageStatStruct GetPageStatStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOStatusStruct GetStatusStruct(FString key);
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




