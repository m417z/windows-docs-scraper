# WPUCreateEvent function

## Description

The
**WPUCreateEvent** function creates a new event object.

## Parameters

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WPUCreateEvent** function returns the handle of the event object.

Otherwise, the return value is WSA_INVALID_EVENT and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough free memory available to create the event object. |

## Remarks

The event object created by this function is manually reset with an initial state of nonsignaled. If a Windows service provider requires auto reset events, it can call the Windows [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function directly.

## See also

[WPUCloseEvent](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpucloseevent)