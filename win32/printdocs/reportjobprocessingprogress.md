# ReportJobProcessingProgress function

Reports to the Print Spooler service whether an XPS print job is in the spooling or the rendering phase and what part of the processing is currently underway.

## Parameters

*printerHandle* \[in\]

A printer handle for which the function is to retrieve information. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*jobId* \[in\]

Identifies the print job for which to retrieve data. Use the [**AddJob**](https://learn.microsoft.com/windows/win32/printdocs/addjob) function or [**StartDoc**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-startdoca) function to get a print job identifier.

*jobOperation*

Specifies whether the job is in the spooling phase or the rendering phase.

*jobProgress*

Specifies what part of the processing is currently underway. This value refers to events in either the spooling or rendering phase depending on the value of *jobOperation*.

## Return value

If the operation succeeds, the return value is S\_OK, otherwise the **HRESULT** will contain an error code.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/win32/com/error-handling-in-com).

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

> [!Note]
> **ReportJobProcessingProgress** will only report the progress of the XPS print job if the print job is in the spooling or rendering phase. **ReportJobProcessingProgress** will fail if it is called when the XPS print job is not in the spooling or rendering phase.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**EPrintXPSJobOperation**](https://learn.microsoft.com/windows/win32/printdocs/eprintxpsjoboperation)

[**EPrintXPSJobProgress**](https://learn.microsoft.com/windows/win32/printdocs/eprintxpsjobprogress)

