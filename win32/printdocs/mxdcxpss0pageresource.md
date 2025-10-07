# MXDC\_XPS\_S0PAGE\_RESOURCE\_T structure

The **MXDC\_XPS\_S0PAGE\_RESOURCE\_T** structure holds information about a resource, such as an image or font, that is associated with an XPS document page, and is to be passed to the Microsoft XPS Document Converter (MXDC) output file.

## Members

**dwSize**

The total size of this structure and the resource to which it points.

**dwResourceType**

A value of type [**MXDC\_S0\_PAGE\_ENUMS**](https://learn.microsoft.com/windows/win32/printdocs/mxdcs0pageenums) indicating the type of resource, such as TIFF image or TrueType font.

**szUri**

The URI of the resource. This cannot be more than 260 bytes.

**dwDataSize**

The size of the resource in bytes.

**bData**

The data of the resource in an array of bytes with size 1 + the size of the resource.

## Remarks

This structure is appended to a [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure (that has its **opCode** set to **MXDCOP\_SET\_S0PAGERESOURCE**) to make an [**MXDC\_S0PAGE\_RESOURCE\_ESCAPE\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcs0pageresourceescape) structure. The resulting **MXDC\_S0PAGE\_RESOURCE\_ESCAPE\_T** structure is then passed in the *lpszInData* parameter of the [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) function that it is called with the [**MXDC\_ESCAPE**](https://learn.microsoft.com/windows/win32/printdocs/mxdc-escape) escape. The effect is to send the resource to the MXDC for conversion and to be written to the output file.

The call to [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) must be between a call to [**StartPage**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-startpage) and a call to [**EndPage**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-endpage); however there can be more than one such calls between the calls to **StartPage** and **EndPage**.

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

