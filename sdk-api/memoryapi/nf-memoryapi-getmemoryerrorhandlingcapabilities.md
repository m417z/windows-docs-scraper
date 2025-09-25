# GetMemoryErrorHandlingCapabilities function

## Description

Gets the memory error handling capabilities of the system.

## Parameters

### `Capabilities` [out]

A **PULONG** that receives one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **MEHC_PATROL_SCRUBBER_PRESENT**<br><br>1 | The hardware can detect and report failed memory. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that calls this function, define **_WIN32_WINNT** as
**_WIN32_WINNT_WIN8** or higher. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).