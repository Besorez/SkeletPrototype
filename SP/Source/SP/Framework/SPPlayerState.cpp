// Fill out your copyright notice in the Description page of Project Settings.

#include "SPPlayerState.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "SP/Abilities/SPAbilitySystemComponent.h"
#include "SP/Attributes/AttributeSet_Health.h"

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

void ASPPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent
			->GetGameplayAttributeValueChangeDelegate(UAttributeSet_Health::GetHealthAttribute())
			.AddUObject(this, &ASPPlayerState::OnHealthChanged);
	}
}

void ASPPlayerState::OnPawnSetHandle(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
	AbilitySystemComponent->SetAvatarActor(NewPawn);
}

void ASPPlayerState::OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData) const
{
	if (AttributeChangeData.NewValue <= 0)
	{
		OnDeath.Broadcast();
	}
}

UAbilitySystemComponent* ASPPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
