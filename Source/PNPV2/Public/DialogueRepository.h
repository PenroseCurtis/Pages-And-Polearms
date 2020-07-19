// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DialogueRepository.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FDialogueNodeStruct
{
	GENERATED_BODY() 
	UPROPERTY(BlueprintReadWrite)
		FString ID;
	UPROPERTY(BlueprintReadWrite)
		TArray<FString> linkIds;
};

USTRUCT(BlueprintType)
struct FDialogueLineStruct
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
		bool speaker;
	UPROPERTY(BlueprintReadWrite)
		FString text;
};

USTRUCT(BlueprintType)
struct FDialogueLinkStruct
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
		FString ID;
	UPROPERTY(BlueprintReadWrite)
		FString label;
	UPROPERTY(BlueprintReadWrite)
		TArray<FDialogueLineStruct> script;
	UPROPERTY(BlueprintReadWrite)
		FString nextNodeId;
	UPROPERTY(BlueprintReadWrite)
		FString action;
};

USTRUCT(BlueprintType)
struct FDialogueTree
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
		FString key;
	UPROPERTY(BlueprintReadWrite)
		FString startLinkId;
	UPROPERTY(BlueprintReadWrite)
		TArray<FDialogueNodeStruct> nodes;
	UPROPERTY(BlueprintReadWrite)
		TArray<FDialogueLinkStruct> links;
};

UCLASS()
class PNPV2_API UDialogueRepository : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public: 
		UFUNCTION(BlueprintCallable)
			static FDialogueTree GetDialogueTree(FString key);
};
