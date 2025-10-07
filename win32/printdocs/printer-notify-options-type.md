# PRINTER\_NOTIFY\_OPTIONS\_TYPE structure

The **PRINTER\_NOTIFY\_OPTIONS\_TYPE** structure specifies the set of printer or job information fields to be monitored by a printer change notification object.

A call to the [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) function specifies a [**PRINTER\_NOTIFY\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options) structure, which contains an array of **PRINTER\_NOTIFY\_OPTIONS\_TYPE** structures.

## Members

**Type**

The type to be watched. This member can be one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| **JOB\_NOTIFY\_TYPE**

0x01 | Indicates that the fields specified in the **pFields** array are JOB\_NOTIFY\_FIELD\_\* constants.\ | | **PRINTER\_NOTIFY\_TYPE**

0x00 | Indicates that the fields specified in the **pFields** array are PRINTER\_NOTIFY\_FIELD\_\* constants.\ |

**Reserved0**

Reserved.

**Reserved1**

Reserved.

**Reserved2**

Reserved.

**Count**

The number of elements in the **pFields** array.

**pFields**

A pointer to an array of values. Each element of the array specifies a job or printer information field of interest. For a list of supported printer and job information fields, see the [**PRINTER\_NOTIFY\_INFO\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info-data) structure.

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

[**PRINTER\_NOTIFY\_INFO\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info-data)

[**PRINTER\_NOTIFY\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options)

