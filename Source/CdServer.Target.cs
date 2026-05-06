// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CdServerTarget : TargetRules
{
	public CdServerTarget(TargetInfo Target) : base(Target)
	{
		RegisterDefaults();
		RegisterModules();
	}

	private void RegisterDefaults()
	{
		Type = TargetType.Server;
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