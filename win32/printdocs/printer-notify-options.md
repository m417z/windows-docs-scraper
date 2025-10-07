# PRINTER\_NOTIFY\_OPTIONS structure

The **PRINTER\_NOTIFY\_OPTIONS** structure specifies options for a change notification object that monitors a printer or print server.

## Members

**Version**

The version of this structure. Set this member to 2.

**Flags**

A bit flag. If you set the PRINTER\_NOTIFY\_OPTIONS\_REFRESH flag in a call to the [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) function, the function provides current data for all monitored printer information fields. The [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) function ignores the **Flags** member.

**Count**

The number of elements in the **pTypes** array.

**pTypes**

A pointer to an array of [**PRINTER\_NOTIFY\_OPTIONS\_TYPE**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options-type) structures. Use one element of this array to specify the printer information fields to monitor, and one element to specify the job information fields to monitor. You can monitor either printer information, job information, or both.

## Remarks

Use this structure with the [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) function to specify the set of printer or job information fields to monitor for change.

Use this structure with the [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) function to request the current data for all monitored printer and job information fields. In this case, the **Flags** member specifies the PRINTER\_NOTIFY\_OPTIONS\_REFRESH flag, and the function ignores the other structure members.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification)

[**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification)

[**PRINTER\_NOTIFY\_OPTIONS\_TYPE**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options-type)

