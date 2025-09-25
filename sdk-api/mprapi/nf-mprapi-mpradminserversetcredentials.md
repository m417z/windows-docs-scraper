# MprAdminServerSetCredentials function

## Description

The
**MprAdminServerSetCredentials** functions sets the pre-shared key for the specified server.

## Parameters

### `hMprServer` [in]

Handle to a Windows server. Obtain this handle by calling
[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is structured in the *lpbBuffer* parameter. Must be zero.

### `lpbBuffer` [in]

A pointer to an [MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1) structure that contains the pre-shared key for the server.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_PARAMETER** | The *lpbBuffer* parameter is **NULL**. |
| **ERROR_NOT_SUPPORTED** | The *dwLevel* parameter is not zero. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

The server maintains a single pre-shared key for all users.

To delete the pre-shared key, call
**MprAdminServerSetCredentials** with the [MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1)**dwSize** member set to zero.

## See also

[MPR_CREDENTIALSEX_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_credentialsex_1)

[MprAdminServerGetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminservergetcredentials)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)