# AddPrinterConnection2 function

Adds a connection to the specified printer for the current user and specifies connection details.

## Parameters

*hWnd* \[in\]

A handle to the parent window in which the dialog box will be displayed if the print system must download a printer driver from the print server for this connection.

*pszName* \[in\]

A pointer to a constant null-terminated string specifying the name of the printer to which the current user wishes to connect.

*dwLevel*

The version of the structure pointed to by *pConnectionInfo*. Currently, only level 1 is defined so the value of *dwLevel* must be 1.

*pConnectionInfo* \[in\]

A pointer to a [**PRINTER\_CONNECTION\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/printer-connection-info-1) structure. See the Remarks section for more about this parameter.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. For extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

When Windows Vista makes a connection to a printer, it may need to copy printer driver files from the server to which the printer is attached. If the user does not have permission to copy files to the appropriate location, the **AddPrinterConnection2** function fails and [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_ACCESS\_DENIED.

If the printer driver files must be copied from the print server but cannot be copied silently due to the group policies that are in effect and PRINTER\_CONNECTION\_NO\_UI is set in *pConnectionInfo->dwFlags*, no dialog boxes will be displayed and the call will fail.

If the local printer driver can be used to render print jobs for this printer and the version of the local driver must not match the version of the printer driver on the server, set PRINTER\_CONNECTION\_MISMATCH in *pConnectionInfo->dwFlags* and assign the pointer to a string variable that contains the path to the local printer driver to *pConnectionInfo->pszDriverName*.

A printer connection that is established by calling **AddPrinterConnection2** will be enumerated when [**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters) is called with *dwType* set to PRINTER\_ENUM\_CONNECTION.

The ANSI version of this function, **AddPrinterConnection2A**, is not supported and returns **ERROR\_NOT\_SUPPORTED**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **AddPrinterConnection2W** (Unicode)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**ConnectToPrinterDlg**](https://learn.microsoft.com/windows/win32/printdocs/connecttoprinterdlg)

[**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters)

[**DeletePrinterConnection**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterconnection)

