# MXDC\_S0PAGE\_DATA\_T structure

The **MXDC\_S0PAGE\_DATA\_T** structure holds an XPS document page to be passed to the Microsoft XPS Document Converter (MXDC) output file without any processing.

## Members

**dwSize**

The size of the output buffer, **bData**.

**bData**

The XPS document page.

## Remarks

This structure is appended to an [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure (which has its **opCode** set to MXDCOP\_SET\_S0PAGE) to make an [**MXDC\_S0PAGE\_PASSTHROUGH\_ESCAPE\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcs0pagepassthroughescape) structure. That structure is then passed to the *lpszInData* parameter of the [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) function when it is called with [**MXDC\_ESCAPE**](https://learn.microsoft.com/windows/win32/printdocs/mxdc-escape) as the escape. The result is that the MXDC passes the page through to the output without processing it.

The call to [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) must be between a call to [**StartPage**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-startpage) and a call to [**EndPage**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-endpage).

The calling application is responsible for validating the XML of the XPS document page.

Streaming consumption is more efficient if you call [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) with **MXDCOP\_SET\_S0PAGE\_RESOURCE** as **opCode** for each resource on the page before you call it with **MXDCOP\_SET\_S0PAGE**.

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

