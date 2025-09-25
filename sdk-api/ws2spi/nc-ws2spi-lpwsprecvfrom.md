## Description

The **LPWSPRecvFrom** function receives a datagram and stores the source address.

## Parameters

### `s` [in]

Descriptor identifying a socket.

### `lpBuffers` [in, out]

Pointer to an array of [WSABUF](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) structures. Each **WSABUF** structure contains a pointer to a buffer and the length of the buffer, in bytes.

### `dwBufferCount` [in]

Number of [WSABUF](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) structures in the *lpBuffers* array.

### `lpNumberOfBytesRecvd` [out]

Pointer to the number of bytes received by this call.

### `lpFlags` [in, out]

Pointer to flags.

### `lpFrom` [out]

Optional pointer to a buffer in the **[sockaddr](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2)** structure that will hold the source address upon the completion of the overlapped operation.

### `lpFromlen` [in, out]

Pointer to the size of the *lpFrom* buffer, in bytes, required only if *lpFrom* is specified.

### `lpOverlapped` [in]

Pointer to a **[WSAOverlapped](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)** structure (ignored for nonoverlapped sockets).

### `lpCompletionRoutine` [in]

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

Pointer to the completion routine called when the receive operation has been completed (ignored for nonoverlapped sockets).

### `lpThreadId` \[in\]

Pointer to a **[WSATHREADID](https://learn.microsoft.com/windows/win32/api/ws2spi/ns-ws2spi-wsathreadid)** structure to be used by the provider in a subsequent call to **[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)**. The provider should store the referenced **WSATHREADID** structure (not the pointer to same) until after the **WPUQueueApc** function returns.

### `lpErrno` [in, out]

Pointer to the error code.

## Return value

If no error occurs and the receive operation has completed immediately, **LPWSPRecvFrom** returns zero. Note that in this case the completion routine, if specified will have already been queued. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*. The error code WSA_IO_PENDING indicates that the overlapped operation has been successfully initiated and that completion will be indicated at a later time. Any other error code indicates that no overlapped operations was initiated and no completion indication will occur.

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT) | The *lpFromlen* parameter was invalid: the *lpFrom* buffer was too small to accommodate the peer address or *lpbuffers* is not totally contained within a valid part of the user address space. |
| [WSAEINTR](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINTR) | (Blocking) call was canceled through **[LPWSPCancelBlockingCall](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcancelblockingcall)**. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL) | Socket has not been bound (for example, with **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**) or the socket is not created with the overlapped flag. |
| [WSAEISCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEISCONN) | Socket is connected. This function is not permitted with a connected socket, whether the socket is connection-oriented or connectionless. |
| [WSAENETRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETRESET) | The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. |
| [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK) | The descriptor is not a socket. |
| [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEOPNOTSUPP) | MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only send operations. |
| [WSAESHUTDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAESHUTDOWN) | Socket has been shut down; it is not possible to run **[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)** on a socket after **[LPWSPShutdown](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspshutdown)** has been invoked with *how* set to SD_RECEIVE or SD_BOTH. |
| [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEWOULDBLOCK) | **Windows NT:**\  Overlapped sockets: There are too many outstanding overlapped I/O requests.Nonoverlapped sockets: The socket is marked as nonblocking and the receive operation cannot be completed immediately. |
| [WSAEMSGSIZE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEMSGSIZE) | Message was too large to fit into the specified buffer and (for unreliable protocols only) any trailing portion of the message that did not fit into the buffer has been discarded. |
| [WSAECONNRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNRESET) | The virtual circuit was reset by the remote side executing a hard or abortive close. The application should close the socket as it is no longer usable. On a UDP datagram socket this error would indicate that a previous send operation resulted in an ICMP "Port Unreachable" message. |
| [WSAEDISCON](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEDISCON) | Socket *s* is message oriented and the virtual circuit was gracefully closed by the remote side. |
| [WSA_IO_PENDING](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSA_IO_PENDING) | An overlapped operation was successfully initiated and completion will be indicated at a later time. |
| [WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSA_OPERATION_ABORTED) | Overlapped operation has been canceled due to the closure of the socket. |

