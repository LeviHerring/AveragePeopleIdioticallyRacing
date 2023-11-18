// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "InputAction.h"
#include "MyPawn_CarTest.generated.h"

UCLASS()
class AVERAGEPEOPLERACING_API AMyPawn_CarTest : public APawn
{
	GENERATED_BODY()

public:


	// Sets default values for this pawn's properties
	AMyPawn_CarTest();
	UStaticMeshComponent* PawnMesh; 
	void EnhancedInputMove(const FInputActionValue& Value); 

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	UInputAction* InputToMove; 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
