# WSAConnectByList function

## Description

The **WSAConnectByList** function
establishes a connection to one out of a collection of possible endpoints represented by a set of
destination addresses (host names and ports). This function takes all the destination addresses passed
to it and all of the local computer's source addresses, and tries connecting using all possible address
combinations before giving up.

This function supports both IPv4 and IPv6 addresses.

## Parameters

### `s` [in]

A descriptor that identifies an unbound and unconnected socket. Note that unlike other Winsock calls to
establish a connection (for example, [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)),
the **WSAConnectByList** function requires an
unbound socket.

### `SocketAddress` [in]

A pointer to a [SOCKET_ADDRESS_LIST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa385467(v=vs.85))
structure that represents the possible destination address and port pairs to connect to a peer. It is the
application's responsibility to fill in the port number in the each
[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structure in the
**SOCKET_ADDRESS_LIST**.

### `LocalAddressLength` [in, out]

On input, a pointer to the size, in bytes, of the *LocalAddress* buffer provided by
the caller. On output, a pointer to the size, in bytes, of the **SOCKADDR** for the
local address stored in the *LocalAddress* buffer filled in by the system upon
successful completion of the call.

### `LocalAddress` [out]

A pointer to the **SOCKADDR** structure that receives the local address of the
connection. The size of the parameter is exactly the size returned in
*LocalAddressLength*. This is the same information that would be returned by the
[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname) function. This parameter can be
**NULL**, in which case, the *LocalAddressLength* parameter is
ignored.

### `RemoteAddressLength` [in, out]

On input, a pointer to the size, in bytes, of the *RemoteAddress* buffer provided
by the caller. On output, a pointer to the size, in bytes, of the **SOCKADDR** for the
remote address stored in *RemoteAddress* buffer filled-in by the system upon successful
completion of the call.

### `RemoteAddress` [out]

A pointer to the **SOCKADDR** structure that receives the remote address of the
connection. This is the same information that would be returned by the
**getpeername** function. This parameter can be **NULL**, in
which case, the *RemoteAddressLength* is ignored.

### `timeout` [in]

The time, in milliseconds, to wait for a response from the remote application before aborting the call.
This parameter can be **NULL** in which case
**WSAConnectByList** will complete after either the
connection is successfully established or after a connection was attempted and failed on all possible
local-remote address pairs.

### `Reserved` [in]

Reserved for future implementation. This parameter must be set to **NULL**.

## Return value

If a connection is established,
**WSAConnectByList** returns **TRUE** and
*LocalAddress* and *RemoteAddress* parameters are filled in if
these buffers were supplied by the caller.

If the call fails, **FALSE** is returned.
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) can then be called to get
extended error information.

| Return code | Description |
| --- | --- |
| **WSAEHOSTUNREACH** | The host passed as the *nodename* parameter was unreachable. |
| **WSAEINVAL** | An invalid parameter was passed to the function. The *Reserved* parameter must be **NULL**. |
| **WSAENOBUFS** | Sufficient memory could not be allocated. |
| **WSAENOTSOCK** | An invalid socket was passed to the function. The *s* parameter must not be **INVALID_SOCKET** or **NULL**. |
| **WSAETIMEDOUT** | A response from the remote application was not received before the *timeout* parameter was exceeded. |

## Remarks

**WSAConnectByList** is similar to the
[WSAConnectByName](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbynamea) function. Instead of taking a
single host name and service name (port),
**WSAConnectByList** takes a list of addresses (host
addresses and ports) and connects to one of the addresses. The
**WSAConnectByList** function is designed to support
peer-to-peer collaboration scenarios where an application needs to connect to any available node out of a list of
potential nodes. **WSAConnectByList** is compatible
with both IPv6 and IPv4 versions.

The set of possible destinations, represented by a list of addresses, is
provided by the caller. **WSAConnectByList** does
more than simply attempt to connect to one of possibly many destination addresses. Specifically, the function
takes all remote addresses passed in by the caller, all local addresses, and then attempts a connection first
using address pairs with the highest chance of success. As such,
**WSAConnectByList** not only ensures that connection
will be established if a connection is at all possible, but also minimizes the time to establish the
connection.

The caller can specify the *LocalAddress* and *RemoteAddress*
buffers and lengths to determine the local and remote addresses for which the connection was successfully
established.

The *timeout* parameter allows the caller to limit the time spent by the function in
establishing a connection. Internally,
**WSAConnectByList** performs multiple operations
(connection attempts). In between each operation, the *timeout* parameter is checked to
see if the *timeout* has been exceeded and, if so, the call is aborted. Note that an
individual operation (connect) will not be interrupted once the *timeout* is exceeded,
so the **WSAConnectByList** call can take longer to
time out than the value specified in the *timeout* parameter.

**WSAConnectByList** has limitations: It works only
for connection-oriented sockets, such as those of type SOCK_STREAM. The function does not support overlapped I/O
or non-blocking behavior. **WSAConnectByList** will
block even if the socket is in non-blocking mode.
**WSAConnectByList** will try connecting (one-by-one)
to the various addresses provided by the caller. Potentially, each of these connection attempts may fail with a
different error code. Since only a single error code can be returned, the value returned is the error code from
the last connection attempt.

