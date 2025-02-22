// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/SKWidgetController.h"

void USKWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void USKWidgetController::BroadcastInitialValues()
{
}

void USKWidgetController::BindCallbacksToDependencies()
{
}
