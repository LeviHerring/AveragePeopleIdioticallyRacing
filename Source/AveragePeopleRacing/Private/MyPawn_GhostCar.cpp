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

	if (location != Position1 && location != Position2 && location != Position3 && location != Position4)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("In if"));

		/*switch(CurrentPositionNumber)
		{
			case 0:
				PositionDifference = Position1 - location;
				location += PositionDifference;
				break;
			case 1:
				PositionDifference = Position2 - location;
				location += PositionDifference;
				break;
			case 2:
				PositionDifference = Position3 - location;
				location += PositionDifference;
				break;
			case 3:
				PositionDifference = Position4 - location;
				location += PositionDifference;
				break;


		}*/
		if (CurrentPositionNumber == 0)
		{
			PositionDifference = Position1 - location;
			location += PositionDifference;
		}
	}
	if (location == Position1)
	{
		CurrentPositionNumber = 1; 
	}
	if (location == Position2)
	{
		CurrentPositionNumber = 2;
	}
	if (location == Position3)
	{
		CurrentPositionNumber = 3;
	}
	if (location == Position4)
	{
		CurrentPositionNumber = 4;
	}


}

void AMyPawn_GhostCar::GoToPosition(FVector3d Position, FVector Location)
{
	
	
}

// Called to bind functionality to input
void AMyPawn_GhostCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

