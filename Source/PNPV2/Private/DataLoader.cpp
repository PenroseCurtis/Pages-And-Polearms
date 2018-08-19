// Fill out your copyright notice in the Description page of Project Settings.

#include "DataLoader.h"
#include "JsonObjectConverter.h"
#include "PaperSprite.h"


FString UDataLoader::GetMessage() {
	FJsonObject JSON;
	return "Henlo";
}

FOStatBlockStruct UDataLoader::GetStatBlock(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Dojo/JSON/StatBlocks.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	GLog->Log("Json String:");
	GLog->Log(jsonString);

	TSharedPtr<FJsonValue> jsonValues;  //= MakeShareable(new FJsonValue());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOStatBlockStruct statBlockOut = FOStatBlockStruct();
		FOStatBlockStruct * statBlockPtr = &statBlockOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		//Getting various properties
		int64 flags = 0;
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				GLog->Log("You have found the correct thingy!");
				if (FJsonObjectConverter::JsonObjectToUStruct<FOStatBlockStruct>(jsonObject, statBlockPtr, flags, flags))
				{
					GLog->Log("Converstion succeded");
					return statBlockOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOStatBlockStruct();
				}
				/*statBlockOut.strength = jsonObject->GetNumberField("Strength");
				statBlockOut.dexterity = jsonObject->GetNumberField("Dexterity");
				statBlockOut.constitution= jsonObject->GetNumberField("Constitution");
				statBlockOut.intelligence = jsonObject->GetNumberField("Intelligence");
				statBlockOut.wisdom = jsonObject->GetNumberField("Wisdom");
				statBlockOut.spirit = jsonObject->GetNumberField("Spirit");
				statBlockOut.vitality = jsonObject->GetNumberField("Vitatlity");
				statBlockOut.vitalityTotal= jsonObject->GetNumberField("VitatlityTotal");
				statBlockOut.vitalityRegeneration= jsonObject->GetNumberField("VitatlityRegeneration");
				statBlockOut.stamina = jsonObject->GetNumberField("Stamina");
				statBlockOut.staminaTotal= jsonObject->GetNumberField("StaminaTotal");
				statBlockOut.staminaRegeneration= jsonObject->GetNumberField("StaminaRegeneration");
				statBlockOut.mana= jsonObject->GetNumberField("Mana");
				statBlockOut.manaTotal = jsonObject->GetNumberField("ManaTotal");
				statBlockOut.manaRegeneration = jsonObject->GetNumberField("ManaRegeneration"); */
			}

		}
	}
	else
	{
		GLog->Log("couldn't deserialize");
		return FOStatBlockStruct();
	}
	return FOStatBlockStruct();
	
}

FOItemStruct UDataLoader::GetItemStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Dojo/JSON/ItemStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	GLog->Log("Json String:");
	GLog->Log(jsonString);

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
					GLog->Log("Converstion succeded");
					return itemStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOItemStruct();
				}
				/*itemStructOut.description = jsonObject->GetStringField("Description");
				itemStructOut.weight = jsonObject->GetNumberField("Weight");
				itemStructOut.opacity = jsonObject->GetNumberField("Opacity");
				itemStructOut.iconPath = jsonObject->GetStringField("IconPath");
				itemStructOut.spritePath = jsonObject->GetStringField("SpritePath");
				itemStructOut.key = key;
				TArray<TSharedPtr<FJsonValue>> enchantmentKeys = jsonObject->GetArrayField("Enchantments");
				for (int32 i = 0; i < enchantmentKeys.Num(); i++)
				{
					itemStructOut.enchantments.Add(*enchantmentKeys[i]->AsString());
				}*/
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

FOWeaponStruct UDataLoader::GetWeaponStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Dojo/JSON/WeaponStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	GLog->Log("Json String:");
	GLog->Log(jsonString);

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
					GLog->Log("Converstion succeded");
					return weaponStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOWeaponStruct();
				}
				//weaponStructOut.accuracy = jsonObject->GetNumberField("Accuracy");
				//weaponStructOut.baseItemKey = jsonObject->GetStringField("BaseItemKey");
				//weaponStructOut.bludgeon = jsonObject->GetNumberField("Bludgeon");
				//weaponStructOut.contact = jsonObject->GetNumberField("Contact");
				//weaponStructOut.damage = jsonObject->GetNumberField("Damage");
				//weaponStructOut.piercing = jsonObject->GetNumberField("Piercing");
				//TArray<TSharedPtr<FJsonValue>> stanceKeys = jsonObject->GetArrayField("Stances");
				//for (int32 i = 0; i < stanceKeys.Num(); i++)
				//{
				//	weaponStructOut.stances.Add(*stanceKeys[i]->AsString());
				//}
				//TArray<TSharedPtr<FJsonValue>> attackKeys = jsonObject->GetArrayField("SpecialAttacks");
				//for (int32 i = 0; i < attackKeys.Num(); i++)
				//{
				//	weaponStructOut.specialAttacks.Add(*attackKeys[i]->AsString());
				//}
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

