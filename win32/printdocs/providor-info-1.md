# PROVIDOR\_INFO\_1 structure

The **PROVIDOR\_INFO\_1** structure identifies a print provider.

## Members

**pName**

Pointer to a null-terminated string that is the name of the print provider.

**pEnvironment**

Pointer to a null-terminated environment string specifying the environment the provider dynamic-link library (DLL) is designed to run in.

**pDLLName**

Pointer to a null-terminated string that is the name of the provider .dll.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PROVIDOR\_INFO\_1W** (Unicode) and **\_PROVIDOR\_INFO\_1A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**AddPrintProvidor**](https://learn.microsoft.com/windows/win32/printdocs/addprintprovidor)

