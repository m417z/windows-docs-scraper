# RasAdminFreeBuffer function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminBufferFree**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradminbufferfree) function.\]

The **RasAdminFreeBuffer** function frees memory that was allocated by RAS on behalf of the caller.

## Parameters

*Pointer* \[in\]

Pointer to the buffer to be freed.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value can be the following error code.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------|------------------------------------------------|
| **ERROR\_INVALID\_PARAMETER** | The *Pointer* parameter is invalid.<br> |

There is no extended error information for this function; do not call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Use the **RasAdminFreeBuffer** function to free the buffers allocated by the [**RasAdminPortEnum**](https://learn.microsoft.com/windows/win32/rras/rasadminportenum) and [**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo) functions.

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

[**RasAdminPortEnum**](https://learn.microsoft.com/windows/win32/rras/rasadminportenum)

[**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo)

