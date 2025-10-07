# PRINTER\_OPTIONS structure

Represents printer options.

## Members

**cbSize**

The size of the **PRINTER\_OPTIONS** structure.

**dwFlags**

A set of [**PRINTER\_OPTION\_FLAGS**](https://learn.microsoft.com/windows/win32/printdocs/printer-option-flags) that specifies how the handle to a printer returned by [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2) will be used by other functions.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2)

[**PRINTER\_OPTION\_FLAGS**](https://learn.microsoft.com/windows/win32/printdocs/printer-option-flags)

