# SetCommTimeouts function

## Description

Sets the time-out parameters for all read and write operations on a specified communications device.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpCommTimeouts` [in]

A pointer to a
[COMMTIMEOUTS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commtimeouts) structure that contains the new time-out values.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[COMMTIMEOUTS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commtimeouts)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[GetCommTimeouts](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommtimeouts)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)

[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)