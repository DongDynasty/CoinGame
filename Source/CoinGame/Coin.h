// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "Coin.generated.h"

UCLASS()
class COINGAME_API ACoin : public APickupBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//override function
	virtual void OnCollected(ACharacter* Collector) override;

private:
	UPROPERTY(EditAnywhere, Category = "Coin")
	float RotationSpeed = 90.f;

	UPROPERTY(EditAnywhere, Category = "Coin")
	float BobHeight = 20.f;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Coin")
	int32 CoinValue = 1;
};
