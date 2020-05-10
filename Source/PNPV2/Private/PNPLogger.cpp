// Fill out your copyright notice in the Description page of Project Settings.

#include "PNPLogger.h"
#include "PNPV2.h"


void UPNPLogger::LogMessage(ELogLevels logLevel, FString message)
{
	switch (logLevel) {
	case ELogLevels::Warning:
		UE_LOG(LogTemp, Warning, TEXT("%s"), *message);
		break;
	case ELogLevels::Log:
		UE_LOG(LogTemp, Log, TEXT("%s"), *message);
		break;
	case ELogLevels::Error:
		UE_LOG(LogTemp, Error, TEXT("%s"), *message);
		break;	
	case ELogLevels::Fatal:
		UE_LOG(LogTemp,Fatal , TEXT("%s"), *message);
		break;
	case ELogLevels::Display:
		UE_LOG(LogTemp, Display, TEXT("%s"), *message);
		break;
	}
}

void UPNPLogger::LogAIMessage(ELogLevels logLevel, FString message)
{
	switch (logLevel) {
	case ELogLevels::Warning:
		UE_LOG(AILog, Warning, TEXT("%s"), *message);
		break;
	case ELogLevels::Log:
		UE_LOG(AILog, Log, TEXT("%s"), *message);
		break;
	case ELogLevels::Error:
		UE_LOG(AILog, Error, TEXT("%s"), *message);
		break;
	case ELogLevels::Fatal:
		UE_LOG(AILog, Fatal, TEXT("%s"), *message);
		break;
	case ELogLevels::Display:
		UE_LOG(AILog, Display, TEXT("%s"), *message);
		break;
	}
}

void UPNPLogger::LogMultiplayerMessage(ELogLevels logLevel, FString message)
{
	switch (logLevel) {
	case ELogLevels::Warning:
		UE_LOG(MultiPlayerLog, Warning, TEXT("%s"), *message);
		break;
	case ELogLevels::Log:
		UE_LOG(MultiPlayerLog, Log, TEXT("%s"), *message);
		break;
	case ELogLevels::Error:
		UE_LOG(MultiPlayerLog, Error, TEXT("%s"), *message);
		break;
	case ELogLevels::Fatal:
		UE_LOG(MultiPlayerLog, Fatal, TEXT("%s"), *message);
		break;
	case ELogLevels::Display:
		UE_LOG(MultiPlayerLog, Display, TEXT("%s"), *message);
		break;
	}
}

void UPNPLogger::LogTestMessage(ELogLevels logLevel, FString message)
{
	switch (logLevel) {
	case ELogLevels::Warning:
		UE_LOG(TestLog, Warning, TEXT("%s"), *message);
		break;
	case ELogLevels::Log:
		UE_LOG(TestLog, Log, TEXT("%s"), *message);
		break;
	case ELogLevels::Error:
		UE_LOG(TestLog, Error, TEXT("%s"), *message);
		break;
	case ELogLevels::Fatal:
		UE_LOG(TestLog, Fatal, TEXT("%s"), *message);
		break;
	case ELogLevels::Display:
		UE_LOG(TestLog, Display, TEXT("%s"), *message);
		break;
	}
}

void UPNPLogger::LogVisualUpdateMessage(ELogLevels logLevel, FString message)
{
	switch (logLevel) {
	case ELogLevels::Warning:
		UE_LOG(VisualUpdateLog, Warning, TEXT("%s"), *message);
		break;
	case ELogLevels::Log:
		UE_LOG(VisualUpdateLog, Log, TEXT("%s"), *message);
		break;
	case ELogLevels::Error:
		UE_LOG(VisualUpdateLog, Error, TEXT("%s"), *message);
		break;
	case ELogLevels::Fatal:
		UE_LOG(VisualUpdateLog, Fatal, TEXT("%s"), *message);
		break;
	case ELogLevels::Display:
		UE_LOG(VisualUpdateLog, Display, TEXT("%s"), *message);
		break;
	}
}



