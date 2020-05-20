// Fill out your copyright notice in the Description page of Project Settings.

#include "DataLoader.h"
#include "JsonObjectConverter.h"
#include "PaperSprite.h"
#include "PaperFlipBook.h"

FString UDataLoader::GetMessage() {
	FJsonObject JSON;
	return "Henlo";
}

FOStatBlockStruct UDataLoader::GetStatBlock(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/StatBlocks.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);

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
				if (FJsonObjectConverter::JsonObjectToUStruct<FOStatBlockStruct>(jsonObject, statBlockPtr, flags, flags))
				{
					return statBlockOut;
				}
				else {
					GLog->Log("Converting to struct failed");
					return FOStatBlockStruct();
				}
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

FOStanceStruct UDataLoader::GetStanceStruct(FString key, int32 level)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/StanceStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);


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
			if (jsonObject->GetStringField("key") == key && jsonObject->GetIntegerField("level") == level)
			{
				int64 flags = 0;
				if (FJsonObjectConverter::JsonObjectToUStruct<FOStanceStruct>(jsonObject, stanceStructPtr, flags, flags))
				{
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
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/AttackStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);
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

FOStatusStruct UDataLoader::GetStatusStruct(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/StatusStructs.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);

	TSharedPtr<FJsonValue> jsonValues;  //= MakeShareable(new FJsonValue());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FOStatusStruct statusStructOut = FOStatusStruct();
		FOStatusStruct * statusStructPtr= &statusStructOut;
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

FCombatStats UDataLoader::GetCombatStats(FString key) {
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/CombatStats.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);

	TSharedPtr<FJsonValue> jsonValues;  //= MakeShareable(new FJsonValue());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FCombatStats combatStatsOut = FCombatStats();
		FCombatStats * combatStatsPtr = &combatStatsOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				int64 flags = 0;
				if (FJsonObjectConverter::JsonObjectToUStruct<FCombatStats>(jsonObject, combatStatsPtr, flags, flags))
				{
					return combatStatsOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FCombatStats();
				}
			}

		}
	}
	else
	{
		GLog->Log("Serialization Failed");
		return FCombatStats();
	}
	return FCombatStats();
}

UTexture2D* UDataLoader::MyLoadTextureFromPath(const FString& Path)
{
	if (Path.IsEmpty()) return NULL;

	//FString PathToLoad = FPaths::ProjectContentDir() + "Dojo/Textures/" + Path;
	FString PathToLoad = "/Game/Textures/"+Path;
	return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(PathToLoad)));
}

UPaperSprite* UDataLoader::MyLoadSpriteFromPath(const FString& Path)
{
	if (Path.IsEmpty()) return NULL;

	FString PathToLoad =  "/Game/Sprites/" + Path;
	

	return Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, *(PathToLoad)));
} 	

