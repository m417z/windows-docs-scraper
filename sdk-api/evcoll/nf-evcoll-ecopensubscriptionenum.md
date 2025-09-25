# EcOpenSubscriptionEnum function

## Description

The **EcOpenSubscriptionEnum** function is creates a subscription enumerator to enumerate all registered subscriptions on the local machine.

## Parameters

### `Flags` [in]

Reserved. Must be 0.

## Return value

If the function succeeds, it returns a handle ([EC_HANDLE](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-data-types)) to a new subscription enumerator object. Returns **NULL** otherwise, in which case use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to obtain the error code.

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)