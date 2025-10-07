# AddPrintProcessor function

The **AddPrintProcessor** function installs a print processor on the specified server and adds the print-processor name to the list of supported print processors.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the print processor should be installed. If this parameter is **NULL**, the print processor is installed locally.

*pEnvironment* \[in\]

A pointer to a null-terminated string that specifies the environment (for example, Windows x86, Windows IA64, or Windows x64). If this parameter is **NULL**, the current environment of the caller/client (not of the destination/server) is used.

*pPathName* \[in\]

A pointer to a null-terminated string that specifies the name of the file that contains the print processor. This file must be in the system print-processor directory.

*pPrintProcessorName* \[in\]

A pointer to a null-terminated string that specifies the name of the print processor.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The caller must have the [SeLoadDriverPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

Before calling the **AddPrintProcessor** function, an application should verify that the file containing the print processor is stored in the system print-processor directory. An application can retrieve the name of the system print-processor directory by calling the [**GetPrintProcessorDirectory**](https://learn.microsoft.com/windows/win32/printdocs/getprintprocessordirectory) function.

An application can determine the name of existing print processors by calling the [**EnumPrintProcessors**](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessors) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **AddPrintProcessorW** (Unicode) and **AddPrintProcessorA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**EnumPrintProcessors**](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessors)

[**GetPrintProcessorDirectory**](https://learn.microsoft.com/windows/win32/printdocs/getprintprocessordirectory)

