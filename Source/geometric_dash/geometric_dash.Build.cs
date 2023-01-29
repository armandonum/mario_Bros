// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class geometric_dash : ModuleRules
{
	public geometric_dash(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
