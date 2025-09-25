# MprAdminPortClearStats function

## Description

The
**MprAdminPortClearStats** function resets the statistics for the specified port.

## Parameters

### `hRasServer` [in]

Handle to the RAS server on which to clear the statistics for the specified port. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hPort` [in]

Handle to the port for which statistics are reset. Obtain this handle by calling
[MprAdminPortEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminportenum).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running, possibly because the Dynamic Interface Manager (DIM) is configured to run only on a LAN. |
| **RPC_S_INVALID_BINDING** | The handle to the RAS server or the handle to the port is invalid. |
| **Other** | An error from MprError.h, RasError.h, or WinError.h. |

## Remarks

This function is available on Windows NT Server 4.0 if the RRAS redistributable is installed. However, the version of Mprapi.dll that ships with the RRAS redistributable exports the function as **RasAdminPortClearStats** rather than
**MprAdminPortClearStats**. Therefore, when using the RRAS redistributable, use
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access this function.

## See also

[MprAdminPortEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminportenum)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)