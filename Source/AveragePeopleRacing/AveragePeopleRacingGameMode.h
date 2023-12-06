// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "AveragePeopleRacingGameMode.generated.h"

UCLASS(minimalapi)
class AAveragePeopleRacingGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAveragePeopleRacingGameMode();

protected:

	virtual void BeginPlay() override; 
};



