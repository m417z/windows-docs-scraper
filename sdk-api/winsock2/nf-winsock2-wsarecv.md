# WSARecv function

## Description

The
**WSARecv** function receives data from a connected socket or a bound connectionless socket.

## Parameters

### `s` [in]

A descriptor identifying a connected socket.

### `lpBuffers` [in, out]

A pointer to an array of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures. Each
**WSABUF** structure contains a pointer to a buffer and the length, in bytes, of the buffer.

### `dwBufferCount` [in]

The number of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures in the *lpBuffers* array.

### `lpNumberOfBytesRecvd` [out]

A pointer to the number, in bytes, of data received by this call if the receive operation completes immediately.

Use **NULL** for this parameter if the *lpOverlapped* parameter is not **NULL** to avoid potentially erroneous results. This parameter can be **NULL** only if the *lpOverlapped* parameter is not **NULL**.

### `lpFlags` [in, out]

A pointer to flags used to modify the behavior of the
**WSARecv** function call. For more information, see the Remarks section.

### `lpOverlapped` [in]

A pointer to a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure (ignored for nonoverlapped sockets).

### `lpCompletionRoutine` [in]

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

A pointer to the completion routine called when the receive operation has been completed (ignored for nonoverlapped sockets).

## Return value

If no error occurs and the receive operation has completed immediately,
**WSARecv** returns zero. In this case, the completion routine will have already been scheduled to be called once the calling thread is in the alertable state. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror). The error code
[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) indicates that the overlapped operation has been successfully initiated and that completion will be indicated at a later time. Any other error code indicates that the overlapped operation was not successfully initiated and no completion indication will occur.

| Error code | Meaning |
| --- | --- |
| **[WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was terminated due to a time-out or other failure. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a stream socket, the virtual circuit was reset by the remote side. The application should close the socket as it is no longer usable. For a UDP datagram socket, this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |
| **[WSAEDISCON](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Socket *s* is message oriented and the virtual circuit was gracefully closed by the remote side. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpBuffers* parameter is not completely contained in a valid part of the user address space. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The (blocking) call was canceled by the [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall) function. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound (for example, with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)). |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The message was too large to fit into the specified buffer and (for unreliable protocols only) any trailing portion of the message that did not fit into the buffer has been discarded. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a connection-oriented socket, this error indicates that the connection has been broken due to *keep-alive* activity that detected a failure while the operation was in progress. For a datagram socket, this error indicates that the time to live has expired. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **MSG_OOB** was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only send operations. |
| **[WSAESHUTDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has been shut down; it is not possible to call [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) on a socket after [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) has been invoked with *how* set to **SD_RECEIVE** or **SD_BOTH**. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has been dropped because of a network failure or because the peer system failed to respond. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **Windows NT:** Overlapped sockets: there are too many outstanding overlapped I/O requests. Nonoverlapped sockets: The socket is marked as nonblocking and the receive operation cannot be completed immediately. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An overlapped operation was successfully initiated and completion will be indicated at a later time. |
| **[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The overlapped operation has been canceled due to the closure of the socket. |

## Remarks

The
**WSARecv** function provides some additional features compared with the standard
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) function in three important areas:

* It can be used in conjunction with overlapped sockets to perform overlapped
  [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) operations.
* It allows multiple receive buffers to be specified making it applicable to the scatter/gather type of I/O.
* The *lpFlags* parameter is used both on input and returned on output, allowing applications to sense the output state of the **MSG_PARTIAL** flag bit. However, the **MSG_PARTIAL** flag bit is not supported by all protocols.

The
**WSARecv** function is used on connected sockets or bound connectionless sockets specified by the *s* parameter and is used to read incoming data. The socket's local address must be known. For server applications, this is usually done explicitly through
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) or implicitly through
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) or
[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept). Explicit binding is discouraged for client applications. For client applications the socket can become bound implicitly to a local address through
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect),
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect),
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto),
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto), or
[WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf).

For connected, connectionless sockets, this function restricts the addresses from which received messages are accepted. The function only returns messages from the remote address specified in the connection. Messages from other addresses are (silently) discarded.

For overlapped sockets,
**WSARecv** is used to post one or more buffers into which incoming data will be placed as it becomes available, after which the application-specified completion indication (invocation of the completion routine or setting of an event object) occurs. If the operation does not complete immediately, the final completion status is retrieved through the completion routine or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult).

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

