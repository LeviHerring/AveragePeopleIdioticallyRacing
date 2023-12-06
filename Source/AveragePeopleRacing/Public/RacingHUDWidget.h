// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RacingHUDWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class URacingHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetLaps(float CurrentLaps, float MaxLaps);


	void SetTimer(float Seconds, float Minutes);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* SecondsText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* MinutesText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* CurrentLapsText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* MaxLapsText;

protected:

	
	
};
