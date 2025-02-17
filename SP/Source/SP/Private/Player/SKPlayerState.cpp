// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/SKPlayerState.h"

#include "AbilitySystem/SKAbilitySystemComponentBase.h"
#include "AbilitySystem/SKAttributeSet.h"

ASKPlayerState::ASKPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USKAbilitySystemComponentBase>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<USKAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* ASKPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