If both *lpOverlapped* and *lpCompletionRoutine* are **NULL**, the socket in this function will be treated as a nonoverlapped socket.

For nonoverlapped sockets, the blocking semantics are identical to that of the standard
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) function and the *lpOverlapped* and *lpCompletionRoutine* parameters are ignored. Any data that has already been received and buffered by the transport will be copied into the specified user buffers. In the case of a blocking socket with no data currently having been received and buffered by the transport, the call will block until data is received. Windows Sockets 2 does not define any standard blocking time-out mechanism for this function. For protocols acting as byte-stream protocols the stack tries to return as much data as possible subject to the available buffer space and amount of received data available. However, receipt of a single byte is sufficient to unblock the caller. There is no guarantee that more than a single byte will be returned. For protocols acting as message-oriented, a full message is required to unblock the caller.

**Note** The socket options **SO_RCVTIMEO** and **SO_SNDTIMEO** apply only to blocking sockets.

Whether or not a protocol is acting as byte stream is determined by the setting of XP1_MESSAGE_ORIENTED and XP1_PSEUDO_STREAM in its
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure and the setting of the MSG_PARTIAL flag passed in to this function (for protocols that support it). The following table lists relevant combinations, (an asterisk (*) indicates that the setting of this bit does not matter in this case).

| XP1_MESSAGE_ORIENTED | XP1_PSEUDO_STREAM | MSG_PARTIAL | Acts as |
| --- | --- | --- | --- |
| not set | * | * | Byte stream |
| * | Set | * | Byte stream |
| set | Not set | set | Byte stream |
| set | Not set | not set | Message oriented |

The buffers are filled in the order in which they appear in the array pointed to by *lpBuffers*, and the buffers are packed so that no holes are created.

If this function is completed in an overlapped manner, it is the Winsock service provider's responsibility to capture the
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures before returning from this call. This enables applications to build stack-based
**WSABUF** arrays pointed to by the *lpBuffers* parameter.

For byte stream-style sockets (for example, type **SOCK_STREAM**), incoming data is placed into the buffers until the buffers are filled, the connection is closed, or the internally buffered data is exhausted. Regardless of whether or not the incoming data fills all the buffers, the completion indication occurs for overlapped sockets.

For message-oriented sockets (for example, type **SOCK_DGRAM**), an incoming message is placed into the buffers up to the total size of the buffers, and the completion indication occurs for overlapped sockets. If the message is larger than the buffers, the buffers are filled with the first part of the message. If the **MSG_PARTIAL** feature is supported by the underlying service provider, the **MSG_PARTIAL** flag is set in *lpFlags* and subsequent receive operations will retrieve the rest of the message. If **MSG_PARTIAL** is not supported but the protocol is reliable,
**WSARecv** generates the error
[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) and a subsequent receive operation with a larger buffer can be used to retrieve the entire message. Otherwise, (that is, the protocol is unreliable and does not support **MSG_PARTIAL**), the excess data is lost, and
**WSARecv** generates the error WSAEMSGSIZE.

