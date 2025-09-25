# WSAQuerySocketSecurity function

## Description

The **WSAQuerySocketSecurity** function queries information about the security applied to a connection on a socket.

## Parameters

### `Socket` [in]

A descriptor identifying a socket for which security information is being queried.

### `SecurityQueryTemplate` [in, optional]

A pointer to a [SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template) structure that specifies the type of query information to return.

A [SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template) structure pointed to by this parameter may contain zeroes for all members to request default security information. On successful return, only the **Flags** member in the [SOCKET_SECURITY_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_info) will be set in the returned *SecurityQueryInfo* parameter.

This parameter may be a **NULL** pointer if the *Socket* parameter was created with a protocol of **IPPROTO_TCP**. In this case, the information returned is the same as if a [SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template) structure with all values set to zero was passed. This parameter should be specified for a socket with protocol of **IPPROTO_TCP** if more than the default security information is required.

If the [SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template) structure is specified with the **PeerTokenAccessMask** member not specified (set to zero), then the **WSAQuerySocketSecurity** function will not return the **PeerApplicationAccessTokenHandle** and **PeerMachineAccessTokenHandle** members in the [SOCKET_SECURITY_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_info) structure.

If a *Socket* parameter was created with a protocol not equal to **IPPROTO_TCP**, the *SecurityQueryTemplate* parameter must be specified. In these cases, the **PeerAddress** member of the [SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template) structure must specify an address family of AF_INET or AF_INET6 along with peer IP address and port number.

### `SecurityQueryTemplateLen` [in]

The size, in bytes, of the *SecurityQueryTemplate* parameter.

This parameter may be a zero if the *Socket* parameter was created with a protocol of **IPPROTO_TCP**. Otherwise, this parameter must be the size of a [SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template) structure.

### `SecurityQueryInfo` [out, optional]

A pointer to a buffer that will receive a [SOCKET_SECURITY_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_info) structure containing the information queried. This value can be set to **NULL** to query the size of the output buffer.

### `SecurityQueryInfoLen` [in, out]

On input, a pointer to the size, in bytes, of the *SecurityQueryInfo* parameter. If the buffer is too small to receive the queried information, the call will return SOCKET_ERROR, and the number of bytes needed to return the queried information will be set in the value pointed to by this parameter. On a successful call, the number of bytes copied is returned.

### `Overlapped` [in, optional]

A pointer to a [WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure. This parameter is ignored for non-overlapped sockets.

### `CompletionRoutine` [in, optional]

A pointer to the completion routine called when the operation has been completed. This parameter is ignored for non-overlapped sockets.

## Return value

If the function succeeds, the return value is zero. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

Some possible error codes are listed below.

| Error code | Meaning |
| --- | --- |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified address family is not supported. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a stream socket, the virtual circuit was reset by the remote side. The application should close the socket as it is no longer usable. For a UDP datagram socket, this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The system detected an invalid pointer address in attempting to use a parameter. This error is returned if the *SecurityQueryInfoLen* parameter was a **NULL** pointer. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid parameter was passed. This error is returned if the socket passed in the *Socket* parameter was not created with an address family of the **AF_INET** or **AF_INET6** and a socket type of **SOCK_DGRAM** or **SOCK_STREAM**. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A buffer passed was too small. This error is returned for a *Socket* parameter when the protocol was not **IPPROTO_TCP** if the *SecurityQueryInfo* parameter is a **NULL** pointer or the *SecurityQueryTemplateLen* parameter is less than the size of a [SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template) structure. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor passed in the *Socket* parameter is not a valid socket. |

## Remarks

The **WSAQuerySocketSecurity** function provides a method to query the current security settings on a socket. After a connection is established, the **WSAQuerySocketSecurity** function allows an application to query the security properties of the connection, which can include information on peer access tokens.

For connection-oriented sockets, it is preferred to call the **WSAQuerySocketSecurity** function immediately after a connection is established. For connectionless sockets, it is preferred to call the **WSAQuerySocketSecurity** function immediately after data is sent to a new peer address or received from a new peer address. The **WSAQuerySocketSecurity** function can be called multiple times on a single socket.

This function simplifies having to call the [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with a *dwIoControlCode* parameter set to **SIO_QUERY_SECURITY**.

The **WSAQuerySocketSecurity** function may be called on a *Socket* parameter created with an address family of **AF_INET** or **AF_INET6**.

If the *Socket* parameter was created with a protocol of **IPPROTO_TCP**, the *SecurityQueryTemplate* parameter may be **NULL** and the *SecurityQueryTemplateLen* parameter may be zero. Otherwise, the *SecurityQueryTemplate* parameter must point to a [SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template) structure.

For a client application using connection-oriented sockets (socket created with a protocol of **IPPROTO_TCP**), the **WSAQuerySocketSecurity** function should be called after the [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect), [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex), or [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) function returns. For a server application using connection-oriented sockets (protocol of **IPPROTO_TCP**), the **WSAQuerySocketSecurity** function should be called after the [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept), [AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex), or [WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept) function returns.

For connectionless sockets (socket created with a protocol of **IPPROTO_UDP**), the application should call the **WSAQuerySocketSecurity** function immediately after [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) or [WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom) call returns for a new peer address.

An error will be returned if the following conditions are not met.

* The address family of the *Socket* parameter must be either AF_INET or AF_INET6.
* The socket type must be either SOCK_STREAM or SOCK_DGRAM.

## See also

[SOCKET_SECURITY_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_info)

[SOCKET_SECURITY_QUERY_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_query_template)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSADeleteSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsadeletesocketpeertargetname)

[WSAImpersonateSocketPeer](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaimpersonatesocketpeer)

[WSARevertImpersonation](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsarevertimpersonation)

[WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname)

[WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)