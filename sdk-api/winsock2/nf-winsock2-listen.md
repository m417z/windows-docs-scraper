# listen function

## Description

The
**listen** function places a socket in a state in which it is listening for an incoming connection.

## Parameters

### `s` [in]

A descriptor identifying a bound, unconnected socket.

### `backlog` [in]

The maximum length of the queue of pending connections. If set to **SOMAXCONN**, the underlying service provider responsible for socket *s* will set the backlog to a maximum reasonable value. If set to **SOMAXCONN_HINT(N)** (where N is a number), the backlog value will be N, adjusted to be within the range (200, 65535). Note that **SOMAXCONN_HINT** can be used to set the backlog to a larger value than possible with SOMAXCONN.

**SOMAXCONN_HINT** is only supported by the Microsoft TCP/IP service provider. There is no standard provision to obtain the actual backlog value.

## Return value

If no error occurs,
**listen** returns zero. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEADDRINUSE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs during execution of the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function, but could be delayed until this function if the **bind** was to a partially wildcard address (involving ADDR_ANY) and if a specific address needs to be committed at the time of this function. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind). |
| **[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is already connected. |
| **[WSAEMFILE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No more socket descriptors are available. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The referenced socket is not of a type that supports the [listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) operation. |

## Remarks

To accept connections, a socket is first created with the
[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) function and bound to a local address with the
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function. A backlog for incoming connections is specified with
**listen**, and then the connections are accepted with the
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) function. Sockets that are connection oriented, those of type **SOCK_STREAM** for example, are used with
**listen**. The socket *s* is put into passive mode where incoming connection requests are acknowledged and queued pending acceptance by the process.

A value for the *backlog* of **SOMAXCONN** is a special constant that instructs the underlying service provider responsible for socket *s* to set the length of the queue of pending connections to a maximum reasonable value.

On Windows Sockets 2, this maximum value defaults to a large value (typically several hundred or more).
When calling the **listen** function in a Bluetooth application, it is strongly recommended that a much lower value be used for the *backlog* parameter (typically 2 to 4), since only a few client connections are accepted. This reduces the system resources that are allocated for use by the listening socket. This same recommendation applies to other network applications that expect only a few client connections.

The
**listen** function is typically used by servers that can have more than one connection request at a time. If a connection request arrives and the queue is full, the client will receive an error with an indication of
[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

If there are no available socket descriptors,
**listen** attempts to continue to function. If descriptors become available, a later call to
**listen** or
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) will refill the queue to the current or most recent value specified for the *backlog* parameter, if possible, and resume listening for incoming connections.

If the **listen** function is called on an already listening socket, it will return success without changing the value for the *backlog* parameter. Setting the *backlog* parameter to 0 in a subsequent call to **listen** on a listening socket is not considered a proper reset, especially if there are connections on the socket.

**Note** When issuing a blocking Winsock call such as **listen**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Example Code

The following example demonstrates the use of the **listen** function.

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
    int iResult = 0;

    SOCKET ListenSocket = INVALID_SOCKET;
    sockaddr_in service;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup() failed with error: %d\n", iResult);
        return 1;
    }
    //----------------------
    // Create a SOCKET for listening for incoming connection requests.
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port for the socket that is being bound.
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr("127.0.0.1");
    service.sin_port = htons(27015);

    iResult = bind(ListenSocket, (SOCKADDR *) & service, sizeof (service));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"bind function failed with error %d\n", WSAGetLastError());
        iResult = closesocket(ListenSocket);
        if (iResult == SOCKET_ERROR)
            wprintf(L"closesocket function failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // Listen for incoming connection requests
    // on the created socket
    if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR)
        wprintf(L"listen function failed with error: %d\n", WSAGetLastError());

    wprintf(L"Listening on socket...\n");

    iResult = closesocket(ListenSocket);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"closesocket function failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    WSACleanup();
    return 0;
}

```

### Example Code

For another example that uses the **listen** function, see [Getting Started With Winsock](https://learn.microsoft.com/windows/desktop/WinSock/getting-started-with-winsock).

### Notes for IrDA Sockets

* The Af_irda.h header file must be explicitly included.

### Compatibility

The *backlog* parameter is limited (silently) to a reasonable value as determined by the underlying service provider. Illegal values are replaced by the nearest legal value. There is no standard provision to find out the actual backlog value.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)