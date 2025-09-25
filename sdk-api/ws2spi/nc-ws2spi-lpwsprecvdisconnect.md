## Description

The **LPWSPRecvDisconnect** function terminates reception on a socket and retrieves the disconnect data, if the socket is connection oriented.

## Parameters

### `s` [in]

Descriptor identifying a socket.

### `lpInboundDisconnectData` [out]

Pointer to a buffer into which disconnect data is to be copied.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPRecvDisconnect** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT) | Buffer referenced by the parameter *lpInboundDisconnectData* is too small. |
| [WSAENOPROTOOPT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOPROTOOPT) | Disconnect data is not supported by the indicated protocol family. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| [WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN) | Socket is not connected (connection-oriented sockets only). |
| [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK) | The descriptor is not a socket. |

## Remarks

**LPWSPRecvDisconnect** is used on connection-oriented sockets to disable reception, and retrieve any incoming disconnect data from the remote party.

After this function has been successfully issued, subsequent receives on the socket will be disallowed. This has no effect on the lower protocol layers. For TCP, the TCP window is not changed and incoming data will be accepted (but not acknowledged) until the window is exhausted. For UDP, incoming datagrams are accepted and queued. In no case will an ICMP error packet be generated.

To successfully receive incoming disconnect data, a Windows Sockets SPI client must use other mechanisms to determine that the circuit has been closed. For example, a client needs to receive an FD_CLOSE notification, or get a zero return value, or a **[WSAEDISCON](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEDISCON)** error code from **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)**.

Note that **LPWSPRecvDisconnect** does not close the socket, and resources attached to the socket will not be freed until **[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)** is invoked.

> [!Note]
> **LPWSPRecvDisconnect** does not block regardless of the SO_LINGER setting on the socket. A Windows Sockets SPI client should not rely on being able to reuse a socket after it has been **LPWSPRecvDisconnect**ed. In particular, a Windows Sockets provider is not required to support the use of **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** on such a socket.

## See also

**[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)**

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)