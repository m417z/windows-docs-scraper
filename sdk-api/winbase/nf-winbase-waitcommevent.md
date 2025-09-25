# WaitCommEvent function

## Description

Waits for an event to occur for a specified communications device. The set of events that are monitored by this function is contained in the event mask associated with the device handle.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpEvtMask` [out]

A pointer to a variable that receives a mask indicating the type of event that occurred. If an error occurs, the value is zero; otherwise, it is one of the following values.

| Value | Meaning |
| --- | --- |
| **EV_BREAK**<br><br>0x0040 | A break was detected on input. |
| **EV_CTS**<br><br>0x0008 | The CTS (clear-to-send) signal changed state. |
| **EV_DSR**<br><br>0x0010 | The DSR (data-set-ready) signal changed state. |
| **EV_ERR**<br><br>0x0080 | A line-status error occurred. Line-status errors are **CE_FRAME**, **CE_OVERRUN**, and **CE_RXPARITY**. |
| **EV_RING**<br><br>0x0100 | A ring indicator was detected. |
| **EV_RLSD**<br><br>0x0020 | The RLSD (receive-line-signal-detect) signal changed state. |
| **EV_RXCHAR**<br><br>0x0001 | A character was received and placed in the input buffer. |
| **EV_RXFLAG**<br><br>0x0002 | The event character was received and placed in the input buffer. The event character is specified in the device's [DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure, which is applied to a serial port by using the [SetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommstate) function. |
| **EV_TXEMPTY**<br><br>0x0004 | The last character in the output buffer was sent. |

### `lpOverlapped` [in]

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. This structure is required if *hFile* was opened with **FILE_FLAG_OVERLAPPED**.

If *hFile* was opened with **FILE_FLAG_OVERLAPPED**, the *lpOverlapped* parameter must not be **NULL**. It must point to a valid [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. If *hFile* was opened with **FILE_FLAG_OVERLAPPED** and *lpOverlapped* is **NULL**, the function can incorrectly report that the operation is complete.

If *hFile* was opened with **FILE_FLAG_OVERLAPPED** and *lpOverlapped* is not **NULL**,
**WaitCommEvent** is performed as an overlapped operation. In this case, the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure must contain a handle to a manual-reset event object (created by using the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function).

If *hFile* was not opened with **FILE_FLAG_OVERLAPPED**,
**WaitCommEvent** does not return until one of the specified events or an error occurs.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**WaitCommEvent** function monitors a set of events for a specified communications resource. To set and query the current event mask of a communications resource, use the
[SetCommMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommmask) and
[GetCommMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommmask) functions.

If the overlapped operation cannot be completed immediately, the function returns **FALSE** and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_IO_PENDING**, indicating that the operation is executing in the background. When this happens, the system sets the **hEvent** member of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure to the not-signaled state before
**WaitCommEvent** returns, and then it sets it to the signaled state when one of the specified events or an error occurs. The calling process can use one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions) to determine the event object's state and then use the [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function to determine the results of the
**WaitCommEvent** operation.
**GetOverlappedResult** reports the success or failure of the operation, and the variable pointed to by the *lpEvtMask* parameter is set to indicate the event that occurred.

If a process attempts to change the device handle's event mask by using the
[SetCommMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommmask) function while an overlapped
**WaitCommEvent** operation is in progress,
**WaitCommEvent** returns immediately. The variable pointed to by the *lpEvtMask* parameter is set to zero.

#### Examples

For an example, see
[Monitoring Communications Events](https://learn.microsoft.com/windows/desktop/DevIO/monitoring-communications-events).

## See also

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb)

[GetCommMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommmask)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[SetCommMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommmask)

[SetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommstate)