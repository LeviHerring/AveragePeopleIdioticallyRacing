// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn_PlayerCar.h"
#include "EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"

// Sets default values
AMyPawn_PlayerCar::AMyPawn_PlayerCar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
	PawnMesh->SetStaticMesh(MeshRef.Object); 
}

void AMyPawn_PlayerCar::PawnMove(const FInputActionValue& Value)
{
	const float TopSpeed = 5.0f; 
	float Speed = 0.0f; 
    const FVector2D MoveValue = Value.Get<FVector2D>();
    const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);
	const FVector2D MoveAxis = Value.Get<FVector2D>(); 
//	const FRotator moveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f); 
//	const FVector directionVector = moveRotation.RotateVector(FVector::RightVector);
//	AddMovementInput(directionVector, MoveAxis.X);
////If the movement is in the forward or backward direction.MoveAxis.Y > 0.05f || MoveAxis.Y < -0.05f)
//	const FVector directionVector = moveRotation.RotateVector(FVector::ForwardVector);
//	AddMovementInput(directionVector, MoveAxis.Y);
	FVector Location = GetActorLocation();
	if (MoveAxis.X == 1)
	{
		if (Speed < TopSpeed)
		{
			while (Speed < TopSpeed)
			{
				Speed += 0.0000001; 
				Location.X += MoveAxis.X + Speed;
				//set timer or something 
			}
		}
		else 
		{
			Speed = 5.0f;
			Location.X += MoveAxis.X + Speed; 
		}
	}
	if (MoveAxis.Y == -1)
	{
		Speed = 0.0f; 
		if (Speed > -TopSpeed)
		{
			while (Speed > -TopSpeed)
			{
				Speed -= 0.0000001;
				Location.Y += MoveAxis.Y + Speed;

			}
		}
		else
		{
			Speed = -5.0f;
			Location.Y += MoveAxis.Y + Speed;
		}
	}
	Location.X += MoveAxis.X;
	Location.Y += MoveAxis.Y;
	SetActorLocation(Location); 

}


// Called when the game starts or when spawned
void AMyPawn_PlayerCar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn_PlayerCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn_PlayerCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	APlayerController* PC = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()); 
	Subsystem->AddMappingContext(MappingContext, 0);

	UEnhancedInputComponent* PawnInputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent); 

	PawnInputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPawn_PlayerCar::PawnMove);
}

