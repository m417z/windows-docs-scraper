# ResetPrinter function

The **ResetPrinter** function specifies the data type and device mode values to be used for printing documents submitted by the [**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter) function. These values can be overridden by using the [**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob) function after document printing has started.

## Parameters

*hPrinter* \[in\]

Handle to the printer. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pDefault* \[in\]

Pointer to a [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure.

The **ResetPrinter** function ignores the **DesiredAccess** member of the [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure. Set that member to zero.

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
| Unicode and ANSI names<br> | **ResetPrinterW** (Unicode) and **ResetPrinterA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults)

[**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter)

[**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob)

