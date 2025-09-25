# GetCommTimeouts function

## Description

Retrieves the time-out parameters for all read and write operations on a specified communications device.

## Parameters

### `hFile` [in]

A handle to the communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpCommTimeouts` [out]

A pointer to a
[COMMTIMEOUTS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commtimeouts) structure in which the time-out information is returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information about time-out values for communications devices, see the
[SetCommTimeouts](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommtimeouts) function.

## See also

[COMMTIMEOUTS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commtimeouts)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[SetCommTimeouts](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommtimeouts)