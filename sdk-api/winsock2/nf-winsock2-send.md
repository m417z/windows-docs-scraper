# send function

## Description

The
**send** function sends data on a connected socket.

## Parameters

### `s` [in]

A descriptor identifying a connected socket.

### `buf` [in]

A pointer to a buffer containing the data to be transmitted.

### `len` [in]

The length, in bytes, of the data in buffer pointed to by the *buf* parameter.

### `flags` [in]

A set of flags that specify the way in which the call is made. This parameter is constructed by using the bitwise OR operator with any of the following values.

| Value | Meaning |
| --- | --- |
| **MSG_DONTROUTE** | Specifies that the data should not be subject to routing. A Windows Sockets service provider can choose to ignore this flag. |
| **MSG_OOB** | Sends OOB data (stream-style socket such as SOCK_STREAM only). |

## Return value

If no error occurs,
**send** returns the total number of bytes sent, which can be less than the number requested to be sent in the *len* parameter. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested address is a broadcast address, but the appropriate flag was not set. Call [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) with the SO_BROADCAST socket option to enable use of the broadcast address. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *buf* parameter is not completely contained in a valid part of the user address space. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has been broken due to the keep-alive activity detecting a failure while the operation was in progress. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only receive operations. |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has been shut down; it is not possible to send on a socket after [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) has been invoked with *how* set to SD_SEND or SD_BOTH. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is marked as nonblocking and the requested operation would block. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is message oriented, and the message is larger than the maximum supported by the underlying transport. |
| **[WSAEHOSTUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The remote host cannot be reached from this host at this time. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), or an unknown flag was specified, or MSG_OOB was specified for a socket with SO_OOBINLINE enabled. |
| **[WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was reset by the remote side executing a hard or abortive close. For UDP sockets, the remote host was unable to deliver a previously sent UDP datagram and responded with a "Port Unreachable" ICMP packet. The application should close the socket as it is no longer usable. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has been dropped, because of a network failure or because the system on the other end went down without notice. |

## Remarks

The
**send** function is used to write outgoing data on a connected socket.

For message-oriented sockets (address family of **AF_INET** or **AF_INET6**, type of **SOCK_DGRAM**, and protocol of **IPPROTO_UDP**, for example), care must be taken not to exceed the maximum packet size of the underlying provider. The maximum message packet size for a provider can be obtained by calling [getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) with the *optname* parameter set to **SO_MAX_MSG_SIZE** to retrieve the value of socket option. If the data is too long to pass atomically through the underlying protocol, the error
[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned, and no data is transmitted.

The successful completion of a
**send** function does not indicate that the data was successfully delivered and received to the recipient. This function only indicates the data was successfully sent.

If no buffer space is available within the transport system to hold the data to be transmitted,
**send** will block unless the socket has been placed in nonblocking mode. On nonblocking stream oriented sockets, the number of bytes written can be between 1 and the requested length, depending on buffer availability on both the client and server computers. The
[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select),
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) functions can be used to determine when it is possible to send more data.

Calling
**send** with a *len* parameter of zero is permissible and will be treated by implementations as successful. In such cases,
**send** will return zero as a valid value. For message-oriented sockets, a zero-length transport datagram is sent.

The *flags* parameter can be used to influence the behavior of the function beyond the options specified for the associated socket. The semantics of the **send** function are determined by any options previously set on the socket specified in the *s* parameter and the *flags* parameter passed to the **send** function.

The order of calls made to **send** is also the order in which the buffers are transmitted to the transport layer. **send** should not be called on the same stream-oriented socket concurrently from different threads, because some Winsock providers may split a large send request into multiple transmissions, and this may lead to unintended data interleaving from multiple concurrent send requests on the same stream-oriented socket.

**Note** When issuing a blocking Winsock call such as **send**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Example Code

The following example demonstrates the use of the **send** function.

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

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT 27015

int main() {

    //----------------------
    // Declare and initialize variables.
    int iResult;
    WSADATA wsaData;

    SOCKET ConnectSocket = INVALID_SOCKET;
    struct sockaddr_in clientService;

    int recvbuflen = DEFAULT_BUFLEN;
    char *sendbuf = "Client: sending data test";
    char recvbuf[DEFAULT_BUFLEN] = "";

    //----------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    //----------------------
    // Create a SOCKET for connecting to server
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port of the server to be connected to.
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    clientService.sin_port = htons( DEFAULT_PORT );

    //----------------------
    // Connect to server.
    iResult = connect( ConnectSocket, (SOCKADDR*) &clientService, sizeof(clientService) );
    if (iResult == SOCKET_ERROR) {
        wprintf(L"connect failed with error: %d\n", WSAGetLastError() );
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
  }

    //----------------------
    // Send an initial buffer
    iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
    if (iResult == SOCKET_ERROR) {
        wprintf(L"send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    printf("Bytes Sent: %d\n", iResult);

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 )
            wprintf(L"Bytes received: %d\n", iResult);
        else if ( iResult == 0 )
            wprintf(L"Connection closed\n");
        else
            wprintf(L"recv failed with error: %d\n", WSAGetLastError());

    } while( iResult > 0 );

    // close the socket
    iResult = closesocket(ConnectSocket);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"close failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    WSACleanup();
    return 0;
}

```

### Example Code

For a another example that uses the **send** function, see [Getting Started With Winsock](https://learn.microsoft.com/windows/desktop/WinSock/getting-started-with-winsock).

### Notes for IrDA Sockets

* The Af_irda.h header file must be explicitly included.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[Getting Started With Winsock](https://learn.microsoft.com/windows/desktop/WinSock/getting-started-with-winsock)

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)

[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)