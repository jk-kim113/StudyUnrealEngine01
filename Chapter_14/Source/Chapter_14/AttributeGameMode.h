// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SlateBasics.h"
#include "AttributeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_14_API AAttributeGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	TSharedPtr<SVerticalBox> Widget;
	FText GetButtonLabel() const;

public:
	virtual void BeginPlay() override;
};
