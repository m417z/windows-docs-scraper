# PORT\_INFO\_2 structure

The **PORT\_INFO\_2** structure identifies a supported printer port.

## Members

**pPortName**

Pointer to a null-terminated string that identifies a supported printer port (for example, "LPT1:").

**pMonitorName**

Pointer to a null-terminated string that identifies an installed monitor (for example, "PJL monitor"). This can be **NULL**.

**pDescription**

Pointer to a null-terminated string that describes the port in more detail (for example, if **pPortName** is "LPT1:", **pDescription** is "printer port"). This can be **NULL**.

**fPortType**

Bitmask describing the type of port. This member can be a combination of the following values:

**PORT\_TYPE\_WRITE**

**PORT\_TYPE\_READ**

**PORT\_TYPE\_REDIRECTED**

**PORT\_TYPE\_NET\_ATTACHED**

**Reserved**

Reserved; must be zero.

## Remarks

Use the **PORT\_INFO\_2** structure when calling [**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports) if there are multiple monitors installed that support the same ports.

The **fPortType** member can be queried to determine information about the port. Note that port settings do not influence printer attributes (as returned by the **Attributes** member of [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PORT\_INFO\_2W** (Unicode) and **\_PORT\_INFO\_2A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports)

