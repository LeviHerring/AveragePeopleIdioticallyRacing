// Copyright Epic Games, Inc. All Rights Reserved.

#include "AveragePeopleRacingGameMode.h"
#include "AveragePeopleRacingCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AAveragePeopleRacingGameMode::AAveragePeopleRacingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AAveragePeopleRacingGameMode::BeginPlay()
{
	
}
