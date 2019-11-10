// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PNPLogger.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ELogLevels : uint8
{
	Log,
	Display,
	Warning,
	Error,
	Fatal
};

UCLASS()
class PNPV2_API UPNPLogger : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		static void LogMessage(ELogLevels logLevel, FString message);

	UFUNCTION(BlueprintCallable)
		static void LogAIMessage(ELogLevels logLevel, FString message);

	UFUNCTION(BlueprintCallable)
		static void LogMultiplayerMessage(ELogLevels logLevel, FString message);
};
