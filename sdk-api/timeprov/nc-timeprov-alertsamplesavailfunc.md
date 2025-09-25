# AlertSamplesAvailFunc callback function

## Description

Notifies the system that there are new time samples available.

## Parameters

### `unnamedParam1`

## Return value

If the function succeeds, the return value is S_OK. Otherwise, the return value is one of the error codes defined in WinError.h.

## Remarks

The time provider manager uses this notification to determine when to send a TPC_GetSamples command. A hardware provider does not need to call this function, as the time provider manager requests samples without this notification. Time providers that provide samples sporadically, such as a provider that works in the background when a user establishes a transient dial-up connection, must call this function.

The
[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen) function returns a pointer to this function.

## See also

[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen)