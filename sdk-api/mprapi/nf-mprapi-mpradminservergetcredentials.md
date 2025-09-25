# MprAdminServerGetCredentials function

## Description

The
**MprAdminServerGetCredentials** function retrieves the pre-shared key for the specified server.

## Parameters

### `hMprServer` [in]

Handle to a Windows server. Obtain this handle by calling
[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpbBuffer* parameter. Must be zero.

### `lplpbBuffer` [out]

On successful completion, a pointer to an [MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1) structure that contains the pre-shared key for the server. Free the memory occupied by this structure with
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_PARAMETER** | The *lplpbBuffer* parameter is **NULL**. |
| **ERROR_NOT_SUPPORTED** | The *dwLevel* parameter is not zero. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

The server maintains a single pre-shared key for all users.

## See also

[MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1)

[MprAdminServerSetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserversetcredentials)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)