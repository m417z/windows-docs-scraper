# EnumPrintProcessors function

The **EnumPrintProcessors** function enumerates the print processors installed on the specified server.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the print processors reside. If this parameter is **NULL**, the local print processors are enumerated.

*pEnvironment* \[in\]

A pointer to a null-terminated string that specifies the environment (for example, Windows x86, Windows IA64, or Windows x64). If this parameter is **NULL**, the current environment of the calling application and client machine (not of the destination application and print server) is used.

*Level* \[in\]

The type of information returned in the *pPrintProcessorInfo* buffer. This parameter must be 1.

*pPrintProcessorInfo* \[out\]

A pointer to a buffer that receives an array of [**PRINTPROCESSOR\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/printprocessor-info-1) structures. Each structure describes an available print processor. The buffer must be large enough to receive the array of structures and any strings to which the structure members point.

To determine the required buffer size, call **EnumPrintProcessors** with *cbBuf* set to zero. **EnumPrintProcessors** fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_INSUFFICIENT\_BUFFER, and the *pcbNeeded* parameter returns the size, in bytes, of the buffer required to hold the array of structures and their data.

*cbBuf* \[in\]

The size, in bytes, of the buffer pointed to by *pPrintProcessorInfo*.

*pcbNeeded* \[out\]

A pointer to a variable that receives the number of bytes copied to the *pPrintProcessorInfo* buffer if the function succeeds. If the buffer is too small, the function fails and the variable receives the number of bytes required.

*pcReturned* \[out\]

A pointer to a variable that receives the number of structures returned in the *pPrintProcessorInfo* buffer.

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
| Unicode and ANSI names<br> | **EnumPrintProcessorsW** (Unicode) and **EnumPrintProcessorsA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrintProcessor**](https://learn.microsoft.com/windows/win32/printdocs/addprintprocessor)

[**EnumPrintProcessorDatatypes**](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessordatatypes)

[**PRINTPROCESSOR\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/printprocessor-info-1)

