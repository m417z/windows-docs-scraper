## Description

The **LPWSPGetSockOpt** function retrieves a socket option.

## Parameters

### `s`

A descriptor identifying a socket.

### `level`

The level at which the option is defined; the supported levels include **[SOL_SOCKET](https://learn.microsoft.com/windows/win32/winsock/sol-socket-socket-options)**. (See annex for more protocol-specific levels.)

### `optname`

The socket option for which the value is to be retrieved.

### `optval`

A pointer to the buffer in which the value for the requested option is to be returned.

### `optlen`

A pointer to the size, in bytes, of the *optval* buffer.

### `lpErrno`

A pointer to the error code.

## Return value

If no error occurs, **LPWSPGetSockOpt** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT) | One of the *optval* or the *optlen* parameters is not a valid part of the user address space, or the *optlen* parameter is too small. |
| [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL) | The *level* is unknown or invalid. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Function is invoked when a callback is in progress. |
| [WSAENOPROTOOPT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOPROTOOPT) | Option is unknown or unsupported by the indicated protocol family. |
| [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK) | The descriptor is not a socket. |

## Remarks

The **LPWSPGetSockOpt** function retrieves the current value for a socket option associated with a socket of any type, in any state, and stores the result in *optval*. Options can exist at multiple protocol levels, but they are always present at the uppermost socket' level. Options affect socket operations, such as the routing of packets and OOB data transfer.

The value associated with the selected option is returned in the buffer *optval*. The integer pointed to by *optlen* should originally contain the size of this buffer; on return, it will be set to the size of the value returned. For SO_LINGER, this will be the size of a structure linger; for most other options it will be the size of an integer.

The Windows Sockets SPI client is responsible for allocating any memory space pointed to directly or indirectly by any of the parameters it specifies.

If the option was never set with **[LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt)**, then **LPWSPGetSockOpt** returns the default value for the option.

