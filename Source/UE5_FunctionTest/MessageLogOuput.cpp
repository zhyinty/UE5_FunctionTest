// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageLogOuput.h"

#include "MessageLogModule.h"

#define LOCTEXT_NAMESPACE "MessageLogOutput"

// Sets default values
AMessageLogOuput::AMessageLogOuput()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MessageLogCategoryName = "testLog";
	
	FMessageLogModule& MessageLogModule = FModuleManager::LoadModuleChecked<FMessageLogModule>("MessageLog");
	MessageLogModule.RegisterLogListing(MessageLogCategoryName, LOCTEXT("messageLogOutputLabel", "自定义LOG输出"));
}

// Called when the game starts or when spawned
void AMessageLogOuput::BeginPlay()
{
	Super::BeginPlay();
	messageLog = MakeShareable(new FMessageLog(MessageLogCategoryName));
	
}

// Called every frame
void AMessageLogOuput::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// messageLog.Open(EMessageSeverity::Error, true);
	messageLog.Get()->Message(EMessageSeverity::Error, FText::FromString("Error Message"));
	messageLog.Get()->Message(EMessageSeverity::Warning, FText::FromString("Warning Message"));
	messageLog.Get()->Message(EMessageSeverity::PerformanceWarning, FText::FromString("PerformanceWarning Message"));
	messageLog.Get()->Message(EMessageSeverity::Info, FText::FromString("Info"));
}

