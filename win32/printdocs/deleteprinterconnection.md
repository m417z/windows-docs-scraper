# DeletePrinterConnection function

The **DeletePrinterConnection** function deletes a connection to a printer that was established by a call to [**AddPrinterConnection**](https://learn.microsoft.com/windows/win32/printdocs/addprinterconnection) or [**ConnectToPrinterDlg**](https://learn.microsoft.com/windows/win32/printdocs/connecttoprinterdlg).

## Parameters

*pName* \[in\]

Pointer to a null-terminated string that specifies the name of the printer connection to delete.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The **DeletePrinterConnection** function does not delete any printer driver files that were copied to the server to which the printer is attached.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **DeletePrinterConnectionW** (Unicode) and **DeletePrinterConnectionA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinterConnection**](https://learn.microsoft.com/windows/win32/printdocs/addprinterconnection)

[**AddPrinterConnection2**](https://learn.microsoft.com/windows/win32/printdocs/addprinterconnection2)

[**ConnectToPrinterDlg**](https://learn.microsoft.com/windows/win32/printdocs/connecttoprinterdlg)

