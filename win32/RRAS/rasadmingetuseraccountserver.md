# RasAdminGetUserAccountServer function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminGetPDCServer**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradmingetpdcserver) function.\]

The **RasAdminGetUserAccountServer** function retrieves the name of the server that has the user account database. Use the returned server name in the [**RasAdminUserGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusergetinfo) and [**RasAdminUserSetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusersetinfo) functions to get or set information about a specified user.

## Parameters

*lpszDomain* \[in\]

Pointer to a **null**-terminated Unicode string that specifies the name of the domain to which the RAS server belongs. This parameter is **NULL** for the RAS administration applications running on workstations or servers that are not members of a domain. If this parameter is **NULL**, the *lpszServer* parameter must be non-**NULL**.

*lpszServer* \[in\]

Pointer to a **null**-terminated Unicode string that specifies the name of the RAS server. Specify the name with leading "\\\\" characters, in the form: \\\\*servername*. This parameter can be **NULL** if the *lpszDomain* parameter is not **NULL**.

*lpszUserAccountServer* \[out\]

Pointer to a buffer that receives a **null**-terminated Unicode string that specifies the name of a domain controller that has the user account database. The buffer should be big enough to hold the server name (UNCLEN +1). The function prefixes the returned server name with leading "\\\\" characters, in the form: \\\\*servername*.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value can be the following error code.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
| **ERROR\_INVALID\_PARAMETER** | Both *lpszDomain* and *lpszServer* are **NULL**.<br> |

There is no extended error information for this function; do not call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **RasAdminGetUserAccountServer** function obtains the name of the server with the user accounts database. This function requires the name of the RAS server or the name of the domain in which the RAS server resides.

The *lpszDomain* parameter should specify a valid domain name. This parameter is **NULL** for RAS administration applications running on servers that are not members of a domain (for example, the server is in its own workgroup). In this case, the *lpszServer* parameter must specify the server name. To get the server name, call the [**GetComputerName**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getcomputernamea) function. Be sure to prefix the server name with the "\\\\" characters.

If the server name specified by *lpszServer* is a stand-alone server (that is, the server or workstation is not a member of a domain), then the server name itself is returned in the *lpszUserAccountServer* buffer.

Then use the name of the user account server in a call to the [**NetQueryDisplayInformation**](https://learn.microsoft.com/windows/win32/api/lmaccess/nf-lmaccess-netquerydisplayinformation) function to enumerate the users in the user account database.

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

[**GetComputerName**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getcomputernamea)

[**RasAdminUserGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusergetinfo)

[**RasAdminUserSetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusersetinfo)

