# MXDC\_S0PAGE\_RESOURCE\_ESCAPE\_T structure

The **MXDC\_S0PAGE\_RESOURCE\_ESCAPE\_T** structure is an [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure concatenated with an [**MXDC\_XPS\_S0PAGE\_RESOURCE\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcxpss0pageresource) structure.

## Members

**mxdcEscape**

An [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure with its **opCode** member set to MXDCOP\_SET\_S0PAGE\_RESOURCE.

**xpsS0PageResourcePassthrough**

An [**MXDC\_XPS\_S0PAGE\_RESOURCE\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcxpss0pageresource) structure representing a resource, such as a font or image file, on an XPS document page.

## Remarks

This structure is passed in the *lpszInData* parameter of the [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) function when that function is called with the [**MXDC\_ESCAPE**](https://learn.microsoft.com/windows/win32/printdocs/mxdc-escape) escape, and the **opCode** member of the [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure is **MXDCOP\_SET\_S0PAGE\_RESOURCE**. The result is a page resource to send to the MXDC.

Allocate memory for the escape as shown below, set the fields as needed, and then call [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape).

```C++
// Compute size of buffer required adding the
//  size of the escape structure to the size
//  of the resource data buffer.
SIZE_T iTotalDataSize = sizeof(MXDC_S0PAGE_RESOURCE_ESCAPE_T) +
                        iS0PageResourceDataSize - 1;

// Allocate the memory buffer.
P_MXDC_S0PAGE_RESOURCE_ESCAPE_T pS0PageResourceEscapeData =
                        (P_MXDC_S0PAGE_RESOURCE_ESCAPE_T)HeapAlloc(
                            GetProcessHeap(),
                            0,
                            iTotalDataSize);
```

The call to [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) must be between a call to [**StartPage**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-startpage) and a call to [**EndPage**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-endpage); however, there can be more than one of these calls between the calls to **StartPage** and **EndPage**.

Streaming consumption is more efficient if you call [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) with the **MXDCOP\_SET\_S0PAGE\_RESOURCE** **opCode** for each resource on the page before you call **ExtEscape** with the **MXDCOP\_SET\_S0PAGE** **opCode**.

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

