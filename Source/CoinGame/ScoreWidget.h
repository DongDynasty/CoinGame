// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class COINGAME_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Score")
	void UpdateScore(int32 NewScore);

private:

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;
};
