# DeletePrinter function

The **DeletePrinter** function deletes the specified printer object.

## Parameters

*hPrinter* \[in, out\]

Handle to a printer object that will be deleted. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

If there are print jobs remaining to be processed for the specified printer, **DeletePrinter** marks the printer for pending deletion, and then deletes it when all the print jobs have been printed. No print jobs can be added to a printer that is marked for pending deletion.

A printer marked for pending deletion cannot be held, but its print jobs can be held, resumed, and restarted. If the printer is held and there are jobs for the printer, **DeletePrinter** fails with ERROR\_ACCESS\_DENIED.

Note that **DeletePrinter** does not close the handle that is passed to it. Thus, the application must still call [**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter).

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

[**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

