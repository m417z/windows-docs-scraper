# MprAdminServerSetInfoEx function

## Description

The
**MprAdminServerSetInfoEx** function sets port information on a specified RRAS server.

## Parameters

### `hMprServer` [in]

A handle to the router to query. Obtain this handle by calling [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `pServerInfo` [in]

A pointer to a
[MPR_SERVER_SET_CONFIG_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_set_config_ex0) structure that contains the port information being set on the server in *hMprServer*.

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

[MprAdminServerGetInfoEx](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminservergetinfoex)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)