# WSAGetOverlappedResult function

## Description

The
**WSAGetOverlappedResult** function retrieves the results of an overlapped operation on the specified socket.

## Parameters

### `s` [in]

A descriptor identifying the socket.

This is the same socket that was specified when the overlapped operation was started by a call to
any of the Winsock functions that supports overlapped operations. These functions include [AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex), [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex), [DisconnectEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms737757(v=vs.85)), [TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile), [TransmitPackets](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_transmitpackets), [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv),
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom),
[LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg), [WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend),
[WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg), [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto), and
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl).

### `lpOverlapped` [in]

A pointer to a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure that was specified when the overlapped operation was started. This parameter must not be a **NULL** pointer.

### `lpcbTransfer` [out]

A pointer to a 32-bit variable that receives the number of bytes that were actually transferred by a send or receive operation, or by
the [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function. This parameter must not be a **NULL** pointer.

### `fWait` [in]

A flag that specifies whether the function should wait for the pending overlapped operation to complete. If **TRUE**, the function does not return until the operation has been completed. If **FALSE** and the operation is still pending, the function returns **FALSE** and the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function returns WSA_IO_INCOMPLETE. The *fWait* parameter may be set to **TRUE** only if the overlapped operation selected the event-based completion notification.

### `lpdwFlags` [out]

A pointer to a 32-bit variable that will receive one or more flags that supplement the completion status. If the overlapped operation was initiated through
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) or
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom), this parameter will contain the results value for *lpFlags* parameter. This parameter must not be a **NULL** pointer.

## Return value

If
**WSAGetOverlappedResult** succeeds, the return value is **TRUE**. This means that the overlapped operation has completed successfully and that the value pointed to by *lpcbTransfer* has been updated.

If
**WSAGetOverlappedResult** returns **FALSE**, this means that either the overlapped operation has not completed, the overlapped operation completed but with errors, or the overlapped operation's completion status could not be determined due to errors in one or more parameters to
**WSAGetOverlappedResult**. On failure, the value pointed to by *lpcbTransfer* will not be updated. Use
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) to determine the cause of the failure (either by the **WSAGetOverlappedResult** function or by the associated overlapped operation).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *hEvent* parameter of the [WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure does not contain a valid event object handle. |
| **[WSA_INVALID_PARAMETER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One of the parameters is unacceptable. |
| **[WSA_IO_INCOMPLETE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *fWait* parameter is **FALSE** and the I/O operation has not yet completed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the *lpOverlapped*, *lpcbTransfer*, or *lpdwFlags* parameters are not in a valid part of the user address space. This error is returned if the *lpOverlapped*, *lpcbTransfer*, or *lpdwFlags* parameter was a **NULL** pointer on Windows Server 2003 and earlier. |

## Remarks

The
**WSAGetOverlappedResult** function reports the results of the overlapped operation specified in the *lpOverlapped* parameter for the socket specified in the *s* parameter. The
**WSAGetOverlappedResult** function is passed the socket descriptor and the
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure that was specified when the overlapped function was called. A pending operation is indicated when the function that started the operation returns **FALSE** and the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function returns [WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). When an I/O operation such as
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) is pending, the function that started the operation resets the *hEvent* member of the
**WSAOVERLAPPED** structure to the nonsignaled state. Then, when the pending operation has completed, the system sets the event object to the signaled state.

If the *fWait* parameter is **TRUE**,
**WSAGetOverlappedResult** determines whether the pending operation has been completed by waiting for the event object to be in the signaled state. A client may set the *fWait* parameter to **TRUE**, but only if it selected event-based completion notification when the I/O operation was requested. If another form of notification was selected, the usage of the *hEvent* parameter of the
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure is different, and setting *fWait* to **TRUE** causes unpredictable results.

If the **WSAGetOverlappedResult** function is called with the *lpOverlapped*, *lpcbTransfer*, or *lpdwFlags* parameter set to a **NULL** pointer on Windows Vista, this will result in an access violation. If the **WSAGetOverlappedResult** function is called with the *lpOverlapped*, *lpcbTransfer*, or *lpdwFlags* parameter set to a **NULL** pointer on Windows Server 2003 and earlier, this will result in the [WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) error code being returned.

**Note** All I/O is canceled when a thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom)

[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)

[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto)

[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)