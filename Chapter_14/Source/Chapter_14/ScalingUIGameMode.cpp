// Fill out your copyright notice in the Description page of Project Settings.

#include "ScalingUIGameMode.h"
#include "CustomHUDPlayerController.h"

AScalingUIGameMode::AScalingUIGameMode() : AGameModeBase()
{
	PlayerControllerClass = ACustomHUDPlayerController::StaticClass();
}
