// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HUD/SKHUD.h"

#include "UI/Widget/SKUserWidget.h"

void ASKHUD::BeginPlay()
{
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
