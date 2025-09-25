# WSAConnect function

## Description

The
**WSAConnect** function establishes a connection to another socket application, exchanges connect data, and specifies required quality of service based on the specified
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure.

## Parameters

### `s` [in]

A descriptor identifying an unconnected socket.

### `name` [in]

A pointer to a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that specifies the address to which to connect. For IPv4, the **sockaddr** contains **AF_INET** for the address family, the destination IPv4 address, and the destination port. For IPv6, the **sockaddr** structure contains **AF_INET6** for the address family, the destination IPv6 address, the destination port, and may contain additional flow and scope-id information.

### `namelen` [in]

The length, in bytes, of the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure pointed to by the *name* parameter.

### `lpCallerData` [in]

A pointer to the user data that is to be transferred to the other socket during connection establishment. See Remarks.

### `lpCalleeData` [out]

A pointer to the user data that is to be transferred back from the other socket during connection establishment. See Remarks.

### `lpSQOS` [in]

A pointer to the [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures for socket *s*, one for each direction.

### `lpGQOS` [in]

Reserved for future use with socket groups. A pointer to the
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures for the socket group (if applicable). This parameter should be **NULL**.

## Return value

If no error occurs,
**WSAConnect** returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror). On a blocking socket, the return value indicates success or failure of the connection attempt.

With a nonblocking socket, the connection attempt cannot be completed immediately. In this case,
**WSAConnect** will return SOCKET_ERROR, and
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) will return
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2); the application could therefore:

* Use
  [select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select) to determine the completion of the connection request by checking if the socket is writable.
* If your application is using
  [WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) to indicate interest in connection events, then your application will receive an FD_CONNECT notification when the connect operation is complete(successful or not).
* If your application is using
  [WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) to indicate interest in connection events, then the associated event object will be signaled when the connect operation is complete (successful or not).

For a nonblocking socket, until the connection attempt completes all subsequent calls to
**WSAConnect** on the same socket will fail with the error code
[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

If the return error code indicates the connection attempt failed (that is,
[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2),
[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2),
[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)) the application can call
**WSAConnect** again for the same socket.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEADDRINUSE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The local address of the socket is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs during the execution of [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), but could be delayed until this function if the **bind** function operates on a partially wildcard address (involving ADDR_ANY) and if a specific address needs to be "committed" at the time of this function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The (blocking) Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonblocking [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) or [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) call is in progress on the specified socket. |
| **[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The remote address is not a valid address (such as ADDR_ANY). |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Addresses in the specified family cannot be used with this socket. |
| **[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The attempt to connect was rejected. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* or the *namelen* parameter is not a valid part of the user address space, the *namelen* parameter is too small, the buffer length for *lpCalleeData*, *lpSQOS*, and *lpGQOS* are too small, or the buffer length for *lpCallerData* is too large. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The parameter *s* is a listening socket, or the destination address specified is not consistent with that of the constrained group to which the socket belongs, or the *lpGQOS* parameter is not **NULL**. |
| **[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is already connected (connection-oriented sockets only). |
| **[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network cannot be reached from this host at this time. |
| **[WSAEHOSTUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A socket operation was attempted to an unreachable host. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. The socket cannot be connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures specified in *lpSQOS* and *lpGQOS* cannot be satisfied. |
| **[WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpCallerData* parameter is not supported by the service provider. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Attempt to connect timed out without establishing a connection. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is marked as nonblocking and the connection cannot be completed immediately. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Attempt to connect datagram socket to broadcast address failed because [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) SO_BROADCAST is not enabled. |

## Remarks

The
**WSAConnect** function is used to create a connection to the specified destination, and to perform a number of other ancillary operations that occur at connect time. If the socket, *s*, is unbound, unique values are assigned to the local association by the system, and the socket is marked as bound.

For applications targeted to Windows Vista and later, consider using the [WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbylist) or [WSAConnectByName](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbynamea) function which greatly simplify client application design.

For connection-oriented sockets (for example, type SOCK_STREAM), an active connection is initiated to the foreign host using *name* (an address in the namespace of the socket; for a detailed description, please see
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)). When this call completes successfully, the socket is ready to send/receive data. If the address parameter of the *name* structure is all zeroes,
**WSAConnect** will return the error
[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). Any attempt to reconnect an active connection will fail with the error code
[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

**Note** If a socket is opened, a
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) call is made, and then a
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) call is made, Windows Sockets performs an implicit
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function call.

For connection-oriented, nonblocking sockets, it is often not possible to complete the connection immediately. In such cases, this function returns the error
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). However, the operation proceeds. When the success or failure outcome becomes known, it may be reported in one of several ways depending on how the client registers for notification. If the client uses
[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select), success is reported in the *writefds* set and failure is reported in the *exceptfds* set. If the client uses
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect), the notification is announced with FD_CONNECT and the error code associated with the FD_CONNECT indicates either success or a specific reason for failure.

For a connectionless socket (for example, type SOCK_DGRAM), the operation performed by
**WSAConnect** is merely to establish a default destination address so that the socket can be used on subsequent connection-oriented send and receive operations ([send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send),
[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend),
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv), and
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)). Any datagrams received from an address other than the destination address specified will be discarded. If the entire name structure is all zeros (not just the address parameter of the name structure), then the socket will be disconnected. Then, the default remote address will be indeterminate, so **send**, **WSASend**, **recv**, and **WSARecv** calls will return the error code
[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). However,
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto),
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto), [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom), and
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom) can still be used. The default destination can be changed by simply calling
**WSAConnect** again, even if the socket is already connected. Any datagrams queued for receipt are discarded if *name* is different from the previous
**WSAConnect**.

