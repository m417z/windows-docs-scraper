# PRINTER\_INFO\_5 structure

The **PRINTER\_INFO\_5** structure specifies detailed printer information.

## Members

**pPrinterName**

A pointer to a null-terminated string that specifies the name of the printer.

**pPortName**

A pointer to a null-terminated string that identifies the port(s) used to transmit data to the printer. If a printer is connected to more than one port, the names of each port must be separated by commas (for example, "LPT1:,LPT2:,LPT3:").

**Attributes**

The printer attributes. This member can be any reasonable combination of the following values.

| Value | Meaning |
|-----------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| PRINTER\_ATTRIBUTE\_DIRECT | Job is sent directly to the printer (it is not spooled). |
| PRINTER\_ATTRIBUTE\_DO\_COMPLETE\_FIRST | If set and printer is set for print-while-spooling, any jobs that have completed spooling are scheduled to print before jobs that have not completed spooling. |
| PRINTER\_ATTRIBUTE\_ENABLE\_DEVQ | If set, **DevQueryPrint** is called. **DevQueryPrint** may fail if the document and printer setups do not match. Setting this flag causes mismatched documents to be held in the queue. |
| PRINTER\_ATTRIBUTE\_HIDDEN | Reserved. |
| PRINTER\_ATTRIBUTE\_KEEPPRINTEDJOBS | If set, jobs are kept after they are printed. If unset, jobs are deleted. |
| PRINTER\_ATTRIBUTE\_LOCAL | Printer is a local printer. |
| PRINTER\_ATTRIBUTE\_NETWORK | Printer is a network printer connection. |
| PRINTER\_ATTRIBUTE\_PUBLISHED | Indicates whether the printer is published in the directory service. |
| PRINTER\_ATTRIBUTE\_QUEUED | If set, the printer spools and starts printing after the last page is spooled. If not set and PRINTER\_ATTRIBUTE\_DIRECT is not set, the printer spools and prints while spooling. |
| PRINTER\_ATTRIBUTE\_RAW\_ONLY | Indicates that only raw data type print jobs can be spooled. |
| PRINTER\_ATTRIBUTE\_SHARED | Printer is shared. |

In Windows XP and later versions of Windows, the following value can also be used.

| Value | Meaning |
|-------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| PRINTER\_ATTRIBUTE\_FAX | If set, printer is a fax printer. This can only be set by [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter), but it can be retrieved by [**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters) and [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter). |

In Windows Vista and later versions of Windows, the following values can also be used.

| Value | Meaning |
|-------------------------------------|----------------------------------------------------------------------------------|
| PRINTER\_ATTRIBUTE\_FRIENDLY\_NAME | A computer has connected to this printer and given it a friendly name. |
| PRINTER\_ATTRIBUTE\_MACHINE | Printer is a per-machine connection. |
| PRINTER\_ATTRIBUTE\_PUSHED\_USER | The printer was installed by using the Push Printer Connections user policy. |
| PRINTER\_ATTRIBUTE\_PUSHED\_MACHINE | The printer was installed by using the Push Printer Connections computer policy. |

**DeviceNotSelectedTimeout**

This value is not used.

**TransmissionRetryTimeout**

This value is not used.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PRINTER\_INFO\_5W** (Unicode) and **\_PRINTER\_INFO\_5A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**PRINTER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-1)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

[**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3)

[**PRINTER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-4)

