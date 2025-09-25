# GetDefaultCommConfigW function

## Description

Retrieves the default configuration for the specified communications device.

## Parameters

### `lpszName` [in]

The name of the device. For example, COM1 through COM9 are serial ports and LPT1 through LPT9 are parallel ports.

### `lpCC` [out]

A pointer to a buffer that receives a
[COMMCONFIG](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commconfig) structure.

### `lpdwSize` [in, out]

A pointer to a variable that specifies the size of the buffer pointed to by *lpCC*, in bytes. Upon return, the variable contains the number of bytes copied if the function succeeds, or the number of bytes required if the buffer was too small.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[COMMCONFIG](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commconfig)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[SetDefaultCommConfig](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setdefaultcommconfiga)

## Remarks

> [!NOTE]
> The winbase.h header defines GetDefaultCommConfig as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).