# WPUCloseThread function

## Description

The
**WPUCloseThread** function closes a thread opened with a call to
[WPUOpenCurrentThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuopencurrentthread).

## Parameters

### `lpThreadId` [in]

Pointer to a
[WSATHREADID](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsathreadid) structure that identifies the thread context. This structure must have been initialized by a previous call to
[WPUOpenCurrentThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuopencurrentthread).

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
[WPUOpenCurrentThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuopencurrentthread) returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup) call must occur before using this function. |

## Remarks

The
**WPUCloseThread** function is used in a layered service provider to deallocate the resources that were initiated in a call by the
[WPUOpenCurrentThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuopencurrentthread) function. The
[WSATHREADID](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsathreadid) structure in the *lpThreadId* is the thread to deallocate.

Every call to
[WPUOpenCurrentThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuopencurrentthread) must have a call to
**WPUCloseThread**. These two functions are used when the overlapped functions, such as
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend), are called in a lower layer of the service provider than the current thread.

## See also

[WPUOpenCurrentThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuopencurrentthread)

[WSATHREADID](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsathreadid)