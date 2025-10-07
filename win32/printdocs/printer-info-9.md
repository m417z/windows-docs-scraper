# PRINTER\_INFO\_9 structure

The **PRINTER\_INFO\_9** structure specifies the per-user default printer settings.

## Members

**pDevMode**

A pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that defines the per-user default printer data such as the paper orientation and the resolution. The **DEVMODE** is stored in the user's registry.

## Remarks

The per-user defaults will affect only a particular user or anyone who uses the profile. In contrast, the global defaults are set by the administrator of a printer that can be used by anyone. For global defaults, use [**PRINTER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-8).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PRINTER\_INFO\_9W** (Unicode) and **\_PRINTER\_INFO\_9A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**PRINTER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-8)

