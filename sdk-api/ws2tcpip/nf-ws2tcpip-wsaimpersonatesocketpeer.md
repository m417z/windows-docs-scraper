# WSAImpersonateSocketPeer function

## Description

The **WSAImpersonateSocketPeer** function is used to impersonate the security principal corresponding to a socket peer in order to perform application-level authorization.

## Parameters

### `Socket` [in]

Identifies the application socket.

### `PeerAddr` [in, optional]

The IP address of the peer to be impersonated. For connection-oriented sockets, the connected socket uniquely identifies a peer. In this case, this parameter is ignored.

### `PeerAddrLen` [in]

The size, in bytes, of the *PeerAddress* parameter.

## Return value

If the function succeeds, the return value is 0. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

Some possible error codes are listed below.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The system detected an invalid address pointer in attempting to use a pointer argument of a call. This error is returned if the *PeerAddr* parameter was a **NULL** pointer. |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified address family is not supported. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A buffer passed was too small. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor passed in the *Socket* parameter is not a valid socket. |

## Remarks

The **WSAImpersonateSocketPeer** function provides an application the ability to impersonate the security principal corresponding to a socket peer in order to perform application-level authorization. If peer user (impersonation) token is available then it will be used for impersonation, otherwise the peer computer token will be used. The **WSAImpersonateSocketPeer** function can be called only for blocking, non-overlapped sockets. After performing any authorization checks, an application must call the [WSARevertImpersonation](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsarevertimpersonation) function to terminate the impersonation.

For connection-oriented sockets, the **WSAImpersonateSocketPeer** function should be called after a connection is established. For a server application using connection-oriented sockets, the **WSAImpersonateSocketPeer** should be called after the [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept), [AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex), or [WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept) function returns.

For connectionless sockets, the application should call the **WSAImpersonateSocketPeer** function immediately after the [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv), [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom), [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv), [WSARecvEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-wsarecvex), [WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom), or [LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg) function returns for a new peer address.

The **WSAImpersonateSocketPeer** function can be called multiple times for a single socket.

An error will be returned if the following conditions are not met.

* The address family of the *Socket* parameter must be either AF_INET or AF_INET6.
* The socket type must be either SOCK_STREAM or SOCK_DGRAM.

The [WSARevertImpersonation](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsarevertimpersonation) function must be called to end the impersonation.

## See also

[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept)

[WSADeleteSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsadeletesocketpeertargetname)

[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[WSARecvEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-wsarecvex)

[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom)

[LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg)

[WSARevertImpersonation](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsarevertimpersonation)

[WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname)

[WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom)