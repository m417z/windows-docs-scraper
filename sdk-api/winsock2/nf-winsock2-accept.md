# accept function

## Description

The
**accept** function permits an incoming connection attempt on a socket.

## Parameters

### `s` [in]

A descriptor that identifies a socket that has been placed in a listening state with the
[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) function. The connection is actually made with the socket that is returned by
**accept**.

### `addr` [out]

An optional pointer to a buffer that receives the address of the connecting entity, as known to the communications layer. The exact format of the *addr* parameter is determined by the address family that was established when the socket from the
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure was created.

### `addrlen` [in, out]

An optional pointer to an integer that contains the length of structure pointed to by the *addr* parameter.

## Return value

If no error occurs,
**accept** returns a value of type **SOCKET** that is a descriptor for the new socket. This returned value is a handle for the socket on which the actual connection is made.

Otherwise, a value of **INVALID_SOCKET** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

The integer referred to by *addrlen* initially contains the amount of space pointed to by *addr*. On return it will contain the actual length in bytes of the address returned.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An incoming connection was indicated, but was subsequently terminated by the remote peer prior to accepting the call. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *addrlen* parameter is too small or *addr* is not a valid part of the user address space. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The [listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) function was not invoked prior to [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEMFILE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The queue is nonempty upon entry to [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) and there are no descriptors available. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The referenced socket is not a type that supports connection-oriented service. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is marked as nonblocking and no connections are present to be accepted. |

## Remarks

The
**accept** function extracts the first connection on the queue of pending connections on socket *s*. It then creates and returns a handle to the new socket. The newly created socket is the socket that will handle the actual connection; it has the same properties as socket *s*, including the asynchronous events registered with the
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) functions.

The
**accept** function can block the caller until a connection is present if no pending connections are present on the queue, and the socket is marked as blocking. If the socket is marked as nonblocking and no pending connections are present on the queue,
**accept** returns an error as described in the following. After the successful completion of
**accept** returns a new socket handle, the accepted socket cannot be used to accept more connections. The original socket remains open and listens for new connection requests.

The parameter *addr* is a result parameter that is filled in with the address of the connecting entity, as known to the communications layer. The exact format of the *addr* parameter is determined by the address family in which the communication is occurring. The *addrlen* is a value-result parameter; it should initially contain the amount of space pointed to by *addr*; on return it will contain the actual length (in bytes) of the address returned.

The
**accept** function is used with connection-oriented socket types such as SOCK_STREAM. If *addr* and/or *addrlen* are equal to **NULL**, then no information about the remote address of the accepted socket is returned.

**Note** When issuing a blocking Winsock call such as **accept**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Example Code

The following example demonstrates the use of the **accept** function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#include <winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <windows.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int wmain(void)
{

    //----------------------
    // Initialize Winsock.
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %ld\n", iResult);
        return 1;
    }
    //----------------------
    // Create a SOCKET for listening for
    // incoming connection requests.
    SOCKET ListenSocket;
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port for the socket that is being bound.
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(27015);
    inet_pton(AF_INET, "127.0.0.1", &service.sin_addr);

    if (bind(ListenSocket,
             (SOCKADDR *) & service, sizeof (service)) == SOCKET_ERROR) {
        wprintf(L"bind failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    //----------------------
    // Listen for incoming connection requests.
    // on the created socket
    if (listen(ListenSocket, 1) == SOCKET_ERROR) {
        wprintf(L"listen failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    //----------------------
    // Create a SOCKET for accepting incoming requests.
    SOCKET AcceptSocket;
    wprintf(L"Waiting for client to connect...\n");

    //----------------------
    // Accept the connection.
    AcceptSocket = accept(ListenSocket, NULL, NULL);
    if (AcceptSocket == INVALID_SOCKET) {
        wprintf(L"accept failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    } else
        wprintf(L"Client connected.\n");

    // No longer need server socket
    closesocket(ListenSocket);

    WSACleanup();
    return 0;
}

```

For another example that uses the **accept** function, see [Getting Started With Winsock](https://learn.microsoft.com/windows/desktop/WinSock/getting-started-with-winsock).

### Notes for ATM

The following are important issues associated with connection setup, and must be considered when using Asynchronous Transfer Mode (ATM) with Windows Sockets 2:

* The
  **accept** and
  [WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept) functions do not necessarily set the remote address and address length parameters. Therefore, when using ATM, the caller should use the
  **WSAAccept** function and place ATM_CALLING_PARTY_NUMBER_IE in the
  **ProviderSpecific** member of the
  [QoS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure, which itself is included in the *lpSQOS* parameter of the callback function used in accordance with
  **WSAAccept**.
* When using the
  **accept** function, realize that the function may return before connection establishment has traversed the entire distance between sender and receiver. This is because the
  **accept** function returns as soon as it receives a CONNECT ACK message; in ATM, a CONNECT ACK message is returned by the next switch in the path as soon as a CONNECT message is processed (rather than the CONNECT ACK being sent by the end node to which the connection is ultimately established). As such, applications should realize that if data is sent immediately following receipt of a CONNECT ACK message, data loss is possible, since the connection may not have been established all the way between sender and receiver.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept)

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)