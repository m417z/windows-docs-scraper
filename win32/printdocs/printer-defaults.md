# PRINTER\_DEFAULTS structure

The **PRINTER\_DEFAULTS** structure specifies the default data type, environment, initialization data, and access rights for a printer.

## Members

**pDatatype**

Pointer to a null-terminated string that specifies the default data type for a printer.

**pDevMode**

Pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that identifies the default environment and initialization data for a printer.

**DesiredAccess**

Specifies desired access rights for a printer. The [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) function uses this member to set access rights to the printer. These rights can affect the operation of the [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) and [**DeletePrinter**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinter) functions. The access rights can be one of the following.

| Value | Meaning |
|---------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| PRINTER\_ACCESS\_ADMINISTER | To perform administrative tasks, such as those provided by [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter). |
| PRINTER\_ACCESS\_USE | To perform basic printing operations. |
| PRINTER\_ACCESS\_MANAGE\_LIMITED | To perform administrative tasks, such as those provided by [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) and [**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata). This value is available starting from Windows 8.1. |
| PRINTER\_ALL\_ACCESS | To perform all administrative tasks and basic printing operations except for SYNCHRONIZE (see [Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights) ). |
| generic security values, such as WRITE\_DAC | To allow specific control access rights. See [Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights). |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PRINTER\_DEFAULTSW** (Unicode) and **\_PRINTER\_DEFAULTSA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**DeletePrinter**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinter)

[**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

