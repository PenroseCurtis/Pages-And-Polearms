// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueRepository.h"
#include "JsonObjectConverter.h"

FDialogueTree UDialogueRepository::GetDialogueTree(FString key)
{
	const FString JsonFilePath = FPaths::ProjectContentDir() + "/JSON/DialogueTrees.json";
	FString jsonString;
	FFileHelper::LoadFileToString(jsonString, *JsonFilePath);

	TSharedPtr<FJsonValue> jsonValues;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(jsonString);

	if (FJsonSerializer::Deserialize(JsonReader, jsonValues) && jsonValues.IsValid())
	{
		FDialogueTree dialogueTreeOut = FDialogueTree();
		FDialogueTree  * dialogueTreePtr = &dialogueTreeOut;
		TArray<TSharedPtr<FJsonValue>> jsonArray = jsonValues->AsArray();
		int64 flags = 0;
		//Getting various properties
		for (int32 i = 0; i < jsonArray.Num(); i++)
		{
			TSharedRef<FJsonObject> jsonObject = jsonArray[i]->AsObject().ToSharedRef();
			if (jsonObject->GetStringField("key") == key)
			{
				if (FJsonObjectConverter::JsonObjectToUStruct<FDialogueTree>(jsonObject, dialogueTreePtr, flags, flags))
				{
					return dialogueTreeOut;
				}
				else {
					GLog->Log("Converting To Struct Failed");
					return FDialogueTree();
				}

				return dialogueTreeOut;
			}
		}
	}
	else {
		GLog->Log("couldn't deserialize");
		return FDialogueTree();
	}
	return FDialogueTree();
}