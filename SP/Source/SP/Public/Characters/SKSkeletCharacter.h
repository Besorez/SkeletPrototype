// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SKCharacterBase.h"
#include "SKSkeletCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SP_API ASKSkeletCharacter : public ASKCharacterBase
{
	GENERATED_BODY()
	
public:
	ASKSkeletCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();

};
