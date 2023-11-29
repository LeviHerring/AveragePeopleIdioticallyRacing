// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCar.h"

// Sets default values
AEnemyCar::AEnemyCar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyCar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

