// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SKCharacterBase.h"
#include "Interaction/EnemyInterface.h"

#include "SKEnemyCharacter.generated.h"

UCLASS()
class SP_API ASKEnemyCharacter : public ASKCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	ASKEnemyCharacter();

	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end Enemy Interface */

protected:
	virtual void BeginPlay() override;

};
