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
		strength = 10;
		dexterity = 10;
		constitution = 10;
		intelligence = 10;
		wisdom = 10;
		spirit = 10;
		vitality = 10;
		vitalityTotal = 10;
		vitalityRegeneration = 1;
		stamina = 10;
		staminaTotal = 10;
		staminaRegeneration = 1;
		mana = 10;
		manaTotal = 10;
		manaRegeneration = 1;
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
		TArray<FString> actions;
	UPROPERTY(BlueprintReadWrite)
		int32 equipableType;
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
		actions = { "drop","examine" };
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
		FString name;
	UPROPERTY(BlueprintReadWrite)
		FString defaultStatBlockKey;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> stances;
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
		TArray<FString> actions;
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
		TArray<int32> targetTypes;
	UPROPERTY(BlueprintReadWrite)
		FString widgetKey;
	UPROPERTY(BlueprintReadWrite)
		int32 attackHeight;
	UPROPERTY(BlueprintReadWrite)
		int32 wieldType;
	UPROPERTY(BlueprintReadWrite)
		FString description;
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
		TArray<FString> attacks;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> mainHandWeaponTypes;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> offHandWeaponTypes;
	UPROPERTY(BlueprintReadWrite)
		float highGuard;
	UPROPERTY(BlueprintReadWrite)
		float midGuard;	
	UPROPERTY(BlueprintReadWrite)
		float lowGuard;
	UPROPERTY(BlueprintReadWrite)
		float accuracyModifier;
	UPROPERTY(BlueprintReadWrite)
		float damageModifier;
	UPROPERTY(BlueprintReadWrite)
		float piercingModifier;
	UPROPERTY(BlueprintReadWrite)
		float bludgeonModifier;
	UPROPERTY(BlueprintReadWrite)
		float contactModifier;
	UPROPERTY(BlueprintReadWrite)
		int32 guardType;
	UPROPERTY(BlueprintReadWrite)
		FString description;
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
		float piercing;
	UPROPERTY(BlueprintReadWrite)
		float bludgeon;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> stances;
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
		TArray<FString> actions;
	UPROPERTY(BlueprintReadWrite)
		int32 equipableType;
	UPROPERTY(BlueprintReadWrite)
		float layer;
	UPROPERTY(BlueprintReadWrite)
		TArray<int32> weaponTypes;
	FOWeaponStruct()
	{
		key = "Default";
		weight = 0.0;
		description = "Default object, perhaps something has run amok...";
		spritePath = "Default";
		iconPath = "Default";
		equipableType = 0;
		actions = { "drop","examine" };
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
		TArray<FString> actions;
	UPROPERTY(BlueprintReadWrite)
		int32 equipableType;
	UPROPERTY(BlueprintReadWrite)
		float layer;
	UPROPERTY(BlueprintReadWrite)
		bool wrapsAround;
	FOArmorStruct()
	{
		key = "Default";
		weight = 0.0;
		description = "Default object, perhaps something has run amok...";
		spritePath = "Default";
		iconPath = "Default";
		equipableType = 0;
		actions = { "drop","examine" };
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
		FString statKey;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> attacks;
	UPROPERTY(BlueprintReadWrite)
		bool isTemporary;
	UPROPERTY(BlueprintReadWrite)
		int32 duration;
	UPROPERTY(BlueprintReadWrite)
		FString description;
};

UCLASS()
class PNPV2_API UDataLoader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:
		UFUNCTION(BlueprintCallable)
		static FString GetMessage();
		UFUNCTION(BlueprintCallable)
			static FOStatBlockStruct GetStatBlock(FString key);
		UFUNCTION(BlueprintCallable)
			static FOItemStruct GetItemStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOWeaponStruct GetWeaponStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOArmorStruct GetArmorStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static FOStanceStruct GetStanceStruct(FString key);
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




