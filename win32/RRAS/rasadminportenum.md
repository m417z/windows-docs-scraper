# RasAdminPortEnum function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminPortEnum**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradminportenum) function.\]

The **RasAdminPortEnum** function enumerates all ports on the specified RAS server. For each port on the server, the function returns the [**RAS\_PORT\_0**](https://learn.microsoft.com/windows/win32/rras/ras-port-0-str) structure that contains information about the port.

## Parameters

*lpszServer* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the RAS server. Specify the name with leading "\\\\" characters, in the form: \\\\*servername*.

*ppRasPort0* \[out\]

Pointer to a variable that receives a pointer to a buffer that contains an array of [**RAS\_PORT\_0**](https://learn.microsoft.com/windows/win32/rras/ras-port-0-str) structures. When the application has finished with the memory, free it by calling the [**RasAdminFreeBuffer**](https://learn.microsoft.com/windows/win32/rras/rasadminfreebuffer) function.

*pcEntriesRead* \[out\]

Pointer to a 16-bit variable that receives the total number of [**RAS\_PORT\_0**](https://learn.microsoft.com/windows/desktop/api/Mprapi/ns-mprapi-ras_port_0) structures returned in the *ppRasPort0* array.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value can be the following error code.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------|
| **NERR\_ItemNotFound** | No ports could be enumerated. This could be because all configured ports on the server are currently being used for dialing out.<br> |

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

[**RAS\_PORT\_0**](https://learn.microsoft.com/windows/win32/rras/ras-port-0-str)

[**RasAdminFreeBuffer**](https://learn.microsoft.com/windows/win32/rras/rasadminfreebuffer)

