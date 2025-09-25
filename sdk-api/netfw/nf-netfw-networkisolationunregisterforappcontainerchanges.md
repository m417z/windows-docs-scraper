# NetworkIsolationUnregisterForAppContainerChanges function

## Description

The **NetworkIsolationUnregisterForAppContainerChanges** function is used to cancel an app container change registration and stop receiving notifications.

## Parameters

### `registrationObject` [in]

Type: **HANDLE**

Handle to the previously created registration.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## See also

[NetworkIsolationRegisterForAppContainerChanges](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-networkisolationregisterforappcontainerchanges)