For connection-oriented sockets,
**WSARecv** can indicate the graceful termination of the virtual circuit in one of two ways that depend on whether the socket is byte stream or message oriented. For byte streams, zero bytes having been read (as indicated by a zero return value to indicate success, and *lpNumberOfBytesRecvd* value of zero) indicates graceful closure and that no more bytes will ever be read. For message-oriented sockets, where a zero byte message is often allowable, a failure with an error code of
[WSAEDISCON](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is used to indicate graceful closure. In any case a return error code of
[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) indicates an abortive close has occurred.

The *lpFlags* parameter can be used to influence the behavior of the function invocation beyond the options specified for the associated socket. That is, the semantics of this function are determined by the socket options and the *lpFlags* parameter. The latter is constructed by using the bitwise OR operator with any of the values listed in the following table.

| Value | Meaning |
| --- | --- |
| MSG_PEEK | Peeks at the incoming data. The data is copied into the buffer, but is not removed from the input queue.<br><br>This flag is valid only for nonoverlapped sockets. |
| MSG_OOB | Processes OOB data. |
| MSG_PARTIAL | This flag is for message-oriented sockets only. On output, this flag indicates that the data specified is a portion of the message transmitted by the sender. Remaining portions of the message will be specified in subsequent receive operations. A subsequent receive operation with the **MSG_PARTIAL** flag cleared indicates end of sender's message.<br><br>As an input parameter, this flag indicates that the receive operation should complete even if only part of a message has been received by the transport provider. |
| MSG_PUSH_IMMEDIATE | This flag is for stream-oriented sockets only. This flag allows an application that uses stream sockets to tell the transport provider not to delay completion of partially filled pending receive requests. This is a hint to the transport provider that the application is willing to receive any incoming data as soon as possible without necessarily waiting for the remainder of the data that might still be in transit. What constitutes a partially filled pending receive request is a transport-specific matter. <br><br>In the case of TCP, this refers to the case of incoming TCP segments being placed into the receive request data buffer where none of the TCP segments indicated a PUSH bit value of 1. In this case, TCP may hold the partially filled receive request a little longer to allow the remainder of the data to arrive with a TCP segment that has the PUSH bit set to 1. This flag tells TCP not to hold the receive request but to complete it immediately.<br><br> Using this flag for large block transfers is not recommended since processing partial blocks is often not optimal. This flag is useful only for cases where receiving and processing the partial data immediately helps decrease processing latency.<br><br>This flag is a hint rather than an actual guarantee.<br><br>This flag is supported on Windows 8.1, Windows Server 2012 R2, and later. |
| MSG_WAITALL | The receive request will complete only when one of the following events occurs:<br><br>* The buffer supplied by the caller is completely full.<br>* The connection has been closed.<br>* The request has been canceled or an error occurred.<br><br>Be aware that if the underlying transport provider does not support **MSG_WAITALL**, or if the socket is in a non-blocking mode, then this call will fail with **WSAEOPNOTSUPP**. Also, if **MSG_WAITALL** is specified along with **MSG_OOB**, **MSG_PEEK**, or **MSG_PARTIAL**, then this call will fail with **WSAEOPNOTSUPP**.<br><br>This flag is not supported on datagram sockets or message-oriented sockets. |

For message-oriented sockets, the **MSG_PARTIAL** bit is set in the *lpFlags* parameter if a partial message is received. If a complete message is received, **MSG_PARTIAL** is cleared in *lpFlags*. In the case of delayed completion, the value pointed to by *lpFlags* is not updated. When completion has been indicated, the application should call
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) and examine the flags indicated by the *lpdwFlags* parameter.

**Note** When issuing a blocking Winsock call such as **WSARecv** with the *lpOverlapped* parameter set to NULL, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Overlapped Socket I/O

If an overlapped operation completes immediately,
**WSARecv** returns a value of zero and the *lpNumberOfBytesRecvd* parameter is updated with the number of bytes received and the flag bits indicated by the *lpFlags* parameter are also updated. If the overlapped operation is successfully initiated and will complete later,
**WSARecv** returns **SOCKET_ERROR** and indicates error code
[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). In this case, *lpNumberOfBytesRecvd* and *lpFlags* are not updated. When the overlapped operation completes, the amount of data transferred is indicated either through the *cbTransferred* parameter in the completion routine (if specified), or through the *lpcbTransfer* parameter in
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult). Flag values are obtained by examining the *lpdwFlags* parameter of
**WSAGetOverlappedResult**.

The
**WSARecv** function using overlapped I/O can be called from within the completion routine of a previous
**WSARecv**,
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom),
[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend) or
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) function. For a given socket, I/O completion routines will not be nested. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

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

The prototype of the completion routine is as follows:

```cpp

void CALLBACK CompletionROUTINE(
  IN DWORD dwError,
  IN DWORD cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD dwFlags
);

```

CompletionRoutine is a placeholder for an application-defined or library-defined function name. The *dwError* specifies the completion status for the overlapped operation as indicated by *lpOverlapped*. The *cbTransferred* parameter specifies the number of bytes received. The *dwFlags* parameter contains information that would have appeared in *lpFlags* if the receive operation had completed immediately. This function does not return a value.

Returning from this function allows invocation of another pending completion routine for this socket. When using
[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents), all waiting completion routines are called before the alertable thread's wait is satisfied with a return code of **WSA_IO_COMPLETION**. The completion routines can be called in any order, not necessarily in the same order the overlapped operations are completed. However, the posted buffers are guaranteed to be filled in the same order in which they are specified.

