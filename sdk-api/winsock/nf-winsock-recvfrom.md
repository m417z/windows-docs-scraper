# recvfrom function

## Description

The
**recvfrom** function receives a datagram and stores the source address.

## Parameters

### `s` [in]

A descriptor identifying a bound socket.

### `buf` [out]

A buffer for the incoming data.

### `len` [in]

The length, in bytes, of the buffer pointed to by the *buf* parameter.

### `flags` [in]

A set of options that modify the behavior of the function call beyond the options specified for the associated socket. See the Remarks below for more details.

### `from` [out]

An optional pointer to a buffer in a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that will hold the source address upon return.

### `fromlen` [in, out, optional]

An optional pointer to the size, in bytes, of the buffer pointed to by the *from* parameter.

## Return value

If no error occurs,
**recvfrom** returns the number of bytes received. If the connection has been gracefully closed, the return value is zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The buffer pointed to by the *buf* or *from* parameters are not in the user address space, or the *fromlen* parameter is too small to accommodate the source address of the peer address. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The (blocking) call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), or an unknown flag was specified, or MSG_OOB was specified for a socket with SO_OOBINLINE enabled, or (for byte stream-style sockets only) *len* was zero or negative. |
| **[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is connected. This function is not permitted with a connected socket, whether the socket is connection oriented or connectionless. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a datagram socket, this error indicates that the time to live has expired. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor in the *s* parameter is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only send operations. |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has been shut down; it is not possible to [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom) on a socket after [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) has been invoked with *how* set to SD_RECEIVE or SD_BOTH. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is marked as nonblocking and the [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom) operation would block. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The message was too large to fit into the buffer pointed to by the *buf* parameter and was truncated. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has been dropped, because of a network failure or because the system on the other end went down without notice. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was reset by the remote side executing a hard or abortive close. The application should close the socket; it is no longer usable. On a UDP-datagram socket this error indicates a previous send operation resulted in an ICMP *Port Unreachable* message. |

## Remarks

The
**recvfrom** function reads incoming data on both connected and unconnected sockets and captures the address from which the data was sent. This function is typically used with connectionless sockets. The local address of the socket must be known. For server applications, this is usually done explicitly through
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind). Explicit binding is discouraged for client applications. For client applications using this function, the socket can become bound implicitly to a local address through
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto),
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto), or
[WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf).

For stream-oriented sockets such as those of type SOCK_STREAM, a call to
**recvfrom** returns as much information as is currently available—up to the size of the buffer specified. If the socket has been configured for inline reception of OOB data (socket option SO_OOBINLINE) and OOB data is yet unread, only OOB data will be returned. The application can use the
[ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket) or
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)**SIOCATMARK** command to determine whether any more OOB data remains to be read. The *from* and *fromlen* parameters are ignored for connection-oriented sockets.

For message-oriented sockets, data is extracted from the first enqueued message, up to the size of the buffer specified. If the datagram or message is larger than the buffer specified, the buffer is filled with the first part of the datagram, and
**recvfrom** generates the error
[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). For unreliable protocols (for example, UDP) the excess data is lost. For UDP if the packet received contains no data (empty), the return value from the **recvfrom** function function is zero.

If the *from* parameter is nonzero and the socket is not connection oriented, (type SOCK_DGRAM for example), the network address of the peer that sent the data is copied to the corresponding
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. The value pointed to by *fromlen* is initialized to the size of this structure and is modified, on return, to indicate the actual size of the address stored in the **sockaddr** structure.

If no incoming data is available at the socket, the
**recvfrom** function blocks and waits for data to arrive according to the blocking rules defined for
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) with the MSG_PARTIAL flag not set unless the socket is nonblocking. In this case, a value of SOCKET_ERROR is returned with the error code set to
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). The
[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select),
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect), or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) can be used to determine when more data arrives.

If the socket is connection oriented and the remote side has shut down the connection gracefully, the call to
**recvfrom** will complete immediately with zero bytes received. If the connection has been reset
**recvfrom** will fail with the error
[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

The *flags* parameter can be used to influence the behavior of the function invocation beyond the options specified for the associated socket. The semantics of this function are determined by the socket options and the *flags* parameter. The latter is constructed by using the bitwise OR operator with any of the following values.

| Value | Meaning |
| --- | --- |
| MSG_PEEK | Peeks at the incoming data. The data is copied into the buffer but is not removed from the input queue. |
| MSG_OOB | Processes Out Of Band (OOB) data. |

**Note** When issuing a blocking Winsock call such as **recvfrom**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Example Code

The following example demonstrates the use of the **recvfrom** function.

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

int main()
{

    int iResult = 0;

    WSADATA wsaData;

    SOCKET RecvSocket;
    struct sockaddr_in RecvAddr;

    unsigned short Port = 27015;

    char RecvBuf[1024];
    int BufLen = 1024;

    struct sockaddr_in SenderAddr;
    int SenderAddrSize = sizeof (SenderAddr);

    //-----------------------------------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error %d\n", iResult);
        return 1;
    }
    //-----------------------------------------------
    // Create a receiver socket to receive datagrams
    RecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (RecvSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error %d\n", WSAGetLastError());
        return 1;
    }
    //-----------------------------------------------
    // Bind the socket to any address and the specified port.
    RecvAddr.sin_family = AF_INET;
    RecvAddr.sin_port = htons(Port);
    RecvAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    iResult = bind(RecvSocket, (SOCKADDR *) & RecvAddr, sizeof (RecvAddr));
    if (iResult != 0) {
        wprintf(L"bind failed with error %d\n", WSAGetLastError());
        return 1;
    }
    //-----------------------------------------------
    // Call the recvfrom function to receive datagrams
    // on the bound socket.
    wprintf(L"Receiving datagrams...\n");
    iResult = recvfrom(RecvSocket,
                       RecvBuf, BufLen, 0, (SOCKADDR *) & SenderAddr, &SenderAddrSize);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"recvfrom failed with error %d\n", WSAGetLastError());
    }

    //-----------------------------------------------
    // Close the socket when finished receiving datagrams
    wprintf(L"Finished receiving. Closing socket.\n");
    iResult = closesocket(RecvSocket);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"closesocket failed with error %d\n", WSAGetLastError());
        return 1;
    }

    //-----------------------------------------------
    // Clean up and exit.
    wprintf(L"Exiting.\n");
    WSACleanup();
    return 0;
}

```

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)