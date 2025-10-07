# GetPrinterDriverDirectory function

The **GetPrinterDriverDirectory** function retrieves the path of the printer-driver directory.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the printer driver resides. If this parameter is **NULL**, the local driver-directory path is retrieved.

*pEnvironment* \[in\]

A pointer to a null-terminated string that specifies the environment (for example, Windows x86, Windows IA64, or Windows x64). If this parameter is **NULL**, the current environment of the calling application and client machine (not of the destination application and print server) is used.

*Level* \[in\]

The structure level. This value must be 1.

*pDriverDirectory* \[out\]

A pointer to a buffer that receives the path.

*cbBuf* \[in\]

The size of the buffer to which *pDriverDirectory* points.

*pcbNeeded* \[out\]

A pointer to a value that specifies the number of bytes copied if the function succeeds, or the number of bytes required if *cbBuf* is too small.

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
| Unicode and ANSI names<br> | **GetPrinterDriverDirectoryW** (Unicode) and **GetPrinterDriverDirectoryA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver)

