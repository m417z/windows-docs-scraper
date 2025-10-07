# MXDC\_PRINTTICKET\_DATA\_T structure

The **MXDC\_PRINTTICKET\_DATA\_T** structure holds an XPS document print ticket, which contains printer and print job settings, to pass to the Microsoft XPS Document Converter (MXDC) output file without any processing.

## Members

**dwDataSize**

The size of the print ticket in bytes.

**bData**

The XPS document print ticket.

## Remarks

This structure is appended to an [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure that has the **opCode** member set to **MXDCOP\_PRINTTICKET\_FIXED\_PAGE**, **MXDCOP\_PRINTTICKET\_FIXED\_DOC**, or **MXDCOP\_PRINTTICKET\_FIXED\_DOC\_SEQ** to make an [**MXDC\_PRINTTICKET\_ESCAPE\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcprintticketescape) structure. The **MXDC\_PRINTTICKET\_ESCAPE\_T** structure is then passed to the *lpszInData* parameter of the [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) function when it is called with the [**MXDC\_ESCAPE**](https://learn.microsoft.com/windows/win32/printdocs/mxdc-escape) escape. The effect is to write the print ticket to the XPS document file.

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

