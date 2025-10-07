# RasAdminPortDisconnect function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminPortDisconnect**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradminportdisconnect) function.\]

The **RasAdminPortDisconnect** function disconnects a port that is currently in use.

## Parameters

*lpszServer* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the Windows NT/Windows 2000 RAS server. Specify the name with leading "\\\\" characters, in the form: \\\\*servername*.

*lpszPort* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the port on the server.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value can be one of the following error codes.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------|----------------------------------------------|
| **ERROR\_INVALID\_PORT** | The specified port is invalid.<br> |
| **NERR\_UserNotFound** | The port is not currently in use.<br> |

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

