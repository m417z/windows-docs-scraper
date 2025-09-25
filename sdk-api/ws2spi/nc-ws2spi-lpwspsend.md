## Description

The **LPWSPSend** function sends data on a connected socket.

## Parameters

### `s` [in]

A descriptor identifying a connected socket.

### `lpBuffers` [in]

A pointer to an array of [WSABUF](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) structures. Each **WSABUF** structure contains a pointer to a buffer and the length of the buffer, in bytes. For a Winsock application, once the **LPWSPSend** function is called, the system owns these buffers and the application may not access them. Data buffers referenced in each WSABUF structure are owned by the system and your application may not access them for the lifetime of the call.

### `dwBufferCount` [in]

The number of [WSABUF](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) structures in the *lpBuffers* array.

### `lpNumberOfBytesSent` [out]

A pointer to the number of bytes sent by this call.

### `dwFlags` [in]

A set of flags that specifies the way in which the call is made.

### `lpOverlapped` [in]

A pointer to a **[WSAOverlapped](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)** structure (ignored for nonoverlapped sockets).

### `lpCompletionRoutine` [in]

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

A pointer to the completion routine called when the send operation has been completed (ignored for nonoverlapped sockets).

### `lpThreadId` [in]

A pointer to a **[WSATHREADID](https://learn.microsoft.com/windows/win32/api/ws2spi/ns-ws2spi-wsathreadid)** structure to be used by the provider in a subsequent call to **[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)**. The provider should store the referenced **WSATHREADID** structure (not the pointer to same) until after the **WPUQueueApc** function returns.

### `lpErrno` [out]

A pointer to the error code.

## Return value

If no error occurs and the send operation has completed immediately, **LPWSPSend** returns zero. Note that in this case the completion routine, if specified, will have already been queued. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*. The error code [WSA_IO_PENDING](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsa-io-pending) indicates that the overlapped operation has been successfully initiated and that completion will be indicated at a later time. Any other error code indicates that no overlapped operation was initiated and no completion indication will occur.

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAEACCES](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEACCES) | Requested address is a broadcast address, but the appropriate flag was not set. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| [WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT) | The *lpBuffers* parameter is not totally contained in a valid part of the user address space. |
| [WSAENETRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETRESET) | The connection has been broken due to the remote host resetting. |
| [WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOBUFS) | The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. |
| [WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN) | Socket is not connected. |
| [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK) | The descriptor is not a socket. |
| [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEOPNOTSUPP) | MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, MSG_PARTIAL is not supported, or the socket is unidirectional and supports only receive operations. |
| [WSAESHUTDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAESHUTDOWN) | Socket has been shut down; it is not possible to **[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)** on a socket after **[LPWSPShutdown](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspshutdown)** has been invoked with how set to SD_SEND or SD_BOTH. |
| [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEWOULDBLOCK) | **Windows NT:** Overlapped sockets: There are too many outstanding overlapped I/O requests.Nonoverlapped sockets: The socket is marked as nonblocking and the send operation cannot be completed immediately. |
| [WSAEMSGSIZE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEMSGSIZE) | Socket is message oriented, and the message is larger than the maximum supported by the underlying transport. |
| [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL) | Socket has not been bound with **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**, or the socket is not created with the overlapped flag. |
| [WSAECONNABORTED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNABORTED) | Virtual circuit was terminated due to a time-out or other failure. |
| [WSAECONNRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNRESET) | Virtual circuit was reset by the remote side. |
| [WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSA_OPERATION_ABORTED) | Overlapped operation has been canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in **[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)**. |

## Remarks

The **LPWSPSend** function is used to write outgoing data from one or more buffers on a connection-oriented socket specified by *s*. It can also be used, however, on connectionless sockets that have a stipulated default peer address established through the **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** function.

For overlapped sockets (created using [LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket) with flag WSA_FLAG_OVERLAPPED) this will occur using overlapped I/O, unless both *lpOverlapped* and *lpCompletionRoutine* are null in which case the socket is treated as a nonoverlapped socket. A completion indication will occur (invocation of the completion routine or setting of an event object) when the supplied buffer(s) have been consumed by the transport. If the operation does not complete immediately, the final completion status is retrieved through the completion routine or [LPWSPGetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult).

For nonoverlapped sockets, the parameters *lpOverlapped*, *lpCompletionRoutine*, and *lpThreadId* are ignored and **LPWSPSend** adopts the regular synchronous semantics. Data is copied from the supplied buffer(s) into the transport's buffer. If the socket is nonblocking and stream oriented, and there is not sufficient space in the transport's buffer, **LPWSPSend** will return with only part of the supplied buffers having been consumed. Given the same buffer situation and a blocking socket, **LPWSPSend** will block until all of the supplied buffer contents have been consumed.

The array of [WSABUF](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) structures pointed to by the *lpBuffers* parameter is transient. If this operation completes in an overlapped manner, it is the service provider's responsibility to capture these **WSABUF** structures before returning from this call. This enables applications to build stack-based **WSABUF** arrays.

