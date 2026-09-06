// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SteelCadence : ModuleRules
{
	public SteelCadence(ReadOnlyTargetRules Target) : base(Target)
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
			"SteelCadence",
			"SteelCadence/Variant_Platforming",
			"SteelCadence/Variant_Platforming/Animation",
			"SteelCadence/Variant_Combat",
			"SteelCadence/Variant_Combat/AI",
			"SteelCadence/Variant_Combat/Animation",
			"SteelCadence/Variant_Combat/Gameplay",
			"SteelCadence/Variant_Combat/Interfaces",
			"SteelCadence/Variant_Combat/UI",
			"SteelCadence/Variant_SideScrolling",
			"SteelCadence/Variant_SideScrolling/AI",
			"SteelCadence/Variant_SideScrolling/Gameplay",
			"SteelCadence/Variant_SideScrolling/Interfaces",
			"SteelCadence/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
