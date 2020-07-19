// Fill out your copyright notice in the Description page of Project Settings.


#include "MapStateRepository.h"
#include "JsonObjectConverter.h"

FInitialLevelState UMapStateRepository::getInitialLevelState(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/InitialLevelStates.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);

	TSharedPtr<FJsonValue> jsonValues;  //= MakeShareable(new FJsonValue());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{

		FInitialLevelState initialLevelStateOut = FInitialLevelState();
		FInitialLevelState* initialLevelStateOutPtr = &initialLevelStateOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();

		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				int64 flags = 0;
				if (FJsonObjectConverter::JsonObjectToUStruct<FInitialLevelState>(jsonObject, initialLevelStateOutPtr, flags, flags))
				{
					return initialLevelStateOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FInitialLevelState();
				}
			}
		}
	}
	else
	{
		GLog->Log("Serialization Failed");
		return FInitialLevelState();
	}
	return FInitialLevelState();
};