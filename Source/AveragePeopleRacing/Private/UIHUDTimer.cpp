// Fill out your copyright notice in the Description page of Project Settings.


#include "UIHUDTimer.h"

// Sets default values
AUIHUDTimer::AUIHUDTimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUIHUDTimer::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AUIHUDTimer::CountDown, 1.f, true, 0.0f); 
	
}

// Called every frame
void AUIHUDTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUIHUDTimer::CountDown()
{
	if (Seconds < 0)
	{
		Seconds = Seconds + 1;
	}
	if (Seconds == 60)
	{
		Minutes++;
		Seconds = 0;
		
	}
	
}

