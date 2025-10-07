# CloseSpoolFileHandle function

The **CloseSpoolFileHandle** function closes a handle to a spool file associated with the print job currently submitted by the application.

## Parameters

*hPrinter* \[in\]

A handle to the printer to which the job was submitted. This should be the same handle that was used to obtain *hSpoolFile* with [**GetSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/getspoolfilehandle).

*hSpoolFile* \[in\]

A handle to the spool file being closed. If [**CommitSpoolData**](https://learn.microsoft.com/windows/win32/printdocs/commitspooldata) has not been called since [**GetSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/getspoolfilehandle) was called, then this should be the same handle that was returned by **GetSpoolFileHandle**. Otherwise, it should be the handle that was returned by the most recent call to **CommitSpoolData**.

## Return value

**TRUE**, if it succeeds, **FALSE** otherwise.

## Remarks

Your application must not call [**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter) on *hPrinter* until after it has accessed the spool file for the last time. Then it should call **CloseSpoolFileHandle** followed by **ClosePrinter**. Attempts to access the spool file handle after the original *hPrinter* has been closed will fail even if the file handle itself has not been closed. **CloseSpoolFileHandle** will fail if **ClosePrinter** is called first.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | WinSpool.drv |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter)

[**GetSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/getspoolfilehandle)

