# RasAdminUserSetInfo function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminUserSetInfo**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradminusersetinfo) function.\]

The **RasAdminUserSetInfo** function sets the RAS permissions and call-back phone number for a specified user.

## Parameters

*lpszUserAccountServer* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the primary or backup domain controller that has the user account database. Use the [**RasAdminGetUserAccountServer**](https://learn.microsoft.com/windows/win32/rras/rasadmingetuseraccountserver) function to get this server name.

*lpszUser* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the user for whom RAS information is to be set.

*pRasUser0* \[in\]

Pointer to the [**RAS\_USER\_0**](https://learn.microsoft.com/windows/win32/rras/ras-user-0-str) structure that specifies the new RAS data for the specified user.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value can be one of the following error codes.

| Value | Description |
|-----------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
| **ERROR\_INVALID\_DATA** | The *pRasUser0* buffer contains invalid data.<br> |
| **ERROR\_INVALID\_CALLBACK\_NUMBER** | The callback number specified in the *pRasUser0* buffer contains invalid characters.<br> |
| **NERR\_BufTooSmall** | Insufficient memory to perform this function.<br> |

There is no extended error information for this function; do not call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When setting the RAS permissions for a user, the **bfPrivilege** member of the [**RAS\_USER\_0**](https://learn.microsoft.com/windows/win32/rras/ras-user-0-str) structure must specify at least one of the call-back flags. For example, to set a user's privileges to allow dial-in privilege but no call-back privilege, set **bfPrivilege** to RASPRIV\_DialinPrivilege \| RASPRIV\_NoCallback.

## Requirements

| Requirement | Value |
|----------------------------------|----------------------------------------------------------------------------------------|
| End of client support<br> | Windows 2000 Professional<br> |
| End of server support<br> | Windows 2000 Server<br> |
| Header<br> | Rassapi.h |
| Library<br> | Rassapi.lib |
| DLL<br> | Rassapi.dll |

## See also

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/win32/rras/about-remote-access-service)

[RAS Server Administration Functions](https://learn.microsoft.com/windows/win32/rras/ras-server-administration-functions)

[**RAS\_USER\_0**](https://learn.microsoft.com/windows/win32/rras/ras-user-0-str)

[**RasAdminGetUserAccountServer**](https://learn.microsoft.com/windows/win32/rras/rasadmingetuseraccountserver)

[**RasAdminUserGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusergetinfo)

