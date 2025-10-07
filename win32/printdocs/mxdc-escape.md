# MXDC\_ESCAPE function

The **MXDC\_ESCAPE** printer escape function enables applications to write documents to a file or to a printer in XML Paper Specification (XPS) format by means of the Microsoft XPS Document Converter (MXDC).

To perform this operation, call the [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) function with the following parameters.

## Parameters

*hdc*

A handle to the printer device context.

*cbInput*

The size, in bytes, of the data pointed to by the *lpszInData* parameter.

*lpszInData*

A pointer to a buffer containing the input data, which is always stored in one of the following structures.

[**MxdcEscapeHeader**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader)

[**MxdcPrintTicketEscape**](https://learn.microsoft.com/windows/win32/printdocs/mxdcprintticketescape)

[**MxdcS0PagePassthroughEscape**](https://learn.microsoft.com/windows/win32/printdocs/mxdcs0pagepassthroughescape)

[**MxdcS0PageResourceEscape**](https://learn.microsoft.com/windows/win32/printdocs/mxdcs0pageresourceescape)

Each of these structures has an opcode member that specifies what the MXDC is supposed to do. See MxdcEscapeHeader for detailed remarks about these codes.

| Operations code (opcode) | Action |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **MXDCOP\_GET\_FILENAME** | Sets the *lpszOutData* parameter of the [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) function to, either the full path of the output file as a zero-terminated string or else the size of that string.<br> |
| **MXDCOP\_PRINTTICKET\_FIXED\_DOC\_SEQ** | Associates a print ticket with an XPS fixed document sequence.<br> |
| **MXDCOP\_PRINTTICKET\_FIXED\_DOC** | Associates a print ticket with an XPS document.<br> |
| **MXDCOP\_PRINTTICKET\_FIXED\_PAGE** | Associates a print ticket with an XPS page.<br> |
| **MXDCOP\_SET\_S0PAGE** | Sends the XPS markup of the current page to the output.<br> |
| **MXDCOP\_SET\_S0PAGE\_RESOURCE** | Sends a resource on the page, such as an image or font, to the output.<br> |
| **MXDCOP\_SET\_XPSPASSTHRU\_MODE** | Puts the MXDC into a pass through state, enabling an application to write XPS directly to the output file without any processing by the MXDC. An entire document or even document sequence can be written in this way.<br> |

*cbOutput*

The size, in bytes, of the data pointed to by the *lpszOutData* parameter.

*lpszOutData*

A pointer to a buffer containing the output data.

## Return value

If the function succeeds, the return value is greater than zero. If the function fails or is not supported, the return value is less than or equal to zero.

## Remarks

This escape is supported by MXDC and XPSDrv, but not by GDI.

To determine if the printer driver is the MXDC, call [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) with the [**GETTECHNOLOGY**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144931(v=vs.85)) escape. If the driver is the MXDC, the **ExtEscape** will return the zero-terminated string, "http://schemas.microsoft.com/xps/2005/06". Be sure the buffer referenced by the *lpszOutData* parameter is large enough to hold this string.

To determine if the printer driver is the Windows in-box Microsoft XPS Document Writer driver, confirm that the printer driver is the MXDC, and then determine whether the name of the printer driver is "Microsoft XPS Document Writer".

To get the printer driver name, use one of the following techniques.

Call [**GetPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver) with the *Level* parameter value set to 1. The printer driver name is returned in the **pName** member of the [**DRIVER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-1) structure.
or
Call [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) with the *Level* parameter value set to 2. The printer driver name is returned in the **pDriverName** member of the [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure.

The following table shows where to find various objects in the XPS file various types of objects will be written.

| Object | Location in the output file |
|--------------|--------------------------------|
| Fixed Page | /Documents/1/Pages/Esc%d.fpage |
| Thumbnail | /Documents/1/Metadata |
| Print Ticket | /Documents/1/Metadata |
| Font | /Documents/1/Resources/Fonts |
| Image | /Documents/1/Resources/Images |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Mxdc.h |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Printer Escape Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162843(v=vs.85))

[**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape)

