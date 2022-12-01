// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Warrior.generated.h"

UCLASS()
class CHAPTER_04_API AWarrior : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWarrior();

	// 액터 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
		FString Name;

	// Name 속성을 갖는 메세지 반환
	UFUNCTION(BlueprintCallable, Category = Properties)
		FString ToString();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
