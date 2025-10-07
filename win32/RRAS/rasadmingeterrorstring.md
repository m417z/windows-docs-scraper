# RasAdminGetErrorString function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminGetErrorString**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradmingeterrorstring) function.\]

The **RasAdminGetErrorString** function retrieves a message string that corresponds to a RAS error code returned by one of the RAS server administration (RasAdmin) functions. These message strings are retrieved from the Rasmsg.dll that is installed as part of RAS.

## Parameters

*ResourceId* \[in\]

Specifies an error code returned by one of the RasAdmin functions. This value must be in the range of error codes from RASBASE to RASBASEEND. These are defined in Raserror.h.

*lpszString* \[out\]

Pointer to a buffer that receives the error message that corresponds to the specified error code.

*InBufSize* \[in\]

Specifies the size, in characters, of the *lpszString* buffer. Error messages are typically 80 characters or less; a buffer size of 512 characters is always adequate.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is an error code. This value can be a last error value set by the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya), [**GlobalAlloc**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalalloc), or [**LoadString**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadstringa) functions; or it can be one of the following error codes.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **ERROR\_INVALID\_PARAMETER** | The *ResourceId* or *lpszString* parameters are invalid.<br> |
| **ERROR\_INSUFFICIENT\_BUFFER** | The size specified by the *InBufSize* parameter is too small.<br> |

There is no extended error information for this function; do not call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The RasAdmin functions can return error codes that are not in the range supported by the **RasAdminGetErrorString** function. For example, the RasAdmin functions can return error codes that are defined in Lmerr.h and Winerror.h. Before calling **RasAdminGetErrorString**, verify that the error code is in the range RASBASE to RASBASEEND, as defined in Raserror.h.

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

[**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[**GlobalAlloc**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalalloc)

[**LoadString**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadstringa)

