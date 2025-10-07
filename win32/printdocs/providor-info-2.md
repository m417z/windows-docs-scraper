# PROVIDOR\_INFO\_2 structure

The **PROVIDOR\_INFO\_2** structure appends a print provider to the print provider order list.

## Members

**pOrder**

Pointer to a null-terminated string that specifies the name of the print provider.

## Remarks

This structure is used when calling [**AddPrintProvidor**](https://learn.microsoft.com/windows/win32/printdocs/addprintprovidor), level 2, to add the specified print provider to the end of the print provider order list. The provider is immediately used for routing if the call succeeds.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PROVIDOR\_INFO\_2W** (Unicode) and **\_PROVIDOR\_INFO\_2A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**AddPrintProvidor**](https://learn.microsoft.com/windows/win32/printdocs/addprintprovidor)

