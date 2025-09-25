# SetCommBreak function

## Description

Suspends character transmission for a specified communications device and places the transmission line in a break state until the
[ClearCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommbreak) function is called.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[ClearCommBreak](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommbreak)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)