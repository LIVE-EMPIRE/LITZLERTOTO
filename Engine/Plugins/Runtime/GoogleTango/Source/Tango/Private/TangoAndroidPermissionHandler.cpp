// Copyright 2017 Google Inc.

#include "TangoAndroidPermissionHandler.h"
#include "AndroidPermissionFunctionLibrary.h"
#include "AndroidPermissionCallbackProxy.h"
#include "TangoLifecycle.h"

UTangoAndroidPermissionHandler::UTangoAndroidPermissionHandler(const FObjectInitializer& Init) : Super(Init)
{
}

bool UTangoAndroidPermissionHandler::CheckRuntimePermission(const FString& RuntimePermission)
{
	return UAndroidPermissionFunctionLibrary::CheckPermission(RuntimePermission);
}

void UTangoAndroidPermissionHandler::RequestRuntimePermissions(const TArray<FString>& RuntimePermissions)
{
	UAndroidPermissionCallbackProxy::GetInstance()->OnPermissionsGrantedDynamicDelegate.AddDynamic(this, &UTangoAndroidPermissionHandler::OnPermissionsGranted);
	UAndroidPermissionFunctionLibrary::AcquirePermissions(RuntimePermissions);
}

void UTangoAndroidPermissionHandler::OnPermissionsGranted(const TArray<FString> &Permissions, const TArray<bool>& Granted)
{
	UAndroidPermissionCallbackProxy::GetInstance()->OnPermissionsGrantedDynamicDelegate.RemoveDynamic(this, &UTangoAndroidPermissionHandler::OnPermissionsGranted);
	FTangoDevice::GetInstance()->HandleRuntimePermissionsGranted(Permissions, Granted);
}

