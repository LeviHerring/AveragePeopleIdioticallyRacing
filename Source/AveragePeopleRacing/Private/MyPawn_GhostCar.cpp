// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn_GhostCar.h"

// Sets default values
AMyPawn_GhostCar::AMyPawn_GhostCar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));
	PawnMesh->SetStaticMesh(MeshRef.Object);

}



// Called when the game starts or when spawned
void AMyPawn_GhostCar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn_GhostCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector location = GetActorLocation();
	FVector PositionDifference;


}


// Called to bind functionality to input
void AMyPawn_GhostCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

