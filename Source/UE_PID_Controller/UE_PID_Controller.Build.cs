// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_PID_Controller : ModuleRules {
	public UE_PID_Controller(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG" });
	}
}