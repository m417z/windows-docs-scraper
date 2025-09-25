## Description

The **LPWSPGetOverlappedResult** function returns the results of an overlapped operation on the specified socket.

## Parameters

### `s` [in]

Identifies the socket. This is the same socket that was specified when the overlapped operation was started by a call to **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)**, **[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)**, **[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)**, **[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)**, or **[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)**.

### `lpOverlapped` [in]

Pointer to a **[WSAOverlapped](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)** structure that was specified when the overlapped operation was started.

### `lpcbTransfer` [out]

Pointer to a 32-bit variable that receives the number of bytes that were actually transferred by a send or receive operation, or by **[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)**.

### `fWait` [in]

Specifies whether the function should wait for the pending overlapped operation to complete. If **TRUE**, the function does not return until the operation has been completed. If **FALSE** and the operation is still pending, the function returns **FALSE** and *lpErrno* is WSA_IO_INCOMPLETE. The *fWait* parameter may be set to **TRUE** only if the overlapped operation selected event-based completion notification.

### `lpdwFlags` [out]

Pointer to a 32-bit variable that will receive one or more flags that supplement the completion status. If the overlapped operation was initiated through **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)** or **[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)**, this parameter will contain the results value for *lpFlags* parameter.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If **LPWSPGetOverlappedResult** succeeds, the return value is **TRUE**. This means the overlapped operation has completed successfully and the value pointed to by *lpcbTransfer* has been updated. If **LPWSPGetOverlappedResult** returns **FALSE**, this means that the overlapped operation has not completed or the overlapped operation completed but with errors, or completion status could not be determined due to errors in one or more parameters to **LPWSPGetOverlappedResult**. On failure, the value pointed to by *lpcbTransfer* will not be updated. The *lpErrno* parameter indicates the cause of the failure (either of **LPWSPGetOverlappedResult** or of the associated overlapped operation).

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK) | The descriptor is not a socket. |
| [WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSA_INVALID_HANDLE) | The **hEvent** member of the **[WSAOverlapped](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)** structure does not contain a valid event object handle. |
| [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL) | One of the parameters is unacceptable. |
| [WSA_IO_INCOMPLETE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSA_IO_INCOMPLETE) | The *fWait* parameter is **FALSE** and the I/O operation has not yet completed. |

## Remarks

The results reported by the **LPWSPGetOverlappedResult** function are those of the specified socket's last overlapped operation to which the specified **[WSAOverlapped](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)** structure was provided, and for which the operation's results were pending. A pending operation is indicated when the function that started the operation returns SOCKET_ERROR, and the *lpErrno* is WSA_IO_PENDING. When an I/O operation is pending, the function that started the operation resets the **hEvent** member of the **WSAOVERLAPPED** structure to the nonsignaled state. Then, when the pending operation has been completed, the system sets the event object to the signaled state.

If the *fWait* parameter is **TRUE**, **LPWSPGetOverlappedResult** determines whether the pending operation has been completed by blocking and waiting for the event object to be in the signaled state. A client may set the *fWait* parameter to **TRUE** only if it selected event-based completion notification when the I/O operation was requested. If another form of notification was selected, the usage of the **hEvent** member of the **[WSAOverlapped](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)** structure is different, and setting *fWait* to **TRUE** causes unpredictable results.

> [!Note]
> All I/O initiated by a given thread is canceled when that thread exits. For overlapped sockets, pending asynchronous operations can fail if the thread is closed before the operations complete. See **[ExitThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread)** for more information.

### Interaction with WPUCompleteOverlappedRequest

The behavior of **[WPUCompleteOverlappedRequest](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucompleteoverlappedrequest)** places some constraints on how a service provider implements **LPWSPGetOverlappedResult** since only the **Offset** and **OffsetHigh** members of the **[WSAOverlapped](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)** structure are exclusively controlled by the service provider even though three values (byte count, flags, and error) must be retrieved from the structure by **LPWSPGetOverlappedResult**. A service provider may accomplish this any way it chooses as long as it interacts with the behavior of **WPUCompleteOverlappedRequest** properly. The following description presents a typical implementation:

At the start of overlapped processing, the service provider sets **Internal** to WSS_OPERATION_IN_PROGRESS.

When the I/O operation is complete, the provider sets **OffsetHigh** to the Windows Sockets 2 error code resulting from the operation, sets **Offset** to the flags resulting from the I/O operation, and calls **[WPUCompleteOverlappedRequest](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucompleteoverlappedrequest)**, passing the transfer byte count as one of the parameters. **WPUCompleteOverlappedRequest** eventually sets **InternalHigh** to the transfer byte count, then sets **Internal** to a value other than WSS_OPERATION_IN_PROGRESS.

When **LPWSPGetOverlappedResult** is called, the service provider checks Internal. If it is WSS_OPERATION_IN_PROGRESS, the provider waits on the event handle in the **hEvent** member or returns an error, based on the setting of the *fWait* flag of **LPWSPGetOverlappedResult**. If not in progress, or after completion of waiting, the provider returns the values from **InternalHigh**, **OffsetHigh**, and **Offset** as the transfer count, operation result error code, and flags respectively.

## See also

[WPUCompleteOverlappedRequest](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucompleteoverlappedrequest)

[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)

[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)

[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)

[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)

[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)

[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)

[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)