If you are using I/O completion ports, be aware that the order of calls made to **WSARecv** is also the order in which the buffers are populated. **WSARecv** should not be called on the same socket simultaneously from different threads, because it can result in an unpredictable buffer order.

### Example Code

The following example shows how to use the **WSARecv** function in overlapped I/O mode.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

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

#pragma warning(disable: 4127)  // Conditional expression is a constant

#define DATA_BUFSIZE 4096

int __cdecl main(int argc, char **argv)
{
    WSADATA wsd;
    struct addrinfo *result = NULL, *ptr = NULL, hints;
    WSAOVERLAPPED RecvOverlapped;
    SOCKET ConnSocket = INVALID_SOCKET;
    WSABUF DataBuf;
    DWORD RecvBytes, Flags;
    char buffer[DATA_BUFSIZE];

    int err = 0;
    int rc;

    if (argc != 2) {
        wprintf(L"usage: %s server-name\n", argv[0]);
        return 1;
    }
    // Load Winsock
    rc = WSAStartup(MAKEWORD(2, 2), &wsd);
    if (rc != 0) {
        wprintf(L"Unable to load Winsock: %d\n", rc);
        return 1;
    }
    // Make sure the hints struct is zeroed out
    SecureZeroMemory((PVOID) & hints, sizeof (struct addrinfo));

    // Initialize the hints to retrieve the server address for IPv4
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    rc = getaddrinfo(argv[1], "27015", &hints, &result);
    if (rc != 0) {
        wprintf(L"getaddrinfo failed with error: %d\n", rc);
        return 1;
    }

    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        ConnSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (ConnSocket == INVALID_SOCKET) {
            wprintf(L"socket failed with error: %d\n", WSAGetLastError());
            freeaddrinfo(result);
            return 1;
        }

        rc = connect(ConnSocket, ptr->ai_addr, (int) ptr->ai_addrlen);
        if (rc == SOCKET_ERROR) {

            if (WSAECONNREFUSED == (err = WSAGetLastError())) {
                closesocket(ConnSocket);
                ConnSocket = INVALID_SOCKET;
                continue;
            }
            wprintf(L"connect failed with error: %d\n", err);
            freeaddrinfo(result);
            closesocket(ConnSocket);
            return 1;
        }
        break;
    }
    if (ConnSocket == INVALID_SOCKET) {
        wprintf(L"Unable to establish connection with the server!\n");
        freeaddrinfo(result);
        return 1;
    }

    wprintf(L"Client connected...\n");

    // Make sure the RecvOverlapped struct is zeroed out
    SecureZeroMemory((PVOID) & RecvOverlapped, sizeof (WSAOVERLAPPED));

    // Create an event handle and setup an overlapped structure.
    RecvOverlapped.hEvent = WSACreateEvent();
    if (RecvOverlapped.hEvent == NULL) {
        wprintf(L"WSACreateEvent failed: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ConnSocket);
        return 1;
    }

    DataBuf.len = DATA_BUFSIZE;
    DataBuf.buf = buffer;

    // Call WSARecv until the peer closes the connection
    // or until an error occurs
    while (1) {

        Flags = 0;
        rc = WSARecv(ConnSocket, &DataBuf, 1, &RecvBytes, &Flags, &RecvOverlapped, NULL);
        if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError()))) {
            wprintf(L"WSARecv failed with error: %d\n", err);
            break;
        }

        rc = WSAWaitForMultipleEvents(1, &RecvOverlapped.hEvent, TRUE, INFINITE, TRUE);
        if (rc == WSA_WAIT_FAILED) {
            wprintf(L"WSAWaitForMultipleEvents failed with error: %d\n", WSAGetLastError());
            break;
        }

        rc = WSAGetOverlappedResult(ConnSocket, &RecvOverlapped, &RecvBytes, FALSE, &Flags);
        if (rc == FALSE) {
            wprintf(L"WSARecv operation failed with error: %d\n", WSAGetLastError());
            break;
        }

        wprintf(L"Read %d bytes\n", RecvBytes);

        WSAResetEvent(RecvOverlapped.hEvent);

        // If 0 bytes are received, the connection was closed
        if (RecvBytes == 0)
            break;
    }

    WSACloseEvent(RecvOverlapped.hEvent);
    closesocket(ConnSocket);
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

[WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent)

[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult)

[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)