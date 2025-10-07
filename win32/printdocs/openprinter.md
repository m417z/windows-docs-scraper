# OpenPrinter function

The **OpenPrinter** function retrieves a handle to the specified printer or print server or other types of handles in the print subsystem.

## Parameters

*pPrinterName* \[in\]

A pointer to a null-terminated string that specifies the name of the printer or print server, the printer object, the XcvMonitor, or the XcvPort.

For a printer object use: PrinterName, Job xxxx. For an XcvMonitor, use: ServerName, XcvMonitor MonitorName. For an XcvPort, use: ServerName, XcvPort PortName.

If **NULL**, it indicates the local printer server.

*phPrinter* \[out\]

A pointer to a variable that receives a handle (not thread safe) to the open printer or print server object.

The *phPrinter* parameter can return an Xcv handle for use with the XcvData function. For more information about XcvData, see the DDK.

*pDefault* \[in\]

A pointer to a [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure. This value can be **NULL**.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

Do not call this method in [**DllMain**](https://learn.microsoft.com/windows/desktop/Dlls/dllmain).

> [!Note]
> A handle obtained for a remote printer by a call to **OpenPrinter** for a remote printer accesses the printer through a local cache in the print spooler service. This cache isn't real-time accurate. To obtain accurate data, replace the OpenPrinter call with [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2) with pOptions.dwFlags set to PRINTER\_OPTION\_NO\_CACHE. Note that only OpenPrinter2W is functional. The function returns a printer handle that uses other Printing API calls and bypasses the local cache. This method blocks while waiting for network communication with the remote printer, so it might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages user interface interaction might make the application appear unresponsive.

> [!Note]
> A handle obtained by a call to **OpenPrinter** for a remote printer will access the printer through a local cache in the print spooler service. This cache is, by design, not real time accurate. If you need to obtain accurate data, replace the **OpenPrinter** call with [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2) with *pOptions.dwFlags* set to [**PRINTER\_OPTION\_NO\_CACHE**](https://learn.microsoft.com/windows/win32/printdocs/printer-options). Note that only **OpenPrinter2W** is functional. Doing so the function returns a printer handle that makes other Printing API calls to bypass the local cache. Note that this approach will block while waiting for the round-trip network communication to the remote printer, so it may not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation - factors that are difficult to predict when writing an application. Therefore calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The handle pointed to by *phPrinter* is not thread safe. If callers need to use it concurrently on multiple threads, they must provide custom synchronization access to the printer handle using the [Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions). To avoid writing custom code the application can open a printer handle on each thread, as needed.

The *pDefault* parameter enables you to specify the data type and device mode values that are used for printing documents submitted by the [**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter) function. However, you can override these values by using the [**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob) function after a document has been started.

The [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) settings defined in the [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure of the *pDefault* parameter are not used when the value of the *pDatatype* member of the [**DOC\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/doc-info-1) structure that was passed in the *pDocInfo* parameter of the [**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter) call is "RAW". When a high-level document (such as an Adobe PDF or Microsoft Word file) or other printer data (such PCL, PS, or HPGL) is sent directly to a printer with *pDatatype* set to "RAW", the document must fully describe the **DEVMODE**-style print job settings in the language understood by the hardware.

You can call the **OpenPrinter** function to open a handle to a print server or to determine the access rights that a client has to a print server. To do so, specify the name of the print server in the *pPrinterName* parameter, set the **pDatatype** and **pDevMode** members of the [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure to **NULL**, and set the **DesiredAccess** member to specify a server access mask value such as SERVER\_ALL\_ACCESS. When you finish with the handle, pass it to the [**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter) function to close it.

Use the **DesiredAccess** member of the [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure to specify the access rights that you need to the printer. The access rights can be one of the following. (If *pDefault* is **NULL**, then the access rights are PRINTER\_ACCESS\_USE.)

| Desired Access value | Meaning |
|---------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| PRINTER\_ACCESS\_ADMINISTER | To perform administrative tasks, such as those provided by [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter). |
| PRINTER\_ACCESS\_USE | To perform basic printing operations. |
| PRINTER\_ALL\_ACCESS | To perform all administrative tasks and basic printing operations except for SYNCHRONIZE (see [Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights). |
| PRINTER\_ACCESS\_MANAGE\_LIMITED | To perform administrative tasks, such as those provided by [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) and [**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata). This value is available starting from Windows 8.1. |
| generic security values, such as WRITE\_DAC | To allow specific control access rights. See [Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights). |

If a user does not have permission to open a specified printer or print server with the desired access, the **OpenPrinter** call will fail with a return value of zero and [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return the value ERROR\_ACCESS\_DENIED.

## Examples

For a sample program that uses this function, see [How To: Print Using the GDI Print API](https://learn.microsoft.com/windows/win32/printdocs/how-to--print-using-the-gdi-print-api).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **OpenPrinterW** (Unicode) and **OpenPrinterA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**WritePrinter**](https://learn.microsoft.com/windows/win32/printdocs/writeprinter)

[**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter)

[**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults)

[**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter)

