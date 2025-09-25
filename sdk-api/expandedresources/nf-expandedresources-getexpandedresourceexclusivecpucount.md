# GetExpandedResourceExclusiveCpuCount function

## Description

Gets the expected number of exclusive CPU sets that are available to the app when in Game Mode.

## Parameters

### `exclusiveCpuCount` [out]

The expected number of exclusive CPU sets that are available to the app when in Game Mode.

## Return value

The result of the operation.

## Remarks

This is a Win32 API that's supported in UWP desktop and Xbox apps, as well as Win32 apps.

You can use this function to determine what resources are available to your app, and use this information to decide whether to enter Game Mode or shared mode.

This function returns 0 if no exclusive CPU sets are available, or if the customer opted out of Game Mode via the Settings in Windows 10.

The app must be in the foreground and have focus before exclusive resources are granted.