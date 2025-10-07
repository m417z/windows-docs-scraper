# DeletePrinterDataEx function

The **DeletePrinterDataEx** function deletes a specified value from the configuration data for a printer. A printer's configuration data consists of a set of named and typed values stored in a hierarchy of registry keys. The function deletes a specified value under a specified key.

Like the [**DeletePrinterData**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdata) function, **DeletePrinterDataEx** can delete values stored by the [**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata) function. In addition, **DeletePrinterDataEx** can delete values stored under a specified key by the [**SetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex) function.

## Parameters

*hPrinter* \[in\]

A handle to the printer for which the function deletes a value. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pKeyName* \[in\]

A pointer to a null-terminated string that specifies the key containing the value to delete. Use the backslash ( \\ ) character as a delimiter to specify a path that has one or more subkeys.

If *pKeyName* is **NULL** or an empty string, **DeletePrinterDataEx** returns ERROR\_INVALID\_PARAMETER.

*pValueName* \[in\]

A pointer to a null-terminated string that specifies the name of the value to delete.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a system error code.

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
| Unicode and ANSI names<br> | **DeletePrinterDataExW** (Unicode) and **DeletePrinterDataExA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**DeletePrinterKey**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterkey)

[**EnumPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdataex)

[**EnumPrinterKey**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterkey)

[**GetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdataex)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex)

