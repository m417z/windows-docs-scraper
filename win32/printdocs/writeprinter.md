# WritePrinter function

The **WritePrinter** function notifies the print spooler that data should be written to the specified printer.

> [!Note]
> **WritePrinter** only supports GDI printing and must not be used for XPS printing. If your print job uses the XPS or the OpenXPS print path, then use the [XPS Print API](https://learn.microsoft.com/windows/desktop/printdocs/xps-printing). Sending XPS or OpenXPS print jobs to the spooler using **WritePrinter** is not supported and can result in undetermined results.

## Parameters

*hPrinter* \[in\]

A handle to the printer. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pBuf* \[in\]

A pointer to an array of bytes that contains the data that should be written to the printer.

*cbBuf* \[in\]

The size, in bytes, of the array.

*pcWritten* \[out\]

A pointer to a value that receives the number of bytes of data that were written to the printer.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The sequence for a print job is as follows:

1. To begin a print job, call [**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter).
2. To begin each page, call [**StartPagePrinter**](https://learn.microsoft.com/windows/win32/printdocs/startpageprinter).
3. To write data to a page, call **WritePrinter**.
4. To end each page, call [**EndPagePrinter**](https://learn.microsoft.com/windows/win32/printdocs/endpageprinter).
5. Repeat 2, 3, and 4 for as many pages as necessary.
6. To end the print job, call [**EndDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/enddocprinter).

When a high-level document (such as an Adobe PDF or Microsoft Word file) or other printer data (such PCL, PS, or HPGL) is sent directly to a printer, the print settings defined in the document take precedent over Windows print settings. Documents output when the value of the *pDatatype* member of the [**DOC\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/doc-info-1) structure that was passed in the *pDocInfo* parameter of the [**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter) call is "RAW" must fully describe the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)-style print job settings in the language understood by the hardware.

In versions of Windows prior to Windows XP, when a page in a spooled file exceeds approximately 350 MB, it can fail to print and not send an error message. For example, this can occur when printing large EMF files. The page size limit in versions of Windows prior to Windows XP depends on many factors including the amount of virtual memory available, the amount of memory allocated by calling processes, and the amount of fragmentation in the process heap. In Windows XP and later versions of Windows, EMF files must be 2GB or less in size. If **WritePrinter** is used to write non EMF data, such as printer-ready PDL, the size of the file is limited only by the available disk space.

## Examples

For a sample program that uses this function, see [How To: Print Using the GDI Print API](https://learn.microsoft.com/windows/win32/printdocs/how-to--print-using-the-gdi-print-api).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**EndDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/enddocprinter)

[**EndPagePrinter**](https://learn.microsoft.com/windows/win32/printdocs/endpageprinter)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**StartDocPrinter**](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter)

[**StartPagePrinter**](https://learn.microsoft.com/windows/win32/printdocs/startpageprinter)

