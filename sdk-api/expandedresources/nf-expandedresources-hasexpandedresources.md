# HasExpandedResources function

## Description

Gets the current resource state (that is, whether the app is running in Game Mode or shared mode).

## Parameters

### `hasExpandedResources` [out]

True if the app is running in Game Mode; otherwise, false.

## Return value

The result of the operation.

## Remarks

This is a Win32 API that's supported in UWP desktop and Xbox apps, as well as Win32 apps.

This function should be called during each iteration of the game loop to check when the app enters and exits Game Mode so that the appropriate settings can be applied.

The app must be in the foreground and have focus before exclusive resources are granted.