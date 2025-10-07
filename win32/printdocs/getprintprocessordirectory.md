# GetPrintProcessorDirectory function

The **GetPrintProcessorDirectory** function retrieves the path to the print processor directory on the specified server.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server. If this parameter is **NULL**, a local path is returned.

*pEnvironment* \[in\]

A pointer to a null-terminated string that specifies the environment (for example, Windows x86, Windows IA64, or Windows x64). If this parameter is **NULL**, the current environment of the calling application and client machine (not of the destination application and print server) is used.

*Level* \[in\]

The structure level. This value must be 1.

*pPrintProcessorInfo* \[out\]

A pointer to a buffer that receives the path. Note that, for operating systems prior to Windows Server 2003 SP 1, the path is in the local format for the server, not the true remote format. For example, the path is given as "%Windir%\\System32\\Spool\\Prtprocs\\%Environment%" instead of "\\\\ServerName\\Print$\\Prtprocs\\%Environment%", even when called for a remote server. For the operating systems Windows Server 2003 SP 1 and later, the true remote path is returned.

*cbBuf* \[in\]

The size of the buffer pointed to by *pPrintProcessorInfo*.

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
| Unicode and ANSI names<br> | **GetPrintProcessorDirectoryW** (Unicode) and **GetPrintProcessorDirectoryA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrintProcessor**](https://learn.microsoft.com/windows/win32/printdocs/addprintprocessor)

