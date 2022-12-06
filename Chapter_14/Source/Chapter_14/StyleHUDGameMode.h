// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SlateBasics.h"
#include "StyleHUDGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_14_API AStyleHUDGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	TSharedPtr<SVerticalBox> Widget;

public:
	virtual void BeginPlay() override;
};
