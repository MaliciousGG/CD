// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CdTarget : TargetRules
{
	public CdTarget(TargetInfo Target) : base(Target)
	{
		RegisterDefaults();
		RegisterModules();
	}

	private void RegisterDefaults()
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V6;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_7;
	}
	
	private void RegisterModules()
	{
		ExtraModuleNames.AddRange([
			"Cd", 
			"CdCore"
		]);
	}
}
