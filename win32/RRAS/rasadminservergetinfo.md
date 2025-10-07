# RasAdminServerGetInfo function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminServerGetInfo**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradminservergetinfo) function.\]

The **RasAdminServerGetInfo** function gets the server configuration of a RAS server.

## Parameters

*lpszServer* \[in\]

Pointer to a **null**-terminated Unicode string that specifies the name of the Windows NT/Windows 2000 RAS server. If this parameter is **NULL**, the function returns information about the local computer. Specify the name with leading "\\\\" characters, in the form: \\\\*servername*.

*pRasServer0* \[out\]

Pointer to the [**RAS\_SERVER\_0**](https://learn.microsoft.com/windows/win32/rras/ras-server-0-str) structure that receives the number of ports configured on the server, the number of ports currently in use, and the server version number.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is an error code. Possible error codes include those returned by [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for the [**CallNamedPipe**](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-callnamedpipea) function. There is no extended error information for this function; do not call **GetLastError**.

## Remarks

To enumerate all RAS servers in a domain, call the [**NetServerEnum**](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserverenum) function and specify SV\_TYPE\_DIALIN for the *servertype* parameter.

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

[**NetServerEnum**](https://learn.microsoft.com/windows/win32/api/lmserver/nf-lmserver-netserverenum)

[**RAS\_SERVER\_0**](https://learn.microsoft.com/windows/win32/rras/ras-server-0-str)

