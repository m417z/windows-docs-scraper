# MXDC\_GET\_FILENAME\_DATA\_T structure

The **MXDC\_GET\_FILENAME\_DATA\_T** structure holds the full path and file name of a Microsoft XPS Document Converter (MXDC) output file.

## Members

**cbOutput**

The size of the output buffer, **wszData**.

**wszData**

The fully qualified path and file name of the output file.

## Remarks

This structure is returned by [**ExtEscape**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-extescape) when it is called with the [**MXDC\_ESCAPE**](https://learn.microsoft.com/windows/win32/printdocs/mxdc-escape) escape and the [**MXDC\_ESCAPE\_HEADER\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcescapeheader) structure that is passed in the *lpszInData* parameter has its **opCode** set to **MXDCOP\_GET\_FILENAME**.

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

