# DeletePrinterData function

The **DeletePrinterData** function deletes specified configuration data for a printer. A printer's configuration data consists of a set of named and typed values. The **DeletePrinterData** function deletes one of these values, specified by its value name.

Calling **DeletePrinterData** is equivalent to calling the [**DeletePrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdataex) function with the *pKeyName* parameter set to "PrinterDriverData".

## Parameters

*hPrinter* \[in\]

A handle to the printer whose configuration data is to be deleted. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pValueName* \[in\]

A pointer to the null-terminated name of the configuration data value to be deleted.

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
| Unicode and ANSI names<br> | **DeletePrinterDataW** (Unicode) and **DeletePrinterDataA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**EnumPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdata)

[**GetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata)

