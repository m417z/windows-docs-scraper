## Description

Sets the preferred frame duration.

## Parameters

### `preferredDuration`

Type: **[SystemInterruptTime](https://learn.microsoft.com/windows/win32/api/presentationtypes/ns-presentationtypes-systeminterrupttime)**

The requested duration, in interrupt time.

### `deviationTolerance`

Type: **[SystemInterruptTime](https://learn.microsoft.com/windows/win32/api/presentationtypes/ns-presentationtypes-systeminterrupttime)**

The allowed tolerance. If the magnitude of the difference between a supported system duration and the _`preferredDuration`_ parameter is within the _`deviationTolerance`_ parameter, that system duration will be used.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

Preferred frame duration is meant to be used as a hint to the system that it would be preferred to refresh the output at the specified framerate. Displays that support this rate, or a multiple, will be set into that mode if appropriate.

This parameter setting persists across presents.

## See also