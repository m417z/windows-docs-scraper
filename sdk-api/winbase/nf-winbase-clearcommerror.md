# ClearCommError function

## Description

Retrieves information about a communications error and reports the current status of a communications device. The function is called when a communications error occurs, and it clears the device's error flag to enable additional input and output (I/O) operations.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpErrors` [out, optional]

A pointer to a variable that receives a mask indicating the type of error. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CE_BREAK**<br><br>0x0010 | The hardware detected a break condition. |
| **CE_FRAME**<br><br>0x0008 | The hardware detected a framing error. |
| **CE_OVERRUN**<br><br>0x0002 | A character-buffer overrun has occurred. The next character is lost. |
| **CE_RXOVER**<br><br>0x0001 | An input buffer overflow has occurred. There is either no room in the input buffer, or a character was received after the end-of-file (EOF) character. |
| **CE_RXPARITY**<br><br>0x0004 | The hardware detected a parity error. |

The following values are not supported:

### `lpStat` [out, optional]

A pointer to a
[COMSTAT](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-comstat) structure in which the device's status information is returned. If this parameter is **NULL**, no status information is returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a communications port has been set up with a **TRUE** value for the **fAbortOnError** member of the setup
[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb) structure, the communications software will terminate all read and write operations on the communications port when a communications error occurs. No new read or write operations will be accepted until the application acknowledges the communications error by calling the
**ClearCommError** function.

The
**ClearCommError** function fills the status buffer pointed to by the *lpStat* parameter with the current status of the communications device specified by the *hFile* parameter.

## See also

[COMSTAT](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-comstat)

[ClearCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommbreak)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb)