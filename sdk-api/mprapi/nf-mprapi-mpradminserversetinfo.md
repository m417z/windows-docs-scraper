# MprAdminServerSetInfo function

## Description

The
**MprAdminServerSetInfo** function is used to set the number of ports for L2TP, PPTP, and SSTP devices when the RRAS service is running.

## Parameters

### `hMprServer` [in]

Handle to the router to query. Obtain this handle by calling [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is structured in the *lpbBuffer* parameter. Acceptable values for *dwLevel* include 1 and 2 as listed in the following table.

| Value | Structure Format |
| --- | --- |
| 1 | Windows Server 2003 or later: [MPR_SERVER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_1) |
| 2 | Windows Server 2008 or later: [MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2) |

### `lpbBuffer` [in]

A pointer to a
[MPR_SERVER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_1)
or [MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2) structure. The *dwLevel* parameter indicates the type of structure.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_SUCCESS_REBOOT_REQUIRED** | A system reboot is required for such a change to take affect. Change the port count using the [MprConfigServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserversetinfo) call and reboot. |
| **ERROR_INVALID_PARAMETER** | If you try to set the number of ports to more than the system supported limits as defined on the [MPR_SERVER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_1) and [MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2) topics.<br><br>Returns this error if you try to set the number of PPTP ports to 0.<br><br>Returns this error if the flags are not valid or if *lpbBuffer* or *hMprServer* is **NULL**. |
| **ERROR_DDM_NOT_RUNNING** | RRAS service is not running on this server. |
| **ERROR_NOT_SUPPORTED** | The value of *dwLevel* is not valid. |
| **ERROR_INVALID_HANDLE** | *hMprServer* handle is invalid. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

This function is used to set the port count for L2TP, PPTP, and SSTP ports and enable or disable RRAS when the service is running. These values are persistent, meaning that you do not have to follow this call with a call to [MprConfigServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserversetinfo). Note that this function is asynchronous, so you might not see the affect of the changes immediately.

#### Examples

The topic [Setting L2TP and PPTP ports of a local RRAS service](https://learn.microsoft.com/windows/desktop/RRAS/setting-l2tp-and-pptp-ports) shows this function in use.

## See also

[MPR_SERVER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_1)

[MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2)

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[MprAdminServerGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminservergetinfo)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)