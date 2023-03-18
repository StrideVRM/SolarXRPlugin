// Copyright Epic Games, Inc. All Rights Reserved.

#include "SolarXRPlugin.h"
#include "SolarXRManager.h"

#define LOCTEXT_NAMESPACE "FSolarXRPlugin"

void FSolarXRPlugin::StartupModule()
{
	SolarXRManagerInstance = MakeUnique<SolarXRManager>();
}

void FSolarXRPlugin::ShutdownModule()
{
	// Clean up duty
	SolarXRManagerInstance.Reset();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSolarXRPlugin, SolarXRPlugin)
