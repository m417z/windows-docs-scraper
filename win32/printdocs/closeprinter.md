# ClosePrinter function

The **ClosePrinter** function closes the specified printer object.

## Parameters

*hPrinter* \[in\]

A handle to the printer object to be closed. This handle is returned by the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

When the **ClosePrinter** function returns, the handle *hPrinter* is invalid, regardless of whether the function has succeeded or failed.

## Examples

For a sample program that uses this function, see [How To: Print Using the GDI Print API](https://learn.microsoft.com/windows/win32/printdocs/how-to--print-using-the-gdi-print-api).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

