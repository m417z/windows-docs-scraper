# WSASendTo function

## Description

The
**WSASendTo** function sends data to a specific destination, using overlapped I/O where applicable.

## Parameters

### `s` [in]

A descriptor identifying a (possibly connected) socket.

### `lpBuffers` [in]

A pointer to an array of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures. Each
**WSABUF** structure contains a pointer to a buffer and the length of the buffer, in bytes. For a Winsock application, once the
**WSASendTo** function is called, the system owns these buffers and the application may not access them. This array must remain valid for the duration of the send operation.

### `dwBufferCount` [in]

The number of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures in the *lpBuffers* array.

### `lpNumberOfBytesSent` [out]

A pointer to the number of bytes sent by this call if the I/O operation completes immediately.

Use **NULL** for this parameter if the *lpOverlapped* parameter is not **NULL** to avoid potentially erroneous results. This parameter can be **NULL** only if the *lpOverlapped* parameter is not **NULL**.

### `dwFlags` [in]

The flags used to modify the behavior of the
**WSASendTo** function call.

### `lpTo` [in]

An optional pointer to the address of the target socket in the
[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `iTolen` [in]

The size, in bytes, of the address in the *lpTo* parameter.

### `lpOverlapped` [in]

A pointer to a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure (ignored for nonoverlapped sockets).

### `lpCompletionRoutine` [in]

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

A pointer to the completion routine called when the send operation has been completed (ignored for nonoverlapped sockets).

## Return value

If no error occurs and the send operation has completed immediately,
**WSASendTo** returns zero. In this case, the completion routine will have already been scheduled to be called once the calling thread is in the alertable state. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror). The error code [WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) indicates that the overlapped operation has been successfully initiated and that completion will be indicated at a later time. Any other error code indicates that the overlapped operation was not successfully initiated and no completion indication will occur.

| Error code | Meaning |
| --- | --- |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested address is a broadcast address, but the appropriate flag was not set. |
| **[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The remote address is not a valid address (such as ADDR_ANY). |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Addresses in the specified family cannot be used with this socket. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a UDP datagram socket, this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |
| **[WSAEDESTADDRREQ](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A destination address is required. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpBuffers*, *lpTo*, *lpOverlapped*, *lpNumberOfBytesSent*, or *lpCompletionRoutine* parameters are not part of the user address space, or the *lpTo* parameter is too small. |
| **[WSAEHOSTUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A socket operation was attempted to an unreachable host. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), or the socket is not created with the overlapped flag. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is message oriented, and the message is larger than the maximum supported by the underlying transport. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a datagram socket, this error indicates that the time to live has expired. |
| **[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network cannot be reached from this host at this time. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The Windows Sockets provider reports a buffer deadlock. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected (connection-oriented sockets only). |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has been shut down; it is not possible to [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) on a socket after [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) has been invoked with *how* set to SD_SEND or SD_BOTH. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **Windows NT:** <br><br>Overlapped sockets: there are too many outstanding overlapped I/O requests. Nonoverlapped sockets: The socket is marked as nonblocking and the send operation cannot be completed immediately. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An overlapped operation was successfully initiated and completion will be indicated at a later time. |
| **[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The overlapped operation has been canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl). |

## Remarks

The
**WSASendTo** function provides enhanced features over the standard
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) function in two important areas:

* It can be used in conjunction with overlapped sockets to perform overlapped send operations.
* It allows multiple send buffers to be specified making it applicable to the scatter/gather type of I/O.

The
**WSASendTo** function is normally used on a connectionless socket specified by *s* to send a datagram contained in one or more buffers to a specific peer socket identified by the *lpTo* parameter. Even if the connectionless socket has been previously connected using the
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) function to a specific address, *lpTo* overrides the destination address for that particular datagram only. On a connection-oriented socket, the *lpTo* and *iToLen* parameters are ignored; in this case, the
**WSASendTo** is equivalent to
[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend).

For overlapped sockets (created using
[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) with flag **WSA_FLAG_OVERLAPPED**) sending data uses overlapped I/O, unless both *lpOverlapped* and *lpCompletionRoutine* are **NULL** in which case the socket is treated as a nonoverlapped socket. A completion indication will occur (invoking the completion routine or setting of an event object) when the buffer(s) have been consumed by the transport. If the operation does not complete immediately, the final completion status is retrieved through the completion routine or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult).

**Note** If a socket is opened, a
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) call is made, and then a
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) call is made, Windows Sockets performs an implicit
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function call.

If both *lpOverlapped* and *lpCompletionRoutine* are **NULL**, the socket in this function will be treated as a nonoverlapped socket.

For nonoverlapped sockets, the last two parameters (*lpOverlapped*, *lpCompletionRoutine*) are ignored and
**WSASendTo** adopts the same blocking semantics as
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send). Data is copied from the buffer(s) into the transport buffer. If the socket is nonblocking and stream oriented, and there is not sufficient space in the transport's buffer,
**WSASendTo** returns with only part of the application's buffers having been consumed. Given the same buffer situation and a blocking socket,
**WSASendTo** will block until all of the application's buffer contents have been consumed.

If this function is completed in an overlapped manner, it is the Winsock service provider's responsibility to capture the
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures before returning from this call. This enables applications to build stack-based
**WSABUF** arrays pointed to by the *lpBuffers* parameter.

For message-oriented sockets, care must be taken not to exceed the maximum message size of the underlying transport, which can be obtained by getting the value of socket option **SO_MAX_MSG_SIZE**. If the data is too long to pass atomically through the underlying protocol the error
[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned, and no data is transmitted.

If the socket is unbound, unique values are assigned to the local association by the system, and the socket is then marked as bound.

If the socket is connected, the [getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname) function can be used to determine the local IP address and port associated with the socket.

If the socket is not connected, the
[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname) function can be used to determine the local port number associated with the socket but the IP address returned is set to the wildcard address for the given protocol (for example, INADDR_ANY or "0.0.0.0" for IPv4 and IN6ADDR_ANY_INIT or "::" for IPv6).

The successful completion of a
**WSASendTo** does not indicate that the data was successfully delivered.

The *dwFlags* parameter can be used to influence the behavior of the function invocation beyond the options specified for the associated socket. That is, the semantics of this function are determined by the socket options and the *dwFlags* parameter. The latter is constructed by using the bitwise OR operator with any of any of the values listed in the following table.

| Value | Meaning |
| --- | --- |
| **MSG_DONTROUTE** | Specifies that the data should not be subject to routing. A Windows Socket service provider may choose to ignore this flag. |
| **MSG_OOB** | Send OOB data (stream-style socket such as **SOCK_STREAM** only). |
| **MSG_PARTIAL** | Specifies that *lpBuffers* only contains a partial message. Be aware that the error code [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) will be returned by transports that do not support partial message transmissions. |

**Note** When issuing a blocking Winsock call such as **WSASendTo** with the *lpOverlapped* parameter set to **NULL**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Overlapped Socket I/O

If an overlapped operation completes immediately,
**WSASendTo** returns a value of zero and the *lpNumberOfBytesSent* parameter is updated with the number of bytes sent. If the overlapped operation is successfully initiated and will complete later,
**WSASendTo** returns **SOCKET_ERROR** and indicates error code
[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). In this case, *lpNumberOfBytesSent* is not updated. When the overlapped operation completes the amount of data transferred is indicated either through the *cbTransferred* parameter in the completion routine (if specified), or through the *lpcbTransfer* parameter in
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult).

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

The
**WSASendTo** function using overlapped I/O can be called from within the completion routine of a previous
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv),
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom),
[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend), or
**WSASendTo** function. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

The *lpOverlapped* parameter must be valid for the duration of the overlapped operation. If multiple I/O operations are simultaneously outstanding, each must reference a separate
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure.

If the *lpCompletionRoutine* parameter is **NULL**, the *hEvent* parameter of *lpOverlapped* is signaled when the overlapped operation completes if it contains a valid event object handle. An application can use
[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents) or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) to wait or poll on the event object.

If *lpCompletionRoutine* is not **NULL**, the *hEvent* parameter is ignored and can be used by the application to pass context information to the completion routine. A caller that passes a non-**NULL***lpCompletionRoutine* and later calls
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) for the same overlapped I/O request may not set the *fWait* parameter for that invocation of
**WSAGetOverlappedResult** to **TRUE**. In this case the usage of the *hEvent* parameter is undefined, and attempting to wait on the *hEvent* parameter would produce unpredictable results.

The completion routine follows the same rules as stipulated for Windows file I/O completion routines. The completion routine will not be invoked until the thread is in an alertable wait state such as can occur when the function
[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents) with the *fAlertable* parameter set to **TRUE** is invoked.

Transport providers allow an application to invoke send and receive operations from within the context of the socket I/O completion routine, and guarantee that, for a given socket, I/O completion routines will not be nested. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

The prototype of the completion routine is as follows.

```cpp

void CALLBACK CompletionROUTINE(
  IN DWORD dwError,
  IN DWORD cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD dwFlags
);

```

The CompletionRoutine function is a placeholder for an application-defined or library-defined function name. The *dwError* parameter specifies the completion status for the overlapped operation as indicated by *lpOverlapped*. The *cbTransferred* parameter specifies the number of bytes sent. Currently there are no flag values defined and *dwFlags* will be zero. This function does not return a value.

Returning from this function allows invocation of another pending completion routine for this socket. All waiting completion routines are called before the alertable thread's wait is satisfied with a return code of WSA_IO_COMPLETION. The completion routines can be called in any order, not necessarily in the same order in which the overlapped operations are completed. However, the posted buffers are guaranteed to be sent in the same order they are specified.

### Example Code

The following example demonstrates the use of the **WSASendTo** function using an event object.

