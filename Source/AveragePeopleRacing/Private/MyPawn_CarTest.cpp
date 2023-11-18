// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn_CarTest.h"
#include "Components/InputComponent.h"
#include "EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyPawn_CarTest::AMyPawn_CarTest()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	PawnMesh->SetStaticMesh(MeshRef.Object);
}

void AMyPawn_CarTest::EnhancedInputMove(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Input Forward"));
	const FVector2D MoveVector = Value.Get<FVector2D>(); 
	const FRotator MoveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

	if (MoveVector.X > 0.05f || MoveVector.X < -0.05f)
	{
		const FVector DirectionVector = MoveRotation.RotateVector(FVector::RightVector);
		AddMovementInput(DirectionVector, MoveVector.X);

		if (MoveVector.X > 0.05f)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Input Forward" + DirectionVector.ToString()));
		}
	}
}

// Called when the game starts or when spawned
void AMyPawn_CarTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn_CarTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn_CarTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	APlayerController* PC = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
	Subsystem->AddMappingContext(InputMappingContext, 0);

	EnhancedInputComponent->BindAction(InputToMove, ETriggerEvent::Triggered, this, &AMyPawn_CarTest::EnhancedInputMove);

}