For connectionless sockets, *name* can indicate any valid address, including a broadcast address. However, to connect to a broadcast address, a socket must have
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) SO_BROADCAST enabled. Otherwise,
**WSAConnect** will fail with the error code
[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

On connectionless sockets, exchange of user-to-user data is not possible and the corresponding parameters will be silently ignored.

The application is responsible for allocating any memory space pointed to directly or indirectly by any of the parameters it specifies.

The *lpCallerData* parameter contains a pointer to any user data that is to be sent along with the connection request (called connect data). This is additional data, not in the normal network data stream, that is sent with network requests to establish a connection. This option is used by legacy protocols such as DECNet, OSI TP4, and others.

**Note** Connect data is not supported by the TCP/IP protocol in Windows. Connect data is supported only on ATM (RAWWAN) over a raw socket.

If *lpCallerData* is **NULL**, no user data will be passed to the peer. The *lpCalleeData* is a result parameter that will contain any user data passed back from the other socket as part of the connection establishment in a
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure. The **len** member of the **WSABUF** structure pointed to by the *lpCalleeData* parameter initially contains the length of the buffer allocated by the application for the **buf** member of the **WSABUF** structure. The **len** member of the **WSABUF** structure pointed to by the *lpCalleeData* parameter will be set to zero if no user data has been passed back. The *lpCalleeData* information will be valid when the connection operation is complete. For blocking sockets, the connection operation completes when the
**WSAConnect** function returns. For nonblocking sockets, completion will be after the FD_CONNECT notification has occurred. If *lpCalleeData* is **NULL**, no user data will be passed back. The exact format of the user data is specific to the address family to which the socket belongs.

At connect time, an application can use the *lpSQOS* and *lpGQOS* parameter to override any previous quality of service specification made for the socket through
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with either the SIO_SET_QOS or SIO_SET_GROUP_QOS opcode.

The *lpSQOS* parameter specifies the
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures for socket *s*, one for each direction, followed by any additional provider-specific parameters. If either the associated transport provider in general or the specific type of socket in particular cannot honor the quality of service request, an error will be returned as indicated in the following. The sending or receiving flow specification values will be ignored, respectively, for any unidirectional sockets. If no provider-specific parameters are specified, the **buf** and **len** members of the [WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure pointed to by the *lpCalleeData* parameter should be set to **NULL** and zero, respectively. A **NULL** value for *lpSQOS* parameter indicates no application-supplied quality of service.

Reserved for future use with socket groups *lpGQOS* specifies the [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures for the socket group (if applicable), one for each direction, followed by any additional provider-specific parameters. If no provider-specific parameters are specified, the **buf** and **len** members of the [WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure pointed to by the *lpCalleeData* parameter should be set to **NULL** and zero, respectively. A **NULL** value for *lpGQOS* indicates no application-supplied group quality of service. This parameter will be ignored if *s* is not the creator of the socket group.

When connected sockets become closed for whatever reason, they should be discarded and recreated. It is safest to assume that when things go awry for any reason on a connected socket, the application must discard and recreate the needed sockets in order to return to a stable point.

**Note** When issuing a blocking Winsock call such as **WSAConnect**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex)

[WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbylist)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)