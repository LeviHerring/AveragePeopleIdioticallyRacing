// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class AVERAGEPEOPLERACING_API AMyAIController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override; 

	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override; 

	UFUNCTION()
	void GetSplinePoints();

private:
	USplineComponent* MySplineLinePath; 

	

	int myNumberOfSplinePoints; 
	
	
};
