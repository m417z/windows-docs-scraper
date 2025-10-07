# FindNextPrinterChangeNotification function

The **FindNextPrinterChangeNotification** function retrieves information about the most recent change notification for a change notification object associated with a printer or print server. Call this function when a wait operation on the change notification object is satisfied.

The function also resets the change notification object to the not-signaled state. You can then use the object in another wait operation to continue monitoring the printer or print server. The operating system will set the object to the signaled state the next time one of a specified set of changes occurs to the printer or print server. The [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) function creates the change notification object and specifies the set of changes to be monitored.

## Parameters

*hChange* \[in\]

A handle to a change notification object associated with a printer or print server. You obtain such a handle by calling the [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) function. The operating system sets this change notification object to the signaled state when it detects one of the changes specified in the object's change notification filter.

*pdwChange* \[out, optional\]

A pointer to a variable whose bits are set to indicate the changes that occurred to cause the most recent notification. The bit flags that might be set correspond to those specified in the *fdwFilter* parameter of the [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) call. The system sets one or more of the following bit flags.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------|
| **PRINTER\_CHANGE\_ADD\_FORM** | A form was added to the server.<br> |
| **PRINTER\_CHANGE\_ADD\_JOB** | A print job was sent to the printer.<br> |
| **PRINTER\_CHANGE\_ADD\_PORT** | A port or monitor was added to the server.<br> |
| **PRINTER\_CHANGE\_ADD\_PRINT\_PROCESSOR** | A print processor was added to the server.<br> |
| **PRINTER\_CHANGE\_ADD\_PRINTER** | A printer was added to the server.<br> |
| **PRINTER\_CHANGE\_ADD\_PRINTER\_DRIVER** | A printer driver was added to the server.<br> |
| **PRINTER\_CHANGE\_CONFIGURE\_PORT** | A port was configured on the server.<br> |
| **PRINTER\_CHANGE\_DELETE\_FORM** | A form was deleted from the server.<br> |
| **PRINTER\_CHANGE\_DELETE\_JOB** | A job was deleted.<br> |
| **PRINTER\_CHANGE\_DELETE\_PORT** | A port or monitor was deleted from the server.<br> |
| **PRINTER\_CHANGE\_DELETE\_PRINT\_PROCESSOR** | A print processor was deleted from the server.<br> |
| **PRINTER\_CHANGE\_DELETE\_PRINTER** | A printer was deleted.<br> |
| **PRINTER\_CHANGE\_DELETE\_PRINTER\_DRIVER** | A printer driver was deleted from the server.<br> |
| **PRINTER\_CHANGE\_FAILED\_CONNECTION\_PRINTER** | A printer connection has failed.<br> |
| **PRINTER\_CHANGE\_SET\_FORM** | A form was set on the server.<br> |
| **PRINTER\_CHANGE\_SET\_JOB** | A job was set.<br> |
| **PRINTER\_CHANGE\_SET\_PRINTER** | A printer was set.<br> |
| **PRINTER\_CHANGE\_SET\_PRINTER\_DRIVER** | A printer driver was set.<br> |
| **PRINTER\_CHANGE\_WRITE\_JOB** | Job data was written.<br> |
| **PRINTER\_CHANGE\_TIMEOUT** | The job timed out.<br> |
| **PRINTER\_CHANGE\_SERVER** | Windows 7: A change occurred on the server.<br> |

*pPrinterNotifyOptions* \[in, optional\]

A pointer to a [**PRINTER\_NOTIFY\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options) structure. Set the **Flags** member of this structure to **PRINTER\_NOTIFY\_OPTIONS\_REFRESH**, to cause the function to return the current data for all monitored printer information fields. The function ignores all other members of the structure. This parameter can be **NULL**.

*ppPrinterNotifyInfo* \[out, optional\]

