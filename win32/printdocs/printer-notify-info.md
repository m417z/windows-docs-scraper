# PRINTER\_NOTIFY\_INFO structure

The **PRINTER\_NOTIFY\_INFO** structure contains printer information returned by the [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) function. The function returns this information after a wait operation on a printer change notification object has been satisfied.

## Members

**Version**

The version of this structure. Set this member to 2.

**Flags**

A bit flag that indicates the state of the notification structure. If the PRINTER\_NOTIFY\_INFO\_DISCARDED bit is set, it indicates that some notifications had to be discarded.

**Count**

The number of [**PRINTER\_NOTIFY\_INFO\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info-data) elements in the **aData** array.

**aData**

An array of [**PRINTER\_NOTIFY\_INFO\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info-data) structures. Each element of the array identifies a single job or printer information field, and provides the current data for that field.

## Remarks

If the **Flags** member has the PRINTER\_NOTIFY\_INFO\_DISCARDED bit set, this indicates that an overflow or error occurred, and notifications may have been lost. In this case, you must call [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) and specify the PRINTER\_NOTIFY\_OPTIONS\_REFRESH flag to retrieve all current information. Until you request this refresh operation, the system will not send additional notifications for this change notification object.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification)

[**PRINTER\_NOTIFY\_INFO\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info-data)

