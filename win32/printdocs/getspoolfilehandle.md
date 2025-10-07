# GetSpoolFileHandle function

The **GetSpoolFileHandle** function retrieves a handle for the spool file associated with the job currently submitted by the application.

## Parameters

*hPrinter* \[in\]

A handle to the printer to which the job was submitted. This should be the same handle that was used to submit the job. (Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.)

## Return value

If the function succeeds, it returns a handle to the spool file.

If the function fails, it returns **INVALID\_HANDLE\_VALUE**.

## Remarks

With the handle to the spool file, your application can write to the spool file with calls to [**WriteFile**](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) followed by [**CommitSpoolData**](https://learn.microsoft.com/windows/win32/printdocs/commitspooldata).

Your application must not call [**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter) on *hPrinter* until after it has accessed the spool file for the last time. Then it should call [**CloseSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/closespoolfilehandle) followed by **ClosePrinter**. Attempts to access the spool file handle after the original *hPrinter* has been closed will fail even if the file handle itself has not been closed. **CloseSpoolFileHandle** will itself fail if **ClosePrinter** is called first.

This function will fail if it is called before the print job has finished spooling.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | WinSpool.drv |
| Unicode and ANSI names<br> | **GetSpoolFileHandleW** (Unicode) and **GetSpoolFileHandleA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter)

[**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter)

[**CloseSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/closespoolfilehandle)

[**CommitSpoolData**](https://learn.microsoft.com/windows/win32/printdocs/commitspooldata)

