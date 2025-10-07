# EndDocPrinter function

The **EndDocPrinter** function ends a print job for the specified printer.

## Parameters

*hPrinter* \[in\]

Handle to a printer for which the print job should be ended. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The **EndDocPrinter** function returns an error if the print job was not started by calling the [**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter) function.

The sequence for a print job is as follows:

1. To begin a print job, call [**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter).
2. To begin each page, call [**StartPagePrinter**](https://learn.microsoft.com/windows/win32/printdocs/startpageprinter).
3. To write data to a page, call [**WritePrinter**](https://learn.microsoft.com/windows/win32/printdocs/writeprinter).
4. To end each page, call [**EndPagePrinter**](https://learn.microsoft.com/windows/win32/printdocs/endpageprinter).
5. Repeat 2, 3, and 4 for as many pages as necessary.
6. To end the print job, call **EndDocPrinter**.

When a page in a spooled file exceeds approximately 350 MB, it may fail to print and not send an error message. For example, this can occur when printing large EMF files. The page size limit depends on many factors including the amount of virtual memory available, the amount of memory allocated by calling processes, and the amount of fragmentation in the process heap.

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

[**EndPagePrinter**](https://learn.microsoft.com/windows/win32/printdocs/endpageprinter)

[**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter)

[**StartPagePrinter**](https://learn.microsoft.com/windows/win32/printdocs/startpageprinter)

[**WritePrinter**](https://learn.microsoft.com/windows/win32/printdocs/writeprinter)

