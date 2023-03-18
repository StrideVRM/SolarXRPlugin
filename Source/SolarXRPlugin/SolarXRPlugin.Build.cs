// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SolarXRPlugin : ModuleRules
{
    public SolarXRPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.AddRange(new string[] { "OnlineSubsystem", "OnlineSubsystemUtils" });
        // DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");

        // Add the Flatbuffers include path
        PublicIncludePaths.Add(System.IO.Path.Combine(ModuleDirectory, "../../ThirdParty/flatbuffers/include"));

        // Link the Flatbuffers library
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicAdditionalLibraries.Add(System.IO.Path.Combine(ModuleDirectory, "../../ThirdParty/flatbuffers/lib/Win64/flatbuffers.lib"));
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            PublicAdditionalLibraries.Add(System.IO.Path.Combine(ModuleDirectory, "../../ThirdParty/flatbuffers/lib/Mac/libflatbuffers.a"));
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            PublicAdditionalLibraries.Add(System.IO.Path.Combine(ModuleDirectory, "../../ThirdParty/flatbuffers/lib/Linux/libflatbuffers.a"));
        }
    }
}
