# WSARecvDisconnect function

## Description

The
**WSARecvDisconnect** function terminates reception on a socket, and retrieves the disconnect data if the socket is connection oriented.

## Parameters

### `s` [in]

A descriptor identifying a socket.

### `lpInboundDisconnectData` [out]

A pointer to the incoming disconnect data.

## Return value

If no error occurs,
**WSARecvDisconnect** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The buffer referenced by the parameter *lpInboundDisconnectData* is too small. |
| **[WSAENOPROTOOPT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The disconnect data is not supported by the indicated protocol family. Note that implementations of TCP/IP that do not support disconnect data are not required to return the WSAENOPROTOOPT error code. See the remarks section for information about the Microsoft implementation of TCP/IP. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected (connection-oriented sockets only). |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |

## Remarks

The
**WSARecvDisconnect** function is used on connection-oriented sockets to disable reception and retrieve any incoming disconnect data from the remote party. This is equivalent to a shutdown (SD_RECEIVE), except that
**WSARecvDisconnect** also allows receipt of disconnect data (in protocols that support it).

After this function has been successfully issued, subsequent receives on the socket will be disallowed. Calling
**WSARecvDisconnect** has no effect on the lower protocol layers. For TCP sockets, if there is still data queued on the socket waiting to be received, or data arrives subsequently, the connection is reset, since the data cannot be delivered to the user. For UDP, incoming datagrams are accepted and queued. In no case will an ICMP error packet be generated.

**Note** The native implementation of TCP/IP on Windows does not support disconnect data. Disconnect data is only supported with Windows Sockets providers that have the XP1_DISCONNECT_DATA flag in their
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure. Use the
[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) function to obtain
**WSAPROTOCOL_INFO** structures for all installed providers.

To successfully receive incoming disconnect data, an application must use other mechanisms to determine that the circuit has been closed. For example, an application needs to receive an FD_CLOSE notification, to receive a zero return value, or to receive a
[WSAEDISCON](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) or
[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) error code from
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)/[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv).

The
**WSARecvDisconnect** function does not close the socket, and resources attached to the socket will not be freed until
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) is invoked.

The
**WSARecvDisconnect** function does not block regardless of the SO_LINGER setting on the socket.

An application should not rely on being able to reuse a socket after it has been disconnected using
**WSARecvDisconnect**. In particular, a Windows Sockets provider is not required to support the use of
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) or
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) on such a socket.

**Note** When issuing a blocking Winsock call such as **WSARecvDisconnect**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

## See also

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)