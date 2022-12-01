// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_04_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	// CurrentScore 초기화를 위한 생성자
	AMyGameStateBase();

	// CurrentScore 변수를 설정
	UFUNCTION()
		void SetScore(int32 NewScore);

	// 게터(Getter)
	UFUNCTION()
		int32 GetScore();

private:
	UPROPERTY()
		int32 CurrentScore;
};
