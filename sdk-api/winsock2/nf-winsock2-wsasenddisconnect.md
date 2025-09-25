# WSASendDisconnect function

## Description

The
**WSASendDisconnect** function initiates termination of the connection for the socket and sends disconnect data.

## Parameters

### `s` [in]

Descriptor identifying a socket.

### `lpOutboundDisconnectData` [in]

A pointer to the outgoing disconnect data.

## Return value

If no error occurs,
**WSASendDisconnect** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENOPROTOOPT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The parameter *lpOutboundDisconnectData* is not **NULL**, and the disconnect data is not supported by the service provider. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected (connection-oriented sockets only). |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpOutboundDisconnectData* parameter is not completely contained in a valid part of the user address space. |

## Remarks

The
**WSASendDisconnect** function is used on connection-oriented sockets to disable transmission and to initiate termination of the connection along with the transmission of disconnect data, if any. This is equivalent to a shutdown (SD_SEND), except that
**WSASendDisconnect** also allows sending disconnect data (in protocols that support it).

After this function has been successfully issued, subsequent sends are disallowed.

The *lpOutboundDisconnectData* parameter, if not **NULL**, points to a buffer containing the outgoing disconnect data to be sent to the remote party for retrieval by using
[WSARecvDisconnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvdisconnect).

**Note** The native implementation of TCP/IP on Windows does not support disconnect data. Disconnect data is only supported with Windows Sockets providers that have the XP1_DISCONNECT_DATA flag in their
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure. Use the
[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) function to obtain
**WSAPROTOCOL_INFO** structures for all installed providers.

The
**WSASendDisconnect** function does not close the socket, and resources attached to the socket will not be freed until
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) is invoked.

The
**WSASendDisconnect** function does not block regardless of the SO_LINGER setting on the socket.

An application should not rely on being able to reuse a socket after calling
**WSASendDisconnect**. In particular, a Windows Sockets provider is not required to support the use of
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)/[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) on such a socket.

**Note** When issuing a blocking Winsock call such as **WSASendDisconnect**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

## See also

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)