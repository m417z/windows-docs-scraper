# WPUCompleteOverlappedRequest function

## Description

The
**WPUCompleteOverlappedRequest** function performs overlapped I/O completion notification for overlapped I/O operations.

## Parameters

### `s` [in]

The service provider socket created by
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle).

### `lpOverlapped` [in]

A pointer to a
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure associated with the overlapped I/O operation whose completion is to be notified.

### `dwError` [in]

The completion status of the overlapped I/O operation whose completion is to be notified.

### `cbTransferred` [in]

The number of bytes transferred to or from client buffers (the direction of the transfer depends on the send or receive nature of the overlapped I/O operation whose completion is to be notified).

### `lpErrno` [out]

A pointer to the error code resulting from execution of this function.

## Return value

If no error occurs,
**WPUCompleteOverlappedRequest** returns zero and notifies completion of the overlapped I/O operation according to the mechanism selected by the client (signals an event found in the
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure referenced by *lpOverlapped* and/or queues a completion status report to the completion port associated with the socket if a completion port is associated). Otherwise,
**WPUCompleteOverlappedRequest** returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket passed in the *s* parameter is not a socket created by [WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle). |

## Remarks

The
**WPUCompleteOverlappedRequest** function performs overlapped I/O completion notification for overlapped I/O operations where the client-specified completion mechanism is something other than user mode–asynchronous procedure call (APC). This function can only be used for socket handles created by
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle).

**Note** This function is different from other functions with the "WPU" prefix in that it is not accessed through the upcall table. Instead, it is exported directly by Ws2_32.dll. Service providers that need to call this function should link with WS2_32.lib or use appropriate operating system functions such as [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to retrieve the function pointer.

The function
**WPUCompleteOverlappedRequest** is used by service providers that do not implement Installable File System (IFS) functionality directly for the socket handles they expose. It performs completion notification for any overlapped I/O request for which the specified completion notification is other than a user-mode APC.
**WPUCompleteOverlappedRequest** is supported only for the socket handles created by
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle) and not for sockets created by a service provider directly.

If the client selects a user-mode APC as the notification method, the service provider should use
[WPUQueueApc](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuqueueapc) or another appropriate operating system function to perform the completion notification. If user-mode APC is not selected by the client, a service provider that does not implement IFS functionality directly cannot determine whether or not the client has associated a completion port with the socket handle. Thus, it cannot determine whether the completion notification method should be queuing a completion status record to a completion port or signaling an event found in the
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure. The Windows Socket 2 architecture keeps track of any completion port association with a socket created by
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle) and can make a correct decision between completion port-based notification or event-based notification.

When
**WPUCompleteOverlappedRequest** queues a completion indication, it sets the **InternalHigh** member of the
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure to the count of bytes transferred. Then, it sets the **Internal** member to some OS-dependent value other than the special value WSS_OPERATION_IN_PROGRESS. There may be some slight delay after
**WPUCompleteOverlappedRequest** returns before these values appear, since processing may occur asynchronously. However, the **InternalHigh** value (byte count) is guaranteed to be set by the time **Internal** is set.

**WPUCompleteOverlappedRequest** works as stated (performs the completion notification as requested by the client) whether or not the socket handle has been associated with a completion port.

**Interaction with WSPGetOverlappedResult**

The behavior of
**WPUCompleteOverlappedRequest** places some constraints on how a service provider implements
[WSPGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult) since only the **Offset** and **OffsetHigh** members of the
[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure are exclusively controlled by the service provider, yet three values (byte count, flags, and error) must be retrieved from the structure by
**WSPGetOverlappedResult**. A service provider may accomplish this any way it chooses as long as it interacts with the behavior of
**WPUCompleteOverlappedRequest** properly. However, a typical implementation is as follows:

- At the start of overlapped processing, the service provider sets **Internal** to WSS_OPERATION_IN_PROGRESS.
- When the I/O operation has been completed, the provider sets **OffsetHigh** to the Windows Socket 2 error code resulting from the operation, sets **Offset** to the flags resulting from the I/O operation, and calls
**WPUCompleteOverlappedRequest**, passing the transfer byte count as one of the parameters.
**WPUCompleteOverlappedRequest** eventually sets **InternalHigh** to the transfer byte count, then sets **Internal** to a value other than WSS_OPERATION_IN_PROGRESS.
- When
[WSPGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult) is called, the service provider checks **Internal**. If it is WSS_OPERATION_IN_PROGRESS, the provider waits on the event handle in the **hEvent** member or returns an error, based on the setting of the FWAIT flag of
**WSPGetOverlappedResult**. If not in progress, or after completion of waiting, the provider returns the values from **InternalHigh**, **OffsetHigh**, and **Offset** as the transfer count, operation result error code, and flags respectively.

## See also

[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle)

[WPUQueueApc](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuqueueapc)

[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped)

[WSPGetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspgetoverlappedresult)