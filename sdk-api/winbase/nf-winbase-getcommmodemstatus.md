# GetCommModemStatus function

## Description

Retrieves the modem control-register values.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpModemStat` [out]

A pointer to a variable that receives the current state of the modem control-register values. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MS_CTS_ON**<br><br>0x0010 | The CTS (clear-to-send) signal is on. |
| **MS_DSR_ON**<br><br>0x0020 | The DSR (data-set-ready) signal is on. |
| **MS_RING_ON**<br><br>0x0040 | The ring indicator signal is on. |
| **MS_RLSD_ON**<br><br>0x0080 | The RLSD (receive-line-signal-detect) signal is on. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**GetCommModemStatus** function is useful when you are using the
[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent) function to monitor the CTS, RLSD, DSR, or ring indicator signals. To detect when these signals change state, use
**WaitCommEvent** and then use
**GetCommModemStatus** to determine the state after a change occurs.

The function fails if the hardware does not support the control-register values.

## See also

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent)