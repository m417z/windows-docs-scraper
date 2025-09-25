## Description

The **LPWSPBind** function associates a local address (that is, name) with a socket.

## Parameters

### `s` [in]

A descriptor identifying an unbound socket.

### `name` [in]

The address to assign to the socket, in the form of a [**sockaddr**](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2) structure.

Except for the **sa_family** member, [**sockaddr**](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2) contents are expressed in network byte order. In Windows Sockets 2, the *name* parameter is not strictly interpreted as a pointer to a **sockaddr** structure. It is cast this way for Winsock compatibility. The actual structure is interpreted differently in the context of different address families. The only requirements are that the first **u_short** is the address family and the total size of the memory buffer, in bytes, is *namelen*.

### `namelen` [in]

The length, in bytes, of structure pointed to by the *name* parameter.

### `lpErrno` [out]

A pointer to the error code.

## Return value

If no error occurs, **LPWSPBind** returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEADDRINUSE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEADDRINUSE)** | Some process on the local computer has already bound to the same fully qualified address (for example, IP address and port in the **AF_INET** case) and the socket has not been marked to allow address reuse with SO_REUSEADDR. (See the SO_REUSEADDR socket option under [LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt).) |
| **[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEADDRNOTAVAIL)** | The specified address is not a valid address for this computer. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT)** | The *name* or the *namelen* parameter is not a valid part of the user address space, the *namelen* parameter is too small, the *name* parameter contains incorrect address format for the associated address family, or the first two bytes of the memory block specified by *name* do not match the address family associated with the socket descriptor *s*. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS)** | Function is invoked when a callback is in progress. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | The socket is already bound to an address. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOBUFS)** | There are not enough buffers available, there are too many connections. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |

## Remarks

The **LPWSPBind** function is used on an unconnected connectionless or connection-oriented socket, before subsequent calls to the [**LPWSPConnect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect) or [**LPWSPListen**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten) functions. When a socket is created with [**LPWSPSocket**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket), it exists in a namespace (address family), but it has no name or local address assigned. The **LPWSPBind** function establishes the local association of the socket by assigning a local name to an unnamed socket.

As an example, in the Internet address family, a name consists of three parts: the address family, a host address, and a port number that identifies the Winsock SPI client. In Windows Sockets 2, the *name* parameter is not strictly interpreted as a pointer to a [**sockaddr**](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2) structure. Service providers are free to regard it as a pointer to a block of memory of size *namelen*. The first two bytes in this block (corresponding to **sa_family** in the **sockaddr** declaration) must contain the address family that was used to create the socket. Otherwise, the error [WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT) will be indicated.

If a Windows Sockets 2 SPI client does not care what local address is assigned to it, it will specify the manifest constant value **ADDR_ANY** for the **sa_data** member of the *name* parameter. This instructs the service provider to use any appropriate network address. For TCP/IP, if the port is specified as zero, the service provider will assign a unique port to the Winsock SPI client with a value between 1024 and 5000. The SPI client can use [**LPWSPGetSockName**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockname) after **LPWSPBind** to learn the address and the port that has been assigned to it. However, note that if the Internet address is equal to INADDR_ANY, [**LPWSPGetSockOpt**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt) will not necessarily be able to supply the address until the socket is connected, since several addresses can be valid if the host is multihomed.

## See also

[sockaddr](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2)

[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)

[LPWSPGetSockName](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockname)

[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)

[WSPSetSockOpt](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566318(v=vs.85))

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)