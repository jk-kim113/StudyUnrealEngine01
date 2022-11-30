// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter_02GameModeBase.h"

void AChapter_02GameModeBase::BeginPlay()
{
	AChapter_02GameModeBase * gm = Cast<AChapter_02GameModeBase>(GetWorld()->GetAuthGameMode());

	if (gm)
	{
		UUserProfile* newobject = NewObject<UUserProfile>((UObject*)GetTransientPackage(), UUserProfile::StaticClass());

		if (newobject)
		{
			newobject->ConditionalBeginDestroy();
			newobject = nullptr;
		}
	}
}
