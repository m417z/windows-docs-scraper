# MprConfigServerSetInfoEx function

## Description

The
**MprConfigServerSetInfoEx** function sets port information on a specified RRAS server.

## Parameters

### `hMprConfig` [in]

A handle to the router configuration. Obtain this handle by calling [MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `pSetServerConfig` [in]

A pointer to a
[MPR_SERVER_SET_CONFIG_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_set_config_ex0) structure that contains the port information being set on the server in *hMprServer*.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_PARAMETER** | The **pSetServerConfig** parameter is **NULL** or the **Header** field values are erroneous. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

These changes to a server configuration are persistent, but have no effect on a RRAS server until it is restarted.

## See also

[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[MprConfigServerGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigservergetinfo)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)