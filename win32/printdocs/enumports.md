# EnumPorts function

The **EnumPorts** function enumerates the ports that are available for printing on a specified server.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server whose printer ports you want to enumerate.

If *pName* is **NULL**, the function enumerates the local machine's printer ports.

*Level* \[in\]

The type of information returned in the *pPorts* buffer. If *Level* is 1, *pPorts* receives an array of [**PORT\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/port-info-1) structures. If *Level* is 2, *pPorts* receives an array of [**PORT\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/port-info-2) structures.

*pPorts* \[out\]

A pointer to a buffer that receives an array of [**PORT\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/port-info-1) or [**PORT\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/port-info-2) structures. Each structure contains data that describes an available printer port. The buffer must be large enough to store the strings pointed to by the structure members.

To determine the required buffer size, call **EnumPorts** with *cbBuf* set to zero. **EnumPorts** fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_INSUFFICIENT\_BUFFER, and the *pcbNeeded* parameter returns the size, in bytes, of the buffer required to hold the array of structures and their data.

*cbBuf* \[in\]

The size, in bytes, of the buffer pointed to by *pPorts*.

*pcbNeeded* \[out\]

A pointer to a variable that receives the number of bytes copied to the *pPorts* buffer. If the buffer is too small, the function fails and the variable receives the number of bytes required.

*pcReturned* \[out\]

A pointer to a variable that receives the number of [**PORT\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/port-info-1) or [**PORT\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/port-info-2) structures returned in the *pPorts* buffer. This is the number of printer ports that are available on the specified server.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The **EnumPorts** function can succeed even if the server specified by *pName* does not have a printer defined.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **EnumPortsW** (Unicode) and **EnumPortsA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPort**](https://learn.microsoft.com/windows/win32/printdocs/addport)

[**DeletePort**](https://learn.microsoft.com/windows/win32/printdocs/deleteport)

[**PORT\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/port-info-1)

[**PORT\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/port-info-2)

