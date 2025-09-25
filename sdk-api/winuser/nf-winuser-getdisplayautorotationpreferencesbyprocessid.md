# GetDisplayAutoRotationPreferencesByProcessId function

## Description

Retrieves the screen auto-rotation preferences for the process indicated by the *dwProcessId* parameter.

## Parameters

### `dwProcessId` [in]

The process to get preference settings for.

### `pOrientation` [out]

Pointer to a location in memory that will receive the current orientation preference setting for the indicated process.

### `fRotateScreen` [out]

Pointer to a location in memory that will receive a TRUE or FALSE value indicating whether the screen was rotated to comply with the process orientation preferences.

## Return value

TRUE if the method succeeds, otherwise FALSE.

Applications should use [GetDisplayAutoRotationPreferences](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdisplayautorotationpreferences) to retrieve their auto-rotation preferences instead of using this API. For an example, see [GetDisplayAutoRotationPreferences](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdisplayautorotationpreferences).