// Fill out your copyright notice in the Description page of Project Settings.

#include "DataLoader.h"
#include "JsonObjectConverter.h"
#include "PaperSprite.h"
#include "PaperFlipBook.h"

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
	if (Path.IsEmpty()) return NULL;

	const TCHAR* Empty = TEXT("");

	const TArray<FStringArray> keysToRemove = {
		FStringArray({TEXT("Left"), TEXT("Right")}),
		FStringArray({TEXT("Low"), TEXT("Mid"), TEXT("High")}),
		FStringArray({TEXT("OneH"), TEXT("TwoH")}),
		FStringArray({TEXT("Idle"), TEXT("Walk"), TEXT("Attack")})
	};

	const TCHAR* LoadPreFix = TEXT("/Game/FlipBooks/");

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString ContentDirectory = FPaths::ProjectContentDir();
	FString TestPrefix = ContentDirectory + TEXT("FlipBooks/");
	
	const FString LeftPath = Path.Left(Path.Find("|")); //Left half of the path is unique to the asset
	//Ex: Helmet/Default_Helmet/Helmet

	FString RightPath = Path.RightChop(Path.Find("|")+1); //Right half of the path is the naming convention
	//Ex: FrontLowOneHIdle
	
	UPaperFlipbook* flipBook = NULL;
	FString PathToLoad;
	FString PathToTest = TestPrefix + LeftPath + RightPath + TEXT(".uasset");

	if (PlatformFile.FileExists(*PathToTest)) {
		PathToLoad = LoadPreFix + LeftPath + RightPath;
		flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
		if (flipBook) return flipBook;
	}

	for (int i = 0; i < keysToRemove.Num(); i++) {
		for (int j = 0; j < keysToRemove[i].array.Num(); j++) {
			RightPath = RightPath.Replace(*keysToRemove[i].array[j], Empty, ESearchCase::IgnoreCase);
		}
		PathToTest = TestPrefix + LeftPath + RightPath + TEXT(".uasset");

		if (PlatformFile.FileExists(*PathToTest)) {
			PathToLoad = LoadPreFix + LeftPath + RightPath;
			flipBook = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, *(PathToLoad)));
			if (flipBook) return flipBook;
		}
	}

	return NULL;
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
