// Fill out your copyright notice in the Description page of Project Settings.

#include "SPPlayerState.h"
#include "AbilitySystemComponent.h"
#include "SP/Abilities/SPAbilitySystemComponent.h"

ASPPlayerState::ASPPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USPAbilitySystemComponent>("AbilitySystemComponent");
}

void ASPPlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	OnPawnSet.AddDynamic(this, &ASPPlayerState::OnPawnSetHandle);
}

void ASPPlayerState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	OnPawnSet.RemoveDynamic(this, &ASPPlayerState::OnPawnSetHandle);

	Super::EndPlay(EndPlayReason);
}

void ASPPlayerState::OnPawnSetHandle(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
	AbilitySystemComponent->SetAvatarActor(NewPawn);
}

UAbilitySystemComponent* ASPPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
