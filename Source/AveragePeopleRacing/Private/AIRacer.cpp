// Fill out your copyright notice in the Description page of Project Settings.


#include "AIRacer.h"

void AAIRacer::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);
	WPIndexCount = Waypoints.Num(); 
	GoToNextWayPoint();
}

void AAIRacer::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result); 

	if (bIsPathRandom)
	{
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AAIRacer::GoToRandomWayPoint, 3.0f, false);

	}
	else
	{
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AAIRacer::GoToNextWayPoint, 0.001f, false);
	}
}

ATargetPoint* AAIRacer::GetRandomWaypoint()
{
	auto index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Cast<ATargetPoint>(Waypoints[index]);
}

void AAIRacer::GoToRandomWayPoint()
{
	MoveToActor(GetRandomWaypoint());
}

void AAIRacer::GoToNextWayPoint()
{
	MoveToActor(Waypoints[currentWPIndex]);
	currentWPIndex++; 
	int Cycle = currentWPIndex % WPIndexCount;
	if (currentWPIndex >= WPIndexCount - 1)
	{
		currentWPIndex = 0; 
	}
}
