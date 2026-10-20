// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPlayerState.h"


void ACoinPlayerState::AddScore(int32 Amount) {

	PlayerScore += Amount;
	UE_LOG(LogTemp, Log, TEXT("Player %s score changed to %d"), *GetPlayerName(), PlayerScore);
	OnScoreChanged.Broadcast(PlayerScore);
}