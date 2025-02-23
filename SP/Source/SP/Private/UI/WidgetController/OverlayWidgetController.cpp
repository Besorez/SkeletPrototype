// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/SKAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USKAttributeSet* SKAttributeSet = CastChecked<USKAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(SKAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(SKAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(SKAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(SKAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const USKAttributeSet* SKAttributeSet = CastChecked<USKAttributeSet>(AttributeSet);

	FOnGameplayAttributeValueChange& GameplayAttributeValueHealthChangedDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate((SKAttributeSet->GetHealthAttribute()));
	GameplayAttributeValueHealthChangedDelegate.AddUObject(this, &UOverlayWidgetController::HealthChanged);

	FOnGameplayAttributeValueChange& GameplayAttributeValueMaxHealthChangedDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SKAttributeSet->GetMaxHealthAttribute());
	GameplayAttributeValueMaxHealthChangedDelegate.AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	FOnGameplayAttributeValueChange& GameplayAttributeValueManaChangedDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate((SKAttributeSet->GetManaAttribute()));
	GameplayAttributeValueManaChangedDelegate.AddUObject(this, &UOverlayWidgetController::ManaChanged);

	FOnGameplayAttributeValueChange& GameplayAttributeValueMaxManaChangedDelegate = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SKAttributeSet->GetMaxManaAttribute());
	GameplayAttributeValueMaxManaChangedDelegate.AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
