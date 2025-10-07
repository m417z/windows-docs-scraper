# MXDC\_S0PAGE\_PASSTHROUGH\_ESCAPE\_T structure

The **MXDC\_S0PAGE\_PASSTHROUGH\_ESCAPE\_T** structure is an [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure concatenated with an [**MXDC\_S0PAGE\_DATA\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcs0pagedata) structure.

## Members

**mxdcEscape**

An [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure with its **opCode** member set to **MXDCOP\_SET\_S0PAGE**.

**xpsS0PageData**

An [**MxdcS0PageData**](https://learn.microsoft.com/windows/win32/printdocs/mxdcs0pagedata) structure that represents an XPS-document page.

## Remarks

This structure is passed in the *lpszInData* parameter of the [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) function when it is called with the [**MXDC\_ESCAPE**](https://learn.microsoft.com/windows/win32/printdocs/mxdc-escape) escape and the **opCode** member of the [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure is **MXDCOP\_SET\_S0PAGE**. The result is that the Microsoft XML Document Converter (MXDC) passes the page through to the printer without processing it.

Allocate memory for the escape as shown below, set the fields as needed, and then call [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape).

```C++
// Compute size of buffer required adding the
//  size of the escape structure to the size
//  of the resource data buffer.
SIZE_T iTotalDataSize = sizeof(MXDC_S0PAGE_PASSTHROUGH_ESCAPE_T) +
                        iS0PageDataSize - 1;

// Allocate the memory buffer.
P_MXDC_S0PAGE_PASSTHROUGH_ESCAPE_T pS0PageEscapeData =
                        (P_MXDC_S0PAGE_PASSTHROUGH_ESCAPE_T)HeapAlloc(
                            GetProcessHeap(),
                            0,
                            iTotalDataSize);
```

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

