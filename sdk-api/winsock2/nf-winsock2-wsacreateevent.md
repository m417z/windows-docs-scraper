# WSACreateEvent function

## Description

The
**WSACreateEvent** function creates a new event object.

## Return value

If no error occurs,
**WSACreateEvent** returns the handle of the event object. Otherwise, the return value is WSA_INVALID_EVENT. To get extended error information, call
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Not enough free memory available to create the event object. |

## Remarks

The
**WSACreateEvent** function creates a manual-reset event object with an initial state of nonsignaled. The handle of the event object returned cannot be inherited by child processes.
The event object is unnamed.

The [WSASetEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasetevent) function can be called to set the state of the event object to signaled. The [WSAResetEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaresetevent) function can be called to set the state of the event object to nonsignaled. When an event object is no longer needed, the [WSACloseEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacloseevent) function should be called to free the resources associated with the event object.

Windows Sockets 2 event objects are system objects in Windows environments. Therefore, if a Windows application wants to use an auto-reset event rather than a manual-reset event, the application can call the [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function directly. The scope of an event object is limited to the process in which it is created.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[WSACloseEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacloseevent)

[WSAEnumNetworkEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnetworkevents)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom)

[WSAResetEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaresetevent)

[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)

[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto)

[WSASetEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasetevent)

[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)