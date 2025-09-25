## Description

The **LPWSPSetSockOpt** function sets a socket option.

## Parameters

### `s` [in]

The descriptor that identifies a socket.

### `level` [in]

The level at which the option is defined; the supported levels include **[SOL_SOCKET](https://learn.microsoft.com/windows/win32/winsock/sol-socket-socket-options)**. For more information, see [Winsock Annexes](https://learn.microsoft.com/windows/win32/winsock/winsock-annexes).

### `optname` [in]

The socket option for which the value is to be set.

### `optval` [in]

A pointer to the buffer in which the value for the requested option is supplied.

### `optlen` [in]

The size, in bytes, of the *optval* buffer.

### `lpErrno` [out]

A pointer to the error code.

## Return value

If no error occurs, **LPWSPSetSockOpt** returns zero. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT) | The *optval* is not in a valid part of the process address space or *optlen* parameter is too small. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Function is invoked when a callback is in progress. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL) | The *level* is not valid, or the information in *optval* is not valid. |
| [WSAENETRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETRESET) | The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. |
| **[WSAENOPROTOOPT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOPROTOOPT)** | Option is unknown or unsupported for the specified provider. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN)** | The connection has been reset when [SO_KEEPALIVE](https://learn.microsoft.com/windows/win32/winsock/so-keepalive) is set. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |

## Remarks

The **LPWSPSetSockOpt** function sets the current value for a socket option associated with a socket of any type, in any state. Although options can exist at multiple protocol levels, they are always present at the uppermost socket level. Options affect socket operations, such as whether broadcast messages can be sent on the socket.

There are two types of socket options: Boolean options that enable or disable a feature or behavior, and options that require an integer value or structure. To enable a Boolean option, *optval* points to a nonzero integer. To disable the option, *optval* points to an integer equal to zero. The *optlen* parameter should be equal to sizeof (int) for Boolean options. For other options, *optval* points to an integer or structure that contains the desired value for the option, and *optlen* is the length of the integer or structure.

For more information about socket options, see **[Socket Options](https://learn.microsoft.com/windows/win32/winsock/socket-options)**.

### level = SOL_SOCKET

| Value | Type | Meaning |
|---------------------------------------|----------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| SO_BROADCAST | BOOL | Enables transmission and receipt of broadcast messages on the socket. |
| SO_DEBUG | BOOL | Records debugging information. |
| SO_DONTLINGER | BOOL | Reserved. |
| SO_DONTROUTE | BOOL | Disabled routing: send directly to an interface. Setting this socket option succeeds but is ignored on AF_INET sockets; fails on AF_INET6 sockets with [WSAENOPROTOOPT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOPROTOOPT) . This option is not supported on ATM sockets (results in an error). |
| SO_GROUP_PRIORITY | int | Reserved. |
| **[SO_KEEPALIVE](https://learn.microsoft.com/windows/win32/winsock/so-keepalive)** | BOOL | Sends keep-alives. Not supported on ATM sockets (results in an error). |
| SO_LINGER | struct linger | Lingers on close if unsent data is present. |
| SO_OOBINLINE | BOOL | Receives OOB data in the normal data stream. |
| SO_RCVBUF | int | Specifies the total per-socket buffer space reserved for receives. This is unrelated to SO_MAX_MSG_SIZE and does not necessarily correspond to the size of the TCP receive window. |
| SO_REUSEADDR | BOOL | Allows the socket to be bound to an address that is already in use. (See **[Bind](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-bind)**.) Not applicable on ATM sockets. |
| SO_SNDBUF | int | Specifies the total per-socket buffer space reserved for sends. This is unrelated to SO_MAX_MSG_SIZE and does not necessarily correspond to the size of a TCP send window. |
| PVD_CONFIG | Service Provider Dependent | This object stores the configuration information for the service provider associated with socket *s*. The exact format of this data structure is service provider specific. |

Calling **[LPWSPGetSockopt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)** with an unsupported option will result in an error code of [WSAENOPROTOOPT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOPROTOOPT) returned in *lpErrno*.

SO_DEBUG

Windows Sockets service providers are encouraged, but not required, to supply output debug information if the **SO_DEBUG** option is set by a Windows Sockets SPI client. The mechanism for generating the debug information and the format are beyond the scope of this specification.

SO_GROUP_PRIORITY

Reserved.

**[SO_KEEPALIVE](https://learn.microsoft.com/windows/win32/winsock/so-keepalive)**

A Windows Sockets SPI client can request that a TCP/IP provider enable the use of keep-alive packets on TCP connections by turning on the **[SO_KEEPALIVE](https://learn.microsoft.com/windows/win32/winsock/so-keepalive)** socket option. A Windows Sockets provider need not support the use of keep-alives: if it does, the precise semantics are implementation specific, but should conform to section 4.2.3.6 of RFC 1122: *Requirements for Internet Hosts—Communication Layers*. (This resource may only be available in English.) If a connection is dropped as the result of keep-alive the error code [WSAENETRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETRESET) is returned to any calls in progress on the socket, and any subsequent calls will fail with [WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN) .

SO_LINGER

SO_LINGER controls the action taken when unsent data is queued on a socket and a **[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)** is performed. See **LPWSPCloseSocket** for a description of the way in which the **SO_LINGER** settings affect the semantics of **LPWSPCloseSocket**. The Windows Sockets SPI client sets the desired behavior by creating a **[LINGER](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-linger)** structure, pointed to by the *optval* parameter, with the following elements.

```cpp
struct linger {
  u_short l_onoff;
  u_short l_linger;
}
```

To enable **SO_LINGER**, a Windows Sockets SPI client should set **l_onoff** to a nonzero value, set **l_linger** to zero or the desired time-out, in seconds, and call **LPWSPSetSockOpt**. To enable **SO_DONTLINGER**, that is, disable SO_LINGER, **l_onoff** should be set to zero and **LPWSPSetSockOpt** should be called. Be aware that enabling **SO_LINGER** with a nonzero time-out on a nonblocking socket is not recommended. For more information, see **[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)**.

Enabling **SO_LINGER** also disables **SO_DONTLINGER**, and vice versa. Be aware that if **SO_DONTLINGER** is disabled (that is, **SO_LINGER** is enabled) then no time-out value is specified. In this case, the time-out used is implementation dependent. If a previous time-out has been established for a socket (by enabling **SO_LINGER**), then this time-out value should be reinstated by the service provider.

SO_REUSEADDR

By default, a socket cannot be bound (for more information, see **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**) to a local address that is already in use. On occasion, however, it may be desirable to reuse an address in this way. Because every connection is uniquely identified by the combination of local and remote addresses, there is no problem with having two sockets bound to the same local address as long as the remote addresses are different. To inform the Windows Sockets provider that a **LPWSPBind** on a socket should be allowed to bind to a local address that is already in use by another socket, the Windows Sockets SPI client should set the **SO_REUSEADDR** socket option for the socket before issuing the **LPWSPBind**. Be aware that the option is interpreted only at the time of the **LPWSPBind**: it is therefore unnecessary, but harmless, to set the option on a socket that is not to be bound to an existing address, and setting or resetting the option after the **LPWSPBind** has no effect on this or any other socket.

SO_SNDBUF

When a Windows Sockets implementation supports the **SO_RCVBUF** and **SO_SNDBUF** options, a Windows Sockets SPI client can request different buffer sizes (larger or smaller). The call can succeed even though the service provider did not make available the entire amount requested. A Windows Sockets SPI client must call **[LPWSPGetSockopt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)** with the same option to verify the buffer size actually provided.

PVD_CONFIG

This object stores the configuration information for the service provider associated with socket *s*. The exact format of this data structure is service provider specific.

## See also

**[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**

**[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)**

**[LPWSPGetSockopt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)**

**[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)**

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)