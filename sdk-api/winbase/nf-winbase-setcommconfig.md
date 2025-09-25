# SetCommConfig function

## Description

Sets the current configuration of a communications device.

## Parameters

### `hCommDev` [in]

A handle to the open communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpCC` [in]

A pointer to a
[COMMCONFIG](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commconfig) structure.

### `dwSize` [in]

The size of the structure pointed to by *lpCC*, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[COMMCONFIG](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commconfig)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[GetCommConfig](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommconfig)