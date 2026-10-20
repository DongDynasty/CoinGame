// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CoinPlayerState.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int32, NewScore);

/**
 * 
 */
UCLASS()
class COINGAME_API ACoinPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category = "Score")
	FOnScoreChanged OnScoreChanged;

	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Score")
	int32 GetPlayerScore() const { return PlayerScore; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	int32 PlayerScore = 0;
};
