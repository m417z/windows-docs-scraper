## Description

The **LPWSPGetSockName** function gets the local name for a socket.

## Parameters

### `s` [in]

Descriptor identifying a bound socket.

### `name` [out]

Pointer to a **[sockaddr](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2)** structure used to supply the address (name) of the socket.

### `namelen` [in, out]

On input, pointer to an integer that indicates the size of the structure pointed to by *name*, in bytes. On output indicates the size of the returned name, in bytes.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPGetSockName** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT)** | The *name* or the *namelen* parameter is not a valid part of the user address space, or the *namelen* parameter is too small. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS)** | Function is invoked when a callback is in progress. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | Socket has not been bound to an address with **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**, or ADDR_ANY is specified in **LPWSPBind** but connection has not yet occurred. |

## Remarks

**LPWSPGetSockName** retrieves the current name for the specified socket descriptor in *name*. It is used on a bound and/or connected socket specified by the *s* parameter. The local association is returned. This call is especially useful when a **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** call has been made without doing a **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)** first; as this call provides the only means by which the local association that has been set by the service provider can be determined.

If a socket was bound to an unspecified address (for example, ADDR_ANY), indicating that any of the host's addresses within the specified address family should be used for the socket, **LPWSPGetSockName** will *not* necessarily return information about the host address, unless the socket has been connected with **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** or **[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)**. The Windows Sockets SPI client must not assume that an address will be specified unless the socket is connected. This is because for a multihomed host, the address that will be used for the socket is unknown until the socket is connected.

## See also

**[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**

**[LPWSPGetPeerName](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetpeername)**

**[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)**
