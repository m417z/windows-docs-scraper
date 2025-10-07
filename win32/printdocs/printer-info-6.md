# PRINTER\_INFO\_6 structure

The **PRINTER\_INFO\_6** specifies the status value of a printer.

## Members

**dwStatus**

The printer status. This member can be any reasonable combination of the following values.

| Value | Meaning |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| PRINTER\_STATUS\_BUSY | The printer is busy. |
| PRINTER\_STATUS\_DOOR\_OPEN | The printer door is open. |
| PRINTER\_STATUS\_ERROR | Not used. |
| PRINTER\_STATUS\_INITIALIZING | The printer is initializing. |
| PRINTER\_STATUS\_IO\_ACTIVE | The printer is in an active input/output state |
| PRINTER\_STATUS\_MANUAL\_FEED | The printer is in a manual feed state. |
| PRINTER\_STATUS\_NO\_TONER | The printer is out of toner. |
| PRINTER\_STATUS\_NOT\_AVAILABLE | The printer is not available for printing. |
| PRINTER\_STATUS\_OFFLINE | The printer is offline. |
| PRINTER\_STATUS\_OUT\_OF\_MEMORY | The printer has run out of memory. |
| PRINTER\_STATUS\_OUTPUT\_BIN\_FULL | The printer's output bin is full. |
| PRINTER\_STATUS\_PAGE\_PUNT | The printer cannot print the current page. |
| PRINTER\_STATUS\_PAPER\_JAM | Paper is jammed in the printer |
| PRINTER\_STATUS\_PAPER\_OUT | The printer is out of paper. |
| PRINTER\_STATUS\_PAPER\_PROBLEM | The printer has a paper problem. |
| PRINTER\_STATUS\_PAUSED | The printer is paused. |
| PRINTER\_STATUS\_PENDING\_DELETION | The printer is pending deletion as a result of a call to the [**DeletePrinter**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinter) function. |
| PRINTER\_STATUS\_POWER\_SAVE | The printer is in power save mode. |
| PRINTER\_STATUS\_PRINTING | The printer is printing. |
| PRINTER\_STATUS\_PROCESSING | The printer is processing a command from the [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) function. |
| PRINTER\_STATUS\_SERVER\_UNKNOWN | The printer status is unknown. |
| PRINTER\_STATUS\_TONER\_LOW | The printer is low on toner. |
| PRINTER\_STATUS\_USER\_INTERVENTION | The printer has an error that requires the user to do something. |
| PRINTER\_STATUS\_WAITING | The printer is waiting. |
| PRINTER\_STATUS\_WARMING\_UP | The printer is warming up. |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PRINTER\_INFO\_6W** (Unicode) and **\_PRINTER\_INFO\_6A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**PRINTER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-1)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

[**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3)

[**PRINTER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-4)

[**PRINTER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-5)

