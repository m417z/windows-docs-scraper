# WSARecvFrom function

## Description

The
**WSARecvFrom** function receives a datagram and stores the source address.

## Parameters

### `s` [in]

A descriptor identifying a socket.

### `lpBuffers` [in, out]

A pointer to an array of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures. Each
**WSABUF** structure contains a pointer to a buffer and the length of the buffer.

### `dwBufferCount` [in]

The number of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures in the *lpBuffers* array.

### `lpNumberOfBytesRecvd` [out]

A pointer to the number of bytes received by this call if the
**WSARecvFrom** operation completes immediately.

Use **NULL** for this parameter if the *lpOverlapped* parameter is not **NULL** to avoid potentially erroneous results. This parameter can be **NULL** only if the *lpOverlapped* parameter is not **NULL**.

### `lpFlags` [in, out]

A pointer to flags used to modify the behavior of the
**WSARecvFrom** function call. See remarks below.

### `lpFrom` [out]

An optional pointer to a buffer that will hold the source address upon the completion of the overlapped operation.

### `lpFromlen` [in, out]

A pointer to the size, in bytes, of the "from" buffer required only if *lpFrom* is specified.

### `lpOverlapped` [in]

A pointer to a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure (ignored for nonoverlapped sockets).

### `lpCompletionRoutine` [in]

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

A pointer to the completion routine called when the
**WSARecvFrom** operation has been completed (ignored for nonoverlapped sockets).

## Return value

If no error occurs and the receive operation has completed immediately,
**WSARecvFrom** returns zero. In this case, the completion routine will have already been scheduled to be called once the calling thread is in the alertable state. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror). The error code **WSA_IO_PENDING** indicates that the overlapped operation has been successfully initiated and that completion will be indicated at a later time. Any other error code indicates that the overlapped operation was not successfully initiated and no completion indication will occur.

| Error code | Meaning |
| --- | --- |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was reset by the remote side executing a hard or abortive close. The application should close the socket as it is no longer usable. For a UPD datagram socket, this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpBuffers*, *lpFlags*, *lpFrom*, *lpNumberOfBytesRecvd*, *lpFromlen*, *lpOverlapped*, or *lpCompletionRoutine* parameter is not totally contained in a valid part of the user address space: the *lpFrom* buffer was too small to accommodate the peer address. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound (with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), for example). |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The message was too large for the specified buffer and (for unreliable protocols only) any trailing portion of the message that did not fit into the buffer has been discarded. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | For a datagram socket, this error indicates that the time to live has expired. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected (connection-oriented sockets only). |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **Windows NT:** <br><br>Overlapped sockets: There are too many outstanding overlapped I/O requests. Nonoverlapped sockets: The socket is marked as nonblocking and the receive operation cannot be completed immediately. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSA_IO_PENDING](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An overlapped operation was successfully initiated and completion will be indicated later. |
| **[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The overlapped operation has been canceled due to the closure of the socket. |

## Remarks

The
**WSARecvFrom** function provides functionality over and above the standard
[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom) function in three important areas:

* It can be used in conjunction with overlapped sockets to perform overlapped receive operations.
* It allows multiple receive buffers to be specified making it applicable to the scatter/gather type of I/O.
* The *lpFlags* parameter is both an input and an output parameter, allowing applications to sense the output state of the **MSG_PARTIAL** flag bit. Be aware that the **MSG_PARTIAL** flag bit is not supported by all protocols.

The
**WSARecvFrom** function is used primarily on a connectionless socket specified by *s*. The socket's local address must be known. For server applications, this is usually done explicitly through
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind). Explicit binding is discouraged for client applications. For client applications using this function the socket can become bound implicitly to a local address through
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto),
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto), or
[WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf).

For overlapped sockets, this function is used to post one or more buffers into which incoming data will be placed as it becomes available on a (possibly connected) socket, after which the application-specified completion indication (invocation of the completion routine or setting of an event object) occurs. If the operation does not complete immediately, the final completion status is retrieved through the completion routine or
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult). Also, the values indicated by *lpFrom* and *lpFromlen* are not updated until completion is itself indicated. Applications must not use or disturb these values until they have been updated; therefore the application must not use automatic (that is, stack-based) variables for these parameters.

**Note** All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See [ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) for more information.

If both *lpOverlapped* and *lpCompletionRoutine* are **NULL**, the socket in this function will be treated as a nonoverlapped socket.

For nonoverlapped sockets, the blocking semantics are identical to that of the standard
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) function and the *lpOverlapped* and *lpCompletionRoutine* parameters are ignored. Any data that has already been received and buffered by the transport will be copied into the user buffers. For the case of a blocking socket with no data currently having been received and buffered by the transport, the call will block until data is received.

The buffers are filled in the order in which they appear in the array indicated by *lpBuffers*, and the buffers are packed so that no holes are created.

