# MprAdminConnectionGetInfoEx function

## Description

The
**MprAdminConnectionGetInfoEx** function retrieves the connection information for a specific connection on a specified RRAS server.

## Parameters

### `hRasServer` [in]

A handle to the computer from which the connection information is retrieved. To obtain this handle, call [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hRasConnection` [in]

A handle to the connection to retrieve data about. To obtain this handle, call [MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum).

### `pRasConnection` [out]

A pointer, on output, to a [RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex) structure that contains the connection information for the RRAS server in *hRasServer*.

To free this memory, call [MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running. |
| **ERROR_PROC_NOT_FOUND** | The specified procedure could not be found. |
| **Other** | An error from MprError.h, RasError.h, or WinError.h. |

## Remarks

The caller should free the memory pointed to by *pRasConnection* by calling the function [MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## See also

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminConnectionGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectiongetinfo)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)