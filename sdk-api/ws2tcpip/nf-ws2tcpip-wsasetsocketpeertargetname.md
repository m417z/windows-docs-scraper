# WSASetSocketPeerTargetName function

## Description

The **WSASetSocketPeerTargetName** function is used to specify the peer target name (SPN) that corresponds to a peer IP address. This target name is meant to be specified by client applications to securely identify the peer that should be authenticated.

## Parameters

### `Socket` [in]

A descriptor identifying a socket on which the peer target name is being assigned.

### `PeerTargetName` [in]

A pointer to a [SOCKET_PEER_TARGET_NAME](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_peer_target_name) structure that defines the peer target name.

### `PeerTargetNameLen` [in]

The size, in bytes, of the *PeerTargetName* parameter.

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
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The system detected an invalid address pointer in attempting to use a pointer argument of a call. This error is returned if the *PeerTargetName* parameter was a **NULL** pointer. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid parameter was passed. This error is returned if the socket passed in the *Socket* parameter was not created with an address family of the **AF_INET** or **AF_INET6** and a socket type of **SOCK_DGRAM** or **SOCK_STREAM**. This error is also returned for a connectionless socket if the IP address and port are zero in the **PeerAddress** member of the [SOCKET_PEER_TARGET_NAME](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_peer_target_name) structure pointed to by the *PeerTargetName* parameter. |
| **[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is connected. This function is not permitted with a connected socket, whether the socket is connection oriented or connectionless. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A buffer passed was too small. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor passed in the *Socket* parameter is not a valid socket. |

## Remarks

The **WSASetSocketPeerTargetName** function provides a method to specify the target name that corresponds to a peer security principal. This function is meant to be used by a client application to identify the peer that should be authenticated. A client application should specify the peer target name in order to prevent trusted man-in-the-middle attacks. For connectionless sockets, an application can call the **WSASetSocketPeerTargetName** function multiple times to specify different target names for different peer IP addresses.

This function simplifies having to call the [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with a *dwIoControlCode* parameter set to **SIO_SET_PEER_TARGET_NAME**.

For connection-oriented sockets, the **WSASetSocketPeerTargetName** function should be called before [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect). For connectionless sockets, this function should be called before **WSAConnect** or before the first [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) call directed to the peer address.

An error will be returned if the following conditions are not met.

* The address family of the *Socket* parameter must be either AF_INET or AF_INET6.
* The socket type must be either SOCK_STREAM or SOCK_DGRAM.

## See also

[SOCKET_PEER_TARGET_NAME](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_peer_target_name)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSADeleteSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsadeletesocketpeertargetname)

[WSAImpersonateSocketPeer](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaimpersonatesocketpeer)

[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)

[WSARevertImpersonation](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsarevertimpersonation)

[WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)