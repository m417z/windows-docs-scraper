# RasAdminPortGetInfo function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminPortGetInfo**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradminportgetinfo) function.\]

The **RasAdminPortGetInfo** function retrieves information about a specified port on a specified server.

## Parameters

*lpszServer* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the RAS server. Specify the name with leading "\\\\" characters, in the form: \\\\*servername*.

*lpszPort* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the port on the server.

*pRasPort1* \[out\]

Pointer to the [**RAS\_PORT\_1**](https://learn.microsoft.com/windows/win32/rras/ras-port-1-str) structure that the function fills in with information about the state of the port.

*pRasStats* \[out\]

Pointer to the [**RAS\_PORT\_STATISTICS**](https://learn.microsoft.com/windows/win32/rras/ras-port-statistics-str) structure that the function fills in with statistics about the port.

*ppRasParams* \[out\]

Pointer to a pointer variable that receives the address of an array of [**RAS\_PARAMETERS**](https://learn.microsoft.com/windows/win32/rras/ras-parameters-str) structures. Each structure contains the name of a media-specific key, such as MAXCONNECTBPS, and its associated value. When the application is finished with this memory, free it by calling the [**RasAdminFreeBuffer**](https://learn.microsoft.com/windows/win32/rras/rasadminfreebuffer) function.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value can be one of the following error codes.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------|
| **ERROR\_DEV\_NOT\_EXIST** | The specified port is invalid.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | Insufficient memory to allocate a buffer for the *ppRasParams* array.<br> |

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

[**RAS\_PARAMETERS**](https://learn.microsoft.com/windows/win32/rras/ras-parameters-str)

[**RAS\_PORT\_1**](https://learn.microsoft.com/windows/win32/rras/ras-port-1-str)

[**RAS\_PORT\_STATISTICS**](https://learn.microsoft.com/windows/win32/rras/ras-port-statistics-str)

[**RasAdminFreeBuffer**](https://learn.microsoft.com/windows/win32/rras/rasadminfreebuffer)

