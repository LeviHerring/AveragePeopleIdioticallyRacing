// Fill out your copyright notice in the Description page of Project Settings.


#include "Particles/ParticleSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MyActor_FireExtinguisher.h"


// Sets default values
AMyActor_FireExtinguisher::AMyActor_FireExtinguisher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/fire_extinguisher_(1)/defaultMaterial.defaultMaterial'"));
	ActorMesh->SetStaticMesh(MeshRef.Object);

}

// Called when the game starts or when spawned
void AMyActor_FireExtinguisher::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AMyActor_FireExtinguisher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector ParticleLocation = ActorMesh->GetComponentLocation(); 

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NS_Explosion, ParticleLocation); 
	
}

