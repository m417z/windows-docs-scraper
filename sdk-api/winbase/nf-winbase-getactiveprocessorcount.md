# GetActiveProcessorCount function

## Description

Returns the number of active processors in a processor group or in the system.

## Parameters

### `GroupNumber` [in]

The processor group number. If this parameter is ALL_PROCESSOR_GROUPS, the function returns the number of active processors in the system.

## Return value

If the function succeeds, the return value is the number of active processors in the specified group.

If the function fails, the return value is zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).