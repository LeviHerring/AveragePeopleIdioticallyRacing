// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

const int HEIGHT = 250; 
const int MAXPOINTS = 5000;
FVector pathPointLocation[MAXPOINTS]; 
int splinePointer = 1; 
int totalSplinePoints = 0;

void AMyAIController::BeginPlay()
{
	Super::BeginPlay(); 

	GetSplinePoints();
	MoveToLocation(pathPointLocation[splinePointer]); 
}

void AMyAIController::GetSplinePoints()
{
	for (TObjectIterator<USplineComponent> SplineComponent; SplineComponent; ++SplineComponent)
	{
		int numberOfSplinePoints = SplineComponent->GetNumberOfSplinePoints(); 
		float totalLength = SplineComponent->GetSplineLength(); 

		float currentLength = 0;
		int itemSampling = 5; 
		int sampleLength = 400; 

		FString splineName = SplineComponent->GetName(); 
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("spline found splineName: %s"), *splineName));  

		if (splineName == "PathSpline")
		{
			int splinePointCount = 0;
			while (currentLength < totalLength)
			{
				FTransform splinePointTransform = SplineComponent->GetTransformAtDistanceAlongSpline(currentLength, ESplineCoordinateSpace::World);

				currentLength += sampleLength;

				pathPointLocation[splinePointCount] = splinePointTransform.GetLocation(); 
				splinePointCount++; 
			}
			totalSplinePoints = splinePointCount; 
		}
	}
}

void AMyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result); 


	splinePointer++;
	if (splinePointer >= totalSplinePoints)
	{
		splinePointer = 1;
	}
	MoveToLocation(pathPointLocation[splinePointer]); 
}


