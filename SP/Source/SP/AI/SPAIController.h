// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SPAIController.generated.h"

UCLASS(Blueprintable)
class SP_API ASPAIController : public AAIController
{
	GENERATED_BODY()

public:
	ASPAIController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
