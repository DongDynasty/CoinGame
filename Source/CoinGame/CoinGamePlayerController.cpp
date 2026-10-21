// Copyright Epic Games, Inc. All Rights Reserved.


#include "CoinGamePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "CoinGame.h"
#include "Widgets/Input/SVirtualJoystick.h"
#include "ScoreWidget.h"
#include "CoinPlayerState.h"

void ACoinGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// only spawn touch controls on local player controllers
	if (IsLocalPlayerController() && ShouldUseTouchControls())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogCoinGame, Error, TEXT("Could not spawn mobile controls widget."));

		}
	}

	if (IsLocalPlayerController()) {

		ScoreWidget = CreateWidget<UScoreWidget>(this, ScoreWidgetClass);

		if (ScoreWidget)
		{
			ScoreWidget->AddToPlayerScreen(0);

			//bind the score widget to the player state
			if (ACoinPlayerState* CoinPlayerState = GetPlayerState<ACoinPlayerState>()) {

				CoinPlayerState->OnScoreChanged.AddUniqueDynamic(ScoreWidget, &UScoreWidget::UpdateScore);
				ScoreWidget->UpdateScore(CoinPlayerState->GetPlayerScore());
			}

		}
		else {
			UE_LOG(LogCoinGame, Error, TEXT("Could not spawn score widget."));
		}
	}
	else {
		UE_LOG(LogCoinGame, Error, TEXT("Score widget can only be spawned on local player controllers."));
	}
}

void ACoinGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!ShouldUseTouchControls())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

bool ACoinGamePlayerController::ShouldUseTouchControls() const
{
	// are we on a mobile platform? Should we force touch?
	return SVirtualJoystick::ShouldDisplayTouchInterface() || bForceTouchControls;
}
