# WSADeleteSocketPeerTargetName function

## Description

The **WSADeleteSocketPeerTargetName** function removes the association between a peer target name and an IP address for a socket. After a successful return, there will be no future association between the IP address and the target name.

## Parameters

### `Socket` [in]

A descriptor identifying a socket on which the peer target name is being deleted.

### `PeerAddr` [in]

The IP address of the peer for which the target name is being deleted.

### `PeerAddrLen` [in]

The size, in bytes, of the *PeerAddr* parameter.

### `Overlapped` [in, optional]

A pointer to a [WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure. This parameter is ignored for non-overlapped sockets.

### `CompletionRoutine` [in, optional]

A pointer to the completion routine called when the operation has been completed. This parameter is ignored for non-overlapped sockets.

## Return value

If the function succeeds, the return value is 0. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

Some possible error codes are listed below.

| Error code | Meaning |
| --- | --- |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified address family is not supported. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The system detected an invalid address pointer in attempting to use a pointer argument of a call. This error is returned if the *PeerAddr* parameter was a **NULL** pointer. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid parameter was passed. This error is returned if the socket passed in the *Socket* parameter was not created with an address family of the **AF_INET** or **AF_INET6** and a socket type of **SOCK_DGRAM** or **SOCK_STREAM**. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A buffer passed was too small. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor passed in the *Socket* parameter is not a valid socket. |

## Remarks

The **WSADeleteSocketPeerTargetName** function provides a method to remove the association between a peer target name and an IP address for a socket. This function is used to delete a peer target name that was previously set with the [WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname) function. After the **WSADeleteSocketPeerTargetName** function returns, no future authentication to the IP address will use the previously specified target name. This function is primarily designed to be used by connectionless clients (for example, a socket created with the type set to SOCK_DGRAM or the protocol set to IPPROTO_UDP) after they have terminated the connection with the IP address associated with the peer target name. For connection oriented clients (for example, a socket created with the type set to SOCK_STREAM or protocol set to IPPROTO_TCP), this function should not be called.

The **WSADeleteSocketPeerTargetName** function simplifies having to call the [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with a *dwIoControlCode* parameter set to **SIO_DELETE_PEER_TARGET_NAME**.

An error will be returned if the following conditions are not met.

* The address family of the *Socket* parameter must be either AF_INET or AF_INET6.
* The socket type must be either SOCK_STREAM or SOCK_DGRAM.

## See also

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSAImpersonateSocketPeer](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaimpersonatesocketpeer)

[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)

[WSARevertImpersonation](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsarevertimpersonation)

[WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname)

[WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)