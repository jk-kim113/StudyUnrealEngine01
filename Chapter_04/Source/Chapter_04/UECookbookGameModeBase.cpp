// Fill out your copyright notice in the Description page of Project Settings.

#include "UECookbookGameModeBase.h"
#include "MyFirstActor.h"

void AUECookbookGameModeBase::BeginPlay()
{
	// �� �Լ��� �θ� Ŭ���� ������ ȣ��
	Super::BeginPlay();

	// 10�ʰ� ȭ�鿡 ������ �޽��� ���
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Spawning"));

	// AMyFirstActor Ŭ������ �ν��Ͻ���
	// �⺻ ��ġ�� ��ȯ
	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnLocation);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AUECookbookGameModeBase::DestroyActorFunction, 10);
}

void AUECookbookGameModeBase::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		// ������ �޽����� 10�� ���� ǥ���Ѵ�
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Destroyed"));
		SpawnedActor->Destroy();
	}
}
