# PRINTER\_INFO\_3 structure

The **PRINTER\_INFO\_3** structure specifies printer security information.

## Members

**pSecurityDescriptor**

Pointer to a [**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that specifies a printer's security information.

## Remarks

The **PRINTER\_INFO\_3** structure lets an application get and set a printer's security descriptor. The caller may do so even if it lacks specific printer permissions, as long as it has the standard rights described in [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) and [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter). Thus, an application may temporarily deny all access to a printer, while allowing the owner of the printer to have access to the printer's discretionary ACL.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**PRINTER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-1)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

[**PRINTER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-4)

[**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