FOArmorStruct UDataLoader::GetArmorStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Dojo/JSON/ArmorStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	GLog->Log("Json String:");
	GLog->Log(jsonString);

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
					GLog->Log("Converstion succeded");
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

FOStanceStruct UDataLoader::GetStanceStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Dojo/JSON/StanceStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	GLog->Log("Json String:");
	GLog->Log(jsonString);

	TSharedPtr<FJsonValue> jsonValues;  
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOStanceStruct stanceStructOut = FOStanceStruct();
		FOStanceStruct * stanceStructPtr = &stanceStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				int64 flags = 0;
				if (FJsonObjectConverter::JsonObjectToUStruct<FOStanceStruct>(jsonObject, stanceStructPtr, flags, flags))
				{
					GLog->Log("Converstion succeded");
					return stanceStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOStanceStruct();
				}
			}
		}
	}
	else
	{
		GLog->Log("Serialization Failed");
		return FOStanceStruct();
	}
	return FOStanceStruct();
}

FOAttackStruct UDataLoader::GetAttackStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Dojo/JSON/AttackStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	GLog->Log("Json String:");
	GLog->Log(jsonString);

	TSharedPtr<FJsonValue> jsonValues;  //= MakeShareable(new FJsonValue());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOAttackStruct attackStructOut = FOAttackStruct();
		FOAttackStruct * attackStructPtr = &attackStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				int64 flags = 0;
				if (FJsonObjectConverter::JsonObjectToUStruct<FOAttackStruct>(jsonObject, attackStructPtr, flags, flags))
				{
					GLog->Log("Converstion succeded");
					return attackStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOAttackStruct();
				}
			}

		}
	}
	else
	{
		GLog->Log("Serialization Failed");
		return FOAttackStruct();
	}
	return FOAttackStruct();
}

FOPageStatStruct UDataLoader::GetPageStatStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Dojo/JSON/PageStatStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	GLog->Log("Json String:");
	GLog->Log(jsonString);

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
					GLog->Log("Converstion succeded");
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

FOEnchantmentStruct UDataLoader::GetEnchantmentStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Dojo/JSON/EnchantmentStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
	GLog->Log("Json String:");
	GLog->Log(jsonString);

	TSharedPtr<FJsonValue> jsonValues;  //= MakeShareable(new FJsonValue());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOEnchantmentStruct enchantmentStructOut = FOEnchantmentStruct();
		FOEnchantmentStruct * enchantmentStructPtr= &enchantmentStructOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				int64 flags = 0;
				if (FJsonObjectConverter::JsonObjectToUStruct<FOEnchantmentStruct>(jsonObject, enchantmentStructPtr, flags, flags))
				{
					GLog->Log("Converstion succeded");
					return enchantmentStructOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FOEnchantmentStruct();
				}
			}
			
		}
	}
	else
	{
		GLog->Log("Serialization Failed");
		return FOEnchantmentStruct();
	}
	return FOEnchantmentStruct();
}

UTexture2D* UDataLoader::MyLoadTextureFromPath(const FString& Path)
{
	if (Path.IsEmpty()) return NULL;

	//FString PathToLoad = FPaths::ProjectContentDir() + "Dojo/Textures/" + Path;
	FString PathToLoad = "/Game/Dojo/Textures/"+Path;
	//UTexture2D* tmpTexture = StaticLoadObject(UTexture2D::StaticClass(), NULL, PathToLoad)
	//LoadObjFromPath<UTexture2D>(PathToLoad);
	GLog->Log(PathToLoad);
	return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(PathToLoad)));
}

UPaperSprite* UDataLoader::MyLoadSpriteFromPath(const FString& Path)
{
	if (Path.IsEmpty()) return NULL;

	FString PathToLoad =  "/Game/Dojo/Textures/" + Path;
	//UTexture2D* tmpTexture = StaticLoadObject(UTexture2D::StaticClass(), NULL, PathToLoad)
	//LoadObjFromPath<UTexture2D>(PathToLoad);

	return Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, *(PathToLoad)));
} 	
void UDataLoader::LoadAssetsForCooking()
{
	UClass* Ut2D = TSubclassOf<class UTexture2D>();
	UObjectLibrary* ObjectLibrary = UObjectLibrary::CreateLibrary(Ut2D, false, GIsEditor);
	ObjectLibrary->AddToRoot();
	ObjectLibrary->LoadAssetDataFromPath(TEXT("/Game/Dojo/Textures"));
	ObjectLibrary->LoadAssetsFromAssetData();
}