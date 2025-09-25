## Description

**LPFN_WSARECVMSG** is a function pointer type. You implement a matching **WSARecvMsg** callback function in your app. The system uses your callback function to transmit to you in-memory data, or file data, over a connected socket.

Your **WSARecvMsg** callback function receives ancillary data/control information with a message, from connected and unconnected sockets.

> [!NOTE]
> This function is a Microsoft-specific extension to the Windows Sockets specification.

## Parameters

### `s`

Type: \_In\_ **SOCKET**

A descriptor that identifies the socket.

### `lpMsg`

Type: \_Inout\_ **[LPWSAMSG](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg)**

A pointer to a [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure based on the Posix.1g specification for the msghdr structure.

### `lpdwNumberOfBytesRecvd`

Type: \_Out_opt\_ **[LPDWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A pointer to a **DWORD** containing number of bytes received by this call if the **WSARecvMsg** operation completes immediately.

To avoid potentially erroneous results, pass **NULL** for this parameter if the *lpOverlapped* parameter is not **NULL** . This parameter can be **NULL** only if the *lpOverlapped* parameter is not **NULL**.

### `lpOverlapped`

Type: \_Inout_opt\_ **[LPWSAOVERLAPPED](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)**

A pointer to a [**WSAOVERLAPPED**](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped) structure. Ignored for non-overlapped structures.

### `lpCompletionRoutine`

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

A pointer to the completion routine called when the receive operation completes. Ignored for non-overlapped structures.

## Return value

If no error occurs and the receive operation has completed immediately, **WSARecvMsg** returns zero. In this case, the completion routine will have already been scheduled to be called once the calling thread is in the alertable state. Otherwise, a value of SOCKET\_ERROR is returned, and a specific error code can be retrieved by calling [**WSAGetLastError**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror). The error code **WSA\_IO\_PENDING** indicates that the overlapped operation has been successfully initiated and that completion will be indicated at a later time.

Any other error code indicates that the operation was not successfully initiated and no completion indication will occur if an overlapped operation was requested.

| Error code | Meaning |
| --- | --- |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | For a UDP datagram socket, this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | The *lpBuffers*, *lpFlags*, *lpFrom*, *lpNumberOfBytesRecvd*, *lpFromlen*, *lpOverlapped*, or *lpCompletionRoutine* parameter is not totally contained in a valid part of the user address space: the *lpFrom* buffer was too small to accommodate the peer address. This error is also returned if a **name** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter was a **NULL** pointer and the **namelen** member of the **WSAMSG** structure was not set to zero. This error is also returned if a **Control.buf** member of the **WSAMSG** structure pointed to by the *lpMsg* parameter was a **NULL** pointer and the **Control.len** member of the **WSAMSG** structure was not set to zero. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | The socket has not been bound (with [**bind**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-bind), for example). |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | The message was too large to fit into the specified buffer and (for unreliable protocols only) any trailing portion of the message that did not fit into the buffer has been discarded. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | For a datagram socket, this error indicates that the time to live has expired. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | The socket is not connected (connection-oriented sockets only). |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | The socket timed out. This error is returned if the socket had a wait timeout specified using the **SO_RCVTIMEO** socket option and the timeout was exceeded. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | The socket operation is not supported. This error is returned if the **dwFlags** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter includes the **MSG_PEEK** control flag on a non-datagram socket. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | **Windows NT:**<br><br>Overlapped sockets: There are too many outstanding overlapped I/O requests. Non-overlapped sockets: The socket is marked as nonblocking and the receive operation cannot be completed immediately. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | A successful [**WSAStartup**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | An overlapped operation was successfully initiated and completion will be indicated at a later time. |
| **[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2)** | The overlapped operation has been canceled due to the closure of the socket. |

## Remarks

The **WSARecvMsg** function can be used in place of the [**WSARecv**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsarecv) and [**WSARecvFrom**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsarecvfrom) functions to receive data and optional control information from connected and unconnected sockets. The **WSARecvMsg** function can only be used with datagrams and raw sockets. The socket descriptor in the *s* parameter must be opened with the socket type set to **SOCK\_DGRAM** or **SOCK\_RAW**.

**Note** The function pointer for the **WSARecvMsg** function must be obtained at run time by making a call to the [**WSAIoctl**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO\_GET\_EXTENSION\_FUNCTION\_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID\_WSARECVMSG**, a globally unique identifier (GUID) whose value identifies the **WSARecvMsg** extension function. On success, the output returned by the **WSAIoctl** function contains a pointer to the **WSARecvMsg** function. The **WSAID\_WSARECVMSG** GUID is defined in the *Mswsock.h* header file.

The **dwFlags** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter may only contain the **MSG\_PEEK** control flag on input.

Overlapped sockets are created with a [**WSASocket**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasocketa) function call that has the **WSA\_FLAG\_OVERLAPPED** flag set. For overlapped sockets, receiving information uses overlapped I/O unless both the *lpOverlapped* and *lpCompletionRoutine* parameters are **NULL**. The socket is treated as a non-overlapped socket when both the *lpOverlapped* and *lpCompletionRoutine* parameters are **NULL**.

A completion indication occurs with overlapped sockets. Once the buffer or buffers have been consumed by the transport, a completion routine is triggered or an event object is set. If the operation does not complete immediately, the final completion status is retrieved through the completion routine or by calling the [**WSAGetOverlappedResult**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsagetoverlappedresult) function.

For overlapped sockets, **WSARecvMsg** is used to post one or more buffers into which incoming data will be placed as it becomes available, after which the application-specified completion indication (invocation of the completion routine or setting of an event object) occurs. If the operation does not complete immediately, the final completion status is retrieved through the completion routine or the [**WSAGetOverlappedResult**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsagetoverlappedresult) function.

For non-overlapped sockets, the blocking semantics are identical to that of the standard [**recv**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-recv) function and the *lpOverlapped* and *lpCompletionRoutine* parameters are ignored. Any data that has already been received and buffered by the transport will be copied into the specified user buffers. In the case of a blocking socket with no data currently having been received and buffered by the transport, the call will block until data is received. Windows Sockets 2 does not define any standard blocking time-out mechanism for this function. For protocols acting as byte-stream protocols the stack tries to return as much data as possible subject to the available buffer space and amount of received data available. However, receipt of a single byte is sufficient to unblock the caller. There is no guarantee that more than a single byte will be returned. For protocols acting as message-oriented, a full message is required to unblock the caller.

**Note** The **SO\_RCVTIMEO** socket option applies only to blocking sockets.

The buffers are filled in the order in which they appear in the array pointed to by the **lpBuffers** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter, and the buffers are packed so that no holes are created.

If this function is completed in an overlapped manner, it is the Winsock service provider's responsibility to capture this [**WSABUF**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) structure before returning from this call. This enables applications to build stack-based **WSABUF** arrays pointed to by the **lpBuffers** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter.

For message-oriented sockets (a socket type of **SOCK\_DGRAM** or **SOCK\_RAW**), an incoming message is placed into the buffers up to the total size of the buffers, and the completion indication occurs for overlapped sockets. If the message is larger than the buffers, the buffers are filled with the first part of the message and the excess data is lost, and **WSARecvMsg** generates the error WSAEMSGSIZE.

When the [IP\_PKTINFO](https://learn.microsoft.com/windows/win32/WinSock/ip-pktinfo) socket option is enabled on an IPv4 socket of type **SOCK\_DGRAM** or **SOCK\_RAW**, the **WSARecvMsg** function returns packet information in the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter. One of the control data objects in the returned **WSAMSG** structure will contain an [**in\_pktinfo**](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-in_pktinfo) structure used to store received packet address information.

For datagrams received over IPv4, the **Control** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure received will contain a [**WSABUF**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) structure that contains a **WSACMSGHDR** structure. The **cmsg\_level** member of this **WSACMSGHDR** structure would contain **IPPROTO\_IP**, the **cmsg\_type** member of this structure would contain **IP\_PKTINFO**, and the **cmsg\_data** member would contain an [**in\_pktinfo**](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-in_pktinfo) structure used to store received IPv4 packet address information. The IPv4 address in the **in\_pktinfo** structure is the IPv4 address from which the packet was received.

When the [IPV6\_PKTINFO](https://learn.microsoft.com/windows/win32/WinSock/ipv6-pktinfo) socket option is enabled on an IPv6 socket of type **SOCK\_DGRAM** or **SOCK\_RAW**, the **WSARecvMsg** function returns packet information in the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter. One of the control data objects in the returned **WSAMSG** structure will contain an [**in6\_pktinfo**](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-in6_pktinfo) structure used to store received packet address information.

For datagrams received over IPv6, the **Control** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure received will contain a [**WSABUF**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) structure that contains a **WSACMSGHDR** structure. The **cmsg\_level** member of this **WSACMSGHDR** structure would contain **IPPROTO\_IPV6**, the **cmsg\_type** member of this structure would contain **IPV6\_PKTINFO**, and the **cmsg\_data** member would contain an [**in6\_pktinfo**](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-in6_pktinfo) structure used to store received IPv6 packet address information. The IPv6 address in the **in6\_pktinfo** structure is the IPv6 address from which the packet was received.

For a dual-stack datagram socket, if an application requires the **WSARecvMsg** function to return packet information in a [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure for datagrams received over IPv4, then [IP\_PKTINFO](https://learn.microsoft.com/windows/win32/WinSock/ip-pktinfo) socket option must be set to true on the socket. If only the [IPV6\_PKTINFO](https://learn.microsoft.com/windows/win32/WinSock/ipv6-pktinfo) option is set to true on the socket, packet information will be provided for datagrams received over IPv6 but may not be provided for datagrams received over IPv4.

Note that the *Ws2ipdef.h* header file is automatically included in *Ws2tcpip.h*, and should never be used directly.

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. For more information, see [**ExitThread**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread).

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

### dwFlags

On input, the **dwFlags** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter can be used to influence the behavior of the function invocation beyond the socket options specified for the associated socket. That is, the semantics of this function are determined by the socket options and the **dwFlags** member of the **WSAMSG** structure. The only possible input value for the **dwFlags** member of the **WSAMSG** structure pointed to by the *lpMsg* parameter is **MSG\_PEEK**.

| Value | Meaning |
| --- | --- |
| MSG_PEEK | Peek at the incoming data. The data is copied into the buffer, but is not removed from the input queue. This flag is valid only for non-overlapped sockets. |

The possible values for **dwFlags** member on input are defined in the *Winsock2.h* header file.

On output, the **dwFlags** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter may return a combination of any of the following values.

| Value | Meaning |
| --- | --- |
| MSG_BCAST | The datagram was received as a link-layer broadcast or with a destination IP address that is a broadcast address. |
| MSG_CTRUNC | The control (ancillary) data was truncated. More control data was present than the process allocated room for. |
| MSG_MCAST | The datagram was received with a destination IP address that is a multicast address. |
| MSG_TRUNC | The datagram was truncated. More data was present than the process allocated room for. |

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the possible values for the **dwFlags** member on output are defined in the *Ws2def.h* header file which is automatically included by the *Winsock2.h* header file.

On versions of the Platform Software Development Kit (SDK) for Windows Server 2003 and earlier, the possible values for the **dwFlags** member on output are defined in the *Mswsock.h* header file.

**Note** When issuing a blocking Winsock call such as **WSARecvMsg** with the *lpOverlapped* parameter set to NULL, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Overlapped Socket I/O

If an overlapped operation completes immediately, **WSARecvMsg** returns a value of zero and the *lpNumberOfBytesRecvd* parameter is updated with the number of bytes received and the flag bits indicated by the *lpFlags* parameter are also updated. If the overlapped operation is successfully initiated and will complete later, **WSARecvMsg** returns **SOCKET\_ERROR** and indicates error code [WSA\_IO\_PENDING](https://learn.microsoft.com/windows/win32/WinSock/windows-sockets-error-codes-2). In this case, *lpNumberOfBytesRecvd* is not updated. When the overlapped operation completes, the amount of data transferred is indicated either through the *cbTransferred* parameter in the completion routine (if specified), or through the *lpcbTransfer* parameter in [**WSAGetOverlappedResult**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsagetoverlappedresult). Flag values are obtained by examining the *lpdwFlags* parameter of **WSAGetOverlappedResult**.

The **WSARecvMsg** function using overlapped I/O can be called from within the completion routine of a previous [**WSARecv**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsarecv), [**WSARecvFrom**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsarecvfrom), **WSARecvMsg**, [**WSASend**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasend), [**WSASendMsg**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasendmsg), or [**WSASendTo**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasendto) function. For a given socket, I/O completion routines will not be nested. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

The *lpOverlapped* parameter must be valid for the duration of the overlapped operation. If multiple I/O operations are simultaneously outstanding, each must reference a separate [**WSAOVERLAPPED**](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped) structure.

If the *lpCompletionRoutine* parameter is **NULL**, the *hEvent* parameter of *lpOverlapped* is signaled when the overlapped operation completes if it contains a valid event object handle. An application can use [**WSAWaitForMultipleEvents**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsawaitformultipleevents) or [**WSAGetOverlappedResult**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsagetoverlappedresult) to wait or poll on the event object.

If *lpCompletionRoutine* is not **NULL**, the *hEvent* parameter is ignored and can be used by the application to pass context information to the completion routine. A caller that passes a non-**NULL** *lpCompletionRoutine* and later calls [**WSAGetOverlappedResult**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsagetoverlappedresult) for the same overlapped I/O request may not set the *fWait* parameter for that invocation of **WSAGetOverlappedResult** to **TRUE**. In this case the usage of the *hEvent* parameter is undefined, and attempting to wait on the *hEvent* parameter would produce unpredictable results.

The completion routine follows the same rules as stipulated for Windows file I/O completion routines. The completion routine will not be invoked until the thread is in an alertable wait state such as can occur when the function [**WSAWaitForMultipleEvents**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsawaitformultipleevents) with the *fAlertable* parameter set to **TRUE** is invoked.

The prototype of the completion routine is as follows:

``` c++

void CALLBACK CompletionRoutine(
  IN DWORD dwError,
  IN DWORD cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD dwFlags
);
```

The **CompletionRoutine** is a placeholder for an application-defined or library-defined function name. The *dwError* parameter specifies the completion status for the overlapped operation as indicated by the *lpOverlapped* parameter. The *cbTransferred* parameter specifies the number of bytes received. The *dwFlags* parameter contains information that is also returned in **dwFlags** member of the [**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg) structure pointed to by the *lpMsg* parameter if the receive operation had completed immediately. The **CompletionRoutine** function does not return a value.

Returning from this function allows invocation of another pending completion routine for this socket. When using [**WSAWaitForMultipleEvents**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsawaitformultipleevents), all waiting completion routines are called before the alertable thread's wait is satisfied with a return code of **WSA\_IO\_COMPLETION**. The completion routines can be called in any order, not necessarily in the same order the overlapped operations are completed. However, the posted buffers are guaranteed to be filled in the same order in which they are specified.

If you are using I/O completion ports, be aware that the order of calls made to **WSARecvMsg** is also the order in which the buffers are populated. The **WSARecvMsg** function should not be called on the same socket simultaneously from different threads, because it can result in an unpredictable buffer order.

## See also

[**ExitThread**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread)

[**IP_PKTINFO**](https://learn.microsoft.com/windows/win32/winsock/ip-pktinfo)

[**IPV6_PKTINFO**](https://learn.microsoft.com/windows/win32/winsock/ipv6-pktinfo)

[Winsock reference](https://learn.microsoft.com/windows/win32/winsock/winsock-reference)

[Winsock functions](https://learn.microsoft.com/windows/win32/winsock/winsock-functions)

[**WSABUF**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf)

[**WSAGetLastError**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror)

[**WSAIoctl**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl)

[**WSAMSG**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsamsg)

[**WSAOVERLAPPED**](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)

[**WSARecv**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsarecv)

[**WSARecvFrom**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsarecvfrom)

[**WSASend**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasend)

[**WSASendMsg**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasendmsg)

[**WSASendTo**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasendto)

[**WSAStartup**](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsastartup)

[**WSAWaitForMultipleEvents**](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsawaitformultipleevents)