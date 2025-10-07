# ConnectToPrinterDlg function

The **ConnectToPrinterDlg** function displays a dialog box that lets users browse and connect to printers on a network. If the user selects a printer, the function attempts to create a connection to it; if a suitable driver is not installed on the server, the user is given the option of creating a printer locally.

## Parameters

*hwnd* \[in\]

Specifies the parent window of the dialog box.

*Flags* \[in\]

This parameter is reserved and must be zero.

## Return value

If the function succeeds and the user selects a printer, the return value is a handle to the selected printer.

If the function fails, or the user cancels the dialog box without selecting a printer, the return value is **NULL**.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The **ConnectToPrinterDlg** function attempts to create a connection to the selected printer. However, if the server on which the printer resides does not have a suitable driver installed, the function offers the user the option of creating a printer locally. A calling application can determine whether the function has created a printer locally by calling [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) with a [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure, then examining that structure's **Attributes** member.

An application should call [**DeletePrinter**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinter) to delete a local printer. An application should call [**DeletePrinterConnection**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterconnection) to delete a connection to a printer.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | WinSpool.drv |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinterConnection**](https://learn.microsoft.com/windows/win32/printdocs/addprinterconnection)

[**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter)

[**DeletePrinter**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinter)

[**DeletePrinterConnection**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterconnection)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

