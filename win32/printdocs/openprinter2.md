# OpenPrinter2 function

Retrieves a handle to the specified printer, print server, or other types of handles in the print subsystem, while setting some of the printer options.

## Parameters

*pPrinterName* \[in\]

A pointer to a constant null-terminated string that specifies the name of the printer or print server, the printer object, the XcvMonitor, or the XcvPort.

For a printer object, use: PrinterName,Job xxxx. For an XcvMonitor, use: ServerName,XcvMonitor MonitorName. For an XcvPort, use: ServerName,XcvPort PortName.

**Windows Vista:** If **NULL**, it indicates the local print server.

*phPrinter* \[out\]

A pointer to a variable that receives a handle to the open printer or print server object.

*pDefault* \[in\]

A pointer to a [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure. This value can be **NULL**.

*pOptions* \[in\]

A pointer to a [**PRINTER\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-options) structure. This value can be **NULL**.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. For extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not call this method in [**DllMain**](https://learn.microsoft.com/windows/desktop/Dlls/dllmain).

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The ANSI version of this function is not implemented and returns ERROR\_NOT\_SUPPORTED.

The *pDefault* parameter enables you to specify the data type and device mode values that are used for printing documents submitted by the [**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter) function. However, you can override these values by using the [**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob) function after a document has been started.

You can call the **OpenPrinter2** function to open a handle to a print server or to determine client access rights to a print server. To do this, specify the name of the print server in the *pPrinterName* parameter, set the **pDatatype** and **pDevMode** members of the [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure to **NULL**, and set the **DesiredAccess** member to specify a server access mask value such as SERVER\_ALL\_ACCESS. When you are finished with the handle, pass it to the [**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter) function to close it.

Use the **DesiredAccess** member of the [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure to specify the necessary access rights. The access rights can be one of the following.

| Desired Access value | Meaning |
|---------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| PRINTER\_ACCESS\_ADMINISTER | To perform administrative tasks, such as those provided by [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter). |
| PRINTER\_ACCESS\_USE | To perform basic printing operations. |
| PRINTER\_ALL\_ACCESS | To perform all administrative tasks and basic printing operations except SYNCHRONIZE. See [Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights). |
| PRINTER\_ACCESS\_MANAGE\_LIMITED | To perform administrative tasks, such as those provided by [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) and [**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata). This value is available starting from Windows 8.1. |
| generic security values, such as WRITE\_DAC | To allow specific control access rights. See [Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights). |

If a user does not have permission to open a specified printer or print server with the desired access, the **OpenPrinter2** call will fail, and [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return the value ERROR\_ACCESS\_DENIED.

When *pPrinterName* is a local printer, then **OpenPrinter2** ignores all values of the **dwFlags** that the [**PRINTER\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-options) structure pointed to using *pOptions*, except PRINTER\_OPTION\_CLIENT\_CHANGE. If the latter is passed, then **OpenPrinter2** will return ERROR\_ACCESS\_DENIED. Accordingly, when opening a local printer, **OpenPrinter2** provides no advantage over [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter).

**Windows Vista:** The printer data returned by **OpenPrinter2** is retrieved from a local cache unless the **PRINTER\_OPTION\_NO\_CACHE** flag is set in the **dwFlags** field of the [**PRINTER\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-options) structure referenced by *pOptions*.

## Examples

In this example, **OpenPrinter2** fails when PRINTER\_ACCESS\_MANAGE\_LIMITED is passed to the [**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults) structure, and the user does not have the appropriate permission.

```C++
// Specify the limited management permission.
PRINTER_DEFAULTS defaults = {};
defaults.DesiredAccess = PRINTER_ACCESS_MANAGE_LIMITED;

// Open a printer to which the user has no administrative rights.
HANDLE printer = nullptr;
assert(!OpenPrinter2(L QueueWithNoAdminRights , // Queue name
                     &printer,                  // Printer handle
                     &defaults,                 // Printer defaults
                     nullptr));                 // Printer options

assert(GetLastError() == ERROR_ACCESS_DENIED);

if (printer)
{
    ClosePrinter(printer);
}
```

For a sample program that shows how to use this function, see [How To: Print Using the GDI Print API](https://learn.microsoft.com/windows/win32/printdocs/how-to--print-using-the-gdi-print-api).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |
| Unicode and ANSI names<br> | **OpenPrinter2W** (Unicode) and **OpenPrinter2A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter)

[**PRINTER\_DEFAULTS**](https://learn.microsoft.com/windows/win32/printdocs/printer-defaults)

[**PRINTER\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-options)

[**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

