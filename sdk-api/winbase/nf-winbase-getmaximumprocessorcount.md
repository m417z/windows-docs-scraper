# GetMaximumProcessorCount function

## Description

Returns the maximum number of logical processors that a processor group or the system can have.

## Parameters

### `GroupNumber` [in]

The processor group number. If this parameter is ALL_PROCESSOR_GROUPS, the function returns the maximum number of processors that the system can have.

## Return value

If the function succeeds, the return value is the maximum number of processors that the specified group can have.

If the function fails, the return value is zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).