# PRINTER\_INFO\_8 structure

The **PRINTER\_INFO\_8** structure specifies the global default printer settings.

## Members

**pDevMode**

A pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that defines the global default printer data such as the paper orientation and the resolution.

## Remarks

The global defaults are set by the administrator of a printer that can be used by anyone. In contrast, the per-user defaults will affect a particular user or anyone else who uses the profile. For per-user defaults, use [**PRINTER\_INFO\_9**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-9).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PRINTER\_INFO\_8W** (Unicode) and **\_PRINTER\_INFO\_8A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**PRINTER\_INFO\_9**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-9)

