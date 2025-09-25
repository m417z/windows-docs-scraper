# MprConfigServerGetInfo function

## Description

The
**MprConfigServerGetInfo** function retrieves server-level configuration information for the specified router.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpBuffer* parameter. Acceptable values for *dwLevel* include 0, 1, and 2 as listed in the following table.

| Value | Structure Format |
| --- | --- |
| 0 | Windows 2000 Server or later: [MPR_SERVER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_0) |
| 1 | Windows Server 2003 or later: [MPR_SERVER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_1) |
| 2 | Windows Server 2008 or later: [MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2) |

### `lplpbBuffer` [out]

On successful completion, a pointer to a
[MPR_SERVER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_0),
[MPR_SERVER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_1),
or [MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2) structure. The *dwLevel* parameter indicates the type of structure.
Free the memory for this buffer using
[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true: <br><br>* The *hMprConfig* parameter is **NULL**.<br>* The *dwLevel* parameter is not zero.<br>* The *lplpBuffer* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MPR_SERVER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_0)

[MPR_SERVER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_1)

[MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2)

[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[MprConfigServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserversetinfo)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)