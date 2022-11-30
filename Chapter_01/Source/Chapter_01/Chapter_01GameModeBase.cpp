// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter_01GameModeBase.h"

void AChapter_01GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// 기본적인 UE_LOG 메시지
	UE_LOG(LogTemp, Warning, TEXT("Some warning message"));
	// 인자를 포함하는 UE_LOG 메시지
	int intVar = 5;
	float floatVar = 3.7f;
	FString fstringVar = "an fstring variable";
	UE_LOG(LogTemp, Warning, TEXT("Text, %d %f %s"), intVar, floatVar, *fstringVar);

	FString name = "Tim";
	int32 mana = 450;
	FString string = FString::Printf(TEXT("Name = %s Mana = %d"), *name, mana);

	TArray<FStringFormatArg> args;
	args.Add(FStringFormatArg(name));
	args.Add(FStringFormatArg(mana));
	string = FString::Format(TEXT("Format() - Name = {0} Mana = {1}"), args);
	UE_LOG(LogTemp, Warning, TEXT("Your string: %s"), *string);

}