If this function is completed in an overlapped manner, it is the Winsock service provider's responsibility to capture the
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures before returning from this call. This enables applications to build stack-based
**WSABUF** arrays pointed to by the *lpBuffers* parameter.

For connectionless socket types, the address from which the data originated is copied to the buffer indicated by *lpFrom*. The value pointed to by *lpFromlen* is initialized to the size of this buffer, and is modified on completion to indicate the actual size of the address stored there. As stated previously for overlapped sockets, the *lpFrom* and *lpFromlen* parameters are not updated until after the overlapped I/O has completed. The memory pointed to by these parameters must, therefore, remain available to the service provider and cannot be allocated on the application stack frame. The *lpFrom* and *lpFromlen* parameters are ignored for connection-oriented sockets.

For byte stream–style sockets (for example, type SOCK_STREAM), incoming data is placed into the buffers until:

* The buffers are filled.
* The connection is closed.
* The internally buffered data is exhausted.

Regardless of whether or not the incoming data fills all the buffers, the completion indication occurs for overlapped sockets. For message-oriented sockets, an incoming message is placed into the buffers up to the total size of the buffers, and the completion indication occurs for overlapped sockets. If the message is larger than the buffers, the buffers are filled with the first part of the message. If the **MSG_PARTIAL** feature is supported by the underlying service provider, the **MSG_PARTIAL** flag is set in *lpFlags* and subsequent receive operation(s) will retrieve the rest of the message. If **MSG_PARTIAL** is not supported, but the protocol is reliable,
**WSARecvFrom** generates the error
[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) and a subsequent receive operation with a larger buffer can be used to retrieve the entire message. Otherwise, (that is, the protocol is unreliable and does not support **MSG_PARTIAL**), the excess data is lost, and
**WSARecvFrom** generates the error WSAEMSGSIZE.

The *lpFlags* parameter can be used to influence the behavior of the function invocation beyond the options specified for the associated socket. That is, the semantics of this function are determined by the socket options and the *lpFlags* parameter. The latter is constructed by using the bitwise OR operator with any of any of the values listed in the following table.

| Value | Meaning |
| --- | --- |
| **MSG_PEEK** | Previews the incoming data. The data is copied into the buffer, but is not removed from the input queue. This flag is valid only for nonoverlapped sockets. |
| **MSG_OOB** | Processes OOB data. |
| **MSG_PARTIAL** | This flag is for message-oriented sockets only. On output, this flag indicates that the data is a portion of the message transmitted by the sender. Remaining portions of the message will be transmitted in subsequent receive operations. A subsequent receive operation with **MSG_PARTIAL** flag cleared indicates the end of the sender's message. <br><br>As an input parameter, this flag indicates that the receive operation should complete even if only part of a message has been received by the service provider. |

For message-oriented sockets, the **MSG_PARTIAL** bit is set in the *lpFlags* parameter if a partial message is received. If a complete message is received, **MSG_PARTIAL** is cleared in *lpFlags*. In the case of delayed completion, the value pointed to by *lpFlags* is not updated. When completion has been indicated the application should call
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult) and examine the flags pointed to by the *lpdwFlags* parameter.

**Note** When issuing a blocking Winsock call such as **WSARecvFrom** with the *lpOverlapped* parameter set to NULL, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Overlapped Socket I/O

If an overlapped operation completes immediately,
**WSARecvFrom** returns a value of zero and the *lpNumberOfBytesRecvd* parameter is updated with the number of bytes received and the flag bits pointed by the *lpFlags* parameter are also updated. If the overlapped operation is successfully initiated and will complete later,
**WSARecvFrom** returns **SOCKET_ERROR** and indicates error code **WSA_IO_PENDING**. In this case, *lpNumberOfBytesRecvd* and *lpFlags* is not updated. When the overlapped operation completes the amount of data transferred is indicated either through the *cbTransferred* parameter in the completion routine (if specified), or through the *lpcbTransfer* parameter in
[WSAGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetoverlappedresult). Flag values are obtained either through the *dwFlags* parameter of the completion routine, or by examining the *lpdwFlags* parameter of
**WSAGetOverlappedResult**.

The
**WSARecvFrom** function can be called from within the completion routine of a previous
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv),
**WSARecvFrom**,
[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend), or
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

If an IO completion port is used and the *lpCompletionRoutine* parameter and the *hEvent* parameter are **NULL**, the result of the operation is schedule on the IO completion port. This happens for all successful operations, whether the operations complete immediately or not.

The transport providers allow an application to invoke send and receive operations from within the context of the socket I/O completion routine, and guarantee that, for a given socket, I/O completion routines will not be nested. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

The prototype of the completion routine is as follows.

```cpp

void CALLBACK CompletionROUTINE(
  IN DWORD dwError,
  IN DWORD cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD dwFlags
);

```

