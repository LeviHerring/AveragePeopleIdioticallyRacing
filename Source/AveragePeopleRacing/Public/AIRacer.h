// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIRacer.generated.h"

/**
 * 
 */
UCLASS()
class AVERAGEPEOPLERACING_API AAIRacer : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

	UPROPERTY()
	TArray<AActor*> Waypoints; 

	FTimerHandle TimerHandle; 

	UFUNCTION()
	ATargetPoint* GetRandomWaypoint(); 

	UFUNCTION()
	void GoToRandomWayPoint();

	UFUNCTION()
	void GoToNextWayPoint();

	int currentWPIndex = 0;
	int WPIndexCount = 0; 

private:

public:
	UPROPERTY(EditAnywhere)
	bool bIsPathRandom = false; 
	
};
