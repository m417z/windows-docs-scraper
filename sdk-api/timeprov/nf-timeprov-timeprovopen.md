# TimeProvOpen function

## Description

A callback function that is called by the time provider manager when the time provider DLL is loaded.

## Parameters

### `wszName` [in]

The provider name.

### `pSysCallbacks` [in]

A pointer to a
[TimeProvSysCallbacks](https://learn.microsoft.com/windows/desktop/api/timeprov/ns-timeprov-timeprovsyscallbacks) structure that specifies pointers to the functions provided by the time service to the time provider. The system allocates this structure, and it is destroyed when the function returns. Therefore, you must copy the information to another buffer.

### `phTimeProv` [out]

A pointer to a buffer that contains a handle to the provider. The time provider manager uses this handle to communicate with the time provider.

## Return value

If the function succeeds, the return value is S_OK. Otherwise, the return value is one of the error codes defined in WinError.h.

## Remarks

You should return from this callback function as quickly as possible. Perform any initialization in another thread.

#### Examples

For an example, see [Sample Time Provider](https://learn.microsoft.com/windows/desktop/SysInfo/sample-time-provider).

## See also

[AlertSamplesAvailFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-alertsamplesavailfunc)

[GetTimeSysInfoFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-gettimesysinfofunc)

[LogTimeProvEventFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-logtimeproveventfunc)

[SetProviderStatusFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-setproviderstatusfunc)

[TimeProvSysCallbacks](https://learn.microsoft.com/windows/desktop/api/timeprov/ns-timeprov-timeprovsyscallbacks)