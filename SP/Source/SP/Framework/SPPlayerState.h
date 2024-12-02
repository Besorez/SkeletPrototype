// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "SPPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SP_API ASPPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASPPlayerState();
	virtual void PostInitializeComponents() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
private:
	UFUNCTION()
	void OnPawnSetHandle(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);
	
#pragma region ASC

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

#pragma endregion
};