For more information on socket options, see **[Socket Options](https://learn.microsoft.com/windows/win32/winsock/socket-options)**.

### level = SOL_SOCKET

| Value | Type | Meaning | Default |
|---------------------------------------|-----------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------|
| SO_ACCEPTCONN | BOOL | The socket is listening through **[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)**. | **FALSE** unless a **[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)** has been performed. |
| SO_BROADCAST | BOOL | The socket is configured for the transmission and receipt of broadcast messages. | **FALSE** |
| SO_DEBUG | BOOL | Debugging is enabled. | **FALSE** |
| SO_DONTLINGER | BOOL | If true, the SO_LINGER option is disabled. | **TRUE** |
| SO_DONTROUTE | BOOL | Routing is disabled. Setting this socket option succeeds but is ignored on AF_INET sockets; fails on AF_INET6 sockets with [WSAENOPROTOOPT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOPROTOOPT) . This option is not supported on ATM sockets (results in an error). | **FALSE** |
| SO_ERROR | integer | Retrieves error status and clears. | 0 |
| SO_GROUP_ID | GROUP | Reserved. | Null |
| SO_GROUP_PRIORITY | integer | Reserved. | 0 |
| **[SO_KEEPALIVE](https://learn.microsoft.com/windows/win32/winsock/so-keepalive)** | BOOL | Keepalives are being sent. Not supported on ATM sockets (results in an error). | **FALSE** |
| SO_LINGER | **[LINGER](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-linger)** structure | Returns the current linger options. | 1 is on (default), 0 is off |
| SO_MAX_MSG_SIZE | unsigned integer | The maximum size of a message for message-oriented socket types (for example, SOCK_DGRAM). Has no meaning for stream oriented sockets. | Implementation dependent |
| SO_OOBINLINE | BOOL | OOB data is being received in the normal data stream. | **FALSE** |
| SO_PROTOCOL_INFO | **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure | A description of the protocol information for the protocol that is bound to this socket. | Protocol dependent |
| SO_RCVBUF | integer | The total per-socket buffer space reserved for receives. This is unrelated to SO_MAX_MSG_SIZE and does not necessarily correspond to the size of the TCP receive window. | Implementation dependent |
| SO_REUSEADDR | BOOL | The socket can be bound to an address that is already in use. This option is not applicable on ATM sockets. | **FALSE**. |
| SO_SNDBUF | integer | The total per-socket buffer space reserved for sends. This is unrelated to SO_MAX_MSG_SIZE and does not necessarily correspond to the size of a TCP send window. | Implementation dependent |
| SO_TYPE | integer | The type of socket (for example, SOCK_STREAM). | As created with **[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)">LPWSPSocket** |
| PVD_CONFIG | Service Provider Dependent | An opaque data structure object from the service provider associated with socket *s*. This object stores the current configuration information of the service provider. The exact format of this data structure is service provider-specific. | Implementation dependent |

Calling **LPWSPGetSockOpt** with an unsupported option will result in an error code of [WSAENOPROTOOPT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOPROTOOPT) being returned in *lpErrno*.

SO_DEBUG

Windows Sockets service providers are encouraged (but not required) to supply output debug information if the SO_DEBUG option is set by a Windows Sockets SPI client. The mechanism for generating the debug information and the form it takes are beyond the scope of this specification.

SO_ERROR

The SO_ERROR option returns and resets the per-socket-based error code (that is not necessarily the same as the per-thread-error code that is maintained by the WS2_32.DLL). A successful Windows Sockets call on the socket does not reset the socket-based error code returned by the SO_ERROR option.

SO_GROUP_ID

Reserved. This value should be **NULL**.

SO_GROUP_PRIORITY

Reserved.

**[SO_KEEPALIVE](https://learn.microsoft.com/windows/win32/winsock/so-keepalive)**

A Windows Sockets SPI client can request that a TCP/IP service provider enable the use of keep-alive packets on TCP connections by turning on the **[SO_KEEPALIVE](https://learn.microsoft.com/windows/win32/winsock/so-keepalive)** socket option. A Windows Sockets provider need not support the use of keep-alives: if it does, the precise semantics are implementation specific but should conform to section 4.2.3.6 of RFC 1122: *Requirements for Internet Hosts—Communication Layers*. (This resource may only be available in English.) If a connection is dropped as the result of keep-alives, the error code [WSAENETRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETRESET) is returned to any calls in progress on the socket, and any subsequent calls will fail with [WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN) .

SO_LINGER

SO_LINGER controls the action taken when unsent data is queued on a socket and a **[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)** is performed. See **LPWSPCloseSocket** for a description of the way in which the SO_LINGER settings affect the semantics of **LPWSPCloseSocket**. The Windows Sockets SPI client obtains the desired behavior by creating a **[LINGER](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-linger)** structure (pointed to by the **optval** parameter) with the following elements:

```C++
}
```

SO_MAX_MSG_SIZE

This is a get-only socket option, which indicates the maximum size of an outbound send message for message-oriented socket types (for example, SOCK_DGRAM) as implemented by the service provider. It has no meaning for byte stream-oriented sockets. There is no provision to determine the maximum inbound message size.

SO_PROTOCOL_INFOW

This is a get-only option that supplies the **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure associated with this socket. See **[WSCEnumProtocols](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wscenumprotocols)** for more information about this structure.

SO_SNDBUF

When a Windows Sockets service provider supports the SO_RCVBUF and SO_SNDBUF options, a Windows Sockets SPI client can use **[LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt)** to request different buffer sizes (larger or smaller). The call can succeed even though the service provider did not make available the entire amount requested. A Windows Sockets SPI client must call this function with the same option to check the buffer size actually provided.

SO_REUSEADDR

By default, a socket cannot be bound (see **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**) to a local address that is already in use. On occasion, however, it may be desirable to reuse an address in this way. Since every connection is uniquely identified by the combination of local and remote addresses, there is no problem with having two sockets bound to the same local address as long as the remote addresses are different. To inform the Windows Sockets provider that a **LPWSPBind** on a socket should be allowed to bind to a local address that is already in use by another socket, the Windows Sockets SPI client should set the SO_REUSEADDR socket option for the socket before issuing the **LPWSPBind**. Note that the option is interpreted only at the time of the **LPWSPBind**. It is therefore unnecessary (but harmless) to set the option on a socket that is not to be bound to an existing address, and setting or resetting the option after the **LPWSPBind** has no effect on this or any other socket.

PVD_CONFIG

This option retrieves an opaque data structure object from the service provider associated with socket *s*. This object stores the current configuration information of the service provider. The exact format of this data structure is service-provider specific.

## See also

**[LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt)**

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)