A pointer to a pointer variable that receives a pointer to a system-allocated, read-only buffer. Call the [**FreePrinterNotifyInfo**](https://learn.microsoft.com/windows/win32/printdocs/freeprinternotifyinfo) function to free the buffer when you are finished with it. This parameter can be **NULL** if no information is required.

The buffer contains a [**PRINTER\_NOTIFY\_INFO**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info) structure, which contains an array of [**PRINTER\_NOTIFY\_INFO\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info-data) structures. Each element of the array contains information about one of the fields specified in the *pPrinterNotifyOptions* parameter of the [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) call. Typically, the function provides data only for the fields that changed to cause the most recent notification. However, if the structure pointed to by the *pPrinterNotifyOptions* parameter specifies **PRINTER\_NOTIFY\_OPTIONS\_REFRESH**, the function provides data for all monitored fields.

If the **PRINTER\_NOTIFY\_INFO\_DISCARDED** bit is set in the **Flags** member of the [**PRINTER\_NOTIFY\_INFO**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info) structure, an overflow or error occurred, and notifications may have been lost. In this case, no additional notifications will be sent until you make a second **FindNextPrinterChangeNotification** call that specifies **PRINTER\_NOTIFY\_OPTIONS\_REFRESH**.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

Call the **FindNextPrinterChangeNotification** function after a wait operation on a notification object created by [**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) has been satisfied. Calling **FindNextPrinterChangeNotification** lets you obtain information about the change that satisfied the wait operation, and resets the notification object so it can be signaled when the next change occurs.

With one exception, do not call the **FindNextPrinterChangeNotification** function if the change notification object is not in the signaled state. If a wait function returns the value **WAIT\_TIMEOUT**, the change object is not in the signaled state. Call the **FindNextPrinterChangeNotification** function only if the wait function succeeds without timing out. The exception is when **FindNextPrinterChangeNotification** is called with the **PRINTER\_NOTIFY\_OPTIONS\_REFRESH** bit set in the *pPrinterNotifyOptions* parameter. Note that even when this flag is set, it is still possible for the **PRINTER\_NOTIFY\_INFO\_DISCARDED** flag to be set in the *ppPrinterNotifyInfo* parameter.

To continue monitoring the printer or print server for changes, repeat the cycle of calling one of the [wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions) , and then calling the **FindNextPrinterChangeNotification** function to examine the change and reset the notification object.

**FindNextPrinterChangeNotification** may combine multiple changes to the same printer information field into a single notification. When this occurs, the function typically collapses all changes for the field into a single entry in the array of [**PRINTER\_NOTIFY\_INFO\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info-data) structures in *ppPrinterNotifyInfo*; the single entry reports only the most current information. However, for some job and printer information fields, the function can return multiple array entries for the same field. In this case, the last array entry for the field reports the current data, and the earlier entries contain the data for the intermediate stages.

When you no longer need the change notification object, close it by calling the [**FindClosePrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findcloseprinterchangenotification) function.

> [!Note]
> In Windows XP with Service Pack 2 (SP2) and later, the Internet Connection Firewall (ICF) blocks printer ports by default, but an exception for File and Print Sharing can be enabled. If a user makes a printer connection to another machine, and the exception is not enabled, then the user will not receive printer change notifications from the server. A machine admin will have to enable exception.

## Examples

The following code sample illustrates how you might monitor printer status by using these functions.

```C++
// Get change notification handle for the printer
chgObject = FindFirstPrinterChangeNotification(
                hPrinter,
                PRINTER_CHANGE_JOB,
                0,
                NULL);

if (chgObject != INVALID_HANDLE_VALUE) {
    while (bKeepMonitoring) {
        // Wait for the change notification
        WaitForSingleObject(chgObject, INFINITE);

        fcnreturn = FindNextPrinterChangeNotification(
                        chgObject,
                        pdwChange,
                        NULL,
                        NULL);

        if (fcnreturn) {
            // Check value of *pdwChange and
            //  deal with the indicated change
        }
        // Insert some mechanism to stop monitoring
        //  such as:
        //
        // if (something happens) {
        //     bKeepMonitoring = false;
        // }
        //
    }
    // Close Printer Change Notification handle when finished.
    FindClosePrinterChangeNotification(chgObject);
} else {
    // Unable to open printer change notification handle
    dwStatus = GetLastError();
}
```

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

[**FindFirstPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification)

[**PRINTER\_NOTIFY\_INFO**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info)

[**PRINTER\_NOTIFY\_INFO\_DATA**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info-data)

[**PRINTER\_NOTIFY\_OPTIONS**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-options)

