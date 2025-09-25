# WPUOpenCurrentThread function

## Description

The
**WPUOpenCurrentThread** function opens a handle to the current thread that can be used with overlapped functions in a layered service provider. This is intended to be used by layered service providers that wish to initiate overlapped I/O from nonapplication threads.

## Parameters

### `lpThreadId` [out]

Pointer to a
[WSATHREADID](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsathreadid) structure that can then be passed to an overlapped function.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WPUOpenCurrentThread** returns the zero. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup) call must occur before using this function. |

## Remarks

The
**WPUOpenCurrentThread** function provides a pointer to a
[WSATHREADID](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsathreadid) structure that can then be passed to an overlapped function such as
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) or
[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv). Layered service providers using a private thread in one of the upper layers will use
**WPUOpenCurrentThread** to pass a
**WSATHREADID** pointer to the lower layer that is administering overlapped functions.

Overlapped functions such as
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) and
[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) can then be used in the same way as a regular service provider.

Every call to
**WPUOpenCurrentThread** must have a corresponding call to
[WPUCloseThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuclosethread).

## See also

[WPUCloseThread](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuclosethread)

[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)

[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)