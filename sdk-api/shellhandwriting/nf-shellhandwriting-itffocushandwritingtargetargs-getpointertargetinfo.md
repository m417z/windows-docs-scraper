# GetPointerTargetInfo function

Retrieves details about the top-level target window of the pointer input.

## Description

## Parameters

### `targetWindow` [out, optional]

The target window of the pointer input.

### `targetScreenArea` [out, optional]

The target area of the pointer input.

This value is based on the dots-per-inch (DPI) awareness of the current thread associated with the Text Services Framework (TSF) thread manager object.

### `distanceThreshold` [out, optional]

The distance (vertical and horizontal) in pixels from a valid edit control for which the *[targetScreenPoint](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfdetermineproximatehandwritingtargetargs-getpointertargetinfo)* enables handwriting functionality.

This value is based on the dots-per-inch (DPI) awareness of the current thread associated with the TSF thread manager object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also