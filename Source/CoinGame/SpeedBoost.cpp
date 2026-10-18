// Fill out your copyright notice in the Description page of Project Settings.

#include "SpeedBoost.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/Engine.h"

void ASpeedBoost::OnCollected(ACharacter* Collector)
{
	Super::OnCollected(Collector);

	if (Collector)
	{
		//if the collector has a character movement component,
		if (UCharacterMovementComponent* CollectorMovementComponent = Collector->GetCharacterMovement()) {

			//local variables to pass into the lambda
			TWeakObjectPtr<UCharacterMovementComponent> CollectorMovementComponentPtr = CollectorMovementComponent;
			FTimerHandle TimerHandle;
			float LocalBoostMultiplier = BoostMultiplier;

			//apply the speed boost
			CollectorMovementComponent->MaxWalkSpeed *= LocalBoostMultiplier;

			GetWorldTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([CollectorMovementComponentPtr, LocalBoostMultiplier]() {
				if (CollectorMovementComponentPtr.IsValid())
				{
					//revert the speed boost after the duration
					CollectorMovementComponentPtr->MaxWalkSpeed /= LocalBoostMultiplier;
				}
				}), BoostDuration, false);
		}
	}
}