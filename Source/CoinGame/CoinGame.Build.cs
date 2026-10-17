// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CoinGame : ModuleRules
{
	public CoinGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CoinGame",
			"CoinGame/Variant_Platforming",
			"CoinGame/Variant_Platforming/Animation",
			"CoinGame/Variant_Combat",
			"CoinGame/Variant_Combat/AI",
			"CoinGame/Variant_Combat/Animation",
			"CoinGame/Variant_Combat/Gameplay",
			"CoinGame/Variant_Combat/Interfaces",
			"CoinGame/Variant_Combat/UI",
			"CoinGame/Variant_SideScrolling",
			"CoinGame/Variant_SideScrolling/AI",
			"CoinGame/Variant_SideScrolling/Gameplay",
			"CoinGame/Variant_SideScrolling/Interfaces",
			"CoinGame/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
