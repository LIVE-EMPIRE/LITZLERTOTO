// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EyeTracker : ModuleRules
{
    public EyeTracker(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicIncludePaths.AddRange(
			new string[] {
				"Runtime/EyeTracker/Public"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
                "InputCore"
                //,
// 				"Slate",
// 				"SlateCore",
//                 "RHI",
//                 "Renderer",
//                 "ShaderCore",
//                 "RenderCore",
//                 "UtilityShaders",
//                 "Analytics"
            }
        );
	}
}
