# MprAdminIsServiceInitialized function

## Description

The
**MprAdminIsServiceInitialized** function checks whether the RRAS service is running on a specified server if the calling process has access.

## Parameters

### `lpwsServerName` [in]

A pointer to a **null**-terminated Unicode string that specifies the name of the server to query. If this parameter is **NULL**, the function queries the local machine.

### `fIsServiceInitialized` [in]

On output, a pointer to a BOOL that specifies whether the RRAS service is running on the server in *lpwsServerName*:

| Value | Meaning |
| --- | --- |
| **TRUE** | The service is running on the specified server. |
| **FALSE** | The service is not running on the specified server and/or the calling process does not have access to the RRAS service. |

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *fIsServiceInitialized* parameter is **NULL**. |
| **ERROR_SERVICE_NOT_ACTIVE** | The RRAS service is not running on the server. |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |

## See also

[MprAdminIsServiceRunning](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminisservicerunning)

[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)