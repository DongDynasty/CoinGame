// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class ACharacter;
class UPrimitiveComponent;
struct FHitResult;

UCLASS(Abstract)
class COINGAME_API APickupBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnCollected(ACharacter* Collector);

	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	UStaticMeshComponent* PickupMesh;
};