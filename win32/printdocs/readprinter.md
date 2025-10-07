# ReadPrinter function

The **ReadPrinter** function retrieves data from the specified printer.

## Parameters

*hPrinter* \[in\]

A handle to the printer object for which to retrieve data. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) function to retrieve a printer object handle. Use the format: Printername, Job xxxx.

*pBuf* \[out\]

A pointer to a buffer that receives the printer data.

*cbBuf* \[in\]

The size, in bytes, of the buffer to which *pBuf* points.

*pNoBytesRead* \[out\]

A pointer to a variable that receives the number of bytes of data copied into the array to which *pBuf* points.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

**ReadPrinter** returns an error if the device or the printer is not bidirectional.

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

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

