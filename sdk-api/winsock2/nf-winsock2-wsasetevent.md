# WSASetEvent function

## Description

The
**WSASetEvent** function sets the state of the specified event object to signaled.

## Parameters

### `hEvent` [in]

Handle that identifies an open event object.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To get extended error information, call
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *hEvent* parameter is not a valid event object handle. |

## Remarks

The
**WSASetEvent** function sets the state of the event object to be signaled.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSACloseEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacloseevent)

[WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent)

[WSAResetEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaresetevent)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)