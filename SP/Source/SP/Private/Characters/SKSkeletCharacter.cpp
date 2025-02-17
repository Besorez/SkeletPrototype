// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/SKSkeletCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/SKPlayerState.h"

ASKSkeletCharacter::ASKSkeletCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ASKSkeletCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void ASKSkeletCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void ASKSkeletCharacter::InitAbilityActorInfo()
{
	ASKPlayerState* SKPlayerState = GetPlayerState<ASKPlayerState>();
	check(SKPlayerState);

	SKPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SKPlayerState, this);

	AbilitySystemComponent = SKPlayerState->GetAbilitySystemComponent();
	AttributeSet = SKPlayerState->GetAttributeSet();
}