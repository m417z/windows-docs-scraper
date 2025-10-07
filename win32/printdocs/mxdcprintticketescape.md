# MXDC\_PRINTTICKET\_ESCAPE\_T structure

The **MXDC\_PRINTTICKET\_ESCAPE\_T** structure is a [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure concatenated with a [**MXDC\_PRINTTICKET\_DATA\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcprintticketpassthrough) structure.

## Members

**mxdcEscape**

A [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure with its **opCode** member set to MXDCOP\_PRINTTICKET\_FIXED\_PAGE, MXDCOP\_PRINTTICKET\_FIXED\_DOC, or MXDCOP\_PRINTTICKET\_FIXED\_DOC\_SEQ.

**printTicketData**

A [**MXDC\_PRINTTICKET\_DATA\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcprintticketpassthrough) structure containing the print ticket.

## Remarks

This structure is passed in the *lpszInData* parameter of the [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) function when that function is called with the [**MXDC\_ESCAPE**](https://learn.microsoft.com/windows/win32/printdocs/mxdc-escape) escape and the **opCode** member of the [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure is **MXDCOP\_PRINTTICKET\_FIXED\_PAGE**, **MXDCOP\_PRINTTICKET\_FIXED\_DOC**, or **MXDCOP\_PRINTTICKET\_FIXED\_DOC\_SEQ**. The result is to write the print ticket to the XPS document file.

Allocate memory for the escape as shown below, set the fields as needed, and then call [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape).

```C++
// Compute size of buffer required adding the
//  size of the escape structure to the size
//  of the resource data buffer.
SIZE_T iTotalDataSize = sizeof(MXDC_PRINTTICKET_ESCAPE_T) +
                        iS0PageDataSize - 1;

// Allocate the memory buffer.
P_MXDC_PRINTTICKET_ESCAPE_T pS0PageEscapeData =
                        (P_MXDC_PRINTTICKET_ESCAPE_T)HeapAlloc(
                            GetProcessHeap(),
                            0,
                            iTotalDataSize);
```

If the **opCode** is set to **MXDCOP\_PRINTTICKET\_FIXED\_PAGE**, the call to [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) must occur between a call to [**StartPage**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-startpage) and a call to [**EndPage**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-endpage). If the **opCode** set to either **MXDCOP\_PRINTTICKET\_FIXED\_DOC** or **MXDCOP\_PRINTTICKET\_FIXED\_DOC\_SEQ**, the call to **ExtEscape** must occur between a call to [**StartDoc**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-startdoca) and a call to [**EndDoc**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-enddoc).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Mxdc.h |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[GDI Printer Escape Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162843(v=vs.85))

[**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape)

[**MXDC\_ESCAPE**](https://learn.microsoft.com/windows/win32/printdocs/mxdc-escape)