UPaperFlipbook* UDataLoader::LoadFlipbookFromPath(const FString& Path)
{
	const TCHAR* Empty = TEXT("");
	const TCHAR* Low = TEXT("Low");
	const TCHAR* Mid = TEXT("Mid");
	const TCHAR* High = TEXT("High");
	const TCHAR* OneH = TEXT("OneH");
	const TCHAR* TwoH = TEXT("TwoH");
	const TCHAR* Idle = TEXT("Idle");
	const TCHAR* Walk = TEXT("Walk");

	if (Path.IsEmpty()) return NULL;

	FString PathToLoad = "/Game/FlipBooks/" + Path;

	//UPaperFlipbook* flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
	
	//if (flipBook) return flipBook;
	
	const FString LeftPath = PathToLoad.Left(PathToLoad.Find("|")); //Left half of the path is unique to the asset
	//Ex: Helmet/Default_Helmet/Helmet

	FString RightPath = PathToLoad.RightChop(PathToLoad.Find("|")+1); //Right half of the path is the naming convention
	//Ex: FrontLowOneHIdle

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	PathToLoad = LeftPath + RightPath; 
	//FString filePath = FString("/Game/FlipBooks/Character/Page/PageSideWalk.uasset");
	//FString filePath2 = FString("C:/User/Curtis/Documents/Hoi.txt");
	/*if (PlatformFile.FileExists(*filePath2))
	{
		GLog->Log("Henlo my dude");
	}
	if (PlatformFile.FileExists(*filePath))
	{
		GLog->Log("Ya turkey");
	}
	if (FPaths::FileExists(*filePath2))
	{
		GLog->Log("Ya goober");
	}*/
		//flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
	//if (PlatformFile.FileExists(*PathToLoad))
	//{
	UPaperFlipbook* flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
	if (flipBook) return flipBook;
	//}
	//If the base path doesn't exist, try removing left and right from the right part of the path
	RightPath = RightPath.Replace(TEXT("Right"), Empty, ESearchCase::IgnoreCase);
	RightPath = RightPath.Replace(TEXT("Left"), Empty, ESearchCase::IgnoreCase);
	PathToLoad = LeftPath + RightPath;
	/*if (PlatformFile.FileExists(*PathToLoad))
	{
		flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
		if (flipBook) return flipBook;
	}*/
	flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));

	if (flipBook) return flipBook;

	//If that path doesn't exist, try removing Low, Mid and High From the right part of the path
	RightPath = RightPath.Replace(Low, Empty, ESearchCase::IgnoreCase);
	RightPath = RightPath.Replace(Mid, Empty, ESearchCase::IgnoreCase);
	RightPath = RightPath.Replace(High, Empty, ESearchCase::IgnoreCase);
	PathToLoad = LeftPath + RightPath;

	/*if (PlatformFile.FileExists(*PathToLoad))
	{
		flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
		if (flipBook) return flipBook;
	}*/
	flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
	if (flipBook) return flipBook;

	//If that still doesn't work, try removing one handed and two handed part of the path
	RightPath = RightPath.Replace(OneH, Empty, ESearchCase::IgnoreCase);
	RightPath = RightPath.Replace(TwoH, Empty, ESearchCase::IgnoreCase);
	PathToLoad = LeftPath + RightPath;
	
	/*if (PlatformFile.FileExists(*PathToLoad))
	{
		flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
		if (flipBook) return flipBook;
	}*/
	flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
	if (flipBook) return flipBook;

	//Still? Okay, try removing Walk and Idle. This will be for assets that don't change when you move
	RightPath = RightPath.Replace(Idle, Empty, ESearchCase::IgnoreCase);
	RightPath = RightPath.Replace(Walk, Empty, ESearchCase::IgnoreCase);
	PathToLoad = LeftPath + RightPath;

	/*if (PlatformFile.FileExists(*PathToLoad))
	{
		flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
		if (flipBook) return flipBook;
	}*/
	flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
	//GLog->Log(PathToLoad+" is what you are finally laoding lmao");
	return flipBook;
	//Give up after this point and just return whatever shows up. 
}

void UDataLoader::LoadAssetsForCooking()
{
	UClass* Ut2D = TSubclassOf<class UTexture2D>();
	UObjectLibrary* ObjectLibrary = UObjectLibrary::CreateLibrary(Ut2D, false, GIsEditor);
	ObjectLibrary->AddToRoot();
	ObjectLibrary->LoadAssetDataFromPath(TEXT("/Game/Textures"));
	ObjectLibrary->LoadAssetsFromAssetData();
}

APlayerController* UDataLoader::GetMainController(const UObject* WorldContextObject)
{
	// Get world context (containing player controllers)
	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		// Loop on player controllers
		for (FConstPlayerControllerIterator Iterator = World->GetPlayerControllerIterator(); Iterator; ++Iterator)
		{
			// Get player controller from iterator
			APlayerController* PlayerController = Iterator->Get();

			// Get local player if exist
			ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();

			// If it's local and id is 0, it's the main controller
			if (LocalPlayer != nullptr && LocalPlayer->GetControllerId() == 0)
			{
				return PlayerController;
			}
		}
	}

	// Not found
	return nullptr;
}
