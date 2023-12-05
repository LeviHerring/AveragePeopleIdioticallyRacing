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
	float PreviousSpeed = 1.0f; 
	
	
	//float Acceleration; 
	
		
		
		FVector DirectionVector = GetActorForwardVector();
			
		//AddMovementInput(DirectionVector, MoveVector.X);*/
		if (MoveVector.X > 0.05f || MoveVector.X < -0.05f)
		{
				
				FApp::SetFixedDeltaTime(0); 
				//FApp::SetDeltaTime(0); 
				if (MoveVector.X > 0.05f)
				{
					if (CurrentSpeed < MaxSpeed)
					{
						if (CurrentSpeed <= 0)
						{
							CurrentSpeed = 1; 
						}
						
							DirectionVector = DirectionVector * CurrentSpeed;
							Location += DirectionVector;
							CurrentSpeed += 0.1f;
						
						//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("In if"));

						//CurrentSpeed *= FApp::GetDeltaTime();

						//CurrentSpeed = CurrentSpeed + ((CurrentSpeed - PreviousSpeed) / FApp::GetDeltaTime()) * FApp::GetDeltaTime();
						/*CurrentSpeed = CurrentSpeed + ((CurrentSpeed - PreviousSpeed) / 0.01f) * 0.01f;
						PreviousSpeed = CurrentSpeed;*/
						//DirectionVector = DirectionVector * CurrentSpeed * FApp::GetDeltaTime();
						//CurrentSpeed = CurrentSpeed + 0.6f * FApp::GetDeltaTime(); 

						FString TheFloatStr = FString::SanitizeFloat(CurrentSpeed);
						GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, *TheFloatStr);

					}
				}
				
				
				if (CurrentSpeed >= MaxSpeed)
				{
					Location += DirectionVector; 
					DirectionVector = DirectionVector * MaxSpeed; 
				}
				
				//Location += DirectionVector; 

			if (MoveVector.X < -0.05f)
			{
				if (CurrentSpeed > -MaxSpeed)
				{
					if (CurrentSpeed >= 0)
					{
						CurrentSpeed = -1;
					}
					CurrentSpeed -= 0.01f;
					DirectionVector = DirectionVector * -CurrentSpeed;
				}
					
				
				Location -= DirectionVector * 2;
			}
		}
		if (MoveVector.X == 0)
		{
			CurrentSpeed *= 0;
			if (CurrentSpeed > 0)
			{
				DirectionVector = DirectionVector * CurrentSpeed;
				Location += DirectionVector;
				CurrentSpeed -= 0.1; 

			}
			if (CurrentSpeed < 0)
			{
				DirectionVector = DirectionVector * CurrentSpeed;
				Location -= DirectionVector * 2;
				CurrentSpeed += 0.1;
			}
			
			DirectionVector = DirectionVector - 1;
		}
		
		if (MoveVector.Y > 0.05f || MoveVector.Y < -0.05f)
		{
			//AddActorLocalRotation(FRotator(0, MoveVector.Y / 10, 0));
			if (isDrifting)
			{
				AddActorWorldRotation(FRotator(0, MoveVector.Y, 0));
			}
				
			AddActorWorldRotation(FRotator(0, MoveVector.Y / 5, 0));
			

		}


		SetActorLocation(Location, true); 

}

void AMyPawn_PlayerCar::PawnJump(const FInputActionValue& Value)
{
	const FVector2D driftValue = Value.Get<FVector2D>(); 

	if (driftValue.X == 1)
	{
		isDrifting = true;
	}
	else
	{
		isDrifting = false; 
	}
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
	PawnInputComp->BindAction(MoveActionDrift, ETriggerEvent::Triggered, this, &AMyPawn_PlayerCar::PawnJump);
}

