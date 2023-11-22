// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn_PlayerCar.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Misc/App.h"
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
	
	const FVector2D MoveVector = Value.Get<FVector2D>();
	const FRotator MoveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	FVector Location = GetActorLocation();
	float PreviousSpeed = 0.01f; 
	//float Acceleration; 
	
		
		
		FVector DirectionVector = MoveRotation.RotateVector(FVector::ForwardVector);
		//AddMovementInput(DirectionVector, MoveVector.X);*/
		if (MoveVector.X > 0.05f || MoveVector.X < -0.05f)
		{
			if (MoveVector.X > 0.05f)
			{
				//if (CurrentSpeed < MaxSpeed)
				//{
				//	/*if (CurrentSpeed < 0)
				//	{
				//		CurrentSpeed = 0; 
				//	}*/
				//	//FApp::SetDeltaTime(0);
				//	/*DirectionVector.X = CurrentSpeed;
				//	Acceleration = CurrentSpeed / FApp::GetDeltaTime(); 
				//	Location += DirectionVector - (DirectionVector - 1);*/
				//	//CurrentSpeed = CurrentSpeed + ((CurrentSpeed - PreviousSpeed) / FApp::GetDeltaTime()) * FApp::GetDeltaTime(); 
				//	//PreviousSpeed = CurrentSpeed; 
				//	//DirectionVector.X = CurrentSpeed; 
				//	Location += DirectionVector; 
				//	
				//}
				//if (CurrentSpeed == MaxSpeed)
				//{
				//	//DirectionVector.X = MaxSpeed; 
				//	//Location += DirectionVector; 
				//}
				
				Location += DirectionVector; 
			}
			if (MoveVector.X < -0.05f)
			{
				Location -= DirectionVector;
			}
		}
		if (MoveVector.X == 0)
		{
			CurrentSpeed = 0;
		}
		
		if (MoveVector.Y > 0.05f || MoveVector.Y < -0.05f)
		{
			AddActorLocalRotation(FRotator(0, MoveVector.Y / 10, 0));

		}


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

	if (currentCheckpoint == MaxCheckpoints)
	{
		LapsDone++; 
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You win!" + currentCheckpoint)); 
		currentCheckpoint = 0; 
	}
	if (LapsDone == MaxLaps)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You win, Laps done!"));
	}

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

