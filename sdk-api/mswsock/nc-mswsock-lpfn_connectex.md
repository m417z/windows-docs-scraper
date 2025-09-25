# LPFN_CONNECTEX callback function

## Description

The
**ConnectEx** function establishes a connection to a specified socket, and optionally sends data once the connection is established. The
**ConnectEx** function is only supported on connection-oriented sockets.

**Note** This function is a Microsoft-specific extension to the Windows Sockets specification.

## Parameters

### `s` [in]

A descriptor that identifies an unconnected, previously bound socket. See Remarks for more information.

### `name` [in]

A pointer to
a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that specifies the address to which to connect. For IPv4, the **sockaddr** contains **AF_INET** for the address family, the destination IPv4 address, and the destination port. For IPv6, the **sockaddr** structure contains **AF_INET6** for the address family, the destination IPv6 address, the destination port, and may contain additional IPv6 flow and scope-id information.

### `namelen` [in]

The length, in bytes, of the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure pointed to by the *name* parameter.

### `lpSendBuffer` [in, optional]

A pointer to the buffer to be transferred after a connection is established. This parameter is optional. If the TCP_FASTOPEN option is enabled on *s* before **ConnectEx** is called, then some of this data may be sent during connection establishment.

### `dwSendDataLength` [in]

The length, in bytes, of data pointed to by the *lpSendBuffer* parameter. This parameter is ignored when the *lpSendBuffer* parameter is **NULL**.

### `lpdwBytesSent` [out]

On successful return, this parameter points to a **DWORD** value that indicates the number of bytes that were sent after the connection was established. The bytes sent are from the buffer pointed to by the *lpSendBuffer* parameter. This parameter is ignored when the *lpSendBuffer* parameter is **NULL**.

### `lpOverlapped` [in]

An
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure used to process the request. The *lpOverlapped* parameter must be specified, and cannot be **NULL**.

## Return value

On success, the **ConnectEx** function returns **TRUE**. On failure, the function returns **FALSE**. Use the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function to get extended error information. If a call to the
**WSAGetLastError** function returns **ERROR_IO_PENDING**, the operation initiated successfully and is in progress. Under such circumstances, the call may still fail when the overlapped operation completes.

If the error code returned is [WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), [WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), or [WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), the application can call
**ConnectEx**,
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect), or
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) again on the same socket.