To enable both IPv6 and IPv4 addresses to be passed in the single address list accepted by the function, the
following steps must be performed prior to calling the function:

* The [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function must be called on a
  socket created for the AF_INET6 address family to disable the **IPV6_V6ONLY** socket
  option before calling **WSAConnectByList**. This is
  accomplished by calling the **setsockopt** function on
  the socket with the *level* parameter set to **IPPROTO_IPV6**
  (see [IPPROTO_IPV6 Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options)), the
  *optname* parameter set to **IPV6_V6ONLY**, and the
  *optvalue* parameter value set to zero .
* Any IPv4 addresses must be represented in the IPv4-mapped IPv6 address format which enables an IPv6 only application to communicate with an IPv4 node. The IPv4-mapped IPv6 address format allows the IPv4 address of an IPv4 node to be represented as an IPv6
  address. The IPv4 address is encoded into the low-order 32 bits of
  the IPv6 address, and the high-order 96 bits hold the fixed prefix
  0:0:0:0:0:FFFF. The IPv4-mapped IPv6 address format is specified in RFC 4291. For more information, see [www.ietf.org/rfc/rfc4291.txt](https://www.rfc-editor.org/rfc/rfc4291.html). The IN6ADDR_SETV4MAPPED macro in *Mstcpip.h* can be used to convert an IPv4 address to the required IPv4-mapped IPv6 address format.

The arrays of pointers passed in the *SocketAddressList* parameter point to an array of
[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structures, which are a generic
data type. The *RemoteAddress* and the *LocalAddress*
parameters also point to **SOCKADDR** structures. When
**WSAConnectByList** is called, it is expected that
a socket address type specific to the network protocol or address family being used will actually be passed in
these parameters. So for IPv4 addresses, a pointer to a **sockaddr_in** structure
would be cast to a pointer to **SOCKADDR** when passed as a parameter. For IPv6
addresses, a pointer to a **sockaddr_in6** structure would be cast to a pointer to
**SOCKADDR** when passed as a parameter. The
*SocketAddressList* parameter can contain pointers to a mixture of IPv4 and IPv6
addresses. So some **SOCKET_ADDRESS** pointers can be
to **sockaddr_in** structures and others can be to
**sockaddr_in6** structures. If it is expected that IPv6 addresses can be used, then
the *RemoteAddress* and *LocalAddress* parameters should point
to **sockaddr_in6** structures and be cast to **SOCKADDR**
structures. The *RemoteAddressLength* and the
*LocalAddressLength* parameters must represent the length of these larger
structures.

When the
[WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex) function returns **TRUE**, the socket *s* is in the default state for a connected socket. The socket *s* does not enable previously set properties or options until SO_UPDATE_CONNECT_CONTEXT is set on the socket. Use the
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function to set the SO_UPDATE_CONNECT_CONTEXT option.

For example:

```cpp
//Need to #include <mswsock.h> for SO_UPDATE_CONNECT_CONTEXT

int iResult = 0;

iResult = setsockopt( s, SOL_SOCKET, SO_UPDATE_CONNECT_CONTEXT, NULL, 0 );

```

**Note** When issuing a blocking Winsock call such as [WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex) with the *timeout* parameter set to **NULL**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

#### Examples

Establish a connection using **WSAConnectByList**.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

SOCKET
OpenAndConnect(SOCKET_ADDRESS_LIST *AddressList)
{
    SOCKET ConnSocket = INVALID_SOCKET;

    int ipv6only = 0;
    int iResult;
    BOOL bSuccess;

    SOCKADDR_STORAGE LocalAddr = {0};
    SOCKADDR_STORAGE RemoteAddr = {0};

    DWORD dwLocalAddr = sizeof(LocalAddr);
    DWORD dwRemoteAddr = sizeof(RemoteAddr);

    ConnSocket = socket(AF_INET6, SOCK_STREAM, 0);
    if (ConnSocket == INVALID_SOCKET){
        return INVALID_SOCKET;
    }

    iResult = setsockopt(ConnSocket, IPPROTO_IPV6,
        IPV6_V6ONLY, (char*)&ipv6only, sizeof(ipv6only) );
    if (iResult == SOCKET_ERROR){
        closesocket(ConnSocket);
        return INVALID_SOCKET;
    }

    // AddressList may contain IPv6 and/or IPv4Mapped addresses
    bSuccess = WSAConnectByList(ConnSocket,
            AddressList,
            &dwLocalAddr,
            (SOCKADDR*)&LocalAddr,
            &dwRemoteAddr,
            (SOCKADDR*)&RemoteAddr,
            NULL,
            NULL);
    if (bSuccess){
        return ConnSocket;
    } else {
        return INVALID_SOCKET;
    }
}

```

## See also

[IPPROTO_IPV6 Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options)

[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)

[SOCKET_ADDRESS_LIST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa385467(v=vs.85))

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSAConnectByName](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbynamea)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[getpeername](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getpeername)

[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)