## Remarks

The **LPWSPRecvFrom** function is used primarily on a connectionless socket specified by *s* The socket must not be connected. The local address of the socket must be known. This may be done explicitly through **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)** or implicitly through **[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)** or **[LPWSPJoinLeaf](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspjoinleaf)**.

For overlapped sockets, this function is used to post one or more buffers into which incoming data will be placed as it becomes available on a (possibly connected) socket, after which the client-specified completion indication (invocation of the completion routine or setting of an event object) occurs. If the operation does not complete immediately, the final completion status is retrieved through the completion routine or [LPWSPGetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult). Also note that the values pointed to by *lpFrom* and *lpFromlen* are not updated until completion is indicated. Applications must not use or disturb these values until they have been updated, therefore the client must not use automatic (that is, stack-based) variables for these parameters.

If both *lpOverlapped* and *lpCompletionRoutine* are null, the socket in this function will be treated as a nonoverlapped socket.

For nonoverlapped sockets, the *lpOverlapped*, *lpCompletionRoutine*, and *lpThreadId* parameters are ignored. Any data that has already been received and buffered by the transport will be copied into the supplied user buffers. For the case of a blocking socket with no data currently having been received and buffered by the transport, the call will block until data is received according to the assigned blocking semantics for **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)**.

The supplied buffers are filled in the order in which they appear in the array pointed to by *lpBuffers*, and the buffers are packed so that no holes are created.

The array of [WSABUF](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) structures pointed to by the *lpBuffers* parameter is transient. If this operation completes in an overlapped manner, it is the service provider's responsibility to capture this array of pointers to **WSABUF** structures before returning from this call. This enables Windows Sockets SPI clients to build stack-based **WSABUF** arrays.

For connectionless socket types, the address from which the data originated is copied to the buffer pointed by *lpFrom*. On input, the value pointed to by *lpFromlen* is initialized to the size of this buffer, and is modified on completion to indicate the actual size of the address stored there.

As noted previously for overlapped sockets, the *lpFrom* and *lpFromlen* parameters are not updated until after the overlapped I/O has completed. The memory pointed to by these parameters must, therefore, remain available to the service provider and cannot be allocated on the Windows Sockets SPI client's stack frame. The *lpFrom* and *lpFromlen* parameters are ignored for connection-oriented sockets.

For byte stream-style sockets (for example, type SOCK_STREAM), incoming data is placed into the buffers until the buffers are filled, the connection is closed, or internally buffered data is exhausted. Regardless of whether or not the incoming data fills all the buffers, the completion indication occurs for overlapped sockets.

For message-oriented sockets, a single incoming message is placed into the supplied buffers, up to the total size of the buffers supplied, and the completion indication occurs for overlapped sockets. If the message is larger than the buffers supplied, the buffers are filled with the first part of the message. If the MSG_PARTIAL feature is supported by the service provider, the MSG_PARTIAL flag is set in *lpFlags* for the socket and subsequent receive operation(s) will retrieve the rest of the message. If MSG_PARTIAL is not supported but the protocol is reliable, **LPWSPRecvFrom** generates the error **[WSAEMSGSIZE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEMSGSIZE)** and a subsequent receive operation with a larger buffer can be used to retrieve the entire message. Otherwise, (that is, the protocol is unreliable and does not support MSG_PARTIAL), the excess data is lost, and **LPWSPRecvFrom** generates the error WSAEMSGSIZE.

The *lpFlags* parameter can be used to influence the behavior of the function invocation beyond the options specified for the associated socket. That is, the semantics of this function are determined by the socket options and the *lpFlags* parameter. The latter is constructed by using the bitwise OR operator with any of the following values.

| Value | Meaning |
|--------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| MSG_PEEK | Peeks at the incoming data. The data is copied into the buffer but is not removed from the input queue. This flag is valid only for nonoverlapped sockets. |
| MSG_OOB | Processes Out of Band (OOB) data. |
| MSG_PARTIAL | This flag is for message-oriented sockets only. On output, indicates that the data supplied is a portion of the message transmitted by the sender. Remaining portions of the message will be supplied in subsequent receive operations. A subsequent receive operation with MSG_PARTIAL flag cleared indicates end of sender's message. As an input parameter, MSG_PARTIAL indicates that the receive operation should complete even if only part of a message has been received by the service provider.<br> |

