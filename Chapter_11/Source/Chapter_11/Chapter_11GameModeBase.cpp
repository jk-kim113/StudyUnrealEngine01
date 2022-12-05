// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter_11GameModeBase.h"
#include "Chapter_11.h"
#include "MessageLog.h"

void AChapter_11GameModeBase::BeginPlay()
{
	// Traditional Logging
	UE_LOG(LogTemp, Warning, TEXT("Message %d"), 1);

	// Our custom log type
	UE_LOG(LogCh11, Display, TEXT("A display message, log is working")); // shows in gray 
	UE_LOG(LogCh11, Warning, TEXT("A warning message"));
	UE_LOG(LogCh11, Error, TEXT("An error message "));

	// 11-02 - Core/Logging API - FMessageLog to write messages to the Message Log
	CreateLog(LoggerName);

	// Retrieve the Log by using the LoggerName. 
	FMessageLog logger(LoggerName);
	logger.Warning(FTEXT("A warning message from gamemode Actor"));
	logger.Info(FTEXT("Info to log"));
	logger.Warning(FTEXT("Warning text to log"));
	logger.Error(FTEXT("Error text to log"));

	TestHttp();
}

void AChapter_11GameModeBase::TestHttp()
{
	// Create the IHttpRequest object from your FHttpModule singleton interface.
	TSharedRef<IHttpRequest> http = FHttpModule::Get().CreateRequest();


	// Attach to the OnProcessRequestComplete() function to do something
	// when the HTTP request completes. We demonstrate 7 ways of attaching
	// to the delegate below

	FHttpRequestCompleteDelegate& delegate = http->OnProcessRequestComplete();
	// 1. BindLambda():
	delegate.BindLambda(
		[](FHttpRequestPtr request, FHttpResponsePtr response, bool success) -> void
	{
		UE_LOG(LogTemp, Warning, TEXT("Http response %d, %s"),
			response->GetResponseCode(), *response->GetContentAsString());
	});

	// 4. Set the web address to open by setting the URL of the HttpRequest.
	http->SetURL(TEXT("http://unrealengine.com")); // Do an HTTP request to any site you'd like.

	http->ProcessRequest();
}