# WSADuplicateSocketW function

## Description

The
**WSADuplicateSocket** function returns a
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure that can be used to create a new socket descriptor for a shared socket. The
**WSADuplicateSocket** function cannot be used on a QOS-enabled socket.

## Parameters

### `s` [in]

Descriptor identifying the local socket.

### `dwProcessId` [in]

Process identifier of the target process in which the duplicated socket will be used.

### `lpProtocolInfo` [out]

Pointer to a buffer, allocated by the client, that is large enough to contain a
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure. The service provider copies the protocol information structure contents to this buffer.

## Return value

If no error occurs,
**WSADuplicateSocket** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Indicates that one of the specified parameters was invalid. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEMFILE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No more socket descriptors are available. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. The socket cannot be created. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpProtocolInfo* parameter is not a valid part of the user address space. |

## Remarks

The
**WSADuplicateSocket** function is used to enable socket sharing between processes. A source process calls
**WSADuplicateSocket** to obtain a special
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure. It uses some interprocess communications (IPC) mechanism to pass the contents of this structure to a target process, which in turn uses it in a call to
[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) to obtain a descriptor for the duplicated socket. The special
**WSAPROTOCOL_INFO** structure can only be used once by the target process.

Sockets can be shared among threads in a given process without using the
**WSADuplicateSocket** function because a socket descriptor is valid in all threads of a process.

One possible scenario for establishing and handing off a shared socket is illustrated in the following table.

| Source process | IPC | Destination process |
| --- | --- | --- |
| 1) [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa), [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) |  |  |
| 2) Request target process identifier | ==> |  |
|  |  | 3) Receive process identifier request and respond |
| 4) Receive process identifier | <== |  |
| 5) Call **WSADuplicateSocket** to get a special [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure |  |  |
| 6) Send [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure to target |  |  |
|  | ==> | 7) Receive [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure |
|  |  | 8) Call [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) to create shared socket descriptor. |
|  |  | 9) Use shared socket for data exchange |
| 10) [closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) | <== |  |

The descriptors that reference a shared socket can be used independently for I/O. However, the Windows Sockets interface does not implement any type of access control, so it is up to the processes involved to coordinate their operations on a shared socket. Shared sockets are typically used to having one process that is responsible for creating sockets and establishing connections, and other processes that are responsible for information exchange.

All of the state information associated with a socket is held in common across all the descriptors because the socket descriptors are duplicated and not the actual socket. For example, a
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) operation performed using one descriptor is subsequently visible using a
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) from any or all descriptors. Both the source process and the destination process should pass the same flags to their respective [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) function calls. If the source process uses the [socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) function to create the socket, the destination process must pass the **WSA_FLAG_OVERLAPPED** flag to its **WSASocket** function call. A process can call
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) on a duplicated socket and the descriptor will become deallocated. The underlying socket, however, will remain open until
**closesocket** is called by the last remaining descriptor.

Notification on shared sockets is subject to the usual constraints of
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) and
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect). Issuing either of these calls using any of the shared descriptors cancels any previous event registration for the socket, regardless of which descriptor was used to make that registration. Thus, a shared socket cannot deliver FD_READ events to process A and FD_WRITE events to process B. For situations when such tight coordination is required, developers would be advised to use threads instead of separate processes.

**Windows 8.1** and **Windows Server 2012 R2**: The **WSADuplicateSocketW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The winsock2.h header defines WSADuplicateSocket as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)