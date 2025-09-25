# MprAdminServerGetInfoEx function

## Description

The
**MprAdminServerGetInfoEx** function retrieves port information about the specified RRAS server.

## Parameters

### `hMprServer` [in]

A handle to the server to query. Obtain this handle by calling [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `pServerInfo` [out]

A pointer, on output, to a [MPR_SERVER_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_ex0) structure that contains the port information for the RRAS server in *hMprServer*.

To free this memory, call [MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running. |
| **ERROR_PROC_NOT_FOUND** | The specified procedure could not be found. |

## See also

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[MprAdminServerSetInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetinfoex)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)