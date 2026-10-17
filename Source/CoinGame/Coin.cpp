// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "Engine/Engine.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Coin spawned: %s"), *GetName()));
	}

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Warning, TEXT("Coin spawned: %s"), *GetName());
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.f, RotationSpeed * DeltaTime, 0.f));
	SetActorLocation(StartLocation + FVector(0.f, 0.f, FMath::Sin(GetGameTimeSinceCreation()) * BobHeight));
}