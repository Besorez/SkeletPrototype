// Fill out your copyright notice in the Description page of Project Settings.

#include "SPCharacter.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "SP/AI/SPAIController.h"

ASPCharacter::ASPCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = ASPAIController::StaticClass();
}

void ASPCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* ASPCharacter::GetAbilitySystemComponent() const
{
	if (const IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(GetPlayerState()))
	{
		return ASI->GetAbilitySystemComponent();
	}

	return nullptr;
}
