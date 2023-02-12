// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "json.h"
#include "DataLoader.h"
#include "StatusRepository.generated.h"

/**
 * 
 */

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
		TArray<FString> attacks;
	UPROPERTY(BlueprintReadWrite)
		bool isTemporary;
	UPROPERTY(BlueprintReadWrite)
		int32 duration;
	UPROPERTY(BlueprintReadWrite)
		FString description;
};

UCLASS()
class PNPV2_API UStatusRepository : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable)
		static FOStatusStruct GetStatusStruct(FString key);
};
