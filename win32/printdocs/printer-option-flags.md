# PRINTER\_OPTION\_FLAGS enumeration

Specifies the caching of a handle for a printer opened with [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2).

## Constants

**PRINTER\_OPTION\_NO\_CACHE**

The handle is not cached. All functions applied to a handle returned by [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2) will go to the remote computer.

**PRINTER\_OPTION\_CACHE**

The handle is cached. All functions applied to a handle returned by [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2) will go to the local cache.

**PRINTER\_OPTION\_CLIENT\_CHANGE**

The handle returned by [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2) can be used by [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) to rename the printer connection.

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

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

