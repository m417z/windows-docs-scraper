# AdvancedDocumentProperties function

The **AdvancedDocumentProperties** function displays a printer-configuration dialog box for the specified printer, allowing the user to configure that printer.

This function is a special case of the [**DocumentProperties**](https://learn.microsoft.com/windows/win32/printdocs/documentproperties) function. For more details, see the Remarks section.

## Parameters

*hWnd* \[in\]

A handle to the parent window of the printer-configuration dialog box.

*hPrinter* \[in\]

A handle to a printer object. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pDeviceName* \[in\]

A pointer to a null-terminated string specifying the name of the device for which a printer-configuration dialog box should be displayed.

*pDevModeOutput* \[out\]

A pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that will contain the configuration data specified by the user.

*pDevModeInput* \[in\]

A pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that contains the configuration data used to initialize the controls of the printer-configuration dialog box.

## Return value

If the [**DocumentProperties**](https://learn.microsoft.com/windows/win32/printdocs/documentproperties) function with these parameters is successful, the return value of **AdvancedDocumentProperties** is 1. Otherwise, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

This function can only display the printer-configuration dialog box so a user can configure it. For more control, use [**DocumentProperties**](https://learn.microsoft.com/windows/win32/printdocs/documentproperties). The input parameters for this function are passed directly to **DocumentProperties** and the *fMode* value is set to DM\_IN\_BUFFER \| DM\_IN\_PROMPT \| DM\_OUT\_BUFFER. Unlike **DocumentProperties**, this function only returns 1 or 0. Thus, you cannot determine the required size of [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) by setting *pDevMode* to zero.

An application can obtain the name pointed to by the *pDeviceName* parameter by calling the [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) function and then examining the **pPrinterName** member of the [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **AdvancedDocumentPropertiesW** (Unicode) and **AdvancedDocumentPropertiesA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter)

[**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[**DocumentProperties**](https://learn.microsoft.com/windows/win32/printdocs/documentproperties)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

