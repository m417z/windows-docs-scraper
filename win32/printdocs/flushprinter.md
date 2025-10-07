# FlushPrinter function

The **FlushPrinter** function sends a buffer to the printer in order to clear it from a transient state.

## Parameters

*hPrinter* \[in\]

A handle to the printer object. This should be the same handle that was used, in a prior [**WritePrinter**](https://learn.microsoft.com/windows/win32/printdocs/writeprinter) call, by the printer driver.

*pBuf* \[in\]

A pointer to an array of bytes that contains the data to be written to the printer.

*cbBuf* \[in\]

The size, in bytes, of the array pointed to by *pBuf*.

*pcWritten* \[out\]

A pointer to a value that receives the number of bytes of data that were written to the printer.

*cSleep* \[in\]

The time, in milliseconds, for which the I/O line to the printer port should be kept idle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

**FlushPrinter** should be called only if [**WritePrinter**](https://learn.microsoft.com/windows/win32/printdocs/writeprinter) failed, leaving the printer in a transient state. For example, the printer could get into a transient state when the job gets aborted and the printer driver has partially sent some raw data to the printer.

**FlushPrinter** also can specify an idle period during which the print spooler does not schedule any jobs to the corresponding printer port.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**WritePrinter**](https://learn.microsoft.com/windows/win32/printdocs/writeprinter)

