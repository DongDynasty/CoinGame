// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hazard.generated.h"

class UStaticMeshComponent;
class UPrimitiveComponent;
struct FHitResult;

UCLASS()
class COINGAME_API AHazard : public AActor
{
	GENERATED_BODY()

public:
	AHazard();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHazardHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse,
		const FHitResult& Hit);

private:
	//hazard mesh component
	UPROPERTY(VisibleAnywhere, Category = "Hazard")
	UStaticMeshComponent* HazardMesh;

	UPROPERTY(EditAnywhere, Category = "Hazard")
	float HorizontalLaunchSpeed = 1000.0f;

	UPROPERTY(EditAnywhere, Category = "Hazard")
	float VerticalLaunchSpeed = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Hazard")
	float LaunchCooldown = 0.5f;

	float LastLaunchTime = -100000.0f;
};
