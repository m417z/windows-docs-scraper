# CommitSpoolData function

The **CommitSpoolData** function notifies the print spooler that a specified amount of data has been written to a specified spool file and is ready to be rendered.

## Parameters

*hPrinter* \[in\]

A handle to the printer to which the job was submitted. This should be the same handle that was used to obtain *hSpoolFile* with [**GetSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/getspoolfilehandle).

*hSpoolFile* \[in\]

A handle to the spool file being changed. On the first call of **CommitSpoolData**, this should be the same handle that was returned by [**GetSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/getspoolfilehandle). Subsequent calls to **CommitSpoolData** should pass the handle returned by the preceding call. See Remarks.

*cbCommit*

The number of bytes committed to the print spooler.

## Return value

If the function succeeds, it returns a handle to the spool file.

If the function fails, it returns INVALID\_HANDLE\_VALUE.

## Remarks

Applications submitting a spooler print job can call [**GetSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/getspoolfilehandle) and then directly write data to the spool file handle by calling [**WriteFile**](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile). To notify the print spooler that the file contains data which is ready to be rendered, the application must call **CommitSpoolData** and provide the number of available bytes.

If **CommitSpoolData** is called multiple times, each call must use the spool file handle returned by the previous call. When no more data will be written to the spool file, [**CloseSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/closespoolfilehandle) should be called for the file handle returned by the last call to **CommitSpoolData**.

Before calling **CommitSpoolData**, applications must set the file pointer to the position it had before it wrote data to the file. In the process of rendering the data in the spooler file, the print spooler will move the spool file pointer *cbCommit* bytes from the current value of file pointer.

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

[**GetSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/getspoolfilehandle)

[**CloseSpoolFileHandle**](https://learn.microsoft.com/windows/win32/printdocs/closespoolfilehandle)

