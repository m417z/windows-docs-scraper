# WSASendMsg function

## Description

The **WSASendMsg** function sends data and optional control information from connected and unconnected sockets.

**Note** This function is a Microsoft-specific extension to the Windows Sockets specification.

## Parameters

### `Handle` [in]

A descriptor identifying the socket.

### `lpMsg` [in]

A [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure storing the Posix.1g **msghdr** structure.

### `dwFlags` [in]

The flags used to modify the behavior of the **WSASendMsg** function call. For more information, see Using *dwFlags* in the Remarks section.

### `lpNumberOfBytesSent` [out]

A pointer to the number, in bytes, sent by this call if the I/O operation completes immediately.

Use **NULL** for this parameter if the *lpOverlapped* parameter is not **NULL** to avoid potentially erroneous results. This parameter can be **NULL** only if the *lpOverlapped* parameter is not **NULL**.

### `lpOverlapped` [in]

A pointer to a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure. Ignored for non-overlapped sockets.

### `lpCompletionRoutine` [in]

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

A pointer to the completion routine called when the send operation completes. Ignored for non-overlapped sockets.

## Return value

Returns zero when successful and immediate completion occurs. When zero is returned, the specified completion routine is called when the calling thread is in the alertable state.

A return value of **SOCKET_ERROR**, and subsequent call to [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) that returns WSA_IO_PENDING, indicates the overlapped operation has successfully initiated; completion is then indicated through other means, such as through events or completion ports.

Upon failure, returns **SOCKET_ERROR** and a subsequent call to [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) returns a value other than **WSA_IO_PENDING**. The following table lists error codes.

| Error code | Meaning |
| --- | --- |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested address is a broadcast address, but the appropriate flag was not set. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a UDP datagram socket, this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpMsg*, *lpNumberOfBytesSent*, *lpOverlapped*, or *lpCompletionRoutine* parameter is not totally contained in a valid part of the user address space. This error is also returned if a **name** member of the [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter was a **NULL** pointer and the **namelen** member of the **WSAMSG** structure was not set to zero. This error is also returned if a **Control.buf** member of the **WSAMSG** structure pointed to by the *lpMsg* parameter was a **NULL** pointer and the **Control.len** member of the **WSAMSG** structure was not set to zero. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), or the socket was not created with the overlapped flag. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is message oriented, and the message is larger than the maximum supported by the underlying transport. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a datagram socket, this error indicates that the time to live has expired. |
| **[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network is unreachable. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The Windows Sockets provider reports a buffer deadlock. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket operation is not supported. This error is returned if the **dwFlags** member of the [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter includes any control flags invalid for [WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg). |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has been shut down; it is not possible to call the [WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg) function on a socket after [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) has been invoked with *how* set to SD_SEND or SD_BOTH. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket timed out. This error is returned if the socket had a wait timeout specified using the **SO_SNDTIMEO** socket option and the timeout was exceeded. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Overlapped sockets: There are too many outstanding overlapped I/O requests. Nonoverlapped sockets: The socket is marked as nonblocking and the send operation cannot be completed immediately. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An overlapped operation was successfully initiated and completion will be indicated at a later time. |
| **[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The overlapped operation has been canceled due to the closure of the socket or due to the execution of the **SIO_FLUSH** command in [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl). |

## Remarks

 The **WSASendMsg** function can be used in place of the [WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend) and [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) functions. The **WSASendMsg** function can only be used with datagrams and raw sockets. The socket descriptor in the *s* parameter must be opened with the socket type set to **SOCK_DGRAM** or **SOCK_RAW**.

The *dwFlags* parameter can only contain a combination of the following control flags: **MSG_DONTROUTE**, **MSG_PARTIAL**, and **MSG_OOB**. The **dwFlags** member of the [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter is ignored on input and not used on output.

**Note** The function pointer for the
**WSASendMsg** function must be obtained at run time by making a call to the
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO_GET_EXTENSION_FUNCTION_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID_WSASENDMSG**, a globally unique identifier (GUID) whose value identifies the **WSASendMsg** extension function. On success, the output returned by the **WSAIoctl** function contains a pointer to the **WSASendMsg** function. The **WSAID_WSASENDMSG** GUID is defined in the *Mswsock.h* header file.

Overlapped sockets are created with a [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) function call that has the **WSA_FLAG_OVERLAPPED** flag set. For overlapped sockets, sending information uses overlapped I/O unless both *lpOverlapped* and *lpCompletionRoutine* are **NULL**; when *lpOverlapped* and *lpCompletionRoutine* are **NULL**, the socket is treated as a nonoverlapped socket. A completion indication occurs with overlapped sockets; once the buffer or buffers have been consumed by the transport, a completion routine is triggered or an event object is set. If the operation does not complete immediately, the final completion status is retrieved through the completion routine or by calling the [WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) function.

For nonoverlapped sockets, the *lpOverlapped* and *lpCompletionRoutine* parameters are ignored and **WSASendMsg** adopts the same blocking semantics as the [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) function: data is copied from the buffer or buffers into the transport's buffer. If the socket is nonblocking and stream oriented, and there is insufficient space in the transport's buffer, **WSASendMsg** returns with only part of the application's buffers having been consumed. In contrast, this buffer situation on a blocking socket results in **WSASendMsg** blocking until all of the application's buffer contents have been consumed.

If this function is completed in an overlapped manner, it is the Winsock service provider's responsibility to capture this [WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure before returning from this call. This enables applications to build stack-based
**WSABUF** arrays pointed to by the **lpBuffers** member of the [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter.

For message-oriented sockets, care must be taken not to exceed the maximum message size of the underlying provider, which can be obtained by getting the value of socket option **SO_MAX_MSG_SIZE**. If the data is too long to pass atomically through the underlying protocol, the error **WSAEMSGSIZE** is returned and no data is transmitted.

On an IPv4 socket of type **SOCK_DGRAM** or **SOCK_RAW**, an application can specific the local IP source address to use for sending with the **WSASendMsg** function. One of the control data objects passed in the [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure to the **WSASendMsg** function may contain an
[in_pktinfo](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-in_pktinfo) structure used to specify the local IPv4 source address to use for sending.

On an IPv6 socket of type **SOCK_DGRAM** or **SOCK_RAW**, an application can specific the local IP source address to use for sending with the **WSASendMsg** function. One of the control data objects passed in the [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure to the **WSASendMsg** function may contain an
[in6_pktinfo](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-in6_pktinfo) structure used to specify the local IPv6 source address to use for sending.

For a dual-stack socket when sending datagrams with the **WSASendMsg** function and an application wants to specify a specific local IP source address to be used, the method to handle this depends on the destination IP address. When sending to an IPv4 destination address or an IPv4-mapped IPv6 destination address, one of the control data objects passed in the [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter should contain an
[in_pktinfo](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-in_pktinfo) structure containing the local IPv4 source address to use for sending. When sending to an IPv6 destination address that is not a an IPv4-mapped IPv6 address, one of the control data objects passed in the **WSAMSG** structure pointed to by the *lpMsg* parameter should contain an
[in6_pktinfo](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-in6_pktinfo) structure containing the local IPv6 source address to use for sending.

**Note** The **SO_SNDTIMEO** socket option applies only to blocking sockets.

**Note** The successful completion of a
**WSASendMsg** does not indicate that the data was successfully delivered.

**Note** When issuing a blocking Winsock call such as **WSASendMsg** with the *lpOverlapped* parameter set to NULL, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### dwFlags

The *dwFlags* input parameter can be used to influence the behavior of the function invocation beyond the options specified for the associated socket. That is, the semantics of this function are determined by the socket options and the *dwFlags* parameter. The latter is constructed by using the bitwise OR operator with any of the following values.

| Value | Meaning |
| --- | --- |
| **MSG_DONTROUTE** | Specifies that the data should not be subject to routing. A Windows Sockets service provider can choose to ignore this flag. |
| **MSG_PARTIAL** | Specifies that *lpMsg->lpBuffers* contains only a partial message. Note that the error code [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) will be returned by transports that do not support partial message transmissions. |

The possible values for *dwFlags* parameter are defined in the *Winsock2.h* header file.

On output, the **dwFlags** member of the [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter is not used.

### Overlapped Socket I/O

If an overlapped operation completes immediately,
**WSASendMsg** returns a value of zero and the *lpNumberOfBytesSent* parameter is updated with the number of bytes sent. If the overlapped operation is successfully initiated and will complete later,
**WSASendMsg** returns SOCKET_ERROR and indicates error code
[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). In this case, *lpNumberOfBytesSent* is not updated. When the overlapped operation completes, the amount of data transferred is indicated either through the *cbTransferred* parameter in the completion routine (if specified) or through the *lpcbTransfer* parameter in
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult).

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

The
**WSASendMsg** function using overlapped I/O can be called from within the completion routine of a previous
, [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv),
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom), [LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg), [WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend), **WSASendMsg**, or
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) function. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

The *lpOverlapped* parameter must be valid for the duration of the overlapped operation. If multiple I/O operations are simultaneously outstanding, each must reference a separate
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure.

If the *lpCompletionRoutine* parameter is **NULL**, the *hEvent* parameter of *lpOverlapped* is signaled when the overlapped operation completes if it contains a valid event object handle. An application can use
[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents) or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) to wait or poll on the event object.

If *lpCompletionRoutine* is not **NULL**, the *hEvent* parameter is ignored and can be used by the application to pass context information to the completion routine. A caller that passes a non-**NULL** *lpCompletionRoutine* and later calls
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) for the same overlapped I/O request may not set the *fWait* parameter for that invocation of
**WSAGetOverlappedResult** to **TRUE**. In this case, the usage of the *hEvent* parameter is undefined, and attempting to wait on the *hEvent* parameter would produce unpredictable results.

The completion routine follows the same rules as stipulated for Windows file I/O completion routines. The completion routine will not be invoked until the thread is in an alertable wait state, for example, with [WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents) called with the *fAlertable* parameter set to **TRUE**.

The transport providers allow an application to invoke send and receive operations from within the context of the socket I/O completion routine, and guarantee that, for a given socket, I/O completion routines will not be nested. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

The prototype of the completion routine is as follows.

```cpp

void CALLBACK CompletionRoutine(
  IN DWORD dwError,
  IN DWORD cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD dwFlags
);

```

The **CompletionRoutine** function is a placeholder for an application-defined or library-defined function name. The *dwError* parameter specifies the completion status for the overlapped operation as indicated by the *lpOverlapped* parameter. The *cbTransferred* parameter indicates the number of bytes sent. Currently there are no flag values defined and the *dwFlags* parameter will be zero. The **CompletionRoutine** function does not return a value.

Returning from this function allows invocation of another pending completion routine for the socket. All waiting completion routines are called before the alertable thread's wait is satisfied with a return code of WSA_IO_COMPLETION. The completion routines can be called in any order, not necessarily in the same order the overlapped operations are completed. However, the posted buffers are guaranteed to be sent in the same order they are specified.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[IPV6_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ipv6-pktinfo)

[IP_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ip-pktinfo)

[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf)

[WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)

[WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg)

[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped)

[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)

[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[in6_pktinfo](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-in6_pktinfo)

[in_pktinfo](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-in_pktinfo)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown)