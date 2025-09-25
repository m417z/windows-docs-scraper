# AcceptEx function

## Description

The
**AcceptEx** function accepts a new connection, returns the local and remote address, and receives the first block of data sent by the client application.

**Note** This function is a Microsoft-specific extension to the Windows Sockets specification.

## Parameters

### `sListenSocket` [in]

A descriptor identifying a socket that has already been called with the
[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) function. A server application waits for attempts to connect on this socket.

### `sAcceptSocket` [in]

A descriptor identifying a socket on which to accept an incoming connection. This socket must not be bound or connected.

### `lpOutputBuffer` [in]

A pointer to a buffer that receives the first block of data sent on a new connection, the local address of the server, and the remote address of the client. The receive data is written to the first part of the buffer starting at offset zero, while the addresses are written to the latter part of the buffer. This parameter must be specified.

### `dwReceiveDataLength` [in]

The number of bytes in *lpOutputBuffer* that will be used for actual receive data at the beginning of the buffer. This size should not include the size of the local address of the server, nor the remote address of the client; they are appended to the output buffer. If *dwReceiveDataLength* is zero, accepting the connection will not result in a receive operation. Instead,
**AcceptEx** completes as soon as a connection arrives, without waiting for any data.

### `dwLocalAddressLength` [in]

The number of bytes reserved for the local address information. This value must be at least 16 bytes more than the maximum address length for the transport protocol in use.

### `dwRemoteAddressLength` [in]

The number of bytes reserved for the remote address information. This value must be at least 16 bytes more than the maximum address length for the transport protocol in use. Cannot be zero.

### `lpdwBytesReceived` [out]

A pointer to a **DWORD** that receives the count of bytes received. This parameter is set only if the operation completes synchronously. If it returns ERROR_IO_PENDING and is completed later, then this **DWORD** is never set and you must obtain the number of bytes read from the completion notification mechanism.

### `lpOverlapped` [in]

An
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that is used to process the request. This parameter must be specified; it cannot be **NULL**.

## Return value

If no error occurs, the
**AcceptEx** function completed successfully and a value of **TRUE** is returned.

If the function fails,
**AcceptEx** returns **FALSE**. The
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function can then be called to return extended error information. If
**WSAGetLastError** returns **ERROR_IO_PENDING**, then the operation was successfully initiated and is still in progress. If the error is WSAECONNRESET, an incoming connection was indicated, but was subsequently terminated by the remote peer prior to accepting the call.

## Remarks

The
**AcceptEx** function combines several socket functions into a single API/kernel transition. The
**AcceptEx** function, when successful, performs three tasks:

* A new connection is accepted.
* Both the local and remote addresses for the connection are returned.
* The first block of data sent by the remote is received.

**Note** The function pointer for the
**AcceptEx** function must be obtained at run time by making a call to the
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO_GET_EXTENSION_FUNCTION_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID_ACCEPTEX**, a globally unique identifier (GUID) whose value identifies the **AcceptEx** extension function. On success, the output returned by the **WSAIoctl** function contains a pointer to the **AcceptEx** function. The **WSAID_ACCEPTEX** GUID is defined in the *Mswsock.h* header file.

A program can make a connection to a socket more quickly using
**AcceptEx** instead of the
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) function.

A single output buffer receives the data, the local socket address (the server), and the remote socket address (the client).

Using a single buffer improves performance. When using
**AcceptEx**, the
[GetAcceptExSockaddrs](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-getacceptexsockaddrs) function must be called to parse the buffer into its three distinct parts (data, local socket address, and remote socket address). On Windows XP and later, once the
**AcceptEx** function completes and the **SO_UPDATE_ACCEPT_CONTEXT** option is set on the accepted socket, the local address associated with the accepted socket can also be retrieved using the
[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname) function. Likewise, the remote address associated with the accepted socket can be retrieved using the
[getpeername](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getpeername) function.

