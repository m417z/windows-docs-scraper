# AuthzRegisterCapChangeNotification function

## Description

The **AuthzRegisterCapChangeNotification** function registers a CAP update notification callback.

## Parameters

### `phCapChangeSubscription` [out]

Pointer to the CAP change notification subscription handle. When you have finished using the handle, unsubscribe by passing this parameter to the [AuthzUnregisterCapChangeNotification](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzunregistercapchangenotification) function.

### `pfnCapChangeCallback` [in]

The CAP change notification callback function.

### `pCallbackContext` [in, optional]

The context of the user to be passed to the callback function.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is intended for applications that manually manage CAP usage to get notified of CAP changes in the system.

## See also

[AuthzUnregisterCapChangeNotification](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzunregistercapchangenotification)

[Central Access Policies](https://learn.microsoft.com/windows/desktop/SecAuthZ/central-authorization-policies)

[How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)