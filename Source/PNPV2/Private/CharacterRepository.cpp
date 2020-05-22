// Fill out your copyright notice in the Description page of Project Settings.

#include "JsonObjectConverter.h"
#include "CharacterRepository.h"

FOPageStatStruct UCharacterRepository::GetPageStatStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/PageStatStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);

	TSharedPtr<FJsonValue> jsonValues;  //= MakeShareable(new FJsonValue());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOPageStatStruct pageStatStructOut = FOPageStatStruct();
		FOPageStatStruct * pageStatStructPtr = &pageStatStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				int64 flags = 0;
				if (FJsonObjectConverter::JsonObjectToUStruct<FOPageStatStruct>(jsonObject, pageStatStructPtr, flags, flags))
				{
					return pageStatStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOPageStatStruct();
				}
			}
		}
	}
	else
	{
		GLog->Log("Serialization Failed");
		return FOPageStatStruct();
	}
	return FOPageStatStruct();
}