```cpp
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int __cdecl main(int argc, char **argv)
{

    //---------------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    WSABUF DataBuf;

    WSAOVERLAPPED Overlapped;
    SOCKET SendToSocket = INVALID_SOCKET;

    struct sockaddr_in RecvAddr;
    struct sockaddr_in LocalAddr;
    int RecvAddrSize = sizeof (RecvAddr);
    int LocalAddrSize = sizeof (LocalAddr);

    u_short Port = 27777;
    struct hostent *localHost;
    char *ip;

    char *targetip;
    char *targetport;

    char SendBuf[1024] = "Data buffer to send";
    int BufLen = 1024;
    DWORD BytesSent = 0;
    DWORD Flags = 0;

    int rc, err;
    int retval = 0;

    // Validate the parameters
    if (argc != 3) {
        printf("usage: %s targetip port\n", argv[0]);
        printf("  to sendto the localhost on port 27777\n");
        printf("       %s 127.0.0.1 27777\n", argv[0]);
        return 1;
    }

    targetip = argv[1];
    targetport = argv[2];

    //---------------------------------------------
    // Initialize Winsock
    // Load Winsock
    rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (rc != 0) {
        printf("Unable to load Winsock: %d\n", rc);
        return 1;
    }

    // Make sure the Overlapped struct is zeroed out
    SecureZeroMemory((PVOID) &Overlapped, sizeof(WSAOVERLAPPED));

    // Create an event handle and setup the overlapped structure.
    Overlapped.hEvent = WSACreateEvent();
    if (Overlapped.hEvent == WSA_INVALID_EVENT) {
        printf("WSACreateEvent failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //---------------------------------------------
    // Create a socket for sending data
    SendToSocket =
        WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0,
                  WSA_FLAG_OVERLAPPED);
    if (SendToSocket == INVALID_SOCKET) {
        printf("socket failed with error: %d\n", WSAGetLastError());
        WSACloseEvent(Overlapped.hEvent);
        WSACleanup();
        return 1;
    }
    //---------------------------------------------
    // Set up the RecvAddr structure with the IP address of
    // the receiver (in this example case "123.123.123.1")
    // and the specified port number.
    RecvAddr.sin_family = AF_INET;

    RecvAddr.sin_addr.s_addr = inet_addr(targetip);
    if (RecvAddr.sin_addr.s_addr == INADDR_NONE)  {
        printf("The target ip address entered must be a legal IPv4 address\n");
        WSACloseEvent(Overlapped.hEvent);
        WSACleanup();
        return 1;
    }
    RecvAddr.sin_port = htons( (u_short) atoi(targetport));
    if(RecvAddr.sin_port == 0) {
        printf("The targetport must be a legal UDP port number\n");
        WSACloseEvent(Overlapped.hEvent);
        WSACleanup();
        return 1;
    }

    //---------------------------------------------
    // Set up the LocalAddr structure with the local IP address
    // and the specified port number.
    localHost = gethostbyname("");
    ip = inet_ntoa(*(struct in_addr *) *localHost->h_addr_list);

    LocalAddr.sin_family = AF_INET;
    LocalAddr.sin_addr.s_addr = inet_addr(ip);
    LocalAddr.sin_port = htons(Port);

    //---------------------------------------------
    // Bind the sending socket to the LocalAddr structure
    // that has the internet address family, local IP address
    // and specified port number.
    rc = bind(SendToSocket, (struct sockaddr *) &LocalAddr, LocalAddrSize);
    if (rc == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        WSACloseEvent(Overlapped.hEvent);
        closesocket(SendToSocket);
        WSACleanup();
        return 1;
    }
    //---------------------------------------------
    // Send a datagram to the receiver
    printf("Sending datagram from IPv4 address = %s port=%d\n",
       inet_ntoa(LocalAddr.sin_addr), ntohs(LocalAddr.sin_port) );
    printf("   to IPv4 address = %s port=%d\n",
       inet_ntoa(RecvAddr.sin_addr), ntohs(RecvAddr.sin_port) );

//    printf("Sending a datagram...\n");
    DataBuf.len = BufLen;
    DataBuf.buf = SendBuf;
    rc = WSASendTo(SendToSocket, &DataBuf, 1,
                   &BytesSent, Flags, (SOCKADDR *) & RecvAddr,
                   RecvAddrSize, &Overlapped, NULL);

    if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError()))) {
        printf("WSASendTo failed with error: %d\n", err);
        WSACloseEvent(Overlapped.hEvent);
        closesocket(SendToSocket);
        WSACleanup();
        return 1;
    }

    rc = WSAWaitForMultipleEvents(1, &Overlapped.hEvent, TRUE, INFINITE, TRUE);
    if (rc == WSA_WAIT_FAILED) {
        printf("WSAWaitForMultipleEvents failed with error: %d\n",
                WSAGetLastError());
        retval = 1;
    }

    rc = WSAGetOverlappedResult(SendToSocket, &Overlapped, &BytesSent,
                                FALSE, &Flags);
    if (rc == FALSE) {
        printf("WSASendTo failed with error: %d\n", WSAGetLastError());
        retval = 1;
    }
    else
        printf("Number of sent bytes = %d\n", BytesSent);

    //---------------------------------------------
    // When the application is finished sending, close the socket.
    printf("Finished sending. Closing socket.\n");
    WSACloseEvent(Overlapped.hEvent);
    closesocket(SendToSocket);
    printf("Exiting.\n");

    //---------------------------------------------
    // Clean up and quit.
    WSACleanup();
    return (retval);
}

```

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSACloseEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacloseevent)

[WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent)

[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)