# WSARecvEx function

## Description

The
**WSARecvEx** function receives data from a connected socket or a bound connectionless socket. The **WSARecvEx** function is similar to the
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) function, except that the *flags* parameter is used only to return information. When a partial message is received while using datagram protocol, the MSG_PARTIAL bit is set in the *flags* parameter on return from the function.

**Note** The
**WSARecvEx** function is a Microsoft-specific extension to the Windows Sockets specification.

## Parameters

### `s` [in]

A descriptor that identifies a connected socket.

### `buf` [out]

A pointer to the buffer to receive the incoming data.

### `len` [in]

The length, in bytes, of the buffer pointed to by the *buf* parameter.

### `flags` [in, out]

An indicator specifying whether the message is fully or partially received for datagram sockets.

## Return value

If no error occurs,
**WSARecvEx** returns the number of bytes received. If the connection has been closed, it returns zero. Additionally, if a partial message was received, the MSG_PARTIAL bit is set in the *flags* parameter. If a complete message was received, MSG_PARTIAL is not set in *flags*

Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

**Important** For a stream oriented-transport protocol, MSG_PARTIAL is never set on return from
**WSARecvEx**. This function behaves identically to the
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) function for stream-transport protocols.

| Error code | Meaning |
| --- | --- |
| **[WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was reset by the remote side executing a hard or abortive close. The application should close the socket as it is no longer usable. On a UPD-datagram socket this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *buf* parameter is not completely contained in a valid part of the user address space. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The (blocking) call was canceled by the [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall) call. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), or an unknown flag was specified, or MSG_OOB was specified for a socket with SO_OOBINLINE enabled or (for byte stream sockets only) *len* was zero or negative. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a connection-oriented socket, this error indicates that the connection has been broken due to *keep-alive* activity that detected a failure while the operation was in progress. For a datagram socket, this error indicates that the time to live has expired. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only send operations. |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has been shut down; it is not possible to use [WSARecvEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-wsarecvex) on a socket after [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) has been invoked with *how* set to SD_RECEIVE or SD_BOTH. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has been dropped because of a network failure or because the peer system failed to respond. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is marked as nonblocking and the receive operation would block. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |

## Remarks

The
**WSARecvEx** function that is part of the Microsoft implementation of Windows Sockets 2 is similar to the more common
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) function except that the *flags* parameter is used for a single specific purpose. The *flags* parameter is used to indicate whether a partial or complete message is received when a message-oriented protocol is being used.

The value pointed to by the *flags* parameter is ignored on input. So no flags can be passed to the **WSARecvEx** function to modify its behavior. The value pointed to by the *flags* parameter is set on output. This differs from the [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) and [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) functions where the value pointed to by the *flags* parameter on input can modify the behavior of the function.

The
**WSARecvEx** and
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) functions behave identically for stream-oriented protocols.

The *flags* parameter accommodates two common situations in which a partial message will be received:

* When the application's data buffer size is smaller than the message size and the message coincidentally arrives in two pieces.
* When the message is rather large and must arrive in several pieces.

The MSG_PARTIAL bit is set in the value pointed to by the *flags* parameter on return from
**WSARecvEx** when a partial message was received. If a complete message was received, MSG_PARTIAL is not set in the value pointed to by the *flags* parameter.

The
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) function is different from the
**WSARecvEx** and [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) functions in that the
**recv** function always receives a single message for each call for message-oriented transport protocols. The
**recv** function also does not have a means to indicate to the application that the data received is only a partial message. An application must build its own protocol for checking whether a message is partial or complete by checking for the error code
[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) after each call to
**recv**. When the application buffer is smaller than the data being sent, as much of the message as will fit is copied into the user's buffer and
**recv** returns with the error code WSAEMSGSIZE. A subsequent call to
**recv** will get the next part of the message.

Applications written for message-oriented transport protocols should be coded for this possibility if message sizing is not guaranteed by the application's data transfer protocol. An application can use
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) and manage the protocol itself. Alternatively, an application can use
**WSARecvEx** and check that the MSG_PARTIAL bit is set in the *flags* parameter.

The
**WSARecvEx** function provides the developer with a more effective way of checking whether a message received is partial or complete when a very large message arrives incrementally. For example, if an application sends a one-megabyte message, the transport protocol must break up the message in order to send it over the physical network. It is theoretically possible for the transport protocol on the receiving side to buffer all the data in the message, but this would be quite expensive in terms of resources. Instead,
**WSARecvEx** can be used, minimizing overhead and eliminating the need for an application-based protocol.

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See the [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) function for more information.

## See also

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)