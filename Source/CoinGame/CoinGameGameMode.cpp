// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoinGameGameMode.h"
#include "CoinPlayerState.h"

ACoinGameGameMode::ACoinGameGameMode()
{
	PlayerStateClass = ACoinPlayerState::StaticClass();
}