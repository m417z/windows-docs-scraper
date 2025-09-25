# WPUSetEvent function

## Description

The
**WPUSetEvent** function sets the state of the specified event object to signaled. This call is safe for use within interrupt context.

## Parameters

### `hEvent` [in]

Handle that identifies an open event object.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, the
**WPUSetEvent** function returns the value **TRUE**. Otherwise, **FALSE** is returned, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The *hEvent* parameter is not a valid event object handle. |

## See also

[WPUCloseEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucloseevent)

[WPUCreateEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucreateevent)

[WPUResetEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpuresetevent)