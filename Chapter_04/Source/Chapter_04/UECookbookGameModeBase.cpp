// Fill out your copyright notice in the Description page of Project Settings.

#include "UECookbookGameModeBase.h"
#include "MyFirstActor.h"

void AUECookbookGameModeBase::BeginPlay()
{
	// 이 함수의 부모 클래스 버전을 호출
	Super::BeginPlay();

	// 10초간 화면에 빨간색 메시지 출력
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Spawning"));

	// AMyFirstActor 클래스의 인스턴스를
	// 기본 위치에 소환
	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnLocation);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AUECookbookGameModeBase::DestroyActorFunction, 10);
}

void AUECookbookGameModeBase::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		// 빨간색 메시지를 10초 동안 표시한다
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Destroyed"));
		SpawnedActor->Destroy();
	}
}
