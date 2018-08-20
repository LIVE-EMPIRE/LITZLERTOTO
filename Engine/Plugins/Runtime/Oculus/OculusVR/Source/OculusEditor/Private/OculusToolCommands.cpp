// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OculusToolCommands.h"
#include "Framework/Docking/TabManager.h"

#define LOCTEXT_NAMESPACE "FOculusEditorModule"

void FOculusToolCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "Oculus Tool", "Show Oculus Tool Window", EUserInterfaceActionType::Button, FInputGesture());
}

void FOculusToolCommands::ShowOculusTool()
{
	FGlobalTabmanager::Get()->InvokeTab(FOculusEditorModule::OculusPerfTabName);
}

#undef LOCTEXT_NAMESPACE
