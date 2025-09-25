# TimeProvClose function

## Description

A callback function that is called by the time provider manager to shut down the time provider.

## Parameters

### `hTimeProv` [in]

A handle to the time provider. The
[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen) function receives this handle.

## Return value

If the function succeeds, the return value is S_OK. Otherwise, the return value is one of the error codes defined in WinError.h.

## Remarks

The provider should clean up its resources and terminate its operation. When the function returns, the time provider manager can unload the DLL. Therefore, the handle to the time provider is no longer valid and should not be used again.

#### Examples

For an example, see [Sample Time Provider](https://learn.microsoft.com/windows/desktop/SysInfo/sample-time-provider).

## See also

[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen)