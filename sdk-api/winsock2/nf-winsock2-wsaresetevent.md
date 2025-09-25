# WSAResetEvent function

## Description

The
**WSAResetEvent** function resets the state of the specified event object to nonsignaled.

## Parameters

### `hEvent` [in]

A handle that identifies an open event object handle.

## Return value

If the
**WSAResetEvent** function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *hEvent* parameter is not a valid event object handle. |

## Remarks

The
**WSAResetEvent** function is used to set the state of the event object to nonsignaled.

The proper way to reset the state of an event object used with the [WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) function is to pass the handle of the event object to the [WSAEnumNetworkEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnetworkevents) function in the *hEventObject* parameter. This will reset the event object and adjust the status of active FD events on the socket in an atomic fashion.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSACloseEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacloseevent)

[WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent)

[WSAEnumNetworkEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnetworkevents)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[WSASetEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasetevent)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)