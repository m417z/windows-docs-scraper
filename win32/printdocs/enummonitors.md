# EnumMonitors function

The **EnumMonitors** function retrieves information about the port monitors installed on the specified server.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the monitors reside. If this parameter is **NULL**, the local monitors are enumerated.

*Level* \[in\]

The version of the structure pointed to by *pMonitors*.

This value can be 1 or 2.

*pMonitors* \[out\]

A pointer to a buffer that receives an array of structures. The buffer must be large enough to store the strings referenced by the structure members.

To determine the required buffer size, call **EnumMonitors** with *cbBuf* set to zero. **EnumMonitors** fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_INSUFFICIENT\_BUFFER, and the *pcbNeeded* parameter returns the size, in bytes, of the buffer required to hold the array of structures and their data.

The buffer receives an array of [**MONITOR\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/monitor-info-1) structures if *Level* is 1, or [**MONITOR\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/monitor-info-2) structures if *Level* is 2.

*cbBuf* \[in\]

The size, in bytes, of the buffer pointed to by *pMonitors*.

*pcbNeeded* \[out\]

A pointer to a variable that receives the number of bytes copied if the function succeeds or the number of bytes required if *cbBuf* is too small.

*pcReturned* \[out\]

A pointer to a variable that receives the number of structures that were returned in the buffer pointed to by *pMonitors*.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **EnumMonitorsW** (Unicode) and **EnumMonitorsA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**MONITOR\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/monitor-info-1)

[**MONITOR\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/monitor-info-2)

