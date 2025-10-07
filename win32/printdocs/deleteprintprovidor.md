# DeletePrintProvidor function

The **DeletePrintProvidor** function removes a print provider added by the [**AddPrintProvidor**](https://learn.microsoft.com/windows/win32/printdocs/addprintprovidor) function.

## Parameters

*pName* \[in\]

Reserved; must be **NULL**.

*pEnvironment* \[in\]

A pointer to a null-terminated string that specifies the environment from which the provider is to be removed (for example, Windows NT x86, Windows IA64, or Windows x64). If this parameter is **NULL**, the provider is removed from the current environment of the calling application and client machine (not of the destination application and print server). **NULL** is the recommended value because it provides maximum portability.

*pPrintProviderName* \[in\]

A pointer to a null-terminated string that specifies the name of the provider to be removed.

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
| Unicode and ANSI names<br> | **DeletePrintProvidorW** (Unicode) and **DeletePrintProvidorA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrintProvidor**](https://learn.microsoft.com/windows/win32/printdocs/addprintprovidor)

