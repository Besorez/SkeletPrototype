// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/PlayerState.h"
#include "SPPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

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
	virtual void BeginPlay() override;

#pragma region Settings

protected:
#pragma endregion

private:
	UFUNCTION()
	void OnPawnSetHandle(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);


#pragma region ASC

public:
	// When health gets <= 0
	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeath;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

private:
	void OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData) const;
#pragma endregion
};
