// Fill out your copyright notice in the Description page of Project Settings.

#include "SPAIController.h"

ASPAIController::ASPAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	bWantsPlayerState = true;
}

void ASPAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASPAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

