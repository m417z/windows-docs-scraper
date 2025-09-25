# WSAGetLastError function

## Description

The
**WSAGetLastError** function returns the error status for the last Windows Sockets operation that failed.

## Return value

The return value indicates the error code for this thread's last Windows Sockets operation that failed.

## Remarks

The
**WSAGetLastError** function returns the last error that occurred for the calling thread. When a particular Windows Sockets function indicates an error has occurred, this function should be called immediately to retrieve the extended error code for the failing function call. This extended error code can be different from the error code obtained from
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) when called with an *optname* parameter of **SO_ERROR**, which is socket-specific since
**WSAGetLastError** is for all thread-specific sockets.

If a function call's return value indicates that error or other relevant data was returned in the error code, **WSAGetLastError** should be called immediately. This is necessary because some functions may reset the last extended error code to 0 if they succeed, overwriting the extended error code returned by a previously failed function. To specifically reset the extended error code, use the
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror) function call with the *iError* parameter set to zero. A
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function when called with an *optname* parameter of **SO_ERROR** also resets the extended error code to zero.

The
**WSAGetLastError** function should not be used to check for an extended error value on receipt of an asynchronous message. In this case, the extended error value is passed in the *lParam* parameter of the message, and this can differ from the value returned by
**WSAGetLastError**.

**Note** An application can call the **WSAGetLastError** function to determine the extended error code for other Windows sockets functions as is normally done in Windows Sockets even if
the [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function fails or the **WSAStartup** function was not called to properly initialize Windows Sockets before calling a Windows Sockets function. The **WSAGetLastError** function is one of the only functions in the Winsock 2.2 DLL that can be called in the case of a **WSAStartup** failure.

The Windows Sockets extended error codes returned by this function and the text description of the error are listed under [Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). These error codes and a short text description associated with an error code are defined in the *Winerror.h* header file. The [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function can be used to obtain the message string for the returned error.

For information on how to handle error codes when porting socket applications to Winsock, see [Error Codes - errno, h_errno and WSAGetLastError](https://learn.microsoft.com/windows/desktop/WinSock/error-codes-errno-h-errno-and-wsagetlasterror-2).

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[Error Codes - errno, h_errno and WSAGetLastError](https://learn.microsoft.com/windows/desktop/WinSock/error-codes-errno-h-errno-and-wsagetlasterror-2)

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)