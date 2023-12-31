// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TimerManager.h"
#include "Components/StaticMeshComponent.h"
#include "InputAction.h"
#include "MyPawn_PlayerCar.generated.h"

UCLASS()
class AVERAGEPEOPLERACING_API AMyPawn_PlayerCar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn_PlayerCar();
	UPROPERTY(EditAnywhere); 
	UStaticMeshComponent* PawnMesh; 
	void PawnMove(const FInputActionValue& Value);
	void PawnJump(const FInputActionValue& Value);
	UPROPERTY(EditAnywhere, Category = "Input");
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, Category = "Input");
	UInputMappingContext* MappingContext; 
	UPROPERTY(EditAnywhere, Category = "Input");
	UInputAction* MoveActionDrift;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Checkpoints)
	int MaxCheckpoints; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Checkpoints)
	int currentCheckpoint; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Checkpoints)
	int LapsDone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Checkpoints)
	int MaxLaps; 
	//Input variables
	
	float CurrentSpeed;
	float MaxSpeed = 30.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test)
	bool isDrifting = false; 
	
	 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void CountDown();

	UPROPERTY(BlueprintReadWrite)
	int Minutes = 0;
	UPROPERTY(BlueprintReadWrite)
	int Seconds = 0;

	int winCooldown = 5; 

	UPROPERTY(BlueprintReadWrite)
	bool hasWon = false;

	FTimerHandle winTimerHandle; 
	
	void YouWinFunction(); 

	void WinCountdown(); 

};
