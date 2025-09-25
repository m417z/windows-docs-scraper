# connect function

## Description

The
**connect** function establishes a connection to a specified socket.

## Parameters

### `s` [in]

A descriptor identifying an unconnected socket.

### `name` [in]

A pointer to the
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure to which the connection should be established.

### `namelen` [in]

The length, in bytes, of the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure pointed to by the *name* parameter.

## Return value

If no error occurs,
**connect** returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

On a blocking socket, the return value indicates success or failure of the connection attempt.

With a nonblocking socket, the connection attempt cannot be completed immediately. In this case,
**connect** will return SOCKET_ERROR, and
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) will return
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). In this case, there are three possible scenarios:

* Use the
  [select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select) function to determine the completion of the connection request by checking to see if the socket is writable.
* If the application is using
  [WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) to indicate interest in connection events, then the application will receive an FD_CONNECT notification indicating that the
  **connect** operation is complete (successfully or not).
* If the application is using
  [WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) to indicate interest in connection events, then the associated event object will be signaled indicating that the
  **connect** operation is complete (successfully or not).

Until the connection attempt completes on a nonblocking socket, all subsequent calls to
**connect** on the same socket will fail with the error code
[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), and
[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) when the connection completes successfully. Due to ambiguities in version 1.1 of the Windows Sockets specification, error codes returned from
**connect** while a connection is already pending may vary among implementations. As a result, it is not recommended that applications use multiple calls to connect to detect connection completion. If they do, they must be prepared to handle
[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) and
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) error values the same way that they handle
[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), to assure robust operation.

If the error code returned indicates the connection attempt failed (that is,
[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2),
[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2),
[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)) the application can call
**connect** again for the same socket.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEADDRINUSE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs when executing [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), but could be delayed until the [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) function if the **bind** was to a wildcard address (**INADDR_ANY** or **in6addr_any**) for the local IP address. A specific address needs to be implicitly bound by the **connect** function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonblocking [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) call is in progress on the specified socket.<br><br>**Note** In order to preserve backward compatibility, this error is reported as [WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) to Windows Sockets 1.1 applications that link to either Winsock.dll or Wsock32.dll. |
| **[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The remote address is not a valid address (such as **INADDR_ANY** or **in6addr_any**) . |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Addresses in the specified family cannot be used with this socket. |
| **[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The attempt to connect was forcefully rejected. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure pointed to by the *name* contains incorrect address format for the associated address family or the *namelen* parameter is too small. This error is also returned if the **sockaddr** structure pointed to by the *name* parameter with a length specified in the *namelen* parameter is not in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The parameter *s* is a listening socket. |
| **[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is already connected (connection-oriented sockets only). |
| **[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network cannot be reached from this host at this time. |
| **[WSAEHOSTUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A socket operation was attempted to an unreachable host. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **Note** No buffer space is available. The socket cannot be connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor specified in the *s* parameter is not a socket. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An attempt to connect timed out without establishing a connection. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is marked as nonblocking and the connection cannot be completed immediately. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An attempt to connect a datagram socket to broadcast address failed because [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) option SO_BROADCAST is not enabled. |

## Remarks

The
**connect** function is used to create a connection to the specified destination. If socket *s*, is unbound, unique values are assigned to the local association by the system, and the socket is marked as bound.

For connection-oriented sockets (for example, type SOCK_STREAM), an active connection is initiated to the foreign host using *name* (an address in the namespace of the socket; for a detailed description, see
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) and
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)).

**Note** If a socket is opened, a
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) call is made, and then a
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) call is made, Windows Sockets performs an implicit
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function call.

When the socket call completes successfully, the socket is ready to send and receive data. If the address member of the structure specified by the *name* parameter is filled with zeros,
**connect** will return the error
[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). Any attempt to reconnect an active connection will fail with the error code
[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

For connection-oriented, nonblocking sockets, it is often not possible to complete the connection immediately. In such a case, this function returns the error
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). However, the operation proceeds.

When the success or failure outcome becomes known, it may be reported in one of two ways, depending on how the client registers for notification.

* If the client uses the
  [select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select) function, success is reported in the writefds set and failure is reported in the exceptfds set.
* If the client uses the functions
  [WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or
  [WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect), the notification is announced with FD_CONNECT and the error code associated with the FD_CONNECT indicates either success or a specific reason for failure.

If the connection is not completed immediately, the client should wait for connection completion before attempting to set socket options using [setsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-setsockopt). Calling setsockopt while a connection is in progress is not supported.

For a connectionless socket (for example, type SOCK_DGRAM), the operation performed by
**connect** is merely to establish a default destination address that can be used on subsequent
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)/
[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend) and
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)/
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) calls. Any datagrams received from an address other than the destination address specified will be discarded. If the address member of the structure specified by *name* is filled with zeros, the socket will be disconnected. Then, the default remote address will be indeterminate, so
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)/
[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend) and
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)/
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) calls will return the error code
[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). However,
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)/
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) and
[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom)/
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom) can still be used. The default destination can be changed by simply calling
**connect** again, even if the socket is already connected. Any datagrams queued for receipt are discarded if *name* is different from the previous
**connect**.

For connectionless sockets, *name* can indicate any valid address, including a broadcast address. However, to connect to a broadcast address, a socket must use
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) to enable the SO_BROADCAST option. Otherwise,
**connect** will fail with the error code
[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

When a connection between sockets is broken, the socket that was connected should be discarded and new socket should be created. When a problem develops on a connected socket, the application must discard the socket and create the socket again in order to return to a stable point.

**Note** When issuing a blocking Winsock call such as **connect**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Example Code

The following example demonstrates the use of the **connect** function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

int wmain()
{
    //----------------------
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup function failed with error: %d\n", iResult);
        return 1;
    }
    //----------------------
    // Create a SOCKET for connecting to server
    SOCKET ConnectSocket;
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        wprintf(L"socket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port of the server to be connected to.
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr("127.0.0.1");
    clientService.sin_port = htons(27015);

    //----------------------
    // Connect to server.
    iResult = connect(ConnectSocket, (SOCKADDR *) & clientService, sizeof (clientService));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"connect function failed with error: %ld\n", WSAGetLastError());
        iResult = closesocket(ConnectSocket);
        if (iResult == SOCKET_ERROR)
            wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    wprintf(L"Connected to server.\n");

    iResult = closesocket(ConnectSocket);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    WSACleanup();
    return 0;
}

```

For another example that uses the **connect** function, see [Getting Started With Winsock](https://learn.microsoft.com/windows/desktop/WinSock/getting-started-with-winsock).

### Notes for IrDA Sockets

* The Af_irda.h header file must be explicitly included.
* If an existing IrDA connection is detected at the media-access level,
  [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned.
* If active connections to a device with a different address exist,
  [WSAEADDRINUSE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned.
* If the socket is already connected or an exclusive/multiplexed mode change failed,
  [WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned.
* If the socket was previously bound to a local service name to accept incoming connections using
  [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind),
  [WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned. Note that once a socket is bound, it cannot be used for establishing an outbound connection.

IrDA implements the connect function with addresses of the form sockaddr_irda. Typically, a client application will create a socket with the socket function, scan the immediate vicinity for IrDA devices with the IRLMP_ENUMDEVICES socket option, choose a device from the returned list, form an address, and then call
**connect**. There is no difference between blocking and nonblocking semantics.

## See also

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)