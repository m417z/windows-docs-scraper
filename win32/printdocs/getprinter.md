# GetPrinter function

The **GetPrinter** function retrieves information about a specified printer.

## Parameters

*hPrinter* \[in\]

A handle to the printer for which the function retrieves information. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*Level* \[in\]

The level or type of structure that the function stores into the buffer pointed to by *pPrinter*.

This value can be 1, 2, 3, 4, 5, 6, 7, 8 or 9.

*pPrinter* \[out\]

A pointer to a buffer that receives a structure containing information about the specified printer. The buffer must be large enough to receive the structure and any strings or other data to which the structure members point. If the buffer is too small, the *pcbNeeded* parameter returns the required buffer size.

The type of structure is determined by the value of *Level*.

| Level | Structure |
|------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **1** | A [**PRINTER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-1) structure containing general printer information.<br> |
| **2** | A [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure containing detailed information about the printer.<br> |
| **3** | A [**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3) structure containing the printer's security information.<br> |
| **4** | A [**PRINTER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-4) structure containing minimal printer information, including the name of the printer, the name of the server, and whether the printer is remote or local.<br> |
| **5** | A [**PRINTER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-5) structure containing printer information such as printer attributes and time-out settings.<br> |
| **6** | A [**PRINTER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-6) structure specifying the status value of a printer.<br> |
| **7** | A [**PRINTER\_INFO\_7**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-7) structure that indicates whether the printer is published in the directory service.<br> |
| **8** | A [**PRINTER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-8) structure specifying the global default printer settings.<br> |
| **9** | A [**PRINTER\_INFO\_9**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-9) structure specifying the per-user default printer settings.<br> |

*cbBuf* \[in\]

The size, in bytes, of the buffer pointed to by *pPrinter*.

*pcbNeeded* \[out\]

A pointer to a variable that the function sets to the size, in bytes, of the printer information. If *cbBuf* is smaller than this value, **GetPrinter** fails, and the value represents the required buffer size. If *cbBuf* is equal to or greater than this value, **GetPrinter** succeeds, and the value represents the number of bytes stored in the buffer.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The **pDevMode** member in the [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2), [**PRINTER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-8), and [**PRINTER\_INFO\_9**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-9) structures can be **NULL**. When this happens, the printer is unusable until the driver is reinstalled successfully.

For the [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) and [**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3) structures that contain a pointer to a security descriptor, the function retrieves only those components of the security descriptor that the caller has permission to read. To retrieve particular security descriptor components, you must specify the necessary access rights when you call the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) function to retrieve a handle to the printer. The following table shows the access rights required to read the various security descriptor components.

| Access Right | Security Descriptor Component |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| READ\_CONTROL<br> | Owner<br> Primary group<br> Discretionary access-control list (DACL)<br> |
| ACCESS\_SYSTEM\_SECURITY<br> | System access-control list (SACL)<br> |

If you specify level 7, the **dwAction** member of [**PRINTER\_INFO\_7**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-7) returns one of the following values to indicate whether the printer is published in the directory service.

| dwAction value | Meaning |
|--------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| DSPRINT\_PUBLISH | The printer is published. The **pszObjectGUID** member contains the GUID of the directory services print queue object associated with the printer. |
| DSPRINT\_UNPUBLISH | The printer is not published. |
| DSPRINT\_PENDING | Indicates that the system is attempting to complete a publish or unpublish operation. If a [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) call fails to publish or unpublish a printer, the system makes further attempts to complete the operation in the background. |

Starting with Windows Vista, the printer data returned by **GetPrinter** is retrieved from a local cache when *hPrinter* refers to a printer hosted by a print server and there is at least one open connection to the print server. In all other configurations, the printer data is queried from the print server.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **GetPrinterW** (Unicode) and **GetPrinterA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AbortPrinter**](https://learn.microsoft.com/windows/win32/printdocs/abortprinter)

[**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter)

[**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter)

[**DeletePrinter**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinter)

[**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters)

[**PRINTER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-1)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

[**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3)

[**PRINTER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-4)

[**PRINTER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-5)

[**PRINTER\_INFO\_7**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-7)

[**PRINTER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-8)

[**PRINTER\_INFO\_9**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-9)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

