// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AttributeSet_Health.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class SP_API UAttributeSet_Health : public UAttributeSet
{
	GENERATED_BODY()

	UPROPERTY()
	FGameplayAttributeData Health;
	
	UPROPERTY()
	FGameplayAttributeData MaxHealth;

	ATTRIBUTE_ACCESSORS(UAttributeSet_Health, Health)
	ATTRIBUTE_ACCESSORS(UAttributeSet_Health, MaxHealth)
};
