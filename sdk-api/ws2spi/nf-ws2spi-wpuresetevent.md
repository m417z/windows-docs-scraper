# WPUResetEvent function

## Description

The
**WPUResetEvent** function resets the state of the specified event object to nonsignaled. This call is safe for use within interrupt context.

## Parameters

### `hEvent` [in]

Handle that identifies an open event object.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, the
**WPUResetEvent** function returns the value **TRUE**. Otherwise, **FALSE** is returned, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *hEvent* parameter is not a valid event object handle. |

## See also

[WPUCloseEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucloseevent)

[WPUCreateEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucreateevent)

[WPUSetEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpusetevent)