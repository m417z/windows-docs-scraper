# PRINTER\_ENUM\_VALUES structure

The **PRINTER\_ENUM\_VALUES** structure specifies the value name, type, and data for a printer configuration value returned by the [**EnumPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdataex) function.

## Members

**pValueName**

Pointer to a null-terminated string that specifies the name of the retrieved value.

**cbValueName**

The number of bytes in the **pValueName** member, including the terminating NULL character.

**dwType**

A code indicating the type of data pointed to by the **pData** member. For a list of the possible type codes, see [Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types).

**pData**

Pointer to a buffer containing the data for the retrieved value.

**cbData**

The number of bytes retrieved in the **pData** buffer.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PRINTER\_ENUM\_VALUESW** (Unicode) and **\_PRINTER\_ENUM\_VALUESA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**EnumPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdataex)

