// Fill out your copyright notice in the Description page of Project Settings.

#include "SPCharacter.h"

#include "SP/Attributes/AttributeSet_Health.h"

ASPCharacter::ASPCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
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
	return AbilitySystemComponent;
}
