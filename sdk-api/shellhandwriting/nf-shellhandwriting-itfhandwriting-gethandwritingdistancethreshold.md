# GetHandwritingDistanceThreshold function

## Description

Retrieves the distance (vertical and horizontal) in pixels from a valid edit control for which the *[targetScreenPoint](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfdetermineproximatehandwritingtargetargs-getpointertargetinfo)* enables handwriting functionality.

## Parameters

### `distanceThresholdPixels` [out]

The distance (vertical and horizontal) in pixels from a valid edit control for which the *[targetScreenPoint](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfdetermineproximatehandwritingtargetargs-getpointertargetinfo)* enables handwriting functionality.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This value is based on the dots-per-inch (DPI) awareness of the current thread associated with the TSF thread manager object.

## See also