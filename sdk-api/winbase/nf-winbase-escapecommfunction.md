# EscapeCommFunction function

## Description

Directs the specified communications device to perform an extended function.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `dwFunc` [in]

The extended function to be performed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CLRBREAK**<br><br>9 | Restores character transmission and places the transmission line in a nonbreak state. The CLRBREAK extended function code is identical to the [ClearCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommbreak) function. |
| **CLRDTR**<br><br>6 | Clears the DTR (data-terminal-ready) signal. |
| **CLRRTS**<br><br>4 | Clears the RTS (request-to-send) signal. |
| **SETBREAK**<br><br>8 | Suspends character transmission and places the transmission line in a break state until the [ClearCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommbreak) function is called (or **EscapeCommFunction** is called with the CLRBREAK extended function code). The SETBREAK extended function code is identical to the [SetCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommbreak) function. Note that this extended function does not flush data that has not been transmitted. |
| **SETDTR**<br><br>5 | Sends the DTR (data-terminal-ready) signal. |
| **SETRTS**<br><br>3 | Sends the RTS (request-to-send) signal. |
| **SETXOFF**<br><br>1 | Causes transmission to act as if an XOFF character has been received. |
| **SETXON**<br><br>2 | Causes transmission to act as if an XON character has been received. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[ClearCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommbreak)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[SetCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommbreak)