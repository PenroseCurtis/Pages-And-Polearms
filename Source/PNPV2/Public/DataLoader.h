// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "json.h"
#include "Engine.h"
#include "PaperSprite.h"
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
		manaRegeneration = 1;
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
		FString statBlockKey;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> stances;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> attacks;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> enchantments;
	UPROPERTY(BlueprintReadWrite)
		int level;
	UPROPERTY(BlueprintReadWrite)
		int experience;
	UPROPERTY(BlueprintReadWrite)
		FString defaultWeaponKey;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> actions;
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
		int32 mainHandRequirements;
	UPROPERTY(BlueprintReadWrite)
		int32 offHandRequirements;
	UPROPERTY(BlueprintReadWrite)
		int32 targetTypes;
	UPROPERTY(BlueprintReadWrite)
		FString widgetKey;
	FOAttackStruct()
	{
		minTargets = 1;
		maxTargets = 1;
		range = 1;
		accuracy = 1;
		damage = 1;
		contact = 1;
		bludgeon = 1;
		mainHandRequirements = 0;
		offHandRequirements = 0;
		targetTypes = 0;
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
		int32 mainHandWeaponTypes;
	UPROPERTY(BlueprintReadWrite)
		int32 offHandWeaponTypes;
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

};

USTRUCT(BlueprintType)
struct FOWeaponStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
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
		FString baseItemKey;
};

USTRUCT(BlueprintType)
struct FOArmorStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString baseItemKey;
	UPROPERTY(BlueprintReadWrite)
		float coverage;
	UPROPERTY(BlueprintReadWrite)
		float hardness;
	UPROPERTY(BlueprintReadWrite)
		float padding;
	UPROPERTY(BlueprintReadWrite)
		float deflection;
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
		TArray<FString> enchantments;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> actions;
};

USTRUCT(BlueprintType)
struct FOEnchantmentStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString statKey;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> attacks;
	UPROPERTY(BlueprintReadWrite)
		bool isTemporary;
	UPROPERTY(BlueprintReadWrite)
		int32 duration;
	UPROPERTY(BlueprintReadWrite)
		FString onNewRoundEffect;
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
			static FOEnchantmentStruct GetEnchantmentStruct(FString key);
		UFUNCTION(BlueprintCallable)
			static UTexture2D* MyLoadTextureFromPath(const FString& Path);
		UFUNCTION(BlueprintCallable)
			static UPaperSprite* MyLoadSpriteFromPath(const FString& Path);
		UFUNCTION(BlueprintCallable)
			static void LoadAssetsForCooking();
};




