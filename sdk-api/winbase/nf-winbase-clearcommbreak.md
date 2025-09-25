# ClearCommBreak function

## Description

Restores character transmission for a specified communications device and places the transmission line in a nonbreak state.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A communications device is placed in a break state by the
[SetCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommbreak) or
[EscapeCommFunction](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-escapecommfunction) function. Character transmission is then suspended until the break state is cleared by calling
**ClearCommBreak**.

## See also

[ClearCommError](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommerror)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[EscapeCommFunction](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-escapecommfunction)

[SetCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommbreak)