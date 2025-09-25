# MprAdminConnectionClearStats function

## Description

The
**MprAdminConnectionClearStats** function resets the statistics counters for the specified connection.

## Parameters

### `hRasServer` [in]

Handle to the Remote Access Server on which to execute
**MprAdminConnectionClearStats**. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hRasConnection` [in]

Handle to the connection for which to reset the statistics. Obtain this handle by calling
[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running, possibly because the Dynamic Interface Manager (DIM) is configured to run only on a LAN. |
| **ERROR_INVALID_PARAMETER** | The handle to the port is invalid. |
| **RPC_S_INVALID_BINDING** | This function was called with *hRasServer* parameter equal to **NULL**. |
| **Other** | An error from MprError.h, RasError.h, or WinError.h. |

## Remarks

This function is available on Windows NT 4.0 if the RRAS redistributable is installed. However, the version of Mprapi.dll that ships with the RRAS redistributable exports the function as **RasAdminConnectionClearStats** rather than
**MprAdminConnectionClearStats**. Therefore, when using the RRAS redistributable, use
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access this function.

## See also

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)