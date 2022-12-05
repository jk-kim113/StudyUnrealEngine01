// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCh11, Log, All);

#define LOCTEXT_NAMESPACE "Chapter11Namespace"
#define FTEXT(x) LOCTEXT(x, x) 

extern FName LoggerName;

void CreateLog(FName logName);