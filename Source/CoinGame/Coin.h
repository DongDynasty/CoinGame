// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

class UStaticMeshComponent;
class USceneComponent;

UCLASS()
class COINGAME_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Coin")
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(VisibleAnywhere, Category = "Coin")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, Category = "Coin")
	float RotationSpeed = 90.f;

	UPROPERTY(EditAnywhere, Category = "Coin")
	float BobHeight = 20.f;

	FVector StartLocation;
};
