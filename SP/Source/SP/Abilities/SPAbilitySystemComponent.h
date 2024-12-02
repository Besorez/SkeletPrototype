﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SPAbilitySystemComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SP_API USPAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	USPAbilitySystemComponent();
};
