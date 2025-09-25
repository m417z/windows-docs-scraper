# WPUCloseSocketHandle function

## Description

The
**WPUCloseSocketHandle** function closes an existing socket handle.

## Parameters

### `s` [in]

Handle to socket created with
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle).

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle) returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket created by [WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle). |

## Remarks

The
**WPUCloseSocketHandle** function closes an existing socket handle created by
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle). This function removes the socket from Ws2_32.dll's internal socket table. The owning service provider is responsible for releasing any resources associated with the socket.

## See also

[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle)