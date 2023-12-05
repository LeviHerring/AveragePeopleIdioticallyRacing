// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystem.h"
#include "Components/StaticMeshComponent.h"
#include "MyActor_FireExtinguisher.generated.h"

class UNiagaraSystem; 

UCLASS()
class AVERAGEPEOPLERACING_API AMyActor_FireExtinguisher : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor_FireExtinguisher();
	UStaticMeshComponent* ActorMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Particles"); 
	UNiagaraSystem* NS_Explosion; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
