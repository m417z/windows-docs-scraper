# ScheduleJob function

The **ScheduleJob** function requests that the print spooler schedule a specified print job for printing.

## Parameters

*hPrinter* \[in\]

A handle to the printer for the print job. This must be a local printer that is configured as a spooled printer. If *hPrinter* is a handle to a remote printer connection, or if the printer is configured for direct printing, the **ScheduleJob** function fails. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*hPrinter* must be the same printer handle specified in the call to [**AddJob**](https://learn.microsoft.com/windows/win32/printdocs/addjob) that obtained the *dwJobID* print job identifier.

*dwJobID* \[in\]

The print job to be scheduled. You obtain this print job identifier by calling the [**AddJob**](https://learn.microsoft.com/windows/win32/printdocs/addjob) function.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

You must successfully call the [**AddJob**](https://learn.microsoft.com/windows/win32/printdocs/addjob) function before calling the **ScheduleJob** function. **AddJob** obtains the print job identifier that you pass to **ScheduleJob** as *dwJobID*. Both calls must use the same value for *hPrinter*.

The **ScheduleJob** function checks for a valid spool file. If there is an invalid spool file, or if it is empty, **ScheduleJob** deletes both the spool file and the corresponding print job entry in the print spooler.

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

[**AddJob**](https://learn.microsoft.com/windows/win32/printdocs/addjob)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

