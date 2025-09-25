# EcOpenSubscription function

## Description

The **EcOpenSubscription** function is used to open an existing subscription or create a new subscription according to the flag value specified.

## Parameters

### `SubscriptionName` [in]

Specifies the name of the subscription. The value provided for this parameter should be unique within the computer's scope.

### `AccessMask` [in]

An access mask that specifies the desired access rights to the subscription. Use the [EC_READ_ACCESS](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-constants) or [EC_WRITE_ACCESS](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-constants) constants to specify the access rights. The function fails if the security descriptor of the subscription does not permit the requested access for the calling process.

### `Flags` [in]

A value specifying whether a new or existing subscription will be opened. Use the **EC_CREATE_NEW**, **EC_OPEN_ALWAYS**, or **EC_OPEN_EXISTING** constants.

## Return value

If the function succeeds, it returns a handle ([EC_HANDLE](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-data-types)) to a new subscription object. Returns **NULL** otherwise, in which case use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to obtain the error code.

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)