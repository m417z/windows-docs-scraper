# FindFirstPrinterChangeNotification function

The **FindFirstPrinterChangeNotification** function creates a change notification object and returns a handle to the object. You can then use this handle in a call to one of the wait functions to monitor changes to the printer or print server.

The **FindFirstPrinterChangeNotification** call specifies the type of changes to be monitored. You can specify a set of conditions to monitor for changes, a set of printer information fields to monitor, or both.

A wait operation on the change notification handle succeeds when one of the specified changes occurs in the specified printer or print server. You then call the [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) function to retrieve information about the change, and to reset the change notification object for use in the next wait operation.

## Parameters

*hPrinter* \[in\]

A handle to the printer or print server that you want to monitor. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*fdwFilter*

The conditions that will cause the change notification object to enter a signaled state. A change notification occurs when one or more of the specified conditions are met. The *fdwFilter* parameter can be zero if *pPrinterNotifyOptions* is non-**NULL**.

This parameter can be one or more of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **PRINTER\_CHANGE\_FORM** | Notify of any changes to a form. You can set this general flag or one or more of the following specific flags:<br>
PRINTER\_CHANGE\_ADD\_FORM

PRINTER\_CHANGE\_SET\_FORM

PRINTER\_CHANGE\_DELETE\_FORM

|
| **PRINTER\_CHANGE\_JOB** | Notify of any changes to a job. You can set this general flag or one or more of the following specific flags:<br>
PRINTER\_CHANGE\_ADD\_JOB

PRINTER\_CHANGE\_SET\_JOB

PRINTER\_CHANGE\_DELETE\_JOB

PRINTER\_CHANGE\_WRITE\_JOB

|
| **PRINTER\_CHANGE\_PORT** | Notify of any changes to a port. You can set this general flag or one or more of the following specific flags:<br>
PRINTER\_CHANGE\_ADD\_PORT

PRINTER\_CHANGE\_CONFIGURE\_PORT

PRINTER\_CHANGE\_DELETE\_PORT

|
| **PRINTER\_CHANGE\_PRINT\_PROCESSOR** | Notify of any changes to a print processor. You can set this general flag or one or more of the following specific flags: <br>
PRINTER\_CHANGE\_ADD\_PRINT\_PROCESSOR

PRINTER\_CHANGE\_DELETE\_PRINT\_PROCESSOR

|
| **PRINTER\_CHANGE\_PRINTER** | Notify of any changes to a printer. You can set this general flag or one or more of the following specific flags:<br>
PRINTER\_CHANGE\_ADD\_PRINTER

PRINTER\_CHANGE\_SET\_PRINTER

PRINTER\_CHANGE\_DELETE\_PRINTER

PRINTER\_CHANGE\_FAILED\_CONNECTION\_PRINTER

|
| **PRINTER\_CHANGE\_PRINTER\_DRIVER** | Notify of any changes to a printer driver. You can set this general flag or one or more of the following specific flags:<br>
PRINTER\_CHANGE\_ADD\_PRINTER\_DRIVER

PRINTER\_CHANGE\_SET\_PRINTER\_DRIVER

PRINTER\_CHANGE\_DELETE\_PRINTER\_DRIVER

|
| **PRINTER\_CHANGE\_ALL** | Notify if any of the preceding changes occur.<br> |
| **PRINTER\_CHANGE\_SERVER** | Windows 7: Notify of any changes to the server.<br> This flag is not included in the changes monitored by setting the **PRINTER\_CHANGE\_ALL** value.<br> |

For descriptions of the more specific flags in the preceding table, see the [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) function.

*fdwOptions*

The flag that determines the category of printers for which notifications will work.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------|
| **PRINTER\_NOTIFY\_CATEGORY\_ALL**<br>0x001000 | [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) returns notifications for both 2D and 3D printers.<br> |
| **PRINTER\_NOTIFY\_CATEGORY\_3D**<br>0x002000 | [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) returns notifications only for 3D printers.<br> |

When this flag is set to zero (0), **FindFirstPrinterChangeNotification** will only work for 2D printers. This is the default value.

*pPrinterNotifyOptions* \[in, optional\]

A pointer to a [**PRINTER\_NOTIFY\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options) structure. The **pTypes** member of this structure is an array of one or more [**PRINTER\_NOTIFY\_OPTIONS\_TYPE**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options-type) structures, each of which specifies a printer information field to monitor. A change notification occurs when one or more of the specified fields changes. When a change occurs, the [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) function can retrieve the new printer information. This parameter can be **NULL** if *fdwFilter* is nonzero.

For a list of fields that can be monitored, see [**PRINTER\_NOTIFY\_OPTIONS\_TYPE**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options-type).

## Return value

If the function succeeds, the return value is a handle to a change notification object associated with the specified printer or print server.

If the function fails, the return value is INVALID\_HANDLE\_VALUE.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

To monitor a printer or print server, call the **FindFirstPrinterChangeNotification** function, then use the returned change notification object handle in a call to one of the [wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). A wait operation on a change notification object is satisfied when the change notification object enters the signaled state. The system signals the object when one or more of the changes specified by *fdwFilter* or *pPrinterNotifyOptions* occurs in the monitored printer or print server.

When you call **FindFirstPrinterChangeNotification**, either *fdwFilter* must be nonzero or *pPrinterNotifyOptions* must be non-**NULL**. If both are specified, notifications will occur for both.

When a wait operation on a printer change notification object is satisfied, call the [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) function to determine the cause of the notification. For a condition specified by *fdwFilter*, **FindNextPrinterChangeNotification** reports the condition or conditions that changed. For a printer information field specified by *pPrinterNotifyOptions*, **FindNextPrinterChangeNotification** reports the field or fields that changed as well as the new information for these fields. **FindNextPrinterChangeNotification** also resets the change notification object to the nonsignaled state so you can use it in another wait operation to continue monitoring the printer or print server.

With one exception, do not call the [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) function if the change notification object is not in the signaled state. If the wait function returns the value WAIT\_TIMEOUT, the change object is not in the signaled state. Call the **FindNextPrinterChangeNotification** function only if the wait function succeeds without timing out. The exception is when **FindNextPrinterChangeNotification** is called with the PRINTER\_NOTIFY\_OPTIONS\_REFRESH bit set in the *pPrinterNotifyOptions* parameter.

When you no longer need the change notification object, close it by calling the [**FindClosePrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findcloseprinterchangenotification) function.

Callers of **FindFirstPrinterChangeNotification** must ensure that the printer handle passed into **FindFirstPrinterChangeNotification** remains valid until [**FindClosePrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findcloseprinterchangenotification) is called. If the printer handle is closed before the printer change notification handle, further notifications will fail to be delivered.

**FindFirstPrinterChangeNotification** will not send change notifications for 3D printers to server handles.

> [!Note]
> In Windows XP with Service Pack 2 (SP2) and later, the Internet Connection Firewall (ICF) blocks printer ports by default, but an exception for File and Print Sharing can be enabled. If a user makes a printer connection to another machine, and the exception is not enabled, then the user will not receive printer change notifications from the server. A machine admin will have to enable exception.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Spoolss.dll |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**FindClosePrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findcloseprinterchangenotification)

[**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**PRINTER\_NOTIFY\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options)

[**PRINTER\_NOTIFY\_OPTIONS\_TYPE**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options-type)

