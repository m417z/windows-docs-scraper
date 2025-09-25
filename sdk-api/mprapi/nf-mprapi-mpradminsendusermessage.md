# MprAdminSendUserMessage function

## Description

The
**MprAdminSendUserMessage** function sends a message to the user connected on the specified connection.

## Parameters

### `hMprServer` [in]

Handle to the RAS server on which the user is connected. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hConnection` [in]

Handle to the connection on which the user is connected. Use
[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum) to obtain this handle.

### `lpwszMessage` [in]

Pointer to a Unicode string that specifies the message to the user.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running, possibly because the Dynamic Interface Manager (DIM) is configured to run only on a LAN. |
| **ERROR_INTERFACE_NOT_CONNECTED** | The *hConnection* parameter is not valid. |
| **ERROR_INVALID_PARAMETER** | The *lpwszMessage* parameter is **NULL**. |

## See also

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)