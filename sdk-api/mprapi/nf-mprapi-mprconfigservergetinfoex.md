# MprConfigServerGetInfoEx function

## Description

The
**MprConfigServerGetInfoEx** function retrieves port information for a specified server.

## Parameters

### `hMprConfig` [in]

A handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `pServerInfo` [out]

A pointer, on output, to a [MPR_SERVER_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_ex0) structure that contains the port information for the RRAS server in *hMprConfig*.

To free this memory, call [MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running. |
| **ERROR_PROC_NOT_FOUND** | The specified procedure could not be found. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[MprAdminServerGetInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminservergetinfoex)

[MprAdminServerSetInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetinfoex)

[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)