# DeletePrinterKey function

The **DeletePrinterKey** function deletes a specified key and all its subkeys for a specified printer.

## Parameters

*hPrinter* \[in\]

A handle to the printer for which the function deletes a key. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pKeyName* \[in\]

A pointer to a null-terminated string that specifies the key to delete. Use the backslash ( \\ ) character as a delimiter to specify a path with one or more subkeys.

If *pKeyName* is an empty string (""), **DeletePrinterKey** deletes all keys below the top-level key for the printer. If *pKeyName* is **NULL**, **DeletePrinterKey** returns ERROR\_INVALID\_PARAMETER.

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
| Unicode and ANSI names<br> | **DeletePrinterKeyW** (Unicode) and **DeletePrinterKeyA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**DeletePrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdataex)

[**EnumPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdataex)

[**EnumPrinterKey**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterkey)

[**GetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdataex)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex)

