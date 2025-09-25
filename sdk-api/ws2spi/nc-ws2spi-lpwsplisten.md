## Description

The **LPWSPListen** function establishes a socket to listen for incoming connections.

## Parameters

### `s` [in]

Descriptor identifying a bound, unconnected socket.

### `backlog` [in]

Maximum length to which the queue of pending connections can grow. If this value is SOMAXCONN, then the service provider should set the backlog to a maximum "reasonable" value. There is no standard provision to find out the actual backlog value.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPListen** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAEADDRINUSE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEADDRINUSE) | Socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs at the time of **[Bind](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-bind)**, but could be delayed until this function if the **bind** was to a partially wildcard address (involving ADDR_ANY) and if a specific address needs to be committed at the time of this function. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Function is invoked when a callback is in progress. |
| [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL) | Socket has not been bound with **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**. |
| [WSAEISCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEISCONN) | Socket is already connected. |
| [WSAEMFILE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEMFILE) | No more socket descriptors are available. |
| [WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOBUFS) | No buffer space is available. |
| [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK) | The descriptor is not a socket. |
| [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEOPNOTSUPP) | Referenced socket is not of a type that supports the **[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)** operation. |

## Remarks

To accept connections, a socket is first created with [LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket) bound to a local address with **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**, a backlog for incoming connections is specified with **LPWSPListen**, and then the connections are accepted with **[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)**. **LPWSPListen** applies only to sockets that are connection oriented (for example, SOCK_STREAM). The socket *s* is put into passive mode where incoming connection requests are acknowledged and queued pending acceptance by the Windows Sockets SPI client.

This function is typically used by servers that could have more than one connection request at a time: if a connection request arrives with the queue full, the client will receive an error with an indication of [WSAECONNREFUSED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNREFUSED).

**LPWSPListen** should continue to function rationally when there are no available descriptors. It should accept connections until the queue is emptied. If descriptors become available, a later call to **LPWSPListen** or **[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)** will refill the queue to the current or most recent backlog, if possible, and resume listening for incoming connections.

A Windows Sockets SPI client can call **LPWSPListen** more than once on the same socket. This has the effect of updating the current backlog for the listening socket. Should there be more pending connections than the new *backlog* value, the excess pending connections will be reset and dropped.

The *backlog* parameter is limited (silently) to a reasonable value as determined by the service provider. Illegal values are replaced by the nearest legal value. There is no standard provision to find out the actual backlog value.

## See also

**[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)**

**[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)**

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)