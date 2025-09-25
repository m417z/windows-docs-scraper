# AuthzUnregisterCapChangeNotification function

## Description

The **AuthzUnregisterCapChangeNotification** function removes a previously registered CAP update notification callback.

## Parameters

### `hCapChangeSubscription` [in]

Handle of the CAP change notification subscription to unregister.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function blocks operations until all callbacks are complete. Do not call this function from inside a callback function because it will cause a deadlock.

## See also

[AuthzRegisterCapChangeNotification](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzregistercapchangenotification)

[Central Access Policies](https://learn.microsoft.com/windows/desktop/SecAuthZ/central-authorization-policies)

[How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)