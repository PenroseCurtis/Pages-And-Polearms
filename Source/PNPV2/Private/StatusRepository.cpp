// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusRepository.h"
#include "JsonObjectConverter.h"

FOStatusStruct UStatusRepository::GetStatusStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/StatusStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);

	TSharedPtr<FJsonValue> jsonValues;  //= MakeShareable(new FJsonValue());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOStatusStruct statusStructOut = FOStatusStruct();
		FOStatusStruct * statusStructPtr = &statusStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				int64 flags = 0;
				if (FJsonObjectConverter::JsonObjectToUStruct<FOStatusStruct>(jsonObject, statusStructPtr, flags, flags))
				{
					return statusStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOStatusStruct();
				}
			}
		}
	}
	else
	{
		GLog->Log("Serialization Failed");
		return FOStatusStruct();
	}
	return FOStatusStruct();
}

