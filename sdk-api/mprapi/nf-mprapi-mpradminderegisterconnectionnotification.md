# MprAdminDeregisterConnectionNotification function

## Description

The
**MprAdminDeregisterConnectionNotification** function deregisters an event object that was previously registered using
[MprAdminRegisterConnectionNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminregisterconnectionnotification). Once deregistered, this event is no longer signaled when an interface connects or disconnects.

## Parameters

### `hMprServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hEventNotification` [in]

Handle to an event object to deregister. This event is no longer signaled when an interface connects or disconnects.

## Return value

If the function is successful, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running. |
| **ERROR_INVALID_PARAMETER** | The *hEventNotification* parameter is **NULL** or is an invalid handle. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprAdminRegisterConnectionNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminregisterconnectionnotification)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)