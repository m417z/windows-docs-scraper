# MprAdminServerGetInfo function

## Description

The
**MprAdminServerGetInfo** function retrieves information about the specified RRAS server.

## Parameters

### `hMprServer` [in]

Handle to the router to query. Obtain this handle by calling [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

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
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_PARAMETER** | The *lplpbBuffer* parameter is **NULL**. |
| **RPC_S_INVALID_BINDING** | The *hMprServer* parameter is **NULL**. |

## See also

[MPR_SERVER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_0)

[MPR_SERVER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_1)

[MPR_SERVER_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_server_2)

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[MprAdminServerSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetinfo)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)