The buffer size for the local and remote address must be 16 bytes more than the size of the
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure for the transport protocol in use because the addresses are written in an internal format. For example, the size of a **sockaddr_in** (the address structure for TCP/IP) is 16 bytes. Therefore, a buffer size of at least 32 bytes must be specified for the local and remote addresses.

The
**AcceptEx** function uses overlapped I/O, unlike the
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) function. If your application uses
**AcceptEx**, it can service a large number of clients with a relatively small number of threads. As with all overlapped Windows functions, either Windows events or completion ports can be used as a completion notification mechanism.

Another key difference between the
**AcceptEx** function and the
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) function is that
**AcceptEx** requires the caller to already have two sockets:

* One that specifies the socket on which to listen.
* One that specifies the socket on which to accept the connection.

The *sAcceptSocket* parameter must be an open socket that is neither bound nor connected.

The *lpNumberOfBytesTransferred* parameter of the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function or the
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function indicates the number of bytes received in the request.

When this operation is successfully completed, *sAcceptSocket* can be passed, but to the following functions only:

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile)

[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)(only for SO_UPDATE_ACCEPT_CONTEXT)

**Note** If the
[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile) function is called with both the TF_DISCONNECT and TF_REUSE_SOCKET flags, the specified socket has been returned to a state in which it is neither bound nor connected. The socket handle can then be passed to the
**AcceptEx** function in the *sAcceptSocket* parameter, but the socket cannot be passed to the [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex) function.

When the
**AcceptEx** function returns, the socket *sAcceptSocket* is in the default state for a connected socket. The socket *sAcceptSocket* does not inherit the properties of the socket associated with *sListenSocket* parameter until SO_UPDATE_ACCEPT_CONTEXT is set on the socket. Use the
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function to set the SO_UPDATE_ACCEPT_CONTEXT option, specifying *sAcceptSocket* as the socket handle and *sListenSocket* as the option value.

For example:

```cpp
//Need to #include <mswsock.h> for SO_UPDATE_ACCEPT_CONTEXT

int iResult = 0;

iResult =  setsockopt( sAcceptSocket, SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT,
    (char *)&sListenSocket, sizeof(sListenSocket) );

```

If a receive buffer is provided, the overlapped operation will not complete until a connection is accepted and data is read. Use the
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function with the SO_CONNECT_TIME option to check whether a connection has been accepted. If it has been accepted, you can determine how long the connection has been established. The return value is the number of seconds that the socket has been connected. If the socket is not connected, the
**getsockopt** returns 0xFFFFFFFF. Applications that check whether the overlapped operation has completed, in combination with the SO_CONNECT_TIME option, can determine that a connection has been accepted but no data has been received. Scrutinizing a connection in this manner enables an application to determine whether connections that have been established for a while have received no data. It is recommended such connections be terminated by closing the accepted socket, which forces the
**AcceptEx** function call to complete with an error.

For example:

```cpp

INT seconds;
INT bytes = sizeof(seconds);
int iResult = 0;

iResult = getsockopt( sAcceptSocket, SOL_SOCKET, SO_CONNECT_TIME,
                      (char *)&seconds, (PINT)&bytes );

if ( iResult != NO_ERROR ) {
    printf( "getsockopt(SO_CONNECT_TIME) failed: %u\n", WSAGetLastError( ) );
    exit(1);
}

```

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

### Example Code

