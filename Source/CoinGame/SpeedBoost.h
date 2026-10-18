// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "SpeedBoost.generated.h"

UCLASS()
class COINGAME_API ASpeedBoost : public APickupBase
{
	GENERATED_BODY()

protected:

	virtual void OnCollected(ACharacter* Collector) override;

private:

	UPROPERTY(EditAnywhere, Category = "SpeedBoost")
	float BoostMultiplier = 1.2f; //20% speed boost

	UPROPERTY(EditAnywhere, Category = "SpeedBoost")
	float BoostDuration = 5.0f; //5 seconds duration
};