For message-oriented sockets, the MSG_PARTIAL bit is set in the *lpFlags* parameter if a partial message is received. If a complete message is received, MSG_PARTIAL is cleared in *lpFlags*. In the case of delayed completion, the value pointed to by *lpFlags* is not updated. When completion has been indicated the Windows Sockets SPI client should call [LPWSPGetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult) and examine the flags pointed to by the *lpdwFlags* parameter.

If an overlapped operation completes immediately, **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)** returns a value of zero and the *lpNumberOfBytesRecvd* parameter is updated with the number of bytes received and the flag bits pointed by the *lpFlags* parameter are also updated. If the overlapped operation is successfully initiated and will complete later, **LPWSPRecv** returns SOCKET_ERROR and indicates error code [WSA_IO_PENDING](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsa-io-pending). In this case, *lpNumberOfBytesRecvd* and *lpFlags* is not updated. When the overlapped operation completes, the amount of data transferred is indicated either through the *cbTransferred* parameter in the completion routine (if specified), or through the *lpcbTransfer* parameter in **LPWSPGetOverlappedResult**. Flag values are obtained by examining the *lpdwFlags* parameter of **LPWSPGetOverlappedResult**.

Providers must allow this function to be called from within the completion routine of a previous **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)**, **LPWSPRecvFrom**, **[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)**, or **[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)** function. However, for a given socket, I/O completion routines cannot be nested. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

The *lpOverlapped* parameter must be valid for the duration of the overlapped operation. If multiple I/O operations are simultaneously outstanding, each must reference a separate overlapped structure. The **[WSAOverlapped](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)** structure is defined in its own reference page.

If the *lpCompletionRoutine* parameter is null, the service provider signals the **hEvent** member of *lpOverlapped* when the overlapped operation completes if it contains a valid event object handle. A Windows Sockets SPI client can use [LPWSPGetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult) to wait or poll on the event object.

If *lpCompletionRoutine* is not null, the **hEvent** member is ignored and can be used by the Windows Sockets SPI client to pass context information to the completion routine. It is the service provider's responsibility to arrange for invocation of the client specified–completion routine when the overlapped operation completes. Since the completion routine must be executed in the context of the same thread that initiated the overlapped operation, it cannot be invoked directly from the service provider. The Ws2_32.dll offers an asynchronous procedure call (APC) mechanism to facilitate invocation of completion routines.

A service provider arranges for a function to be executed in the proper thread and process context by calling **[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)**. This function can be called from any process and thread context, even a context different from the thread and process that was used to initiate the overlapped operation.

**[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)** takes as input parameters a pointer to a **[WSATHREADID](https://learn.microsoft.com/windows/win32/api/ws2spi/ns-ws2spi-wsathreadid)** structure (supplied to the provider through the *lpThreadId* input parameter), a pointer to an APC function to be invoked, and a context value that is subsequently passed to the APC function. Because only a single context value is available, the APC function itself cannot be the client specified–completion routine. The service provider must instead supply a pointer to its own APC function that uses the supplied context value to access the needed result information for the overlapped operation, and then invokes the client specified–completion routine.

The prototype for the client-supplied completion routine is as follows:

```cpp
void CALLBACK
CompletionRoutine(
  IN DWORD           dwError,
  IN DWORD           cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD           dwFlags
);
```

The CompletionRoutine is a placeholder for a client-supplied function name. *dwError* specifies the completion status for the overlapped operation as indicated by *lpOverlapped*. *cbTransferred* specifies the number of bytes received. *dwFlags* contains information that would have appeared in *lpFlags* if the receive operation had completed immediately. This function does not return a value.

The completion routines can be called in any order, though not necessarily in the same order that the overlapped operations are completed. However, the posted buffers are guaranteed to be filled in the same order they are supplied.

> [!Note]
> All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See **[ExitThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread)** for more information.

## See also

**[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)**

[LPWSPGetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult)

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)