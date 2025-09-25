# WPUCloseEvent function

## Description

The
**WPUCloseEvent** function closes an open event object handle.

## Parameters

### `hEvent` [in]

Handle to an open event object.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If the function succeeds, the return value is **TRUE**. Otherwise, the return value is **FALSE** and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *hEvent* parameter is not a valid event object handle. |

## See also

[WPUCreateEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucreateevent)