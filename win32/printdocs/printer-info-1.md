# PRINTER\_INFO\_1 structure

The **PRINTER\_INFO\_1** structure specifies general printer information.

## Members

**Flags**

Specifies information about the returned data. Following are the values for this member.

| Value | Meaning |
|--------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| PRINTER\_ENUM\_EXPAND | A print provider can set this flag as a hint to a calling application to enumerate this object further if default expansion is enabled. For example, when domains are enumerated, a print provider might indicate the user's domain by setting this flag. |
| PRINTER\_ENUM\_CONTAINER | If this flag is set, the printer object may contain enumerable objects. For example, the object may be a print server that contains printers. |
| PRINTER\_ENUM\_ICON1 | Indicates that, where appropriate, an application should display an icon identifying the object as a top-level network name, such as Microsoft Windows Network. |
| PRINTER\_ENUM\_ICON2 | Indicates that, where appropriate, an application should display an icon that identifies the object as a network domain. |
| PRINTER\_ENUM\_ICON3 | Indicates that, where appropriate, an application should display an icon that identifies the object as a print server. |
| PRINTER\_ENUM\_ICON4 | Reserved. |
| PRINTER\_ENUM\_ICON5 | Reserved. |
| PRINTER\_ENUM\_ICON6 | Reserved. |
| PRINTER\_ENUM\_ICON7 | Reserved. |
| PRINTER\_ENUM\_ICON8 | Indicates that, where appropriate, an application should display an icon that identifies the object as a printer. |

**pDescription**

Pointer to a null-terminated string that describes the contents of the structure.

**pName**

Pointer to a null-terminated string that names the contents of the structure.

**pComment**

Pointer to a null-terminated string that contains additional data describing the structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PRINTER\_INFO\_1W** (Unicode) and **\_PRINTER\_INFO\_1A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

[**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3)

[**PRINTER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-4)

