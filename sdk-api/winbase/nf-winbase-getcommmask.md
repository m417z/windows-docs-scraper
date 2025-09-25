# GetCommMask function

## Description

Retrieves the value of the event mask for a specified communications device.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpEvtMask` [out]

A pointer to the variable that receives a mask of events that are currently enabled. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **EV_BREAK**<br><br>0x0040 | A break was detected on input. |
| **EV_CTS**<br><br>0x0008 | The CTS (clear-to-send) signal changed state. |
| **EV_DSR**<br><br>0x0010 | The DSR (data-set-ready) signal changed state. |
| **EV_ERR**<br><br>0x0080 | A line-status error occurred. Line-status errors are **CE_FRAME**, **CE_OVERRUN**, and **CE_RXPARITY**. |
| **EV_EVENT1**<br><br>0x0800 | An event of the first provider-specific type occurred. |
| **EV_EVENT2**<br><br>0x1000 | An event of the second provider-specific type occurred. |
| **EV_PERR**<br><br>0x0200 | A printer error occurred. |
| **EV_RING**<br><br>0x0100 | A ring indicator was detected. |
| **EV_RLSD**<br><br>0x0020 | The RLSD (receive-line-signal-detect) signal changed state. |
| **EV_RX80FULL**<br><br>0x0400 | The receive buffer is 80 percent full. |
| **EV_RXCHAR**<br><br>0x0001 | A character was received and placed in the input buffer. |
| **EV_RXFLAG**<br><br>0x0002 | The event character was received and placed in the input buffer. The event character is specified in the device's [DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure, which is applied to a serial port by using the [SetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommstate) function. |
| **EV_TXEMPTY**<br><br>0x0004 | The last character in the output buffer was sent. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**GetCommMask** function uses a mask variable to indicate the set of events that can be monitored for a particular communications resource. A handle to the communications resource can be specified in a call to the
[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent) function, which waits for one of the events to occur. To modify the event mask of a communications resource, use the
[SetCommMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommmask) function.

## See also

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb)

[SetCommMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommmask)

[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent)