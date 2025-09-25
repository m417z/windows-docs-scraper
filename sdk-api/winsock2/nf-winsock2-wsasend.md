# WSASend function

## Description

The
**WSASend** function sends data on a connected socket.

## Parameters

### `s` [in]

A descriptor that identifies a connected socket.

### `lpBuffers` [in]

A pointer to an array of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures. Each
**WSABUF** structure contains a pointer to a buffer and the length, in bytes, of the buffer. For a Winsock application, once the
**WSASend** function is called, the system owns these buffers and the application may not access them. This array must remain valid for the duration of the send operation.

### `dwBufferCount` [in]

The number of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures in the *lpBuffers* array.

### `lpNumberOfBytesSent` [out]

A pointer to the number, in bytes, sent by this call if the I/O operation completes immediately.

Use **NULL** for this parameter if the *lpOverlapped* parameter is not **NULL** to avoid potentially erroneous results. This parameter can be **NULL** only if the *lpOverlapped* parameter is not **NULL**.

### `dwFlags` [in]

The flags used to modify the behavior of the
**WSASend** function call. For more information, see Using *dwFlags* in the Remarks section.

### `lpOverlapped` [in]

A pointer to a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure. This parameter is ignored for nonoverlapped sockets.

### `lpCompletionRoutine` [in]

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

A pointer to the completion routine called when the send operation has been completed. This parameter is ignored for nonoverlapped sockets.

## Return value

If no error occurs and the send operation has completed immediately,
**WSASend** returns zero. In this case, the completion routine will have already been scheduled to be called once the calling thread is in the alertable state. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror). The error code
[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) indicates that the overlapped operation has been successfully initiated and that completion will be indicated at a later time. Any other error code indicates that the overlapped operation was not successfully initiated and no completion indication will occur.

| Error code | Meaning |
| --- | --- |
| **[WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was terminated due to a time-out or other failure. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a stream socket, the virtual circuit was reset by the remote side. The application should close the socket as it is no longer usable. For a UDP datagram socket, this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpBuffers*, *lpNumberOfBytesSent*, *lpOverlapped*, *lpCompletionRoutine* parameter is not totally contained in a valid part of the user address space. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) or the socket is not created with the overlapped flag. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is message oriented, and the message is larger than the maximum supported by the underlying transport. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a stream socket, the connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. For a datagram socket, this error indicates that the time to live has expired. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The Windows Sockets provider reports a buffer deadlock. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **MSG_OOB** was specified, but the socket is not stream-style such as type **SOCK_STREAM**, OOB data is not supported in the communication domain associated with this socket, **MSG_PARTIAL** is not supported, or the socket is unidirectional and supports only receive operations. |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has been shut down; it is not possible to [WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend) on a socket after [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) has been invoked with how set to **SD_SEND** or **SD_BOTH**. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **Windows NT:** <br><br>Overlapped sockets: There are too many outstanding overlapped I/O requests. Nonoverlapped sockets: The socket is marked as nonblocking and the send operation cannot be completed immediately. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An overlapped operation was successfully initiated and completion will be indicated at a later time. |
| **[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The overlapped operation has been canceled due to the closure of the socket, the execution of the "SIO_FLUSH" command in [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl), or the thread that initiated the overlapped request exited before the operation completed. For more information, see the Remarks section. |

## Remarks

The
**WSASend** function provides functionality over and above the standard
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) function in two important areas:

* It can be used in conjunction with overlapped sockets to perform overlapped
  [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) operations.
* It allows multiple
  [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) buffers to be specified making it applicable to the scatter/gather type of I/O.

The
**WSASend** function is used to write outgoing data from one or more buffers on a connection-oriented socket specified by *s*. It can also be used, however, on connectionless sockets that have a stipulated default peer address established through the
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) or
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) function.

A socket created by the [socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) function will have the overlapped attribute as the default. A socket created by the [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) function with the *dwFlags* parameter passed to **WSASocket** with the **WSA_FLAG_OVERLAPPED** bit set will have the overlapped attribute. For sockets with the overlapped attribute, **WSASend** uses overlapped I/O unless both the *lpOverlapped* and *lpCompletionRoutine* parameters are **NULL**. In that case, the socket is treated as a non-overlapped socket. A completion indication will occur, invoking the completion of a routine or setting of an event object, when the buffer(s) have been consumed by the transport. If the operation does not complete immediately, the final completion status is retrieved through the completion routine or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult).

If both *lpOverlapped* and *lpCompletionRoutine* are **NULL**, the socket in this function will be treated as a non-overlapped socket.

For non-overlapped sockets, the last two parameters (*lpOverlapped*, *lpCompletionRoutine*) are ignored and
**WSASend** adopts the same blocking semantics as
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send). Data is copied from the buffer(s) into the transport's buffer. If the socket is non-blocking and stream-oriented, and there is not sufficient space in the transport's buffer,
**WSASend** will return with only part of the application's buffers having been consumed. Given the same buffer situation and a blocking socket,
**WSASend** will block until all of the application buffer contents have been consumed.

**Note** The socket options **SO_RCVTIMEO** and **SO_SNDTIMEO** apply only to blocking sockets.

If this function is completed in an overlapped manner, it is the Winsock service provider's responsibility to capture the
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures before returning from this call. This enables applications to build stack-based
**WSABUF** arrays pointed to by the *lpBuffers* parameter.

For message-oriented sockets, do not exceed the maximum message size of the underlying provider, which can be obtained by getting the value of socket option **SO_MAX_MSG_SIZE**. If the data is too long to pass atomically through the underlying protocol the error
[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned, and no data is transmitted.

**Windows Me/98/95:** The **WSASend** function does not support more than 16 buffers.

**Note** The successful completion of a
**WSASend** does not indicate that the data was successfully delivered.

### Using dwFlags

The *dwFlags* parameter can be used to influence the behavior of the function invocation beyond the options specified for the associated socket. That is, the semantics of this function are determined by the socket options and the *dwFlags* parameter. The latter is constructed by using the bitwise OR operator with any of any of the values listed in the following table.

| Value | Meaning |
| --- | --- |
| **MSG_DONTROUTE** | Specifies that the data should not be subject to routing. A Windows Sockets service provider can choose to ignore this flag. |
| **MSG_OOB** | Send OOB data on a stream-style socket such as **SOCK_STREAM** only. |
| **MSG_PARTIAL** | Specifies that *lpBuffers* only contains a partial message. Be aware that the error code [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) will be returned by transports that do not support partial message transmissions. |

**Note** When issuing a blocking Winsock call such as **WSASend** with the *lpOverlapped* parameter set to NULL, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Overlapped Socket I/O

If an overlapped operation completes immediately,
**WSASend** returns a value of zero and the *lpNumberOfBytesSent* parameter is updated with the number of bytes sent. If the overlapped operation is successfully initiated and will complete later,
**WSASend** returns SOCKET_ERROR and indicates error code
[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). In this case, *lpNumberOfBytesSent* is not updated. When the overlapped operation completes the amount of data transferred is indicated either through the *cbTransferred* parameter in the completion routine (if specified), or through the *lpcbTransfer* parameter in
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult).

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. For more information, see [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread).

The
**WSASend** function using overlapped I/O can be called from within the completion routine of a previous
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv),
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom), **WSASend**, or
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) function. This enables time-sensitive data transmissions to occur entirely within a preemptive context.

The *lpOverlapped* parameter must be valid for the duration of the overlapped operation. If multiple I/O operations are simultaneously outstanding, each must reference a separate
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure.

If the *lpCompletionRoutine* parameter is **NULL**, the *hEvent* parameter of *lpOverlapped* is signaled when the overlapped operation completes if it contains a valid event object handle. An application can use
[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents) or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) to wait or poll on the event object.

If *lpCompletionRoutine* is not **NULL**, the *hEvent* parameter is ignored and can be used by the application to pass context information to the completion routine. A caller that passes a non-**NULL** *lpCompletionRoutine* and later calls
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) for the same overlapped I/O request may not set the *fWait* parameter for that invocation of
**WSAGetOverlappedResult** to **TRUE**. In this case the usage of the *hEvent* parameter is undefined, and attempting to wait on the *hEvent* parameter would produce unpredictable results.

The completion routine follows the same rules as stipulated for Windows file I/O completion routines. The completion routine will not be invoked until the thread is in an alertable wait state such as can occur when the function
[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents) with the *fAlertable* parameter set to **TRUE** is invoked.

The transport providers allow an application to invoke send and receive operations from within the context of the socket I/O completion routine, and guarantee that, for a given socket, I/O completion routines will not be nested. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

The following C++ code example is a prototype of the completion routine.

``` syntax

void CALLBACK CompletionROUTINE(
  IN DWORD dwError,
  IN DWORD cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD dwFlags
);
```

The CompletionRoutine function is a placeholder for an application-defined or library-defined function name. The *dwError* parameter specifies the completion status for the overlapped operation as indicated by *lpOverlapped*. *cbTransferred* specifies the number of bytes sent. Currently there are no flag values defined and *dwFlags* will be zero. This function does not return a value.

Returning from this function allows invocation of another pending completion routine for this socket. All waiting completion routines are called before the alertable thread's wait is satisfied with a return code of **WSA_IO_COMPLETION**. The completion routines can be called in any order, not necessarily in the same order the overlapped operations are completed. However, the posted buffers are guaranteed to be sent in the same order they are specified.

The order of calls made to **WSASend** is also the order in which the buffers are transmitted to the transport layer. **WSASend** should not be called on the same stream-oriented socket concurrently from different threads, because some Winsock providers may split a large send request into multiple transmissions, and this may lead to unintended data interleaving from multiple concurrent send requests on the same stream-oriented socket.

### Example Code

The following code example shows how to use the **WSASend** function in overlapped I/O mode.

```cpp
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

#define DATA_BUFSIZE 4096
#define SEND_COUNT   10

int __cdecl main()
{
    WSADATA wsd;

    struct addrinfo *result = NULL;
    struct addrinfo hints;
    WSAOVERLAPPED SendOverlapped;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET AcceptSocket = INVALID_SOCKET;

    WSABUF DataBuf;
    DWORD SendBytes;
    DWORD Flags;

    char buffer[DATA_BUFSIZE];

    int err = 0;
    int rc, i;

    // Load Winsock
    rc = WSAStartup(MAKEWORD(2, 2), &wsd);
    if (rc != 0) {
        printf("Unable to load Winsock: %d\n", rc);
        return 1;
    }

    // Make sure the hints struct is zeroed out
    SecureZeroMemory((PVOID) & hints, sizeof(struct addrinfo));

    // Initialize the hints to obtain the
    // wildcard bind address for IPv4
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    rc = getaddrinfo(NULL, "27015", &hints, &result);
    if (rc != 0) {
        printf("getaddrinfo failed with error: %d\n", rc);
        return 1;
    }

    ListenSocket = socket(result->ai_family,
                          result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        return 1;
    }

    rc = bind(ListenSocket, result->ai_addr, (int) result->ai_addrlen);
    if (rc == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        return 1;
    }

    rc = listen(ListenSocket, 1);
    if (rc == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        return 1;
    }
    // Accept an incoming connection request
    AcceptSocket = accept(ListenSocket, NULL, NULL);
    if (AcceptSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        return 1;
    }

    printf("Client Accepted...\n");

    // Make sure the SendOverlapped struct is zeroed out
    SecureZeroMemory((PVOID) & SendOverlapped, sizeof (WSAOVERLAPPED));

    // Create an event handle and setup the overlapped structure.
    SendOverlapped.hEvent = WSACreateEvent();
    if (SendOverlapped.hEvent == NULL) {
        printf("WSACreateEvent failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        closesocket(AcceptSocket);
        return 1;
    }

    DataBuf.len = DATA_BUFSIZE;
    DataBuf.buf = buffer;

    for (i = 0; i < SEND_COUNT; i++) {

        rc = WSASend(AcceptSocket, &DataBuf, 1,
                     &SendBytes, 0, &SendOverlapped, NULL);
        if ((rc == SOCKET_ERROR) &&
            (WSA_IO_PENDING != (err = WSAGetLastError()))) {
            printf("WSASend failed with error: %d\n", err);
            break;
        }

        rc = WSAWaitForMultipleEvents(1, &SendOverlapped.hEvent, TRUE, INFINITE,
                                      TRUE);
        if (rc == WSA_WAIT_FAILED) {
            printf("WSAWaitForMultipleEvents failed with error: %d\n",
                   WSAGetLastError());
            break;
        }

        rc = WSAGetOverlappedResult(AcceptSocket, &SendOverlapped, &SendBytes,
                                    FALSE, &Flags);
        if (rc == FALSE) {
            printf("WSASend failed with error: %d\n", WSAGetLastError());
            break;
        }

        printf("Wrote %d bytes\n", SendBytes);

        WSAResetEvent(SendOverlapped.hEvent);

    }

    WSACloseEvent(SendOverlapped.hEvent);
    closesocket(AcceptSocket);
    closesocket(ListenSocket);
    freeaddrinfo(result);

    WSACleanup();

    return 0;
}

```

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf)

[WSACloseEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacloseevent)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent)

[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult)

[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)