For message-oriented sockets, care must be taken not to exceed the maximum message size of the underlying provider, which can be obtained by getting the value of socket option SO_MAX_MSG_SIZE. If the data is too long to pass atomically through the underlying protocol the error **[WSAEMSGSIZE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEMSGSIZE)** is returned, and no data is transmitted.

Note that the successful completion of a **LPWSPSend** does not indicate that the data was successfully delivered.

*dwFlags* can be used to influence the behavior of the function invocation beyond the options specified for the associated socket. That is, the semantics of this function are determined by the socket options and the *dwFlags* parameter. The latter is constructed by using the bitwise OR operator with any of the following values.

| Value | Meaning |
|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| MSG_DONTROUTE | Specifies that the data should not be subject to routing. A Windows Sockets service provider can choose to ignore this flag;. |
| MSG_OOB | Sends OOB data (stream-style socket such as SOCK_STREAM only). |
| MSG_PARTIAL | Specifies that *lpBuffers* only contains a partial message. Note that the error code [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsaeopnotsupp) will be returned for messages that do not support partial message transmissions. |

If an overlapped operation completes immediately, **LPWSPSend** returns a value of zero and the *lpNumberOfBytesSent* parameter is updated with the number of bytes sent. If the overlapped operation is successfully initiated and will complete later, **LPWSPSend** returns SOCKET_ERROR and indicates error code [WSA_IO_PENDING](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#wsa-io-pending). In this case, *lpNumberOfBytesSent* is not updated. When the overlapped operation completes the amount of data transferred is indicated either through the *cbTransferred* parameter in the completion routine (if specified), or through the *lpcbTransfer* parameter in [LPWSPGetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult).

Providers must allow this function to be called from within the completion routine of a previous **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)**, **[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)**, **LPWSPSend** or **[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)** function. However, for a given socket, I/O completion routines cannot be nested. This permits time-sensitive data transmissions to occur entirely within a preemptive context.

The *lpOverlapped* parameter must be valid for the duration of the overlapped operation. If multiple I/O operations are simultaneously outstanding, each must reference a separate overlapped structure. The **[WSAOverlapped](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)** structure is defined in its own reference page.

If the *lpCompletionRoutine* parameter is null, the service provider signals the **hEvent** member of *lpOverlapped* when the overlapped operation completes if it contains a valid event object handle. The Windows Sockets SPI client can use [LPWSPGetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult) to wait or poll on the event object.

If *lpCompletionRoutine* is not null, the **hEvent** member is ignored and can be used by the Windows Sockets SPI client to pass context information to the completion routine. A client that passes a non-null *lpCompletionRoutine* and later calls **WSAGetOverlappedResult** for the same overlapped I/O request may not set the *fWait* parameter for that invocation of **WSAGetOverlappedResult** to **TRUE**. In this case the usage of the **hEvent** member is undefined, and attempting to wait on the **hEvent** member would produce unpredictable results.

A service provider arranges for a function to be executed in the proper thread and process context by calling **[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)**. This function can be called from any process and thread context, even a context different from the thread and process that was used to initiate the overlapped operation.

A service provider arranges for a function to be executed in the proper thread by calling **[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)**. Note that this function must be invoked while in the context of the same process (but not necessarily the same thread) that was used to initiate the overlapped operation. It is the service provider's responsibility to arrange for this process context to be active prior to calling **WPUQueueApc**.

The **[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)** function takes as input parameters a pointer to a **[WSATHREADID](https://learn.microsoft.com/windows/win32/api/ws2spi/ns-ws2spi-wsathreadid)** structure (supplied to the provider through the *lpThreadId* input parameter), a pointer to an APC function to be invoked, and a context value that is subsequently passed to the APC function. Because only a single context value is available, the APC function itself cannot be the client specified–completion routine. The service provider must instead supply a pointer to its own APC function that uses the supplied context value to access the needed result information for the overlapped operation, and then invokes the client specified–completion routine.

The prototype for the client-supplied completion routine is as follows.

```cpp
void CALLBACK
CompletionRoutine(
  IN DWORD           dwError,
  IN DWORD           cbTransferred,
  IN LPWSAOVERLAPPED lpOverlapped,
  IN DWORD           dwFlags
);
```

The CompletionRoutine is a placeholder for a client supplied function name. *dwError* specifies the completion status for the overlapped operation as indicated by *lpOverlapped*. *cbTransferred* specifies the number of bytes sent. No flag values are currently defined and the *dwFlags* value will be zero. This function does not return a value.

The completion routines can be called in any order, though not necessarily in the same order that the overlapped operations are completed. However, the service provider guarantees to the client that posted buffers are sent in the same order they are supplied.

> [!Note]
> All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See **[ExitThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread)** for more information.

## See also

[WPUQueueApc](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpuqueueapc)

[LPWSPGetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult)

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)