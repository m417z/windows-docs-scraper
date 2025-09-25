# MprAdminUserSetInfo function

## Description

The
**MprAdminUserSetInfo** function sets RAS information for the specified user.

## Parameters

### `lpszServer` [in]

Pointer to a Unicode string that specifies the name of the server with the master User Accounts Subsystem (UAS). If the remote access server is part of a domain, the computer with the UAS is either the primary domain controller or the backup domain controller. If the remote access server is not part of a domain, then the server itself stores the UAS. In either case, call the
[MprAdminGetPDCServer](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetpdcserver) function to obtain the value for this parameter.

If the server itself stores the UAS, this parameter can be **NULL**.

### `lpszUser` [in]

Pointer to a Unicode string that specifies the name of the user for which to set RAS information.

### `dwLevel` [in]

This parameter can be zero or one, corresponding to the structure type pointed to by the *lpbBuffer* parameter.

**Windows NT Server 4.0 with SP3 and later:** This parameter must be zero.

### `lpbBuffer` [in]

Pointer to a
[RAS_USER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_user_0) or [RAS_USER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_user_1) structure that specifies the new RAS information for the user.

**Windows NT Server 4.0 with SP3 and later:** If the *dwLevel* parameter specifies zero, *lpbBuffer* should point to a
[RAS_USER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_user_0) structure.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient privileges. |
| **ERROR _INVALID_LEVEL** | The value of *dwLevel* is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NO_SUCH_USER** | The user specified by *lpwsUserName* does not exist on the server specified by *lpwsServerName*. |

## Remarks

This function is available on Windows NT 4.0 if the RRAS redistributable is installed. However, the version of Mprapi.dll that ships with the RRAS redistributable exports the function as
[RasAdminUserSetInfo](https://learn.microsoft.com/windows/desktop/RRAS/rasadminusersetinfo) rather than
**MprAdminUserSetInfo**. Therefore, when using the RRAS redistributable, use
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access this function.

## See also

[MprAdminGetPDCServer](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetpdcserver)

[MprAdminUserGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminusergetinfo)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[RAS_USER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_user_0)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)