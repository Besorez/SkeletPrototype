// Fill out your copyright notice in the Description page of Project Settings.

#include "Actor/SKEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/SKAttributeSet.h"
#include "Components/SphereComponent.h"

ASKEffectActor::ASKEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ASKEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ASKEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ASKEffectActor::EndOverlap);
}

void ASKEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const USKAttributeSet* AuraAttributeSet = Cast<USKAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(USKAttributeSet::StaticClass()));
		USKAttributeSet* MutableSKAttributeSet = const_cast<USKAttributeSet*>(AuraAttributeSet);
		MutableSKAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void ASKEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

