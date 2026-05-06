// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CdEditorTarget : TargetRules
{
	public CdEditorTarget( TargetInfo Target) : base(Target)
	{
		RegisterDefaults();
		RegisterModules();
	}

	private void RegisterDefaults()
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V6;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_7;
	}
	
	private void RegisterModules()
	{
		ExtraModuleNames.AddRange([
			"Cd",
			"CdCore",
			"CdServer"
		]);
	}
}
