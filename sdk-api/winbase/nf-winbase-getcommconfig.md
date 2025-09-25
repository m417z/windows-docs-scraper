# GetCommConfig function

## Description

Retrieves the current configuration of a communications device.

To retrieve the default configuration settings from the device manager, use the [GetDefaultCommConfig](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getdefaultcommconfiga) function.

## Parameters

### `hCommDev` [in]

A handle to the open communications device. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `lpCC` [out]

A pointer to a buffer that receives a
[COMMCONFIG](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commconfig) structure.

### `lpdwSize` [in, out]

The size, in bytes, of the buffer pointed to by *lpCC*. When the function returns, the variable contains the number of bytes copied if the function succeeds, or the number of bytes required if the buffer was too small.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[COMMCONFIG](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commconfig)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[GetDefaultCommConfig](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getdefaultcommconfiga)

[SetCommConfig](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommconfig)