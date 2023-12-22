// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor_Checkpoint.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values
AMyActor_Checkpoint::AMyActor_Checkpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f)); 
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox; 

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMyActor_Checkpoint::OnOverlapBegin); 
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AMyActor_Checkpoint::OnOverlapEnd); 
}



// Called when the game starts or when spawned
void AMyActor_Checkpoint::BeginPlay()
{
	Super::BeginPlay();
	PlayerCar = Cast<AMyPawn_PlayerCar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)); 
}

// Called every frame
void AMyActor_Checkpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor_Checkpoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("Overlap Begin Function Called"));
	if (PlayerCar && PlayerCar == OtherActor)
	{
		if (PlayerCar->currentCheckpoint+1 == CheckpointNumber)
		{
			PlayerCar->currentCheckpoint++;
		}
		
	}
}

void AMyActor_Checkpoint::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Overlap End Function Called"));
}