// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "MyPawn_GhostCar.generated.h"

UCLASS()
class AVERAGEPEOPLERACING_API AMyPawn_GhostCar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn_GhostCar();
	UStaticMeshComponent* PawnMesh;
	
	UPROPERTY(EditAnywhere, Category = Positions)
	FVector3d Position1; 
	UPROPERTY(EditAnywhere, Category = Positions)
	FVector3d Position2; 
	UPROPERTY(EditAnywhere, Category = Positions)
	FVector3d Position3; 
	UPROPERTY(EditAnywhere, Category = Positions)
	FVector3d Position4; 

	
	int CurrentPositionNumber = 0; 

	void GoToPosition(FVector3d Position, FVector Location);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
