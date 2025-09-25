## Description

The **LPWSPGetPeerName** function gets the address of the peer to which a socket is connected.

## Parameters

### `s` [in]

Descriptor identifying a connected socket.

### `name` [out]

Pointer to the **[sockaddr](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2)** structure to receive the name of the peer.

### `namelen` [in, out]

On input, pointer to an integer that indicates the size of the structure pointed to by *name*, in bytes. On output, indicates the size of the returned name, in bytes.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPGetPeerName** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT)** | The *name* or the *namelen* parameter is not a valid part of the user address space, or the *namelen* parameter is too small. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS)** | Function is invoked when a callback is in progress. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN)** | Socket is not connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |

## Remarks

The **LPWSPGetPeerName** function supplies the name of the peer connected to the socket *s* and stores it in the structure **[sockaddr](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2)** referenced by *name*. It can be used only on a connected socket. For datagram sockets, only the name of a peer specified in a previous **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** call will be returned and any name specified by a previous **[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)** call will not be returned by **LPWSPGetPeerName**.

On return, the *namelen* parameter contains the actual size of the name returned in bytes.

## See also

[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)

[LPWSPGetSockName](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockname)

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)