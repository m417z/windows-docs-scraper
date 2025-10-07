# AddPrinterConnection function

The **AddPrinterConnection** function adds a connection to the specified printer for the current user.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of a printer to which the current user wishes to establish a connection.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

When Windows makes a connection to a printer, it may need to copy printer driver files to the server to which the printer is attached. If the user does not have permission to copy files to the appropriate location, the **AddPrinterConnection** function fails, and [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_ACCESS\_DENIED.

A printer connection established by calling **AddPrinterConnection** will be enumerated when [**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters) is called with *dwType* set to PRINTER\_ENUM\_CONNECTION.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **AddPrinterConnectionW** (Unicode) and **AddPrinterConnectionA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**ConnectToPrinterDlg**](https://learn.microsoft.com/windows/win32/printdocs/connecttoprinterdlg)

[**DeletePrinterConnection**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterconnection)

[**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters)

