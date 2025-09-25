# recv function

## Description

The
**recv** function receives data from a connected socket or a bound connectionless socket.

## Parameters

### `s` [in]

The descriptor that identifies a connected socket.

### `buf` [out]

A pointer to the buffer to receive the incoming data.

### `len` [in]

The length, in bytes, of the buffer pointed to by the *buf* parameter.

### `flags` [in]

A set of flags that influences the behavior of this function. See remarks below. See the Remarks section for details on the possible value for this parameter.

## Return value

If no error occurs,
**recv** returns the number of bytes received and the buffer pointed to by the *buf* parameter will contain this data received. If the connection has been gracefully closed, the return value is zero.

 Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *buf* parameter is not completely contained in a valid part of the user address space. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The (blocking) call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a connection-oriented socket, this error indicates that the connection has been broken due to *keep-alive* activity that detected a failure while the operation was in progress. For a datagram socket, this error indicates that the time to live has expired. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only send operations. |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has been shut down; it is not possible to receive on a socket after [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) has been invoked with **how** set to SD_RECEIVE or SD_BOTH. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is marked as nonblocking and the receive operation would block. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The message was too large to fit into the specified buffer and was truncated. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), or an unknown flag was specified, or MSG_OOB was specified for a socket with SO_OOBINLINE enabled or (for byte stream sockets only) *len* was zero or negative. |
| **[WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has been dropped because of a network failure or because the peer system failed to respond. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was reset by the remote side executing a hard or abortive close. The application should close the socket as it is no longer usable. On a UDP-datagram socket, this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |

## Remarks

The
**recv** function is used to read incoming data on connection-oriented sockets, or connectionless sockets. When using a connection-oriented protocol, the sockets must be connected before calling
**recv**. When using a connectionless protocol, the sockets must be bound before calling
**recv**.

The local address of the socket must be known. For server applications, use an explicit
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function or an implicit
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) or
[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept) function. Explicit binding is discouraged for client applications. For client applications, the socket can become bound implicitly to a local address using
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect),
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect),
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto),
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto), or
[WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf).

For connected or connectionless sockets, the
**recv** function restricts the addresses from which received messages are accepted. The function only returns messages from the remote address specified in the connection. Messages from other addresses are (silently) discarded.

For connection-oriented sockets (type SOCK_STREAM for example), calling
**recv** will return as much data as is currently available—up to the size of the buffer specified. If the socket has been configured for in-line reception of OOB data (socket option SO_OOBINLINE) and OOB data is yet unread, only OOB data will be returned. The application can use the
[ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket) or
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)**SIOCATMARK** command to determine whether any more OOB data remains to be read.

For connectionless sockets (type SOCK_DGRAM or other message-oriented sockets), data is extracted from the first enqueued datagram (message) from the destination address specified by the
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) function.

If the datagram or message is larger than the buffer specified, the buffer is filled with the first part of the datagram, and
**recv** generates the error
[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). For unreliable protocols (for example, UDP) the excess data is lost; for reliable protocols, the data is retained by the service provider until it is successfully read by calling
**recv** with a large enough buffer.

If no incoming data is available at the socket, the
**recv** call blocks and waits for data to arrive according to the blocking rules defined for
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) with the MSG_PARTIAL flag not set unless the socket is nonblocking. In this case, a value of SOCKET_ERROR is returned with the error code set to
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). The
[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select),
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect), or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) functions can be used to determine when more data arrives.

If the socket is connection oriented and the remote side has shut down the connection gracefully, and all data has been received, a
**recv** will complete immediately with zero bytes received. If the connection has been reset, a
**recv** will fail with the error
[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

The *flags* parameter can be used to influence the behavior of the function invocation beyond the options specified for the associated socket. The semantics of this function are determined by the socket options and the *flags* parameter. The possible value of *flags* parameter is constructed by using the bitwise OR operator with any of the following values.

| Value | Meaning |
| --- | --- |
| MSG_PEEK | Peeks at the incoming data. The data is copied into the buffer, but is not removed from the input queue. |
| MSG_OOB | Processes Out Of Band (OOB) data. |
| MSG_WAITALL | The receive request will complete only when one of the following events occurs:<br><br>* The buffer supplied by the caller is completely full.<br>* The connection has been closed.<br>* The request has been canceled or an error occurred.<br><br>Note that if the underlying transport does not support MSG_WAITALL, or if the socket is in a non-blocking mode, then this call will fail with **WSAEOPNOTSUPP**. Also, if MSG_WAITALL is specified along with MSG_OOB, MSG_PEEK, or MSG_PARTIAL, then this call will fail with **WSAEOPNOTSUPP**. This flag is not supported on datagram sockets or message-oriented sockets. |

**Note** When issuing a blocking Winsock call such as **recv**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Example Code

The following code example shows the use of the **recv** function.

```cpp
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

int __cdecl main() {

    //----------------------
    // Declare and initialize variables.
    WSADATA wsaData;
    int iResult;

    SOCKET ConnectSocket = INVALID_SOCKET;
    struct sockaddr_in clientService;

    char *sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    //----------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != NO_ERROR) {
      printf("WSAStartup failed: %d\n", iResult);
      return 1;
    }

    //----------------------
    // Create a SOCKET for connecting to server
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("Error at socket(): %ld\n", WSAGetLastError() );
        WSACleanup();
        return 1;
    }

    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port of the server to be connected to.
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    clientService.sin_port = htons( 27015 );

    //----------------------
    // Connect to server.
    iResult = connect( ConnectSocket, (SOCKADDR*) &clientService, sizeof(clientService) );
    if ( iResult == SOCKET_ERROR) {
        closesocket (ConnectSocket);
        printf("Unable to connect to server: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Send an initial buffer
    iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
    if (iResult == SOCKET_ERROR) {
        printf("send failed: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    printf("Bytes Sent: %ld\n", iResult);

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 )
            printf("Bytes received: %d\n", iResult);
        else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed: %d\n", WSAGetLastError());

    } while( iResult > 0 );

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}

```

### Example Code

For more information, and another example of the **recv** function, see [Getting Started With Winsock](https://learn.microsoft.com/windows/desktop/WinSock/getting-started-with-winsock).

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[WSARecvEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-wsarecvex)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)