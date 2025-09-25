## Description

The **LPWSPShutdown** function disables sends and/or receives on a socket.

## Parameters

### `s` [in]

Descriptor identifying a socket.

### `how` [in]

Flag that describes what types of operation will no longer be allowed.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPShutdown** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL) | The *how* is not valid, or is not consistent with the socket type. For example, SD_SEND is used with a UNI_RECV socket type. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Function is invoked when a callback is in progress. |
| [WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN) | Socket is not connected (connection-oriented sockets only). |
| [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK) | The descriptor is not a socket. |

## Remarks

The **LPWSPShutdown** function is used on all types of sockets to disable reception, transmission, or both.

If *how* is SD_RECEIVE, subsequent receives on the socket will be disallowed. This has no effect on the lower protocol layers. For TCP sockets, if there is still data queued on the socket waiting to be received, or data arrives subsequently, the connection is reset, since the data cannot be delivered to the user. For UDP sockets, incoming datagrams are accepted and queued. In no case will an ICMP error packet be generated.

If *how* is SD_SEND, subsequent sends on the socket are disallowed. For TCP sockets, a FIN will be sent. Setting *how* to SD_BOTH disables both sends and receives as described above.

Note that **LPWSPShutdown** does not close the socket, and resources attached to the socket will not be freed until **[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)** is invoked.

> [!Note]
> The **LPWSPShutdown** function does not block regardless of the SO_LINGER setting on the socket. A Windows Sockets SPI client should not rely on being able to reuse a socket after it has been shut down. In particular, a Windows Sockets service provider is not required to support the use of **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** on such a socket.

## See also

**[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)**

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)