| Error code | Description |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function call must occur before using [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex). |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEADDRINUSE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The local address of the socket is already in use, and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs during a [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) operation, but the error could be delayed until a [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex) function call, if the **bind** function was called with a wildcard address (**INADDR_ANY** or **in6addr_any**) specified for the local IP address. A specific IP address needs to be implicitly bound by the **ConnectEx** function. |
| **[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonblocking [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect), [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect), or [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex) function call is in progress on the specified socket. |
| **[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The remote address is not a valid address, such as ADDR_ANY (the [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex) function is only supported for connection-oriented sockets). |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Addresses in the specified family cannot be used with this socket. |
| **[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The attempt to connect was rejected. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name*, *lpSendBuffer*, or *lpOverlapped* parameter is not a valid part of the user address space, or *namelen* is too small. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The parameter *s* is an unbound or a listening socket. |
| **[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is already connected. |
| **[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network cannot be reached from this host at this time. |
| **[WSAEHOSTUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A socket operation was attempted to an unreachable host. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available; the socket cannot be connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The attempt to connect timed out without establishing a connection. |

## Remarks

The
**ConnectEx** function combines several socket functions into a single API/kernel transition. The following operations are performed when a call to the
**ConnectEx** function completes successfully:

* A new connection is established.
* An optional block of data is sent after the connection is established.

For applications targeted to Windows Vista and later, consider using the [WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbylist) or [WSAConnectByName](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbynamea) function which greatly simplify client application design.

The
**ConnectEx** function can only be used with connection-oriented sockets. The socket passed in the *s* parameter must be created with a socket type of **SOCK_STREAM**, **SOCK_RDM**, or **SOCK_SEQPACKET**.

The *lpSendBuffer* parameter points to a buffer of data to send after the connection is established. The *dwSendDataLength* parameter specifies the length in bytes of this data to send. An application can request to send a large buffer of data using the **ConnectEx** in the same way that the [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) and [WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend) functions can be used. But developers are strongly advised against sending a huge buffer in a single call using **ConnectEx**, because this operation uses a large amount of system memory resources until the whole buffer has been sent.

If the **ConnectEx** function is successful, a connection was established and all of the data pointed to by the *lpSendBuffer* parameter was sent to the address specified in the **sockaddr** structure pointed to by the *name* parameter.

**Note** The function pointer for the
**ConnectEx** function must be obtained at run time by making a call to the
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO_GET_EXTENSION_FUNCTION_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID_CONNECTEX**, a globally unique identifier (GUID) whose value identifies the **ConnectEx** extension function. On success, the output returned by the **WSAIoctl** function contains a pointer to the **ConnectEx** function. The **WSAID_CONNECTEX** GUID is defined in the *Mswsock.h* header file.

The
**ConnectEx** function uses overlapped I/O. As a result, the
**ConnectEx** function enables an application to service a large number of clients with relatively few threads. In contrast, the
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) function, which does not use overlapped I/O, usually requires a separate thread to service each connection request when simultaneous requests are received.

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

Connection-oriented sockets are often unable to complete their connection immediately, and therefore the operation is initiated and the function immediately returns with the ERROR_IO_PENDING or WSA_IO_PENDING error. When the connect operation completes and success or failure is achieved, status is reported using the completion notification mechanism indicated in *lpOverlapped*. As with all overlapped function calls, you can use events or completion ports as the completion notification mechanism. The *lpNumberOfBytesTransferred* parameter of the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) or
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) function indicates the number of bytes sent in the request.

When the
**ConnectEx** function successfully completes, socket handle *s* can be passed to only the following functions:

* [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)
* [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)
* [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) or
  [WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)
* [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) or
  [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)
* [TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile)
* [closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)

If the
[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile) function is called on a previously connected socket with both TF_DISCONNECT and TF_REUSE_SOCKET flags, the specified socket is returned to a state in which it is not connected, but still bound. In such cases, the handle of the socket can be passed to the
**ConnectEx** function in its *s* parameter, but the socket cannot be reused in an
[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) function call. Similarly, the accepted socket reused using the
**TransmitFile** function cannot be used in a call to
**ConnectEx**. Note that in the case of a reused socket, **ConnectEx** is subject to the behavior of the underlying transport. For example, a TCP socket may be subject to the TCP TIME_WAIT state, causing the **ConnectEx** call to be delayed.

When the
**ConnectEx** function returns **TRUE**, the socket *s* is in the default state for a connected socket. The socket *s* does not enable previously set properties or options until SO_UPDATE_CONNECT_CONTEXT is set on the socket. Use the
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function to set the SO_UPDATE_CONNECT_CONTEXT option.

For example:

```cpp
//Need to #include <mswsock.h> for SO_UPDATE_CONNECT_CONTEXT

int iResult = 0;

iResult = setsockopt( s, SOL_SOCKET, SO_UPDATE_CONNECT_CONTEXT, NULL, 0 );

```

The
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function can be used with the **SO_CONNECT_TIME** socket option to check whether a connection has been established while
**ConnectEx** is in progress. If a connection has been established, the
value returned in the *optval* parameter passed to the **getsockopt** function is the number of seconds the socket has been connected. If the socket is not connected,
the returned *optval* parameter contains 0xFFFFFFFF. Checking a connection in this manner is necessary to determine whether connections have been established for a period of time without sending any data; in such cases, it is recommended that such connections be terminated.

For example:

```cpp

//Need to #include <mswsock.h> for SO_CONNECT_TIME

int seconds;
int bytes = sizeof(seconds);
int iResult = 0;

iResult = getsockopt( s, SOL_SOCKET, SO_CONNECT_TIME,
                      (char *)&seconds, (PINT)&bytes );
if ( iResult != NO_ERROR ) {
    printf( "getsockopt(SO_CONNECT_TIME) failed with error: %u\n",
        WSAGetLastError() );
}
else {
    if (seconds == 0xFFFFFFFF)
        printf("Connection not established yet\n");
    else
       printf("Connection has been established %ld seconds\n",
           seconds);
}

```

**Note** If a socket is opened, a
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) call is made, and then a
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) call is made, Windows Sockets performs an implicit
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function call.

If the address parameter of the
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure pointed to in the *name* parameter is all zeros,
**ConnectEx** returns the error [WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). Any attempt to reconnect an active connection will fail with the error code [WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

When a connected socket becomes closed for any reason, it is recommended that the socket be discarded and a new socket created. The reasoning for this is that it is safest to assume that when things go awry on a connected socket for any reason, the application must discard the socket and create the needed socket again in order to return to a stable point.

If the
[DisconnectEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms737757(v=vs.85)) function is called with the **TF_REUSE_SOCKET** flag, the specified socket is returned to a state in which it is not connected, but still bound. In such cases, the handle of the socket can be passed to the
**ConnectEx** function in its *s* parameter.

 The interval of time that must elapse before TCP can release a closed connection and reuse its resources is known as the TIME_WAIT state or the 2MSL state. During this time, the connection can be reopened at much less cost to the client and server than establishing a new connection.

The TIME_WAIT behavior is specified in [RFC 793](https://www.ietf.org/rfc/rfc793.txt), which requires that TCP maintains a closed connection for an interval at least equal to twice the maximum segment lifetime (MSL) of the network. When a connection is released, its socket pair and internal resources used for the socket can be used to support another connection.

Windows TCP reverts to a TIME_WAIT state subsequent to the closing of a connection. While in the TIME_WAIT state, a socket pair cannot be reused. The TIME_WAIT period is configurable by modifying the following **DWORD** registry setting that represents the TIME_WAIT period in seconds.

**HKEY_LOCAL_MACHINE**\**System**\**CurrentControlSet**\**Services**\**TCPIP**\**Parameters**\**TcpTimedWaitDelay**

By default, the MSL is defined to be 120 seconds. The TcpTimedWaitDelay registry setting defaults to a value 240 seconds, which represents 2 times the maximum segment lifetime of 120 seconds or 4 minutes. However, you can use this entry to customize the interval.

Reducing the value of this entry allows TCP to release closed connections faster, providing more resources for new connections. However, if the value is too low, TCP might release connection resources before the connection is complete, requiring the server to use additional resources to re-establish the connection.

This registry setting can be set from 0 to 300 seconds.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex)

[DisconnectEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms737757(v=vs.85))

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbylist)

[WSAConnectByName](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbynamea)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)