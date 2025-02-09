// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/SKCharacterBase.h"

ASKCharacterBase::ASKCharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ASKCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
