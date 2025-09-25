# SetProviderStatusFunc callback function

## Description

Sets the time provider's status information.

## Parameters

### `pspsi` [in]

A pointer to a
[SetProviderStatusInfo](https://learn.microsoft.com/windows/desktop/api/timeprov/ns-timeprov-setproviderstatusinfo) structure that provides the status information.

## Return value

If the function succeeds, the return value is S_OK. Otherwise, the return value is one of the error codes defined in WinError.h.

## Remarks

The
[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen) function returns a pointer to this function.

## See also

[SetProviderStatusInfo](https://learn.microsoft.com/windows/desktop/api/timeprov/ns-timeprov-setproviderstatusinfo)

[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen)