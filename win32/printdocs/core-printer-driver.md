# CORE\_PRINTER\_DRIVER structure

Represents a printer driver on which other printer drivers depend.

## Members

**CoreDriverGUID**

The GUID of the core printer driver.

**ftDriverDate**

The date and time of the latest version of the core printer driver.

**dwlDriverVersion**

The version ID of the latest version of the core printer driver.

**szPackageID\[MAX\_PATH\]**

The path to the driver package that contains the core printer driver.

## Remarks

This structure can represent a manufacturer's base driver on which the drivers for various printer models are dependent.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_CORE\_PRINTER\_DRIVERW** (Unicode) and **\_CORE\_PRINTER\_DRIVERA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

