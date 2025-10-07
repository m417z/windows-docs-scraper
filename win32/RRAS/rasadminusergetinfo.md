# RasAdminUserGetInfo function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminUserGetInfo**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradminusergetinfo) function.\]

The **RasAdminUserGetInfo** function gets the RAS permissions and callback phone number information for a specified user.

## Parameters

*lpszUserAccountServer* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the primary or backup domain controller that has the user account database. Use the [**RasAdminGetUserAccountServer**](https://learn.microsoft.com/windows/win32/rras/rasadmingetuseraccountserver) function to get this server name.

*lpszUser* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the user for whom to get RAS information.

*pRasUser0*

Pointer to the [**RAS\_USER\_0**](https://learn.microsoft.com/windows/win32/rras/ras-user-0-str) structure that receives the RAS data for the specified user.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value can be the following error code.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------|----------------------------------------------------------|
| **NERR\_BufTooSmall** | Insufficient memory to perform this function.<br> |

There is no extended error information for this function; do not call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

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

[**RasAdminUserSetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusersetinfo)

