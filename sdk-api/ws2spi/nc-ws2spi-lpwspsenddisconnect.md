## Description

The **LPWSPSendDisconnect** function initiates termination of the connection for the socket and sends disconnect data.

## Parameters

### `s` [in]

Descriptor identifying a socket.

### `lpOutboundDisconnectData` [in]

Pointer to the outgoing disconnect data.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPSendDisconnect** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAENOPROTOOPT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOPROTOOPT) | Parameter *lpOutboundDisconnectData* is not null, and the disconnect data is not supported by the service provider. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| [WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN) | Socket is not connected (connection-oriented sockets only). |
| [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK) | The descriptor is not a socket. |
| [WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT) | The *lpOutboundDisconnectData* parameter is not totally contained in a valid part of the user address space. |

## Remarks

The **LPWSPSendDisconnect** function is used on connection-oriented sockets to disable transmission, and to initiate termination of the connection along with the transmission of disconnect data, if any.

After this function has been successfully issued, subsequent sends are disallowed.

The *lpOutboundDisconnectData* parameter, if not null, points to a buffer containing the outgoing disconnect data to be sent to the remote party.

Note that **LPWSPSendDisconnect** does not close the socket, and that resources attached to the socket will not be freed until **[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)** is invoked.

> [!Note]
> The **LPWSPSendDisconnect** function does not block regardless of the SO_LINGER setting on the socket. A Windows Sockets SPI client should not rely on being able to reuse a socket after it has been disconnected. In particular, a Windows Sockets provider is not required to support the use of **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** on such a socket.

## See also

**[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)**

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)