The following example uses the **AcceptEx** function using overlapped I/O and completion ports.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int main()
{
    //----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult = 0;
    BOOL bRetVal = FALSE;

    HANDLE hCompPort;
    HANDLE hCompPort2;

    LPFN_ACCEPTEX lpfnAcceptEx = NULL;
    GUID GuidAcceptEx = WSAID_ACCEPTEX;
    WSAOVERLAPPED olOverlap;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET AcceptSocket = INVALID_SOCKET;
    sockaddr_in service;
    char lpOutputBuf[1024];
    int outBufLen = 1024;
    DWORD dwBytes;

    hostent *thisHost;
    char *ip;
    u_short port;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"Error at WSAStartup\n");
        return 1;
    }

    // Create a handle for the completion port
    hCompPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, (u_long) 0, 0);
    if (hCompPort == NULL) {
        wprintf(L"CreateIoCompletionPort failed with error: %u\n",
            GetLastError() );
        WSACleanup();
        return 1;
    }

    // Create a listening socket
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"Create of ListenSocket socket failed with error: %u\n",
            WSAGetLastError() );
        WSACleanup();
        return 1;
    }

    // Associate the listening socket with the completion port
    CreateIoCompletionPort((HANDLE) ListenSocket, hCompPort, (u_long) 0, 0);

    //----------------------------------------
    // Bind the listening socket to the local IP address
    // and port 27015
    port = 27015;
    thisHost = gethostbyname("");
    ip = inet_ntoa(*(struct in_addr *) *thisHost->h_addr_list);

    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(ip);
    service.sin_port = htons(port);

    if (bind(ListenSocket, (SOCKADDR *) & service, sizeof (service)) == SOCKET_ERROR) {
        wprintf(L"bind failed with error: %u\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    //----------------------------------------
    // Start listening on the listening socket
    iResult = listen(ListenSocket, 100);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"listen failed with error: %u\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    wprintf(L"Listening on address: %s:%d\n", ip, port);

    // Load the AcceptEx function into memory using WSAIoctl.
    // The WSAIoctl function is an extension of the ioctlsocket()
    // function that can use overlapped I/O. The function's 3rd
    // through 6th parameters are input and output buffers where
    // we pass the pointer to our AcceptEx function. This is used
    // so that we can call the AcceptEx function directly, rather
    // than refer to the Mswsock.lib library.
    iResult = WSAIoctl(ListenSocket, SIO_GET_EXTENSION_FUNCTION_POINTER,
             &GuidAcceptEx, sizeof (GuidAcceptEx),
             &lpfnAcceptEx, sizeof (lpfnAcceptEx),
             &dwBytes, NULL, NULL);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"WSAIoctl failed with error: %u\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Create an accepting socket
    AcceptSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (AcceptSocket == INVALID_SOCKET) {
        wprintf(L"Create accept socket failed with error: %u\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Empty our overlapped structure and accept connections.
    memset(&olOverlap, 0, sizeof (olOverlap));

    bRetVal = lpfnAcceptEx(ListenSocket, AcceptSocket, lpOutputBuf,
                 outBufLen - ((sizeof (sockaddr_in) + 16) * 2),
                 sizeof (sockaddr_in) + 16, sizeof (sockaddr_in) + 16,
                 &dwBytes, &olOverlap);
    if (bRetVal == FALSE) {
        wprintf(L"AcceptEx failed with error: %u\n", WSAGetLastError());
        closesocket(AcceptSocket);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Associate the accept socket with the completion port
    hCompPort2 = CreateIoCompletionPort((HANDLE) AcceptSocket, hCompPort, (u_long) 0, 0);
    // hCompPort2 should be hCompPort if this succeeds
    if (hCompPort2 == NULL) {
        wprintf(L"CreateIoCompletionPort associate failed with error: %u\n",
            GetLastError() );
        closesocket(AcceptSocket);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Continue on to use send, recv, TransmitFile(), etc.,.
    //...

    return 0;
}

```

### Notes for QoS

The
[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile) function allows the setting of two flags, TF_DISCONNECT or TF_REUSE_SOCKET, that return the socket to a "disconnected, reusable" state after the file has been transmitted. These flags should not be used on a socket where quality of service has been requested, since the service provider may immediately delete any quality of service associated with the socket before the file transfer has completed. The best approach for a QoS-enabled socket is to simply call the
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) function when the file transfer has completed, rather than relying on these flags.

### Notes for ATM

There are important issues associated with connection setup when using Asynchronous Transfer Mode (ATM) with Windows Sockets 2. Please see the Remarks section in the
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) function documentation for important ATM connection setup information.

## See also

[GetAcceptExSockaddrs](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-getacceptexsockaddrs)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)