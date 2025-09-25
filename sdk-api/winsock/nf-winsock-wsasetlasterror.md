# WSASetLastError function

## Description

The
**WSASetLastError** function sets the error code that can be retrieved through the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function.

## Parameters

### `iError` [in]

Integer that specifies the error code to be returned by a subsequent
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) call.

## Return value

This function generates no return values.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |

## Remarks

The
**WSASetLastError** function allows an application to set the error code to be returned by a subsequent
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) call for the current thread. Note that any subsequent Windows Sockets routine called by the application will override the error code as set by this routine.

The error code set by
**WSASetLastError** is different from the error code returned by calling the function
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) with SO_ERROR.

The Windows Sockets error codes used by this function are listed under [Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)