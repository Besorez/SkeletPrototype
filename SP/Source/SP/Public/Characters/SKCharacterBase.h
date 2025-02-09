// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SKCharacterBase.generated.h"

UCLASS(Abstract)
class SP_API ASKCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ASKCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
