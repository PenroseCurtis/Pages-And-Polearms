// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemRepository.h"
#include "JsonObjectConverter.h"

FOItemStruct UItemRepository::GetItemStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/ItemStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	//GLog->Log("Json String:");
	//GLog->Log(jsonString);

	TSharedPtr<FJsonValue> jsonValues;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOItemStruct itemStructOut = FOItemStruct();
		FOItemStruct  * itemStructPtr = &itemStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		int64 flags = 0;
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				if (FJsonObjectConverter::JsonObjectToUStruct<FOItemStruct>(jsonObject, itemStructPtr, flags, flags))
				{
					return itemStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOItemStruct();
				}

				return itemStructOut;
			}
		}
	}
	else {
		GLog->Log("couldn't deserialize");
		return FOItemStruct();
	}
	return FOItemStruct();
}

FOWeaponStruct UItemRepository::GetWeaponStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/WeaponStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	//GLog->Log("Json String:");
	//GLog->Log(jsonString);

	TSharedPtr<FJsonValue> jsonValues;  //= MakeShareable(new FJsonValue());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{

		FOWeaponStruct weaponStructOut = FOWeaponStruct();
		FOWeaponStruct* weaponStructPtr = &weaponStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();

		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				int64 flags = 0;
				//weaponStructOut.statKey = key;
				if (FJsonObjectConverter::JsonObjectToUStruct<FOWeaponStruct>(jsonObject, weaponStructPtr, flags, flags))
				{

					return weaponStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOWeaponStruct();
				}
			}
		}
	}
	else
	{
		GLog->Log("Serialization Failed");
		return FOWeaponStruct();
	}
	return FOWeaponStruct();
}

FOArmorStruct UItemRepository::GetArmorStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/ArmorStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	TSharedPtr<FJsonValue> jsonValues;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOArmorStruct armorStructOut = FOArmorStruct();
		FOArmorStruct * armorStructPtr = &armorStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				int64 flags = 0;
				if (FJsonObjectConverter::JsonObjectToUStruct<FOArmorStruct>(jsonObject, armorStructPtr, flags, flags))
				{
					return armorStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOArmorStruct();
				}
			}

		}
	}
	else
	{
		GLog->Log("Serialization Failed");
		return FOArmorStruct();
	}
	return FOArmorStruct();
}

FOConsumableStruct UItemRepository::GetConsumableStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/ConsumableStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);

	TSharedPtr<FJsonValue> jsonValues;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOConsumableStruct consumableStructOut = FOConsumableStruct();
		FOConsumableStruct  * consumableStructPtr = &consumableStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		int64 flags = 0;
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				if (FJsonObjectConverter::JsonObjectToUStruct<FOConsumableStruct>(jsonObject, consumableStructPtr, flags, flags))
				{
					return consumableStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOConsumableStruct();
				}

				return consumableStructOut;
			}
		}
	}
	else {
		GLog->Log("couldn't deserialize");
		return FOConsumableStruct();
	}
	return FOConsumableStruct();
}

FOScrollStruct UItemRepository::GetScrollStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/ScrollStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);

	TSharedPtr<FJsonValue> jsonValues;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOScrollStruct scrollStructOut = FOScrollStruct();
		FOScrollStruct  * scrollStructPtr = &scrollStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		int64 flags = 0;
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				if (FJsonObjectConverter::JsonObjectToUStruct<FOScrollStruct>(jsonObject, scrollStructPtr, flags, flags))
				{
					return scrollStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOScrollStruct();
				}

				return scrollStructOut;
			}
		}
	}
	else {
		GLog->Log("couldn't deserialize");
		return FOScrollStruct();
	}
	return FOScrollStruct();
}