The **CompletionRoutine** is a placeholder for an application-defined or library-defined function name. The *dwError* specifies the completion status for the overlapped operation as indicated by *lpOverlapped*. The *cbTransferred* specifies the number of bytes received. The *dwFlags* parameter contains information that would have appeared in *lpFlags* if the receive operation had completed immediately. This function does not return a value.

Returning from this function allows invocation of another pending completion routine for this socket. When using
[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents), all waiting completion routines are called before the alertable thread's wait is satisfied with a return code of WSA_IO_COMPLETION. The completion routines can be called in any order, not necessarily in the same order the overlapped operations are completed. However, the posted buffers are guaranteed to be filled in the same order they are specified.

### Example Code

The following example demonstrates the use of the **WSARecvFrom** function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

int __cdecl main()
{

    WSADATA wsaData;
    WSABUF DataBuf;
    WSAOVERLAPPED Overlapped;

    SOCKET RecvSocket = INVALID_SOCKET;
    struct sockaddr_in RecvAddr;
    struct sockaddr_in SenderAddr;

    int SenderAddrSize = sizeof (SenderAddr);
    u_short Port = 27015;

    char RecvBuf[1024];
    int BufLen = 1024;
    DWORD BytesRecv = 0;
    DWORD Flags = 0;

    int err = 0;
    int rc;
    int retval = 0;

    //-----------------------------------------------
    // Initialize Winsock
    rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (rc != 0) {
        /* Could not find a usable Winsock DLL */
        wprintf(L"WSAStartup failed with error: %ld\n", rc);
        return 1;
    }

    // Make sure the Overlapped struct is zeroed out
    SecureZeroMemory((PVOID) &Overlapped, sizeof(WSAOVERLAPPED) );

    // Create an event handle and setup the overlapped structure.
    Overlapped.hEvent = WSACreateEvent();
    if (Overlapped.hEvent == NULL) {
        wprintf(L"WSACreateEvent failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //-----------------------------------------------
    // Create a receiver socket to receive datagrams
    RecvSocket = WSASocket(AF_INET,
                           SOCK_DGRAM,
                           IPPROTO_UDP, NULL, 0, WSA_FLAG_OVERLAPPED);

    if (RecvSocket == INVALID_SOCKET) {
        /* Could not open a socket */
        wprintf(L"WSASocket failed with error: %ld\n", WSAGetLastError());
        WSACloseEvent(Overlapped.hEvent);
        WSACleanup();
        return 1;
    }
    //-----------------------------------------------
    // Bind the socket to any address and the specified port.
    RecvAddr.sin_family = AF_INET;
    RecvAddr.sin_port = htons(Port);
    RecvAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    rc = bind(RecvSocket, (SOCKADDR *) & RecvAddr, sizeof (RecvAddr));
    if (rc != 0) {
        /* Bind to the socket failed */
        wprintf(L"bind failed with error: %ld\n", WSAGetLastError());
        WSACloseEvent(Overlapped.hEvent);
        closesocket(RecvSocket);
        WSACleanup();
        return 1;
    }

    //-----------------------------------------------
    // Call the recvfrom function to receive datagrams
    // on the bound socket.
    DataBuf.len = BufLen;
    DataBuf.buf = RecvBuf;
    wprintf(L"Listening for incoming datagrams on port=%d\n", Port);
    rc = WSARecvFrom(RecvSocket,
                      &DataBuf,
                      1,
                      &BytesRecv,
                      &Flags,
                      (SOCKADDR *) & SenderAddr,
                      &SenderAddrSize, &Overlapped, NULL);

    if (rc != 0) {
        err = WSAGetLastError();
        if (err != WSA_IO_PENDING) {
            wprintf(L"WSARecvFrom failed with error: %ld\n", err);
            WSACloseEvent(Overlapped.hEvent);
            closesocket(RecvSocket);
            WSACleanup();
            return 1;
        }
        else {
            rc = WSAWaitForMultipleEvents(1, &Overlapped.hEvent, TRUE, INFINITE, TRUE);
            if (rc == WSA_WAIT_FAILED) {
                wprintf(L"WSAWaitForMultipleEvents failed with error: %d\n", WSAGetLastError());
                retval = 1;
            }

            rc = WSAGetOverlappedResult(RecvSocket, &Overlapped, &BytesRecv,
                                FALSE, &Flags);
            if (rc == FALSE) {
                wprintf(L"WSArecvFrom failed with error: %d\n", WSAGetLastError());
                retval = 1;
            }
            else
                wprintf(L"Number of received bytes = %d\n", BytesRecv);

            wprintf(L"Finished receiving. Closing socket.\n");
        }

    }
    //---------------------------------------------
    // When the application is finished receiving, close the socket.

    WSACloseEvent(Overlapped.hEvent);
    closesocket(RecvSocket);
    wprintf(L"Exiting.\n");

    //---------------------------------------------
    // Clean up and quit.
    WSACleanup();
    return (retval);
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

[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)

[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)